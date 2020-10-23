#!/usr/local/bin/slang

public void Main( int argc, string args ) modify {
	var handle = curl_init();
	//print( "Handle: " + handle );

	curl_set_url( handle, "https://api.exchange.bitpanda.com/public/v1/account/orders" );
	//curl_set_password( handle, "" );
	curl_set_progress( handle, false );
	//curl_set_username( handle, "" );
	curl_set_verbose( handle, false );

	curl_set_bearer( handle, "" );

	curl_set_header( handle, "Accept: application/json" );
	curl_set_header( handle, "Content-Type: application/json" );

	var data = "{ \"instrument_code\": \"BTC_EUR\", \"side\": \"BUY\", \"type\": \"MARKET\", \"amount\": \"1.23\" }";
	curl_set_data( handle, data );

	var result = curl_perform( handle );
	//print( "Result: " + result );

	var content = curl_read_result( handle );
	print( "Content: " + content );

	curl_cleanup( handle );
}

