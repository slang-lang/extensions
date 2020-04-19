
#ifndef Extensions_Sqlite3FieldSeek_h
#define Extensions_Sqlite3FieldSeek_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Sqlite3 {


class Sqlite3FieldSeek : public Extensions::ExtensionMethod
{
public:
	Sqlite3FieldSeek()
	: ExtensionMethod(0, "sqlite3_field_seek", Designtime::VoidObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::IntegerObject::TYPENAME));
		params.push_back(Parameter::CreateDesigntime("offset", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* /*result*/, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_result = (*it++).value().toInt();
			int param_offset = (*it++).value().toInt();

			if ( param_result > 0 && param_result < (int)mResults.size() ) {
			    mResults[param_result].fieldSeek(param_offset);
			}
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
