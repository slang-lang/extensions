
#ifndef Extensions_Sqlite3_Types_h
#define Extensions_Sqlite3_Types_h


// Library includes
#include <map>
#include <Externals/sqlite_3.30.1/sqlite3.h>

// Project includes
#include "Sqlite3Column.h"
#include "Sqlite3Result.h"
#include "Sqlite3Row.h"

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


// {
// connection handle, connection
typedef std::map<int /*connection handle*/, sqlite3*> Sqlite3ConnectionMap;

extern Sqlite3ConnectionMap mConnections;
// }


// {
// result handle, resource
extern Sqlite3ResultMap mResults;
// }


}


#endif
