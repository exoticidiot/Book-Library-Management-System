# Book Library Management System

A console-based C++ application for managing a library's book collection using structures and arrays. Built as a class project to apply structures, arrays of structures, and basic data manipulation.

## Features

- **Add books** — title, author, and ISBN-13 (validated with a real ISBN-13 checksum, and checked for duplicates)
- **Search by title** — case-insensitive match
- **Search by author** — case-insensitive match
- **Display all books** — shows title, author, ISBN, and borrow status
- **Borrow / return books** — tracks borrower name and availability per book
- **Sort books** — by title (ascending) or by author (descending)

## How to run

```
g++ Book-Library_Management_System.cpp -o library
./library
```

## Menu options

```
1. Add Book
2. Search Book by Title
3. Search Book by Author
4. Display All Books
5. Borrow Book
6. Return Book
7. Sort Books
8. Exit
```

## Notes

- Library capacity is fixed at 100 books (`maxbooks`), using a plain array of `Book` structs — no dynamic memory.
- ISBN validation checks both format (13 digits) and the actual ISBN-13 checksum, not just length.
- Data is in-memory only — nothing is saved between runs.
