
#ifndef Extensions_Sqlite3RowCount_h
#define Extensions_Sqlite3RowCount_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Sqlite3 {


class Sqlite3RowCount : public Extensions::ExtensionMethod
{
public:
    Sqlite3RowCount()
	: ExtensionMethod(0, "sqlite3_row_count", Designtime::IntegerObject::TYPENAME)
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

			int rowCount = 0;

			if ( param_result > 0 && param_result < (int)mResults.size() ) {
			    rowCount = (int)mResults[param_result].rowCount();
			}

			*result = Runtime::IntegerObject( rowCount );
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
