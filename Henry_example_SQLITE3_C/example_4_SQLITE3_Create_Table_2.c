/*  http://zetcode.com/DB/sqlitec/
Compile:
$ gcc example_SQLITE3_program_name.c -o out -l sqlite3

Execute:
$ ./out
*/

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    sqlite3 *DB;
    char *messaggeError = 0; // created error message

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
   printf("sql version = %s\n", sqlite3_libversion()); 

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open("example.db", &DB);
   
// If exit is an integer, exit is equal to 0, it succeeded. If exit is equal to 1, database doesn’t exist yet. The database is going to be created in the same directory where the process was executed.
   if( exit ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(DB)); // sqlite3_errmsg() function returns a description of the error.
      sqlite3_close(DB);
      return 1;  
   } else {
      fprintf(stderr, "Opened Database Successfully\n");
   }

/************************************************************/
/*             Creat data table - Create SQL statement      */
/************************************************************/ 
// We connect to the example.db database, and create the table.  
    char *sql = "CREATE TABLE Cars("
                 "Id INT PRIMARY KEY     NOT NULL,"
                 "Name     TEXT          NOT NULL,"
                 "Price    INT           NOT NULL);";

// Execute SQL commands provided by sql argument which can consist of more than one SQL command.
    exit = sqlite3_exec(DB, sql, 0, 0, &messaggeError);

// SQLITE_OK is returned when the connection was successfully established. 
    if (exit != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", messaggeError);
        sqlite3_free(messaggeError);   // The allocated message string must be freed with the sqlite3_free() function call.     
        sqlite3_close(DB);
        return 1;
    } else {
        fprintf(stdout, "Table created Successfully:\n");
    }

// closes the database connection.
    sqlite3_close(DB);
    
    return 0;
}
