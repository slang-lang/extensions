
#ifndef Extensions_MQOpen_h
#define Extensions_MQOpen_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace MQ {


class MQOpenByID : public Extensions::ExtensionMethod
{
public:
	MQOpenByID()
	: ExtensionMethod(nullptr, "msgget", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("id", Designtime::IntegerObject::TYPENAME));
		//params.push_back(Parameter::CreateDesigntime("mode", Designtime::IntegerObject::TYPENAME, 666, true));
		params.push_back(Parameter::CreateDesigntime("create", Designtime::BoolObject::TYPENAME, false, true));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_id = (*it++).value().toInt();
			//int param_mode = (*it++).value().toInt();
			bool param_create = (*it++).value().toBool();

			size_t queue_handle = mMQs.size();
			int& queue = mMQs[queue_handle] = -1;
			key_t key = param_id;
		       
			queue = msgget(key, 0666 | (param_create ? IPC_CREAT : 0));

			if ( queue == -1 ) {
				queue_handle = 0;
			}

			*result = Runtime::IntegerObject( static_cast<int>(queue_handle) );
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

class MQOpenByName : public Extensions::ExtensionMethod
{
public:
	MQOpenByName()
	: ExtensionMethod(nullptr, "msgget", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringObject::TYPENAME));
		//params.push_back(Parameter::CreateDesigntime("mode", Designtime::IntegerObject::TYPENAME, 666, true));
		params.push_back(Parameter::CreateDesigntime("create", Designtime::BoolObject::TYPENAME, false, true));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			std::string param_name = (*it++).value().toStdString();
			//int param_mode = (*it++).value().toInt();
			bool param_create = (*it++).value().toBool();

			size_t queue_handle = mMQs.size();
			int& queue = mMQs[queue_handle] = -1;
			key_t key;
		       
			if ( (key = ftok(param_name.c_str(), 'B')) != -1 ) {
				queue = msgget(key, 0666 | (param_create ? IPC_CREAT : 0));
			}

			if ( queue == -1 ) {
				queue_handle = 0;
			}

			*result = Runtime::IntegerObject( static_cast<int>(queue_handle) );
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

