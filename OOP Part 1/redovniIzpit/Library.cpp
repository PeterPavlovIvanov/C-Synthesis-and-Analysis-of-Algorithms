#include "Library.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>
#include "Book.h"
using namespace std;

Library::Library(string fileName) {
    fstream myFile;
    myFile.open(fileName);

    string libName;
    int shelves;
    int capacity;

    myFile >> libName;
    myFile >> shelves;
    myFile >> capacity;
    this->name = libName;
    this->shelves = shelves;
    this->capacity = capacity;
    
    for (int i = 1; i <= shelves; i++) {
    
        for (int j = 0; j < capacity; j++)
        {
            string bookName;
            myFile >> bookName;

            Book b(bookName);
            this->booksMap.insert(pair<int, Book>(i, b));
        }
        
    }
    myFile.close();
}
vector<Book> Library::search_available_books_by_shelf(int shelf) {
    vector<Book> availableBooks;
    multimap<int, Book>::iterator it;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if ((*it).first == shelf) {
            if ((*it).second.get_available() == true) {
                availableBooks.push_back((*it).second);
            }
        }
    }
    return availableBooks;
}
vector<Book> Library::search_taken_books_by_shelf(int shelf) {
    vector<Book> taken_books;
    multimap<int, Book>::iterator it;
    int i = 1;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if (i >= shelves * capacity) {
            break;
        }
        if ((*it).first == shelf) {
            if ((*it).second.get_available() == false) {
                taken_books.push_back((*it).second);
            }
        }
        i++;
    }
    return taken_books;
}
Book Library::search_available_book_by_name_and_shelf(string name, int shelf) {
    multimap<int, Book>::iterator it;
    int i = 1;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if (i >= shelves * capacity) {
            break;
        }
        if ((*it).first == shelf && (*it).second.get_name() == name  && (*it).second.get_available() == true) {
            return (*it).second;
        }
        i++;
    }
    Book b("not found");
    return b;
}
void Library::take_available_book_by_name(string name) {
    multimap<int, Book>::iterator it;
    int i = 1;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if (i >= shelves * capacity) {
            break;
        }
        if ((*it).second.get_name() == name && (*it).second.get_available() == true) {
            (*it).second.set_available(false);
            cout << "Book name: " << (*it).second.get_name() << " found." << endl;
            return;
        }
        i++;
    }
    cout << "Book name: " << (*it).second.get_name() << " not found." << endl;
}
Book Library::search_taken_book_by_name_and_shelf(string name, int shelf) {
    multimap<int, Book>::iterator it;
    int i = 1;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if (i >= shelves * capacity) {
            break;
        }
        if ((*it).first == shelf && (*it).second.get_name() == name && (*it).second.get_available() == false) {
            return (*it).second;
        }
        i++;
    }
    Book b("not found");
    return b;
}
void Library::return_taken_book_by_name(string name) {
    multimap<int, Book>::iterator it;
    int i = 1;
    for (it = this->booksMap.begin(); it != this->booksMap.end(); it++) {
        if (i >= shelves * capacity) {
            break;
        }
        if ((*it).second.get_name() == name && (*it).second.get_available() == false) {
            (*it).second.set_available(true);
            cout << "Book name: " << (*it).second.get_name() << " found." << endl;
            return;
        }
        i++;
    }
    cout << "Book name: " << (*it).second.get_name() << " not found." << endl;
}