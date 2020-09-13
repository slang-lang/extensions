#!/usr/local/bin/slang

public void Main( int argc, string args ) modify {
	var handle = curl_init();
	print( "Handle: " + handle );

	curl_set_url( handle, "https://api.exchange.bitpanda.com/public/v1/currencies" );
	//curl_set_password( handle, "" );
	curl_set_progress( handle, false );
	//curl_set_username( handle, "" );
	curl_set_verbose( handle, false );

	var result = curl_perform( handle );
	print( "Result: " + result );

	var content = curl_read_result( handle );
	print( "Content: " + content );

	curl_cleanup( handle );
}

