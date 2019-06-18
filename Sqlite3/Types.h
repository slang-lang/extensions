
#ifndef Extensions_Sqlite3_Types_h
#define Extensions_Sqlite3_Types_h


// Library includes
#include <map>
#include <sqlite3.h>

// Project includes

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


// connection handle, connection
typedef std::map<int /*connection handle*/, sqlite3*> Sqlite3ConnectionMap;

extern Sqlite3ConnectionMap mConnections;
extern int mNumConnections;

/*
// result handle, resource
typedef std::map<int, MYSQL_RES*> MysqlResultMap;

extern Sqlite3ResultMap mResults;
extern int mNumResults;
*/


}


#endif
