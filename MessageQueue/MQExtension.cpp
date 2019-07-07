
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
: AExtension("MQ")
{
	// initialize pipes
	mMQs[0];
}

MQExtension::~MQExtension()
{
}

void MQExtension::initialize(ObjectiveScript::IScope* scope)
{
	//std::cout << "MQExtension::initialize()" << std::endl;

	(void)scope;

	// global vars/consts currently don't work for extensions :-(
}

void MQExtension::provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods)
{
	assert(methods.empty());

	methods.push_back(new MQClose());
	methods.push_back(new MQOpenByID());
	methods.push_back(new MQOpenByName());
	methods.push_back(new MQReceive());
	methods.push_back(new MQSend());
}


}


extern "C" AExtension* factory(void) {
	return dynamic_cast<AExtension*>( new MQ::MQExtension() );
}

