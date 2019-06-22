
#ifndef Extensions_Sqlite3Open_h
#define Extensions_Sqlite3Open_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Sqlite3 {


class Sqlite3Open : public Extensions::ExtensionMethod
{
public:
    Sqlite3Open()
	: ExtensionMethod(0, "sqlite3_open", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("file", Designtime::StringObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			std::string param_file = (*it++).value().toStdString();

			size_t connection_handle = mConnections.size();
			sqlite3** database = &mConnections[connection_handle];

			int error = sqlite3_open(param_file.c_str(), database);

			*result = Runtime::IntegerObject( static_cast<int>(error ? 0 : connection_handle) );
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
