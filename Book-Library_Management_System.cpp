//
#include <iostream>
#include <cstring>
using namespace std;

//book structure
struct Book {
    char title[100];
    char author[100];
    char ISBN[20];
    bool isBorrowed;
    char borrowerName[100];
};

//max number of books in the library
const int maxbooks = 100;

Book library[maxbooks];
int bookCount = 0;

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



int main(){
    //menu
    int choice;
    do {
        cout <<"Library Menu:\n";
        cout <<"1. Add Book:\n";
        cout <<"2. Search Book by Title:\n";
        cout <<"3. Search Book by Author:\n";
        cout <<"4. Display All Books\n";
        cout <<"5. Borrow Book\n";
        cout <<"6. Return Book\n";
        cout <<"7. Exit!\n";
        cout <<"Choice(Pick a number betweeen 1 and 7)\n";

        cin>>choice;
        cin.ignore();

        switch (choice){
            case 1:addBook();break;
            case 2:searchByTitle();break;
            case 3:searchByAuthor();break;
            case 4:displayAllBooks(library,bookCount); break;
            case 5:borrowBook(library,bookCount); break;
            case 6:returnBook(library,bookCount); break;
            case 7:cout<<"Thank you!!\n";break;
            default:cout <<"Invalid Input!\n";break;
        }
    }while (choice !=7);
    return 0;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

bool isEqualIgnoreCase(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (toLower(a[i]) != toLower(b[i]))
            return false;
        i++;
    }
    return a[i] == b[i];
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isValidISBN13(const char isbn[]) {
    if (strlen(isbn) != 13)
        return false;

    int sum = 0;

    for (int i = 0; i < 13; i++) {
        if (!isDigit(isbn[i]))
            return false;

        int digit = isbn[i] - '0';

        if (i % 2 == 0)
            sum += digit;
        else
            sum += digit * 3;
    }

    return (sum % 10 == 0);
}

bool isUniqueISBN(const char isbn[]) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].ISBN, isbn) == 0)
            return false;
    }
    return true;
}

void addBook(){
    //checking if library is full
    if (bookCount>=maxbooks){
        cout <<"Library is full! Cannot add any more books!\n";
        return;
    }

    Book b;
    cout <<"Enter the book title:\n";
    cin.getline(b.title,100);
    cout <<"Enter the author name:\n";
    cin.getline(b.author,100);
    cout<<"Enter ISBN number(13 digits):\n";
    cin.getline(b.ISBN,20);

    //checking if the fields are empty
    if (strlen(b.title)==0||strlen(b.author)==0){
        cout <<"Error!!Field cannot be empty!!\n";
        return;
    }

    if(!isValidISBN13(b.ISBN)){
        cout<<"Invalid ISBN!!\n";
        return;
    }

    if(!isUniqueISBN(b.ISBN)){
        cout<<"ISBN already exists!!\n";
        return;
    }

    b.isBorrowed=false;
    b.borrowerName[0]='\0';

    library[bookCount]=b;
    bookCount++;

    cout<<"Book added successfully!!\n";
}

void displayAllBooks(){
    if (bookCount==0){
        cout<<"Library is empty!!\n";
        return;
    }
    for(int i=0;i<bookCount;i++){
        cout <<"\nBook #"<<i+1<<endl;
        cout <<"Title: "<<library[i].title<<endl;
        cout <<"Author: "<<library[i].author<<endl;
        cout <<"ISBN: "<<library[i].ISBN<<endl;

        if(library[i].isBorrowed){
            cout <<"Status: Borrowed\n";
            cout<<"Borrowed by: "<<library[i].borrowerName<<endl;
        }
        else{
            cout <<"Status: Available\n";
        }
    }
}

void searchByTitle(){
    char title[100];
    cout<<"Enter Title: ";
    cin.getline(title,100);

    bool found=false;

    for (int i =0;i<bookCount;i++){
        if(isEqualIgnoreCase(library[i].title,title)){
            cout <<"\nTitle: "<<library[i].title<<endl;
            cout <<"Author: "<<library[i].author<<endl;
            cout<<"ISBN: "<<library[i].ISBN<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"Book not found!!\n";
    }
}

void searchByAuthor(){
    char author[100];
    cout<<"Enter Author's name: ";
    cin.getline(author,100);

    bool found=false;

    for (int i =0;i<bookCount;i++){
        if(isEqualIgnoreCase(library[i].author,author)){
            cout <<"\nTitle: "<<library[i].title<<endl;
            cout <<"Author: "<<library[i].author<<endl;
            cout<<"ISBN: "<<library[i].ISBN<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"Books not found written by this Author!!\n";
    }
}

void borrowBook(){
    char isbn[20];
    cout <<"Enter ISBN: \n";
    cin.getline(isbn,20);

    for (int i=0;i<bookCount;i++){
     if (strcmp(library[i].ISBN, isbn) == 0) {

            if (library[i].isBorrowed) {
                cout << "Already borrowed!\n";
                return;
            }

            cout << "Enter your name: ";
            cin.getline(library[i].borrowerName, 100);

            library[i].isBorrowed = true;
            cout << "Book borrowed!\n";
            return;
        }
    }

    cout << "Book not found.\n";
}

void returnBook() {
    char isbn[20];
    cout << "Enter ISBN: ";
    cin.getline(isbn, 20);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].ISBN, isbn) == 0) {

            if (!library[i].isBorrowed) {
                cout << "Book is not borrowed.\n";
                return;
            }

            library[i].isBorrowed = false;
            library[i].borrowerName[0] = '\0';

            cout << "Book returned!\n";
            return;
        }
    }

    cout << "Book not found.\n";
}
