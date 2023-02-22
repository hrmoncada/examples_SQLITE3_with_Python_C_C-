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

def insert_data(conn):
    """ create a table from the create_table_sql statement
    :param conn: Connection object
    :return:
    """
    try: # Insert a row of data
        cursor = conn.cursor()
        cursor.execute("INSERT INTO Cars VALUES(1, 'Audi', 52642)")
        cursor.execute("INSERT INTO Cars VALUES(2, 'Meexitedes', 57127)")
        cursor.execute("INSERT INTO Cars VALUES(3, 'Skoda', 9000)")
        cursor.execute("INSERT INTO Cars VALUES(4, 'Volvo', 29000)")
        cursor.execute("INSERT INTO Cars VALUES(5, 'Bentley', 350000)")
        cursor.execute("INSERT INTO Cars VALUES(6, 'Citroen', 21000)")
        cursor.execute("INSERT INTO Cars (VALUES(7, 'Hummer', 41400)")
        cursor.execute("INSERT INTO Cars VALUES(8, 'Volkswagen', 21600)")
        # Save (commit) the changes
        conn.commit()

        lid = cursor.lastrowid
        print "The last ID of the inserted row is %d" % lid

    except Error as e:
        print(e)
        sys.exit(1)

if __name__ == '__main__':
    conn = create_connection("example.db")
    insert_data(conn)
    conn.close()
