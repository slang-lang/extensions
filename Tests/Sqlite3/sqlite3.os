#!/usr/local/bin/slang

public int Main(int argc, string args) {
	print("Sqlite3 extension test");

	int handle = sqlite3_open("test.db");
	if ( !handle ) {
		print("Could not connect to database!");
		return -1;
	}

/*
    string query = "CREATE TABLE PERSON(" +
                   "ID INT PRIMARY KEY     NOT NULL, " +
                   "NAME           TEXT    NOT NULL, " +
                   "SURNAME        TEXT    NOT NULL, " +
                   "AGE            INT     NOT NULL, " +
                   "ADDRESS        CHAR(50), " +
                   "SALARY         REAL );";
*/
/*
    string query = "INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);" +
                   "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);" +
                   "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);";
*/

	string query = "SELECT * FROM PERSON";


	int result = sqlite3_exec(handle, query);
	if ( !result ) {
	    print("Error " + sqlite3_errcode(handle) + ": " + sqlite3_errmsg(handle));
	}

	// get number of rows in result set
	print("sqlite3_row_count(result): " + sqlite3_row_count(result));

	// get number of fields in result set
	print("sqlite3_field_count(result): " + sqlite3_field_count(result));

	// loop over all result rows and fields
	while ( sqlite3_next_row(result) ) {
	    while ( sqlite3_next_field(result) ) {
	        print("Row " + sqlite3_row_tell(result) + ", Field " + sqlite3_field_tell(result)
	             + " => " + sqlite3_get_field_name(result) + ": " + sqlite3_get_field_value(result));
	    }
	}

	// release result
	sqlite3_free_result(result);

	// close connection to database
	sqlite3_close(handle);

	print("Done.");
	return 0;
}

