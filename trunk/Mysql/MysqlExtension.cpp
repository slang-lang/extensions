
// Header
#include "MysqlExtension.h"

// Library includes

// Project includes
#include "MysqlAffectedRows.h"
#include "MysqlClose.h"
#include "MysqlDataSeek.h"
#include "MysqlErrno.h"
#include "MysqlError.h"
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
#include "MysqlNextRow.h"
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


MysqlExtension::MysqlExtension()
: AExtension("Mysql")
{
}

void MysqlExtension::initialize(ObjectiveScript::IScope* /*scope*/)
{
	// nothing to do here
}

void MysqlExtension::provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods)
{
	assert(methods.empty());

	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlAffectedRows());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlClose());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlDataSeek());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlErrno());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlError());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlFieldCount());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlFieldSeek());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlFieldTell());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlFreeResult());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlGetClientInfo());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlGetFieldName());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlGetFieldValueByIndex());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlGetFieldValueByName());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlInfo());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlInit());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlNextResult());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlNextRow());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlNumFields());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlNumRows());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlPing());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlQuery());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlRealEscapeString());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlRealConnect());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlRowCount());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlRowSeek());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlRowTell());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlSelectDB());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlStat());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlStoreResult());
	methods.push_back(new ObjectiveScript::Extensions::Mysql::MysqlUseResult());
}


}


extern "C" AExtension* factory(void) {
	return dynamic_cast<AExtension*>( new Mysql::MysqlExtension() );
}
