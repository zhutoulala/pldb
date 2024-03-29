//
//ql.h - Query Language management header
//


struct RelAttr {
	char *relName;     // relation name (may be NULL) 
	char *attrName;    // attribute name              
	friend ostream &operator<<(ostream &s, const RelAttr &ra);
};

struct Value {
	AttrType type;     // type of value               
	void     *data;    // value                       
	friend ostream &operator<<(ostream &s, const Value &v);
};

struct Condition {
	RelAttr lhsAttr;      // left-hand side attribute                     
	CompOp  op;           // comparison operator                          
	int     bRhsIsAttr;   // TRUE if right-hand side is an attribute and not a value
	RelAttr rhsAttr;      // right-hand side attribute if bRhsIsAttr = TRUE
	Value   rhsValue;     // right-hand side value if bRhsIsAttr = FALSE
	friend  ostream &operator<<(ostream &s, const Condition &c);
};


class QL_Manager {
public:
	QL_Manager (SM_Manager &smm, IX_Manager &ixm, RM_Manager &rmm);
	~QL_Manager ();                         // Destructor
public:                                              //
	RC Select(int           nSelAttrs,        // # attrs in Select clause
		const RelAttr selAttrs[],       // attrs in Select clause
		int           nRelations,       // # relations in From clause
              	const char * const relations[], // relations in From clause
              	int           nConditions,      // # conditions in Where clause
              	const Condition conditions[]);  // conditions in Where clause
	RC Insert (const char  *relName,           // relation to insert into
		int         nValues,            // # values to insert
		const Value values[]);          // values to insert
	RC Delete (const char *relName,            // relation to delete from
		int        nConditions,         // # conditions in Where clause
		const Condition conditions[]);  // conditions in Where clause
	RC Update (const char *relName,            // relation to update
		const RelAttr &updAttr,         // attribute to update
		const int bIsValue,             // 0/1 if RHS of = is attribute/value
		const RelAttr &rhsRelAttr,      // attr on RHS of =
		const Value &rhsValue,          // value on RHS of =
		int   nConditions,              // # conditions in Where clause
		const Condition conditions[]);  // conditions in Where clause
};

