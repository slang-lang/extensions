
#ifndef Extensions_Sqlite3GetFieldValue_h
#define Extensions_Sqlite3GetFieldValue_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Sqlite3 {


class Sqlite3GetFieldValue : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldValue()
    : ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringObject::TYPENAME)
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

            std::string fieldValue;
            if ( param_result > 0 && param_result < (int)mResults.size() ) {
                fieldValue = mResults[param_result].getCurrentFieldValue();
            }

            *result = Runtime::StringObject( fieldValue );
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

class Sqlite3GetFieldValueByIndex : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldValueByIndex()
	: ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringObject::TYPENAME)
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

			std::string fieldValue;
            if ( param_result > 0 && param_result < (int)mResults.size() ) {
                fieldValue = mResults[param_result].getFieldValueByIndex(param_index);
            }

			*result = Runtime::StringObject( fieldValue );
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


class Sqlite3GetFieldValueByName : public Extensions::ExtensionMethod
{
public:
    Sqlite3GetFieldValueByName()
    : ExtensionMethod(0, "sqlite3_get_field_value", Designtime::StringObject::TYPENAME)
    {
        ParameterList params;
        params.push_back(Parameter::CreateDesigntime("result", Designtime::IntegerObject::TYPENAME));
        params.push_back(Parameter::CreateDesigntime("field_name", Designtime::StringObject::TYPENAME));

        setSignature(params);
    }

public:
    Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
    {
        ParameterList list = mergeParameters(params);

        try {
            ParameterList::const_iterator it = list.begin();

            int param_result = (*it++).value().toInt();
            std::string param_name = (*it++).value().toStdString();

            std::string fieldValue;
            if ( param_result > 0 && param_result < (int)mResults.size() ) {
                fieldValue = mResults[param_result].getFieldValueByName(param_name);
            }

            *result = Runtime::StringObject( fieldValue );
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
