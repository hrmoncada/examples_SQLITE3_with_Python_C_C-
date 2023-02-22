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

def create_table(conn):
    """ create a table from the create_table_sql statement
    :param conn: Connection object
    :return:
    """
    try:
        cursor = conn.cursor()
        cursor.execute('''CREATE TABLE COMPANY
                     (Id INT PRIMARY KEY     NOT NULL,
                      Name           TEXT    NOT NULL,
                      Price            INT     NOT NULL);''')

        print "Table created successfully";

    except Error as e:
        print(e)
        sys.exit(1)

if __name__ == '__main__':
    conn = create_connection("example.db")
    create_table(conn)
    conn.close()
