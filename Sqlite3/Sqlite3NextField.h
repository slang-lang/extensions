
#ifndef Extensions_Sqlite3NextField_h
#define Extensions_Sqlite3NextField_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3NextField : public Extensions::ExtensionMethod
{
public:
    Sqlite3NextField()
	: ExtensionMethod(0, "sqlite3_next_field", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_result = (*it++).value().toInt();

			int nextField = 0;
			if ( param_result > 0 && param_result < (int)mResults.size() ) {
                nextField = mResults[param_result].nextField();
			}

			*result = Runtime::IntegerObject( nextField );
		}
		catch ( std::exception& e ) {
			Runtime::Object *data = Controller::Instance().repository()->createInstance(Runtime::StringObject::TYPENAME, ANONYMOUS_OBJECT);
			*data = Runtime::StringObject(std::string(e.what()));

			Controller::Instance().thread(threadId)->exception() = Runtime::ExceptionData(data, token.position());
			return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
