
#ifndef Extensions_Sqlite3_Row_h
#define Extensions_Sqlite3_Row_h


// Library includes
#include <string>
#include <vector>

// Project includes

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


class Sqlite3Row
{
public:
    std::string name(size_t index) const {
        for ( size_t idx = 0; idx < mColumns.size(); ++idx ) {
            if ( idx == index ) {
                return mColumns[idx].Name;
            }
        }

        return "";
    }

    void push(const std::string& name, const std::string& value) {
        mColumns.push_back( Sqlite3Column(name, value) );
    }

    void push(const Sqlite3Column& column) {
        mColumns.push_back(column);
    }

    std::string type(size_t index) const {
        for ( size_t idx = 0; idx < mColumns.size(); ++idx ) {
            if ( idx == index ) {
                return mColumns[idx].Type;
            }
        }

        return "";
    }

    std::string value(size_t index) const {
        for ( size_t idx = 0; idx < mColumns.size(); ++idx ) {
            if ( idx == index ) {
                return mColumns[idx].Value;
            }
        }

        return "";
    }

    size_t size() const {
        return mColumns.size();
    }

private:
    Columns mColumns;
};

typedef std::vector<Sqlite3Row> Sqlite3Rows;


}


#endif
