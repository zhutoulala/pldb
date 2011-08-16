//
//res.h - common resources shared by each component
//


typedef enum {
      //errors which can be recovered
      EOF = -100,       // end of file
      PAGEPINNED,       // page pinned in buffer
      PAGENOTINBUF,     // page to be unpinned is not in buffer
      PAGEUNPINNED,     // page already unpinned
      PAGEFREE,         // page already free
      INVALIDPAGE,      // invalid page number
      FILEOPEN,         // file handle already open
      CLOSEDFILE,       // file is closed

      // good
      OK = 0,
      
      //errors which can NOT be recovered
      NOMEM,      // out of memory
      NOBUF,            // out of buffer space
      INCOMPLETEREAD,   // incomplete read of page from file
      INCOMPLETEWRITE,  // incomplete write of page to file
      HDRREAD,          // incomplete read of header from file
      HDRWRITE,         // incomplete write of header to file
      // Internal PF errors:
      PAGEINBUF,        // new allocated page already in buffer
      HASHNOTFOUND,     // hash table entry not found
      HASHPAGEEXIST,    // page already exists in hash table
      INVALIDNAME,      // invalid file name
      UNIX             // Unix error
} RC;
