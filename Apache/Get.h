
#ifndef Extensions_Apache_Get_h
#define Extensions_Apache_Get_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Apache {


class Get : public Extensions::ExtensionMethod
{
public:
	Get()
	: ExtensionMethod(0, "get", Designtime::StringObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList &params, Runtime::Object *result, const Token &token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			std::string param_name = (*it++).value().toStdString();

			std::string result_value;

			StringMap::const_iterator getIt = mGetQueryString.find(param_name);
			if ( getIt != mGetQueryString.end() ) {
				result_value = getIt->second;
			}

			*result = Runtime::StringObject(result_value);
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
