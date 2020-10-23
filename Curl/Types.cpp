
// Header
#include "Types.h"

// Library includes

// Project includes

// Namespace declarations


namespace Curl {


CurlRequests Requests;


void cleanup()
{
	for ( auto it = Requests.begin(); it != Requests.end(); ++it ) {
		delete it->second;
	}
}

void init()
{
	// initialize handles
	Requests.insert( std::make_pair( 0, nullptr ) );
}


}

