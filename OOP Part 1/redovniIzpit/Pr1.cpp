#include <iostream>
#include <fstream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main() {
    //1
    Library l1("data.txt");

    //2
    Book b1("Book21", true), b2("Book22", false), b3("Book23", false), b4("Book24", true), b5("Book25", true);
    vector<Book> books;
    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);
    books.push_back(b4);
    books.push_back(b5);

    //3
    vector<Book> booksMap = l1.search_available_books_by_shelf(3);
    vector<Book>::iterator it;
    for (it = booksMap.begin(); it != booksMap.end(); it++) {
        cout << "Name: " << (*it).get_name() << endl;
    }
    
    //4
    l1.take_available_book_by_name("Book3");

    //5
    l1.return_taken_book_by_name("Book7");

    return 0;
}
