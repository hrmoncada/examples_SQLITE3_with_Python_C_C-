# examples_SQLITE3_with_Python_C_C-

Here you will find simples examples of  sqlit3 (SQLITE 3.0) written in Python, C and C++

sqlite3 (SQLite 3.0) standalone command-line shell program provided in SQLite's distribution. It can be used to create a database, define tables, insert and change rows, run queries and manage an SQLite database file. It also serves as an example for writing applications that use the SQLite library.

SQLite is a database engine written in the C programming language. It is not a standalone app; rather, it is a library that software developers embed in their apps. As such, it belongs to the family of embedded databases. It is the most widely deployed database engine, as it is used by several of the top web browsers, operating systems, mobile phones, and other embedded systems.

SQLite was designed to allow the program to be operated without installing a database management system or requiring a database administrator. Unlike client–server database management systems, the SQLite engine has no standalone processes with which the application program communicates. Instead, a linker integrates the SQLite library — statically or dynamically — into an application program which uses SQLite's functionality through simple function calls, reducing latency in database operations; for simple queries with little concurrency, SQLite performance profits from avoiding the overhead of inter-process communication.

Difference between SQLite and sqlite3. SQLite2.8 will deal with data in various formats internally, but when writing to the disk or interacting through its API, SQLite2.8 always converts data into ASCII text. sqlite3 (SQLite 3.0), in contrast, exposes its internal data representations to the user and stores binary representations to disk when appropriate
