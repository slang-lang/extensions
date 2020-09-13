
// Header
#include "Sqlite3Extension.h"

// Library includes
#include <Core/Runtime/BuildInTypes/IntegerObject.h>

// Project includes
#include "Sqlite3Close.h"
#include "Sqlite3Errcode.h"
#include "Sqlite3Errmsg.h"
#include "Sqlite3Exec.h"
#include "Sqlite3FieldCount.h"
#include "Sqlite3FieldSeek.h"
#include "Sqlite3FieldTell.h"
#include "Sqlite3FreeResult.h"
#include "Sqlite3GetFieldName.h"
#include "Sqlite3GetFieldValue.h"
#include "Sqlite3NextField.h"
#include "Sqlite3NextRow.h"
#include "Sqlite3Open.h"
#include "Sqlite3Rewind.h"
#include "Sqlite3RowCount.h"
#include "Sqlite3RowSeek.h"
#include "Sqlite3RowTell.h"

// Namespace declarations


namespace Sqlite3 {


Sqlite3Extension::Sqlite3Extension()
: AExtension( "Sqlite3", "0.0.1" )
{
	int result = sqlite3_initialize();
	if ( result != SQLITE_OK ) {
		std::cerr << "Error while initializing sqlite3 extension!" << std::endl;
	}

	// initialize first connection which acts as invalid handle
	mConnections[0] = nullptr;
	// initialize first result which acts as invalid result "handle"
	mResults[0] = Sqlite3Result();
}

Sqlite3Extension::~Sqlite3Extension()
{
	sqlite3_shutdown();
}

void Sqlite3Extension::initialize( Slang::IScope* scope )
{
	//std::cout << "Sqlite3Extension::initialize()" << std::endl;

	(void)scope;

	// global vars/consts currently don't work for extensions :-(
	//scope->define("SQLITE_OK", new Slang::Runtime::IntegerObject(SQLITE_OK));
}

void Sqlite3Extension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

	methods.push_back( new Sqlite3Close() );
	methods.push_back( new Sqlite3Errcode() );
	methods.push_back( new Sqlite3Errmsg() );
	methods.push_back( new Sqlite3Exec() );
	methods.push_back( new Sqlite3FieldCount() );
	methods.push_back( new Sqlite3FieldSeek() );
	methods.push_back( new Sqlite3FieldTell() );
	methods.push_back( new Sqlite3FreeResult() );
	methods.push_back( new Sqlite3GetFieldName() );
	methods.push_back( new Sqlite3GetFieldNameByIndex() );
	methods.push_back( new Sqlite3GetFieldValue() );
	methods.push_back( new Sqlite3GetFieldValueByIndex() );
	methods.push_back( new Sqlite3GetFieldValueByName() );
	methods.push_back( new Sqlite3NextField() );
	methods.push_back( new Sqlite3NextRow() );
	methods.push_back( new Sqlite3Open() );
	methods.push_back( new Sqlite3Rewind() );
	methods.push_back( new Sqlite3RowCount() );
	methods.push_back( new Sqlite3RowSeek() );
	methods.push_back( new Sqlite3RowTell() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Sqlite3::Sqlite3Extension() );
}

