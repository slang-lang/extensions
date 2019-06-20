
#ifndef Extensions_Sqlite3_Types_h
#define Extensions_Sqlite3_Types_h


// Library includes
#include <map>
#include <sqlite3.h>
#include <string>
#include <vector>

// Project includes

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
struct Sqlite3Row {
    Sqlite3Row(int _argc, char** _argv, char** _azColName, void* _data)
    : argc(_argc),
      argv(_argv),
      azColName(_azColName),
      data(_data)
    { }

    int argc;
    char** argv;
    char** azColName;
    void* data;
};

typedef std::vector<Sqlite3Row> Sqlite3Rows;


class Sqlite3Result
{
public:
    Sqlite3Result()
    {
        clear();
    }

    void clear() {
        mFieldCount = 0;
        mFieldIdx = 0;
        mRowCount = 0;
        mRowIdx = 0;
        mRows.clear();
    }

    size_t fieldCount() const {
        return mFieldCount;
    }

    void fieldSeek(size_t offset) {
        mFieldIdx = offset;

        if ( mFieldIdx > mFieldCount ) {
            mFieldIdx = mFieldCount;
        }
    }

    size_t fieldTell() const {
        return mFieldIdx;
    }

    std::string getCurrentFieldName() const {
        if ( mRowIdx < mRowCount ) {
            if ( mFieldIdx < mFieldCount ) {
                return mRows[mRowIdx - 1].azColName[mFieldIdx - 1];
            }
        }

        return "";
    }

    std::string getCurrentFieldValue() const {
        if ( mRowIdx < mRowCount ) {
            if ( mFieldIdx < mFieldCount ) {
                return mRows[mRowIdx - 1].argv[mFieldIdx - 1];
            }
        }

        return "";
    }

    std::string getFieldNameByIndex(size_t offset) const {
        if ( mRowIdx < mRowCount ) {
            if ( offset < mFieldCount ) {
                return mRows[mRowIdx - 1].azColName[offset - 1];
            }
        }

        return "";
    }

    std::string getFieldValueByIndex(size_t offset) const {
        if ( mRowIdx < mRowCount ) {
            if ( offset < mFieldCount ) {
                return mRows[mRowIdx - 1].argv[offset - 1];
            }
        }

        return "";
    }

    std::string getFieldValueByName(const std::string& name) const {
        if ( mRowIdx < mRowCount ) {
            for ( size_t idx = 0; idx < mFieldCount; ++idx ) {
                if ( strcmp(mRows[mRowIdx - 1].azColName[idx - 1], name.c_str()) == 0 ) {
                    return mRows[mRowIdx - 1].argv[idx - 1];
                }
            }
        }

        return "";
    }

    size_t nextField() {
        mFieldIdx++;
        if ( mFieldIdx > mFieldCount ) {
            return 0;
        }

        return mFieldIdx;
    }

    size_t nextRow() {
        resetFieldIdx();

        mRowIdx++;
        if ( mRowIdx > mRowCount ) {
            return 0;
        }

        return mRowIdx;
    }

    void pushRow(Sqlite3Row row) {
        mFieldCount = row.argc;
        mRowCount++;
        mRows.push_back( row );
    }

    size_t rowCount() const {
        return mRowCount;
    }

    void rowSeek(size_t offset) {
        resetFieldIdx();

        mRowIdx = offset;

        if ( mRowIdx > mRowCount ) {
            mRowIdx = mRowCount;
        }
    }

    size_t rowTell() const {
        return mRowIdx;
    }


private:
    void resetFieldIdx() {
        mFieldIdx = 0;
    }

private:
    size_t mFieldCount;
    size_t mFieldIdx;
    size_t mRowCount;
    size_t mRowIdx;
    Sqlite3Rows mRows;
};


typedef std::map<int, Sqlite3Result> Sqlite3ResultMap;

extern Sqlite3ResultMap mResults;
// }


}


#endif
