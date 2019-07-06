
// Header
#include "PipeExtension.h"

// Library includes

// Project includes
#include "PipeClose.h"
#include "PipeCreate.h"
#include "PipeRead.h"
#include "PipeWrite.h"

// Namespace declarations


namespace Pipe {


PipeExtension::PipeExtension()
: AExtension("Pipe")
{
	// initialize pipes
	mPipes[0];
}

PipeExtension::~PipeExtension()
{
}

void PipeExtension::initialize(ObjectiveScript::IScope* scope)
{
	//std::cout << "PipeExtension::initialize()" << std::endl;

	(void)scope;

	// global vars/consts currently don't work for extensions :-(
}

void PipeExtension::provideMethods(ObjectiveScript::Extensions::ExtensionMethods &methods)
{
	assert(methods.empty());

	methods.push_back(new PipeClose());
	methods.push_back(new PipeCreate());
	methods.push_back(new PipeRead());
	methods.push_back(new PipeWrite());
}


}


extern "C" AExtension* factory(void) {
	return dynamic_cast<AExtension*>( new Pipe::PipeExtension() );
}
