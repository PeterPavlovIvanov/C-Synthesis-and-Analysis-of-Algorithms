#include "Book.h"
#include <string>
#include <fstream>
using namespace std;

Book::Book(string name) {
	this->name = name;
	this->available = true;
}

Book::Book(string name, bool available) {
	this->name = name;
	this->available = available;
}

void Book::takeBook(string name) {
	available = false;
}

void Book::returnBook(string name) {
	available = true;
}
void Book::set_name(string name) {
	this->name = name;
}
string Book::get_name() {
	return name;
}
bool Book::get_available() {
	return available;
}
void Book::set_available(bool available) {
	this->available = available;
}
string Book::info() {
	string result = "Book:\nName: " + name;
	result += "\nAvailable: " + available;
	result += "\n";
	return result;
}

bool Book::operator == (Book b1) {
	if (this->name == b1.name && this->available == b1.available) {
		return true;
	}
	return false;
}

bool Book::operator < (Book b1) {
	return this->name < b1.name;
}

istream& operator>>(istream& in, Book& book) {
	string name;
	bool available;
	in >> name >> available;
	book.set_name(name);
	book.set_available(available);
	return in;
}

ostream& operator<<(ostream& out, Book& book) {
	return out << "Book name: " << book.get_name() << endl << "Available: " << book.get_available() << endl << endl;
}