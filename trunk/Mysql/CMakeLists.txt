INCLUDE(${PROJECT_SOURCE_DIR}/CMake/Base.cmake)

SET(SOURCES
	MysqlExtension.cpp
	Types.cpp
)

SET(HEADERS
	MysqlAffectedRows.h
	MysqlClose.h
	MysqlDataSeek.h
	MysqlErrno.h
	MysqlError.h
	MysqlExtension.h
	MysqlFieldCount.h
	MysqlFieldSeek.h
	MysqlFieldTell.h
	MysqlFreeResult.h
	MysqlGetClientInfo.h
	MysqlGetFieldName.h
	MysqlGetFieldValue.h
	MysqlInfo.h
	MysqlInit.h
	MysqlNextResult.h
	MysqlNextRow.h
	MysqlNumFields.h
	MysqlNumRows.h
	MysqlPing.h
	MysqlQuery.h
	MysqlRealConnect.h
	MysqlRealEscapeString.h
	MysqlRowCount.h
	MysqlRowSeek.h
	MysqlRowTell.h
	MysqlSelectDB.h
	MysqlStat.h
	MysqlStoreResult.h
	MysqlUseResult.h
	Types.h
)

SET(DEPENDENCIES
#	CoreExtensions
    mysqlclient
)

build_shared_lib(ObjectiveScriptMysql oscript)
