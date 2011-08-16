//
//rm.h - the record management component header
//
#include "res.h"
#include "pf.h"

class RM_Manager{
public:
	RM_Manager(PF_Manager &pfm);
	~RM_Manager();
public:
	RC CreateFile(const char *fileName, int recordSize);
	RC DestroyFile(const char *fileName);
	RC OpenFile(const char *fileName, RM_FileHandle &fileHandle);
	RC CloseFile(RM_FileHandle &fileHandle);
}

class RM_FileHandle{
public:
	RM_FileHandle();
	~RM_FileHandle();
public:
	RC GetRec(const RID &rid, RM_Record &rec) const; //get a record
	RC InsertRec(const char *pData, RID &rid); //insert a new record
	RC DeleteRec(const RID &rid); //delete a record
	RC UpdateRec(const RM_Record &rec); //update a record
	RC ForcePages(PageNum num=ALL_PAGES) const //write dirty pages to disk
}

class RM_FileScan{
public:
	RM_FileScan();
	~RM_FileScan();
public:
	RC OpenScan(const RM_FileHandle &fileHandle, //initialize file scan
			AttrType attrType,
			int attrLength,
			int attrOffset,
			CompOp compOp,
			void *value,
			ClientHint pinHint = NO_HINT);
	RC GetNextRec(RM_Record &rec);
	RC CloseScan();
}

class RM_Record{
public:
	RM_Record();
	~RM_Record();
public:
	RC GetData (char *&pData) const;	
	RC GetRid (RID &rid) const;
}


class RID{
public:
	RID();
	~RID();
	RID(PageNum pageNum, SlotNum slotNum);
public:
	RC GetPageNum(PageNum &pageNum) const;
	RC GetSlotNum(SlotNum &slotNum) const;
}









