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
   char *sql = "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(1, 'Audi', 52642);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(2, 'Meexitedes', 57127);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(3, 'Skoda', 9000);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(4, 'Volvo', 29000);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(5, 'Bentley', 350000);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(6, 'Citroen', 21000);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(7, 'Hummer', 41400);" \
                "INSERT INTO Cars (Id, Name, Price)"\
                "VALUES(8, 'Volkswagen', 21600);";

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
