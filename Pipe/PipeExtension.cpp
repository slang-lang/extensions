
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
: AExtension( "Pipe", "0.1.0" )
{
	// initialize pipes
	mPipes[ 0 ];
}

void PipeExtension::initialize( Slang::Extensions::ExtensionNamespace* scope )
{
	std::cout << "PipeExtension::initialize()" << std::endl;

	scope->defineExternal( "O_NDELAY", new Slang::Runtime::Int32Type( O_NDELAY ) );
	scope->defineExternal( "O_RDONLY", new Slang::Runtime::Int32Type( O_RDONLY ) );
	scope->defineExternal( "O_WRONLY", new Slang::Runtime::Int32Type( O_WRONLY ) );

	scope->defineExternal( "EFAULT", new Slang::Runtime::Int32Type( EFAULT ) );
	scope->defineExternal( "EINVAL", new Slang::Runtime::Int32Type( EINVAL ) );
	scope->defineExternal( "EMFILE", new Slang::Runtime::Int32Type( EMFILE ) );
	scope->defineExternal( "ENFILE", new Slang::Runtime::Int32Type( ENFILE ) );
	//scope->defineExternal( "ENOPKG", new Slang::Runtime::Int32Type( ENOPKG ) );
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
