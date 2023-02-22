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
        cursor.execute("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0)")
        cursor.execute("INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22)")
        cursor.execute("INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0)")

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
