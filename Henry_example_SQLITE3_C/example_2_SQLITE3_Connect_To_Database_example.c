/*  https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
Compile:
 gcc example_SQLITE3_program_name.c -o out -l sqlite3

execute
$ ./out
*/

#include <stdio.h>
#include <sqlite3.h> 

int main(int argc, char* argv[]) {
   sqlite3 *DB;
   char *messaggeError = 0;
   int exit;

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
   printf("sql version = %s\n", sqlite3_libversion()); 

/************************************************************/
/*                     Open Data File                       */
/************************************************************/
// sqlite3_open() : Opens a new database connection to an SQLite database file and returns a database connection object to be used by other SQLite routines.   
   exit = sqlite3_open("example.db", &DB);

// If exit is an integer, exit is equal to 0, it succeeded. If exit is equal to 1, database doesn’t exist yet. The database is going to be created in the same directory where the process was executed.
   if( exit ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(DB)); // sqlite3_errmsg() function returns a description of the error.
      sqlite3_close(DB);
      return 1;  // If the return code indicates an error, we print the message to the console, close the database handle, and terminate the program.                 
                 // Whether or not an error occurs when it is opened, resources associated with the database connection handle should be released by passing it to sqlite3_close() function.
   } else {
      fprintf(stderr, "Opened Database Successfully\n");
   }

// sqlite3_close() : Closes a database connection previously opened by a call to sqlite3_open().
   sqlite3_close(DB);
   return (0);

}
