#include "Library.h"
#include <iostream>

using namespace std;

Library::Library(int initial_capacity)
{
    book_capacity = initial_capacity;
    book_count = 0;
    books = new Book[book_capacity];

    visitor_capacity = initial_capacity;
    visitor_count = 0;
    visitors = new Human[visitor_capacity];
}

Library::~Library()
{
    delete[] books;
    delete[] visitors;
}

void Library::resize_books()
{
    int new_capacity = book_capacity + 1;
    Book* new_books = new Book[new_capacity];

    for (int i = 0; i < book_count; i++)
    {
        new_books[i].copy_from(books[i]);
    }

    delete[] books;
    books = new_books;
    book_capacity = new_capacity;
}

void Library::resize_visitors()
{
    int new_capacity = visitor_capacity + 1;
    Human* new_visitors = new Human[new_capacity];

    for (int i = 0; i < visitor_count; i++)
    {
        new_visitors[i].copy_from(visitors[i]);
    }

    delete[] visitors;
    visitors = new_visitors;
    visitor_capacity = new_capacity;
}

void Library::add_book(const Book& book)
{
    if (book_count >= book_capacity)
    {
        resize_books();
    }

    books[book_count].copy_from(book);
    book_count++;
}

void Library::add_visitor(const Human& visitor)
{
    if (visitor_count >= visitor_capacity)
    {
        resize_visitors();
    }

    visitors[visitor_count].copy_from(visitor);
    visitor_count++;
}

void Library::find_book_by_title(const char* title)
{
    bool found = false;
    cout << "Searching for books by title " << title << endl;

    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(books[i].get_name(), title) == 0)
        {
            cout << "Book found Index: " << i << " ";
            books[i].print();
            found = true;
        }
    }

    if (found == false)
    {
        cout << "No books with this title found" << endl;
    }
}

void Library::find_book_by_author(const char* author)
{
    bool found = false;
    cout << "Searching for books by author " << author << endl;

    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(books[i].get_author(), author) == 0)
        {
            cout << "Book found Index: " << i << " ";
            books[i].print();
            found = true;
        }
    }

    if (found == false)
    {
        cout << "No books by this author found" << endl;
    }
}

void Library::find_book_by_genre(const char* genre)
{
    bool found = false;
    cout << "Searching for books by genre " << genre << endl;

    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(books[i].get_genre(), genre) == 0)
        {
            cout << "Book found Index: " << i << " ";
            books[i].print();
            found = true;
        }
    }

    if (found == false)
    {
        cout << "No books of this genre found" << endl;
    }
}

void Library::issue_book(int book_id, int visitor_id)
{
    if (book_id < 0 || book_id >= book_count)
    {
        cout << "Error: invalid book index" << endl;
        return;
    }

    if (books[book_id].get_is_available() == false)
    {
        cout << "Error: book is already issued" << endl;
        return;
    }

    Human* visitor = get_visitor_by_id(visitor_id);
    if (visitor == nullptr)
    {
        cout << "Error: visitor with ID " << visitor_id << " not found." << endl;
        return;
    }

    if (visitor->get_taken_now() >= 3)
    {
        cout << "Error: " << visitor->get_surname()
            << " ID: " << visitor_id << " already has 3 books, limit exceeded!!!" << endl;
        return;
    }

    books[book_id].check_out(visitor);
    visitor->increment_taken_books();

    cout << "Book " << books[book_id].get_name() << " issued to reader "
        << visitor->get_surname() << " ID: " << visitor_id << endl;
}

void Library::return_book(int book_id)
{
    if (book_id < 0 || book_id >= book_count)
    {
        cout << "Error: invalid book index." << endl;
        return;
    }

    if (books[book_id].get_is_available())
    {
        cout << "Error: book is already available." << endl;
        return;
    }

    Human* holder = books[book_id].get_holder();
    if (holder != nullptr)
    {
        holder->decrement_taken_books();
        cout << "Book " << books[book_id].get_name() << " returned by reader "
            << holder->get_surname() << " ID: " << holder->get_id() << endl;
    }

    books[book_id].return_book();
}

void Library::print_all_books()
{
    if (book_count == 0)
    {
        cout << "No books in the library" << endl;
        return;
    }

    cout << "All books in the library:" << endl;
    for (int i = 0; i < book_count; i++)
    {
        cout << "Index: " << i << " ";
        books[i].print();
    }
}

void Library::print_all_visitors()
{
    if (visitor_count == 0)
    {
        cout << "No visitors in the library" << endl;
        return;
    }

    cout << "All library visitors:" << endl;
    for (int i = 0; i < visitor_count; i++)
    {
        visitors[i].print();
    }
}

void Library::find_most_frequent_visitor()
{
    if (visitor_count == 0)
    {
        cout << "No visitors." << endl;
        return;
    }

    int max_books = 0;
    int most_frequent_id = 0;

    for (int i = 0; i < visitor_count; i++)
    {
        if (visitors[i].get_total_books_taken() > max_books)
        {
            max_books = visitors[i].get_total_books_taken();
            most_frequent_id = i;
        }
    }

    if (max_books == 0)
    {
        cout << "No visitor has taken any books yet" << endl;
    }
    else
    {
        cout << "Most active reader: " << visitors[most_frequent_id].get_surname()
            << " (ID: " << visitors[most_frequent_id].get_id()
            << "), books taken: " << max_books << endl;
    }
}

Human* Library::get_visitor_by_id(int id)
{
    for (int i = 0; i < visitor_count; i++)
    {
        if (visitors[i].get_id() == id)
        {
            return &visitors[i];
        }
    }
    return nullptr;
}