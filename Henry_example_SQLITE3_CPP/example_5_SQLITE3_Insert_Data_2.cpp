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
/*             Insert Data - Create SQL statement           */
/************************************************************/
  
    string sql("INSERT INTO Cars VALUES(1, 'Audi', 52642);" 
               "INSERT INTO Cars VALUES(2, 'Meexitedes', 57127);" 
               "INSERT INTO Cars VALUES(3, 'Skoda', 9000);" 
               "INSERT INTO Cars VALUES(4, 'Volvo', 29000);" 
               "INSERT INTO Cars VALUES(5, 'Bentley', 350000);" 
               "INSERT INTO Cars VALUES(6, 'Citroen', 21000);" 
               "INSERT INTO Cars VALUES(7, 'Hummer', 41400);" 
               "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);");

// sqlite3_exec() : This routine provides a quick, easy way to execute SQL commands provided by sql argument which can consist of more than one SQL command. 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 

// If exit is an integer equal to 0, it succeeded (SQLITE_OK=0). If exit is equal to 1 (SQLITE_OK=1), the database doesn’t exist yet. 
    if (exit != SQLITE_OK) { 
        cout << "Error Insert" << endl; 
        sqlite3_free(messaggeError); 
    }  else {
        cout << "Records created Successfully!" << endl; 
    } 

// closes the database connection.
   sqlite3_close(DB);
   return 0;
}  
