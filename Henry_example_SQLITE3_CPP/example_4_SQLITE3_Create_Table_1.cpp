/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_SQLITE3_program_name.c -o out -l sqlite3

Execute:
$ ./out
*/

#include <iostream> 
#include <sqlite3.h> 
using namespace std;

int main(void) {
    sqlite3 *DB;
    char *messaggeError = 0; // created error message

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open("example.db", &DB);

// If exit is an integer, exit is equal to 0, it succeeded. If exit is equal to 1, database doesn’t exist yet. The database is going to be created in the same directory where the process was executed.
    if (exit) { 
        cout << "Error open DB " << sqlite3_errmsg(DB) << endl; // sqlite3_errmsg() function returns a description of the error.
        sqlite3_close(DB);
        return (1); 
    } else {
        cout << "Opened Database Successfully! "<< sqlite3_errmsg(DB) << endl; 
    }

/************************************************************/
/*             Creat data table - Create SQL statement      */
/************************************************************/ 
// We connect to the example.db database, and create the table.
    string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME        TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );"; 

// Execute SQL commands provided by sql argument which can consist of more than one SQL command.
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 

// SQLITE_OK is returned when the connection was successfully established.   
    if (exit != SQLITE_OK) { 
        cerr << "Error Create Table" << endl; 
        sqlite3_free(messaggeError); 
        sqlite3_close(DB);
        return (1);
    } else {
        cout << "Table created Successfully" << endl; 
    }

// closes the database connection.
    sqlite3_close(DB); 
    return (0); 
} 
