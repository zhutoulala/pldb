//
//pf.h - the paged file manager component header
//

#include "res.h"

class PF_Manager{
public:
	PF_Manager();
	~PF_Manager();
public:
	RC CreateFile(const char *fileName);
	RC DestroyFile(const char *fileName);
	RC OpenFile(const char *fileName, PF_FileHandle &fileHandle);
	RC CloseFile(PF_FileHandle &fileHandle);	
	RC AllocateBlock(char *&buffer); //allocate a new scratch page in buffer
	RC DisposeBlock(char *buffer); //dispose of a scratch page
}


class PF_FileHandle{
public:
	PF_FileHandle();
	~PF_FileHandle();
	PF_FileHandle(const PF_FileHandle &fileHandle);
	PF_FileHandle& operator= (const PF_FileHandle &fileHandle);
public:
	RC GetFirstPage(PF_PageHandle &pageHandle) const;
	RC GetLastPage(PF_PageHandle &pageHandle) const;
	RC GetNextPage(PageNum current, PF_PageHandle &pageHandle) const;
	RC GetPrevPage(PageNum current, PF_PageHandle &pageHandle) const;	
	RC GetThisPage(PageNum current, PF_PageHandle &pageHandle) const;
	RC AllocatePage(PF_PageHandle &pageHandle);
	RC DisposePage(PageNum num);
	RC MarkDirty(PageNum num) const;
	RC UnpinPage(PageNum num) const;
	RC ForcePages(PageNum num = ALL_PAGES) const; //write dirty page(s) to disk
}


class PF_PageHandle{
public:
	PF_PageHandle();
	~PF_PageHandle();
	PF_PageHandle(const PF_PageHandle &pageHandle);
	PF_PageHandle& operator= (const PF_PageHandle &pageHandle);
public:
	RC GetData(char *&pData) const;
	RC GetPageNum(PageNum &num) const;
};

}
