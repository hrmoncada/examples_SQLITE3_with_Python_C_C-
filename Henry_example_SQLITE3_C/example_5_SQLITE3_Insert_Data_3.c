/*  https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
Compile:
$ gcc example_SQLITE3_program_name.c -o out -l sqlite3

Execute:
$ ./out
*/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

int main(int argc, char* argv[]) {
   sqlite3 *DB;
   char *messaggeError = 0;

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
/*             Insert Data - Create SQL statement           */
/************************************************************/   
   char *sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

/* This routine execute SQL commands provided by sql argument which can consist of more than one SQL command. */
   exit = sqlite3_exec(DB, sql, 0 , 0, &messaggeError);
   
// SQLITE_OK is returned when the connection was successfully established.  
    if (exit != SQLITE_OK) {
        fprintf(stderr, "Error Insert: %s\n", sqlite3_errmsg(DB));
        sqlite3_free(messaggeError);   // The allocated message string must be freed with the sqlite3_free() function call.
        sqlite3_close(DB);
        return 1;
    } else {
        fprintf(stdout,  "Records created Successfully!\n");
    }

// closes the database connection.
   sqlite3_close(DB);
   return 0;
}
