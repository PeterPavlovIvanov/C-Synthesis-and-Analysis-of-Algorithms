#pragma once
#include <string>
class Book
{
private:
	std::string name;
	bool available;
public:
	Book(std::string name);
	Book(std::string name, bool available);
	void takeBook(std::string name);
	void returnBook(std::string name);
	void set_name(std::string name);
	std::string get_name();
	bool get_available();
	void set_available(bool available);
	std::string info();
	bool operator == (Book b1);
	bool operator < (Book b1);

};

