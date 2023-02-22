/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_SQLITE3_program_name.c -o out -l sqlite3

Execute:
$ ./out
*/

#include <iostream> 
#include <sqlite3.h> 
#include <string> 
#include <stdio.h>  
using namespace std; 

/************************************************************/
/*                          Callback                        */
/************************************************************/  
static int callback(void* data, int argc, char** argv, char** azColName)  { 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 
/************************************************************/
/*                           Main                           */
/************************************************************/  
int main(int argc, char** argv)  { 
    sqlite3* DB; 
    char* messaggeError; 

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open("example.db", &DB); 

    if (exit) { 
        cerr << "Cannot open database: " << sqlite3_errmsg(DB) << endl; // sqlite3_errmsg() function returns a description of the error.
        sqlite3_close(DB);
        return (1); 
    } else {
        cout << "Opened Database Successfully! "<< sqlite3_errmsg(DB) << endl; 
    }
/************************************************************/
/*             Create merged/update SQL statement           */
/************************************************************/
    string query = "UPDATE Cars set Price = 75999.00 where ID=3; " \
         "SELECT * from Cars";
 
    cout << "STATE OF TABLE AFTER INSERT" << endl<< endl;

 /* This routine execute SQL, and call the callback function for printing. */
     exit =sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 

// SQLITE_OK is returned when the connection was successfully established. 
    if (exit != SQLITE_OK) { 
        cerr << "Error Insert" << endl; 
        sqlite3_free(messaggeError); // The allocated message string must be freed with the sqlite3_free() function call.
        sqlite3_close(DB);
        return (1);
    } else {
        cout << "Records created Successfully!" << endl; 
    }

// closes the database connection.
    sqlite3_close(DB); 
    return (0); 
} 
