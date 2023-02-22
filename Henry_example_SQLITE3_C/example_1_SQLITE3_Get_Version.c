/*  http://zetcode.com/db/sqlitec/

Compile:
 gcc example_SQLITE3_program_name.c -o out -l sqlite3

execute
$ ./out
*/

#include <sqlite3.h>
#include <stdio.h>

int main(void) {

/************************************************************/
/* sqlite3_libversion(): Returns the SQLite library version */
/************************************************************/
    printf("sqlite version = %s\n", sqlite3_libversion()); 
    
    return (0);
}
