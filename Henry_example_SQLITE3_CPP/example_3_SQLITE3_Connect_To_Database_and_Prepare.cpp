/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_SQLITE3_program_name.c -o out -l sqlite3

execute
$ ./out
*/

#include <iostream> 
#include <sqlite3.h> 
using namespace std;

int main(void) {
    sqlite3 *DB;
    sqlite3_stmt *res; // sqlite3 structure defines a database handle and represents a single SQL statement.

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open(":memory:", &DB);  // ":memory:" special database name using which results in opening an in-memory database.  

// SQLITE_OK is returned when the connection was successfully established. 
// If the return code indicates an error, we print the message to the console, close the database handle, and terminate the program. 
    if (exit != SQLITE_OK) {
        cout <<  "Cannot open database: %s\n" <<  sqlite3_errmsg(DB) << endl; 
        sqlite3_close(DB);
        return 1;// If the return code indicates an error, we print the message to the console, close the database handle, and terminate the program.                 
                 // Whether or not an error occurs when it is opened, resources associated with the database connection handle should be released by passing it to sql
    } else {
        cout <<  "Opened Database Successfully! "<< sqlite3_errmsg(DB) << endl; 
    }

/************************************************************/
/*                    Prepare Database File                 */
/************************************************************/
    exit = sqlite3_prepare_v2(DB, "SELECT SQLITE_VERSION()", -1, &res, 0);  
  
// If exit is an integer, exit is equal to 0, it succeeded (SQLITE_OK=0). If exit is equal to 1, the database doesn’t exist yet(SQLITE_OK=1). 
// The database is  going to be created in the same directory where the process was executed.     
    if (exit != SQLITE_OK) {
        cout << "Failed to fetch data: %s\n" <<  sqlite3_errmsg(DB) << endl; 
        sqlite3_close(DB);
        return 1;
    }    

// sqlite3_step() runs the SQL statement, depend on whether the statement was prepared using the newer "vX" interfaces sqlite3_prepare_v2()      
    exit = sqlite3_step(res);
    
    if (exit == SQLITE_ROW) {
      cout <<  sqlite3_column_text(res, 0) << endl; 
    }

// sqlite3_finalize() function destroys the prepared statement object.    
    sqlite3_finalize(res);

// closes the database connection.
    sqlite3_close(DB);
    
    return (0);
} 
