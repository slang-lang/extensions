
#ifndef Extensions_Sqlite3Exec_h
#define Extensions_Sqlite3Exec_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Sqlite3 {


class Sqlite3Exec : public Extensions::ExtensionMethod
{
public:
    Sqlite3Exec()
	: ExtensionMethod(0, "sqlite3_exec", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("sql", Designtime::StringObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

            int param_handle = (*it++).value().toInt();
			std::string param_sql = (*it++).value().toStdString();

			int error = sqlite3_exec(mConnections[param_handle], param_sql.c_str(), NULL, 0, NULL);

			*result = ObjectiveScript::Runtime::IntegerObject( error );
		}
		catch ( std::exception& e ) {
			Runtime::Object *data = Controller::Instance().repository()->createInstance(Runtime::StringObject::TYPENAME, ANONYMOUS_OBJECT);
			*data = ObjectiveScript::Runtime::StringObject(std::string(e.what()));

			Controller::Instance().thread(threadId)->exception() = Runtime::ExceptionData(data, token.position());
			return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
