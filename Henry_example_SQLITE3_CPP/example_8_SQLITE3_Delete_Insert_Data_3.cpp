#include <iostream> 
#include <sqlite3.h> 
#include <string> 
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
        cerr << "Cannot open database: " << sqlite3_errmsg(DB) << endl; // sqlite3_errmsg() function returns a description of the error.
        sqlite3_close(DB);
        return (1); 
    } else {
        cout << "Opened Database Successfully! "<< sqlite3_errmsg(DB) << endl; 
    }

/************************************************************/
/*             Create merged/delete SQL statement           */
/************************************************************/
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl << endl; 

    string query = "DELETE from COMPANY where ID=2; " 
                    "SELECT * from COMPANY";

/* This routine execute SQL, and call the callback function for printing. */   
    exit = sqlite3_exec(DB, query.c_str(), callback, NULL, &messaggeError); 

// SQLITE_OK is returned when the connection was successfully established. 
    if (exit != SQLITE_OK) { 
        cerr << "Error DELETE" << endl; 
        sqlite3_free(messaggeError); 
    } else {
        cout << "Record deleted Successfully!" << endl; 
    }

// closes the database connection. 
    sqlite3_close(DB); 
    return (0); 
} 
