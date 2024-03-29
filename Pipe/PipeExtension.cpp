
// Header
#include "PipeExtension.h"

// Library includes

// Project includes
#include "PipeClose.h"
#include "PipeOpen.h"
#include "PipeRead.h"
#include "PipeWrite.h"

// Namespace declarations


namespace Pipe {


PipeExtension::PipeExtension()
: AExtension( "Pipe", "0.0.2" )
{
	// initialize pipes
	mPipes[0];
}

void PipeExtension::initialize( Slang::Extensions::ExtensionNamespace* scope )
{
	//std::cout << "PipeExtension::initialize()" << std::endl;

	(void)scope;

	// global vars/consts currently don't work for extensions :-(
}

void PipeExtension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	methods.push_back( new PipeClose() );
	methods.push_back( new PipeOpen() );
	methods.push_back( new PipeRead() );
	methods.push_back( new PipeWrite() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Pipe::PipeExtension() );
}

