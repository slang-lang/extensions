
#ifndef Extensions_Mysql_MysqlErrno_h
#define Extensions_Mysql_MysqlErrno_h


// Library includes

// Project includes
#include <Core/Common/Exceptions.h>
#include <Core/Designtime/BuildInTypes/IntegerObject.h>
#include <Core/Designtime/BuildInTypes/StringObject.h>
#include <Core/Extensions/ExtensionMethod.h>
#include <Core/Runtime/BuildInTypes/IntegerObject.h>
#include <Core/Tools.h>
#include "Types.h"

// Forward declarations

// Namespace declarations
using namespace ObjectiveScript;


namespace Mysql {


class MysqlErrno : public Extensions::ExtensionMethod
{
public:
	MysqlErrno()
	: ExtensionMethod(0, "mysql_errno", Designtime::IntegerObject::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("handle", Designtime::IntegerObject::TYPENAME));

		setSignature(params);
	}

	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* result, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			int param_handle = (*it++).value().toInt();

			MYSQL *myConn = mMysqlConnections[param_handle];
			if ( !myConn ) {
				throw Common::Exceptions::Exception("no valid mysql connection handle: " + std::to_string(param_handle));
			}

			*result = Runtime::IntegerObject(
				static_cast<int>( mysql_errno(myConn) )
			);
		}
		catch ( std::exception &e ) {
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
