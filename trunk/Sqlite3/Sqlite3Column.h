
#ifndef Extensions_Sqlite3_Column_h
#define Extensions_Sqlite3_Column_h


// Library includes
#include <string>
#include <vector>

// Project includes

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


class Sqlite3Column
{
public:
    Sqlite3Column(const std::string& name, const std::string& value, const std::string& type = "")
            : Name(name),
              Type(type),
              Value(value)
    { }

public:
    std::string Name;
    std::string Type;
    std::string Value;
};

typedef std::vector<Sqlite3Column> Sqlite3Columns;


}


#endif
