#pragma once
#include <string>
#include <map>
#include <vector>
#include "Book.h"

class Library
{
private:
	std::string name;
	int shelves;
	int capacity;
	std:: multimap<int, Book> booksMap;
public:
	Library(std::string fileName);
	std::vector<Book> search_available_books_by_shelf(int shelf);
	std::vector<Book> search_taken_books_by_shelf(int shelf);
	Book search_available_book_by_name_and_shelf(std::string name, int shelf);
	void take_available_book_by_name(std::string name);
	Book search_taken_book_by_name_and_shelf(std::string name, int shelf);
	void return_taken_book_by_name(std::string name);
};

