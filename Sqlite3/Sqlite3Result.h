
#ifndef Extensions_Sqlite3_Result_h
#define Extensions_Sqlite3_Result_h


// Library includes
#include <algorithm>
#include <string>
#include <vector>

// Project includes
#include "Sqlite3Row.h"

// Forward declarations

// Namespace declarations


namespace Sqlite3 {


class Sqlite3Result
{
public:
    Sqlite3Result()
    : mFieldCount(0),
      mFieldIdx(0),
      mRowCount(0),
      mRowIdx(0)
    { }

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
        if ( mRowIdx <= mRowCount ) {
            if ( mFieldIdx <= mFieldCount ) {
                return mRows[mRowIdx - 1].name(mFieldIdx - 1);
            }
        }

        return "";
    }

    std::string getCurrentFieldValue() const {
        if ( mRowIdx <= mRowCount ) {
            if ( mFieldIdx <= mFieldCount ) {
                return mRows[mRowIdx - 1].value(mFieldIdx - 1);
            }
        }

        return "";
    }

    std::string getFieldNameByIndex(size_t offset) const {
        if ( mRowIdx <= mRowCount ) {
            if ( offset <= mFieldCount ) {
                return mRows[mRowIdx - 1].name(offset - 1);
            }
        }

        return "";
    }

    std::string getFieldValueByIndex(size_t offset) const {
        if ( mRowIdx <= mRowCount ) {
            if ( offset <= mFieldCount ) {
                return mRows[mRowIdx - 1].value(offset - 1);
            }
        }

        return "";
    }

    std::string getFieldValueByName(const std::string& name) const {
        if ( mRowIdx <= mRowCount ) {
            for ( size_t idx = 1; idx <= mFieldCount; ++idx ) {
                //if ( std::toupper(mRows[mRowIdx - 1].name(idx - 1)) == std::toupper(name) ) {

                std::string a = mRows[mRowIdx - 1].name(idx - 1);
                std::string b = name;

                if ( std::equal(a.begin(), a.end(),
                                b.begin(), b.end(),
                                [](char a, char b) {
                                    return tolower(a) == tolower(b);
                                }) ) {
                    return mRows[mRowIdx - 1].value(idx - 1);
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
        mFieldCount = row.size();
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


}


#endif
