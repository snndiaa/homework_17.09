#pragma once
#include "Book.h"
#include "Human.h"

class Library
{
	Book* books;
	int book_count;
	int book_capacity;

	Human* visitors;
	int visitor_count;
	int visitor_capacity;

	void resize_books();
	void resize_visitors();

public:
	Library(int initial_capacity = 10);
	~Library();

	void add_book(const Book& book);
	void add_visitor(const Human& visitor);

	void find_book_by_title(const char* title);
	void find_book_by_author(const char* author);
	void find_book_by_genre(const char* genre);

	void issue_book(int book_id, int visitor_id);
	void return_book(int book_id);

	void print_all_books();
	void print_all_visitors();
	void find_most_frequent_visitor();

	Human* get_visitor_by_id(int id);
};