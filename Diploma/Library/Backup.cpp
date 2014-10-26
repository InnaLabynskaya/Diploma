#include "BackUp.h"
#include <string>
#include <io.h>
#include <iostream>
using namespace std;

enum States {
	T_Start,
	T_TempFile,
	T_End
};

BackUp::BackUp(const char* sFileName)
{
	strncpy_s(m_sFileName, sFileName, FILE_NAME_SIZE);
	strncpy_s(m_sLogFileName, sFileName, FILE_NAME_SIZE);
	strcat_s(m_sLogFileName, ".log");
	strncpy_s(m_sTempFileName, sFileName, FILE_NAME_SIZE);
	strcat_s(m_sTempFileName, ".tmp");
}

void* BackUp::read(int * pFileSize)
{
	int realSize = 0;
	States state = T_End;
	void* data = readImpl(m_sLogFileName, &realSize);
	if(data != NULL)
	{
		state = *(States*)data;
		delete[] data;
	}
	switch(state)
	{
		case T_Start:
		{
			cout<<"Changes wasn't save "<<endl;
			state = T_End;
			writeImpl(m_sLogFileName, &state, sizeof(state));
			return readImpl(m_sFileName, pFileSize);
		}
		case T_TempFile:
		{
			cout<<"Changes was saved in temp file"<<endl;
			data = readImpl(m_sTempFileName, &realSize);
			writeImpl(m_sFileName, data, realSize);
			*pFileSize = realSize;
			state = T_End;
			writeImpl(m_sLogFileName, &state, sizeof(state));
			return data;
		}
		case T_End:
		default:
		{
			return readImpl(m_sFileName, pFileSize);
		}
	}
}

int BackUp::write(void* pData, int nBytes)
{
	States state = T_Start;
	writeImpl(m_sLogFileName, &state, sizeof(state));
	
	writeImpl(m_sTempFileName, pData, nBytes);
	state = T_TempFile;
	writeImpl(m_sLogFileName, &state, sizeof(state));
	
	int realSize = writeImpl(m_sFileName, pData, nBytes);
	state = T_End;
	writeImpl(m_sLogFileName, &state, sizeof(state));
	return realSize;
}

int BackUp::writeImpl(const char* sFileName, const void* pData, int nBytes)
{
	FILE* f = NULL;
	fopen_s(&f, sFileName, "wb");
	if(f==NULL) {
		return 0;
	}
	int realBytes = fwrite(pData, sizeof(char), nBytes, f);
	fclose(f);
	return realBytes;
}

void* BackUp::readImpl(const char* sFileName, int* pFileSize)
{
	FILE *f = NULL;
	fopen_s(&f, sFileName, "rb");
	if(f==NULL) {
		*pFileSize = 0;
		return NULL;
	}
	int iID = _fileno(f);
	size_t nLength = _filelength(iID);
	void* pTemp = new char[nLength];
	if(pTemp==NULL) {
		*pFileSize = 0;
		return NULL;
	}
	*pFileSize = fread(pTemp, sizeof(char), nLength, f);
	fclose(f);
	return pTemp;
}