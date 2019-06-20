INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
    Externals/sqlite328/sqlite3.c
    Sqlite3Extension.cpp
    Types.cpp
)

SET(HEADERS
    Externals/sqlite328/sqlite3.h
    Externals/sqlite328/sqlite3ext.h
    Defines.h
    Sqlite3Extension.h
    Sqlite3Close.h
    Sqlite3Errcode.h
    Sqlite3Errmsg.h
    Sqlite3Exec.h
    Sqlite3FieldCount.h
    Sqlite3FieldSeek.h
    Sqlite3FieldTell.h
    Sqlite3FreeResult.h
    Sqlite3GetFieldName.h
    Sqlite3GetFieldValue.h
    Sqlite3NextField.h
    Sqlite3NextRow.h
    Sqlite3Open.h
    Sqlite3RowCount.h
    Sqlite3RowSeek.h
    Sqlite3RowTell.h
    Types.h
)

SET(DEPENDENCIES
)

add_include(Externals/sqlite328)

build_shared_lib(ObjectiveScriptSqlite3 oscript)
