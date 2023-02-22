#!/usr/bin/python
import sqlite3 as lite
from sqlite3 import Error
""" Get SQLite database  version 
    sqlite3.version(): Returns the SQLite library version
"""
def Get_version(db_file):
  print 'sqlite3 version = %s'% lite.version 
  print 'sqlite3 version = %s'% lite.sqlite_version 

if __name__ == '__main__':
  Get_version('test.db')

