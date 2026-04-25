//
#include <iostream>
using namespace std;

//max number of books in the library
const int MAX_BOOKS = 100;

Book library[MAX_BOOKS];
int bookCount = 0;

//book structure
struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    bool isBorrowed;
    char borrowerName[100];
};

//prototypes
//adding books
void addBook();

//searching books by title
void searchByTitle(const Book library[], int bookCount, const char title[]);

//searching books by author
void searchByAuthor(const Book library[], int bookCount, const char author[]);

//displaying all books
void displayAllBooks(const Book library[], int bookCount); 

//checking if ISBN is valid
bool isValidISBN13(const char isbn[]);

//checking if ISBN is unique
bool isUniqueISBN(const char isbn[]);

//borrowing the book
void borrowBook(Book library[], int bookCount); 

//returning the book
void returnBook(Book library[], int bookCount); 

