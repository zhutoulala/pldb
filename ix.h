//
//ix.h - the index manager component header
//

#include "pf.h"
#include "rm.h"
#include "res.h"

class IX_Manager{
public:
	IX_Manager(PF_Manager &pfm);              // Constructor
	~IX_Manager();                             // Destructor
public:
	RC CreateIndex(const char *fileName,          // Create new index
			int indexNo,
			AttrType attrType,
			int attrLength);
	RC DestroyIndex (const char *fileName,int indexNo);
	RC OpenIndex(const char *fileName, int indexNo, IX_IndexHandle &indexHandle);
	RC CloseIndex(IX_IndexHandle &indexHandle);
};


class IX_IndexHandle{
public:
	IX_IndexHandle  ();                             // Constructor
	~IX_IndexHandle ();                             // Destructor
public:
	RC InsertEntry(void *pData, const RID &rid);  // Insert new index entry
	RC DeleteEntry(void *pData, const RID &rid);  // Delete index entry
	RC ForcePages();                             // Copy index to disk
 };

class IX_IndexScan {
public:
	IX_IndexScan  ();                                 // Constructor
	~IX_IndexScan ();                                 // Destructor
public:
	RC OpenScan(const IX_IndexHandle &indexHandle, // Initialize index scan
                      CompOp      compOp,
                      void        *value,
                      ClientHint  pinHint = NO_HINT);           
	RC GetNextEntry(RID &rid);                         // Get next matching entry
	RC CloseScan();                                 // Terminate index scan
 };

