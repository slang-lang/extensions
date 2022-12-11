
// Header
#include "MQExtension.h"

// Library includes

// Project includes
#include "MQClose.h"
#include "MQOpen.h"
#include "MQReceive.h"
#include "MQSend.h"

// Namespace declarations


namespace MQ {


MQExtension::MQExtension()
: AExtension( "SystemV-MQ", "0.1.1" )
{
	// initialize pipes
	mMQs[0];
}

void MQExtension::initialize( Slang::Extensions::ExtensionNamespace* scope )
{
	//std::cout << "MQExtension::initialize()" << std::endl;

	(void)scope;

	// global vars/consts currently don't work for extensions :-(
}

void MQExtension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	methods.push_back( new MQClose() );
	methods.push_back( new MQOpenByID() );
	methods.push_back( new MQOpenByName() );
	methods.push_back( new MQReceive() );
	methods.push_back( new MQSend() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new MQ::MQExtension() );
}

