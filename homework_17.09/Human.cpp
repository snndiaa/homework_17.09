#include "Human.h"
#include <iostream>

using namespace std;

Human::Human()
{
    surname = new char[1];
    surname[0] = '\0';
    id = 0;
    taken_now = 0;
    total_books_taken = 0;
}

Human::Human(const char* surname, int id) : id(id), taken_now(0), total_books_taken(0)
{
    this->surname = new char[strlen(surname) + 1];
    strcpy_s(this->surname, strlen(surname) + 1, surname);
}

Human::~Human()
{
    delete[] surname;
}

Human::Human(const Human& obj)
{
    surname = new char[strlen(obj.surname) + 1];
    strcpy_s(surname, strlen(obj.surname) + 1, obj.surname);
    id = obj.id;
    taken_now = obj.taken_now;
    total_books_taken = obj.total_books_taken;
}

Human::Human(Human&& obj)
{
    surname = obj.surname;
    obj.surname = nullptr;
    id = obj.id;
    obj.id = 0;
    taken_now = obj.taken_now;
    obj.taken_now = 0;
    total_books_taken = obj.total_books_taken;
    obj.total_books_taken = 0;
}

void Human::copy_from(const Human& obj)
{
    if (this == &obj)
    {
        return;
    }
    delete[] surname;
    surname = new char[strlen(obj.surname) + 1];
    strcpy_s(surname, strlen(obj.surname) + 1, obj.surname);
    id = obj.id;
    taken_now = obj.taken_now;
    total_books_taken = obj.total_books_taken;
}

const char* Human::get_surname()
{
    return surname;
}

int Human::get_id()
{
    return id;
}

int Human::get_taken_now()
{
    return taken_now;
}

int Human::get_total_books_taken()
{
    return total_books_taken;
}

void Human::increment_taken_books()
{
    taken_now++;
    total_books_taken++;
}

void Human::decrement_taken_books()
{
    if (taken_now > 0)
    {
        taken_now--;
    }
}

void Human::print()
{
    cout << "ID: " << id << ", Surname: " << surname << ", Books checked out: " << taken_now << endl;
}