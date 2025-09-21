#pragma once
#include "Human.h"

class Book
{
private:
	char* name;
	char* author;
	char* genre;
	bool is_available;
	Human* holder;

public:
	Book();
	Book(const char* name, const char* author, const char* genre);

	~Book();
	Book(const Book& other);
	Book(Book&& other);

	void copy_from(const Book& other);

	const char* get_name();
	const char* get_author();
	const char* get_genre();
	bool get_is_available();
	Human* get_holder();

	void check_out(Human* holder);
	void return_book();

	void print();
};