/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/
Compile:
$ g++ example_4_sql_createDB.cpp -o out -l sqlite3

execute
$ ./out
*/

#include <iostream> 
#include <sqlite3.h> 
#include <stdio.h> 
#include <stdio.h> 
using namespace std; 

/************************************************************/
/*                          Callback                        */
/************************************************************/   
static int callback(void* data, int argc, char** argv, char** azColName) { 
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
int main(int argc, char** argv) { 
    sqlite3* DB; 
    char* messaggeError;  

/************************************************************/
/*                     Open Database File                   */
/************************************************************/
    int exit = sqlite3_open("example.db", &DB); 

    if (exit) { 
        cerr << "Error open DB " << sqlite3_errmsg(DB) << endl; 
        return (-1); 
    } else {
        cout << "Opened Database Successfully!" << endl; 
    }

/************************************************************/
/*                       Select Database                    */
/************************************************************/
    string data("CALLBACK FUNCTION"); 
  
    string sql("SELECT * FROM COMPANY;");

    exit = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (exit != SQLITE_OK) {
        cerr << "Error SELECT" << endl; 
    } else { 
        cout << "Operation OK!" << endl; 
    } 

// closes the database connection.   
    sqlite3_close(DB); 
    return (0); 
} 

