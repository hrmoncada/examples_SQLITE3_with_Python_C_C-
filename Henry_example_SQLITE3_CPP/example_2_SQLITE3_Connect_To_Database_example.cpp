/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_2_SQLITE3_DB_create_DB.cpp -o out -l sqlite3

execute
$ ./out

Database Connection/Creation of Table:

sqlite3_open(const char *filename, sqlite3 **ppDb)

sqlite3_close(sqlite3 *ppDb)

*/

#include <iostream> 
#include <sqlite3.h> 
using namespace std;
  
int main(int argc, char** argv)  { 
    sqlite3* DB; 
    int exit = 0; 

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

/************************************************************/
/*                     Open Data File                       */
/************************************************************/
// sqlite3_open() : Opens a new database connection to an SQLite database file and returns a database connection object to be used by other SQLite routines.  
    exit = sqlite3_open("example.db", &DB); 

// If exit is an integer, exit is equal to 0, it succeeded. If exit is equal to 1, database doesn’t exist yet. The database is going to be created in the same directory where the process was executed.
   if( exit ) {
      cout << "Cannot open database: "<< sqlite3_errmsg(DB) << endl;   // sqlite3_errmsg() function returns a description of the error.
      sqlite3_close(DB);
      return 1;  // If the return code indicates an error, we print the message to the console, close the database handle, and terminate the program.                 
                 // Whether or not an error occurs when it is opened, resources associated with the database connection handle should be released by passing it to sqlite3_close() function.
   } else {
        cout << "Opened Database Successfully!\n"<< sqlite3_errmsg(DB) << endl; 
   }

// sqlite3_close() : Closes a database connection previously opened by a call to sqlite3_open().
   sqlite3_close(DB);
   return (0);
} 
