#!/usr/bin/python
import sqlite3 as lite
from sqlite3 import Error
import sys 


def create_connection(db_file):
    """ create a database connection to the SQLite database
        specified by db_file
    :param db_file: database file
    :return: Connection object or None
    """
    try:
        conn = lite.connect(db_file)
        return conn

    except Error as e:
        print(e)
        sys.exit(1)

    return None

def Update_data(conn):
    with conn:    
       cursor = conn.cursor()
       cursor.execute("UPDATE Cars set Price = 75999.00 where ID=3; ")

       conn.commit()
       lid = cursor.lastrowid
       print "Total number of rows updated :", conn.total_changes
       print " "

def Show_data(conn):
    with conn:    
       cursor = conn.cursor()
       cursor.execute("SELECT * FROM PERSON")

       rows = cursor.fetchall()

       for row in rows:
          print row

       print " "

       for row in rows:
         print "Id = ", row[0]
         print "Name = ", row[1]
         print "Price = ", row[2], "\n"



if __name__ == '__main__':
    conn = create_connection("example.db")
    Update_data(conn)
    Show_data(conn)
    conn.close()
