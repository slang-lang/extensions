
// Header
#include "Sqlite3Extension.h"

// Library includes
#include <Core/Runtime/BuildInTypes/IntegerObject.h>

// Project includes
#include "Sqlite3Close.h"
#include "Sqlite3Errcode.h"
#include "Sqlite3Errmsg.h"
#include "Sqlite3Exec.h"
#include "Sqlite3Open.h"

// Namespace declarations


namespace Sqlite3 {


Sqlite3Extension::Sqlite3Extension()
: AExtension("Sqlite3")
{
    int result = sqlite3_initialize();
    if ( result != SQLITE_OK ) {
        std::cout << "Error while initializing sqlite3 extension!" << std::endl;
    }
}

Sqlite3Extension::~Sqlite3Extension()
{
    sqlite3_shutdown();
}

void Sqlite3Extension::initialize(ObjectiveScript::IScope* scope)
{
	//std::cout << "Sqlite3Extension::initialize()" << std::endl;

    (void)scope;

    // global vars/consts currently don't work for extensions :-(
    //scope->define("SQLITE_OK", new ObjectiveScript::Runtime::IntegerObject(SQLITE_OK));
}

void Sqlite3Extension::provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods)
{
	assert(methods.empty());

    methods.push_back(new Sqlite3Close());
    methods.push_back(new Sqlite3Errcode());
    methods.push_back(new Sqlite3Errmsg());
    methods.push_back(new Sqlite3Exec());
	methods.push_back(new Sqlite3Open());
}


}


extern "C" AExtension* factory(void) {
	return dynamic_cast<AExtension*>( new Sqlite3::Sqlite3Extension() );
}

