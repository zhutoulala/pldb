

typedef enum {
      //errors which can be recovered
      PF_EOF = -100,       // end of file
      PF_PAGEPINNED,       // page pinned in buffer
      PF_PAGENOTINBUF,     // page to be unpinned is not in buffer
      PF_PAGEUNPINNED,     // page already unpinned
      PF_PAGEFREE,         // page already free
      PF_INVALIDPAGE,      // invalid page number
      PF_FILEOPEN,         // file handle already open
      PF_CLOSEDFILE,       // file is closed

      // good
      PF_OK = 0,
      
      //errors which can NOT be recovered
      PF_NOMEM,      // out of memory
      PF_NOBUF,            // out of buffer space
      PF_INCOMPLETEREAD,   // incomplete read of page from file
      PF_INCOMPLETEWRITE,  // incomplete write of page to file
      PF_HDRREAD,          // incomplete read of header from file
      PF_HDRWRITE,         // incomplete write of header to file
      // Internal PF errors:
      PF_PAGEINBUF,        // new allocated page already in buffer
      PF_HASHNOTFOUND,     // hash table entry not found
      PF_HASHPAGEEXIST,    // page already exists in hash table
      PF_INVALIDNAME,      // invalid file name
      PF_UNIX             // Unix error
} PFRC;


class PF_Manager{
public:
	PF_Manager();
	~PF_Manager();
public:
	PFRC CreateFile(const char *fileName);
	PFRC DestroyFile(const char *fileName);
	PFRC OpenFile(const char *fileName, PF_FileHandle &fileHandle);
	PFRC CloseFile(PF_FileHandle &fileHandle);	
	PFRC AllocateBlock(char *&buffer); //allocate a new scratch page in buffer
	PFRC DisposeBlock(char *buffer); //dispose of a scratch page
}


class PF_FileHandle{
public:
	PF_FileHandle();
	~PF_FileHandle();
	PF_FileHandle(const PF_FileHandle &fileHandle);
	PF_FileHandle& operator= (const PF_FileHandle &fileHandle);
public:
	PFRC GetFirstPage(PF_PageHandle &pageHandle) const;
	PFRC GetLastPage(PF_PageHandle &pageHandle) const;
	PFRC GetNextPage(PageNum current, PF_PageHandle &pageHandle) const;
	PFRC GetPrevPage(PageNum current, PF_PageHandle &pageHandle) const;	
	PFRC GetThisPage(PageNum current, PF_PageHandle &pageHandle) const;
	PFRC AllocatePage(PF_PageHandle &pageHandle);
	PFRC DisposePage(PageNum num);
	PFRC MarkDirty(PageNum num) const;
	PFRC UnpinPage(PageNum num) const;
	PFRC ForcePages(PageNum num = ALL_PAGES) const; //write dirty page(s) to disk
}


class PF_PageHandle{
public:
	PF_PageHandle();
	~PF_PageHandle();
	PF_PageHandle(const PF_PageHandle &pageHandle);
	PF_PageHandle& operator= (const PF_PageHandle &pageHandle);
public:
	PFRC GetData(char *&pData) const;
	PFRC GetPageNum(PageNum &num) const;
};

}
