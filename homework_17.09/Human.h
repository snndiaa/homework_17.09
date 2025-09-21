#pragma once
class Human
{
	char* surname;
	int id;
	int taken_now;
	int total_books_taken;
public:
	Human();
	Human(const char* surname, int id);
	~Human();
	Human(const Human& obj);
	Human(Human&& obj);

	void copy_from(const Human& obj);
	const char* get_surname();
	int get_id();
	int get_taken_now();
	int get_total_books_taken();

	void increment_taken_books();
	void decrement_taken_books();

	void print();
};