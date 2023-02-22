#!/usr/bin/python
import sqlite3 as lite
from sqlite3 import Error
import sys 


def create_connection(db_file):
    """ create a database connection to a SQLite database """
    try: # Create table
        conn = lite.connect(db_file)

        cursor = conn.cursor()    
        cursor.execute('SELECT SQLITE_VERSION()')
        data = cursor.fetchone()
        print "SQLite version: %s" % data

    except Error as e:
        print(e)
        sys.exit(1)

    finally:
        conn.close()
 
if __name__ == '__main__':
    create_connection("example.db")
