
#ifndef Extensions_Sqlite3GetFieldName_h
#define Extensions_Sqlite3GetFieldName_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Sqlite3 {


class Sqlite3GetFieldName : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldName()
    : ExtensionMethod(0, "sqlite3_get_field_name", Designtime::StringObject::TYPENAME)
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
            int param_index = (*it++).value().toInt();

            std::string fieldName;
            if ( param_result > 0 && param_result < (int)mResults.size() ) {
                fieldName = mResults[param_result].getCurrentFieldName();
            }

            *result = Runtime::StringObject( fieldName );
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


class Sqlite3GetFieldNameByIndex : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldNameByIndex()
	: ExtensionMethod(0, "sqlite3_get_field_name", Designtime::StringObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("result", Designtime::IntegerObject::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("field_index", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_result = (*it++).value().toInt();
			int param_index = (*it++).value().toInt();

			std::string fieldName;
            if ( param_result > 0 && param_result < (int)mResults.size() ) {
                fieldName = mResults[param_result].getFieldNameByIndex(param_index);
            }

			*result = Runtime::StringObject( fieldName );
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
