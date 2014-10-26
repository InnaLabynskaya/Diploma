#ifndef __BACKUP__
#define __BACKUP__
#define FILE_NAME_SIZE (260)

class BackUp
{
public:
	BackUp(const char* sFileName);
	void* read(int* pFileSize);
	int write(void* pData, int nBytes);

private:
	char m_sFileName[FILE_NAME_SIZE];
	char m_sLogFileName[FILE_NAME_SIZE];
	char m_sTempFileName[FILE_NAME_SIZE]; 
	int writeImpl(const char* sFileName, const void* pData, int nBytes);
	void* readImpl(const char* sFileName, int* pFileSize);
};

#endif