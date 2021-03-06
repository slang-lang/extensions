
// Header
#include "MysqlExtension.h"

// Library includes

// Project includes
#include "MysqlAffectedRows.h"
#include "MysqlClose.h"
#include "MysqlDataSeek.h"
#include "MysqlErrno.h"
#include "MysqlError.h"
#include "MysqlFetchRow.h"
#include "MysqlFieldCount.h"
#include "MysqlFieldSeek.h"
#include "MysqlFieldTell.h"
#include "MysqlFreeResult.h"
#include "MysqlGetClientInfo.h"
#include "MysqlGetFieldName.h"
#include "MysqlGetFieldValue.h"
#include "MysqlInfo.h"
#include "MysqlInit.h"
#include "MysqlNextResult.h"
#include "MysqlNumFields.h"
#include "MysqlNumRows.h"
#include "MysqlPing.h"
#include "MysqlQuery.h"
#include "MysqlRealConnect.h"
#include "MysqlRealEscapeString.h"
#include "MysqlRowCount.h"
#include "MysqlRowSeek.h"
#include "MysqlRowTell.h"
#include "MysqlSelectDB.h"
#include "MysqlStat.h"
#include "MysqlStoreResult.h"
#include "MysqlUseResult.h"

// Namespace declarations


namespace Mysql {


MariaDBExtension::MariaDBExtension()
: AExtension( "Mysql", "0.4.2" )
{
	mMysqlConnections[0] = mysql_init( nullptr );

	/* get user name for current connection */
	const char *version;
	mariadb_get_infov(mMysqlConnections[0], MARIADB_CLIENT_VERSION, (void *)&version);

	mName = "MariaDB (using libMariaDB " + std::string( version ) + ")";
}

void MariaDBExtension::initialize( Slang::IScope* /*scope*/ )
{
	// nothing to do here
}

void MariaDBExtension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

	methods.push_back( new Mysql::MysqlAffectedRows() );
	methods.push_back( new Mysql::MysqlClose() );
	methods.push_back( new Mysql::MysqlDataSeek() );
	methods.push_back( new Mysql::MysqlErrno() );
	methods.push_back( new Mysql::MysqlError() );
	methods.push_back( new Mysql::MysqlFetchRow() );
	methods.push_back( new Mysql::MysqlFetchRow( "mysql_next_row", Slang::LanguageFeatureState::Deprecated ) );	// this is kept to be backwards compatible to old implementations that used 'mysql_next_row' instead of 'mysql_fetch_row'
	methods.push_back( new Mysql::MysqlFieldCount() );
	methods.push_back( new Mysql::MysqlFieldSeek() );
	methods.push_back( new Mysql::MysqlFieldTell() );
	methods.push_back( new Mysql::MysqlFreeResult() );
	methods.push_back( new Mysql::MysqlGetClientInfo() );
	methods.push_back( new Mysql::MysqlGetFieldName() );
	methods.push_back( new Mysql::MysqlGetFieldValueByIndex() );
	methods.push_back( new Mysql::MysqlGetFieldValueByName() );
	methods.push_back( new Mysql::MysqlInfo() );
	methods.push_back( new Mysql::MysqlInit() );
	methods.push_back( new Mysql::MysqlNextResult() );
	methods.push_back( new Mysql::MysqlNumFields() );
	methods.push_back( new Mysql::MysqlNumRows() );
	methods.push_back( new Mysql::MysqlPing() );
	methods.push_back( new Mysql::MysqlQuery() );
	methods.push_back( new Mysql::MysqlRealEscapeString() );
	methods.push_back( new Mysql::MysqlRealConnect() );
	methods.push_back( new Mysql::MysqlRowCount() );
	methods.push_back( new Mysql::MysqlRowSeek() );
	methods.push_back( new Mysql::MysqlRowTell() );
	methods.push_back( new Mysql::MysqlSelectDB() );
	methods.push_back( new Mysql::MysqlStat() );
	methods.push_back( new Mysql::MysqlStoreResult() );
	methods.push_back( new Mysql::MysqlUseResult() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Mysql::MariaDBExtension() );
}
