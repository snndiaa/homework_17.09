#include "Book.h"
#include "Human.h"
#include <iostream>

using namespace std;

Book::Book()
{
	name = new char[1]; name[0] = '\0';
	author = new char[1]; author[0] = '\0';
	genre = new char[1]; genre[0] = '\0';
	is_available = true;
	holder = nullptr;
}

Book::Book(const char* name, const char* author, const char* genre) : is_available(true), holder(nullptr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);

	this->genre = new char[strlen(genre) + 1];
	strcpy_s(this->genre, strlen(genre) + 1, genre);
}

Book::~Book()
{
	delete[] name;
	delete[] author;
	delete[] genre;
}

Book::Book(const Book& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	author = new char[strlen(other.author) + 1];
	strcpy_s(author, strlen(other.author) + 1, other.author);

	genre = new char[strlen(other.genre) + 1];
	strcpy_s(genre, strlen(other.genre) + 1, other.genre);

	is_available = other.is_available;
	holder = other.holder;
}

Book::Book(Book&& other)
{
	name = other.name;
	other.name = nullptr;

	author = other.author;
	other.author = nullptr;

	genre = other.genre;
	other.genre = nullptr;

	is_available = other.is_available;
	other.is_available = true;

	holder = other.holder;
	other.holder = nullptr;
}

void Book::copy_from(const Book& other)
{
	if (this == &other)
	{
		return;
	}
	delete[] name;
	delete[] author;
	delete[] genre;

	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);

	author = new char[strlen(other.author) + 1];
	strcpy_s(author, strlen(other.author) + 1, other.author);

	genre = new char[strlen(other.genre) + 1];
	strcpy_s(genre, strlen(other.genre) + 1, other.genre);

	is_available = other.is_available;
	holder = other.holder;
}

const char* Book::get_name()
{
	return name;
}

const char* Book::get_author()
{
	return author;
}

const char* Book::get_genre()
{
	return genre;
}

bool Book::get_is_available()
{
	return is_available;
}

Human* Book::get_holder()
{
	return holder;
}

void Book::check_out(Human* holder)
{
	this->is_available = false;
	this->holder = holder;
}

void Book::return_book()
{
	this->is_available = true;
	this->holder = nullptr;
}

void Book::print()
{
	cout << "Title: " << name << " Author: " << author << " Genre: " << genre;
	if (is_available)
	{
		cout << " Status: Available" << endl;
	}
	else
	{
		cout << " Status: Checked out by reader ID " << holder->get_id() << " (" << holder->get_surname() << ")" << endl;
	}
}