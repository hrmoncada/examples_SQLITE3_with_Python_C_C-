/*  https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/

Compile:
$ g++  example_SQLITE3_program_name.c -o out -l sqlite3

execute
$ ./out

*/

#include <iostream> 
#include <sqlite3.h> 
using namespace std;
  
int main(int argc, char** argv)  { 

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    cout << "sqlite version = " << sqlite3_libversion() << endl; 

    return (0); 
} 
