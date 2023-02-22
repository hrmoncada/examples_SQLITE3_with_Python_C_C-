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
        cursor.execute("INSERT INTO COMPANY VALUES(1, 'Paul', 32, 'California', 20000.00)")
        cursor.execute("INSERT INTO COMPANY VALUES(2, 'Allen', 25, 'Texas', 15000.00)")
        cursor.execute("INSERT INTO COMPANY VALUES(3, 'Teddy', 23, 'Norway', 20000.00 )")
        cursor.execute("INSERT INTO COMPANY VALUES(4, 'Mark', 25, 'Rich-Mond ', 65000.00 )")

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
