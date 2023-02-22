/*  https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
Compile:
$ gcc example_SQLITE3_program_name.c -o out -l sqlite3

execute
$ ./out
*/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

/************************************************************/
/*                          Callback                        */
/************************************************************/
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

/************************************************************/
/*                           Main                           */
/************************************************************/
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
   
   if( exit ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(DB));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

/************************************************************/
/*             Show Insert Data - Create SQL statement      */
/************************************************************/ 
   const char* data = "CALLBACK FUNCTION";

   char *sql = "SELECT * from Cars";

   printf("STATE OF TABLE AFTER INSERT\n")l;

/* This routine execute SQL, and call the callback function for printing. */
   exit = sqlite3_exec(DB, sql, callback, (void*)data, &messaggeError);

// SQLITE_OK is returned when the connection was successfully established.     
   if( exit != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", messaggeError);
      sqlite3_free(messaggeError);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }

// closes the database connection.
   sqlite3_close(DB);
   return 0;
}
