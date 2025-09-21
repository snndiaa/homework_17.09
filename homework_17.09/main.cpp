#include <iostream>
#include "Library.h"

using namespace std;

void print_menu() {
    cout << endl << "Library Menu" << endl;
    cout << "1. Add a new book" << endl;
    cout << "2. Add a new visitor" << endl;
    cout << "3. Issue a book" << endl;
    cout << "4. Return a book" << endl;
    cout << "5. Print all books" << endl;
    cout << "6. Print all visitors" << endl;
    cout << "7. Find a book by author" << endl;
    cout << "8. Find a book by title" << endl;
    cout << "9. Find a book by genre" << endl;
    cout << "10. Find the most frequent visitor" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library my_library;

    my_library.add_book(Book("Greek Myths", "Robert Graves", "Mythology"));
    my_library.add_book(Book("Grokking Algorithms", "Aditya Bhargava", "Educational"));
    my_library.add_book(Book("And Quiet Flows the Don", "Mikhail Sholokhov", "Epic Novel"));
    my_library.add_book(Book("Poet Sanek (2025)", "Alexander", "Modern Poetry"));

    my_library.add_visitor(Human("Vanya", 227));
    my_library.add_visitor(Human("Arina", 228));

    cout << "Initial library state:" << endl;
    my_library.print_all_books();
    my_library.print_all_visitors();

    int choice;
    char* name = nullptr;
    char* author = nullptr;
    char* genre = nullptr;
    char* surname = nullptr;
    int book_id, visitor_id, id;

    const int BUFFER_SIZE = 128;
    char temp[BUFFER_SIZE];

    while (true) {
        print_menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter book name: ";
            cin.getline(temp, BUFFER_SIZE);
            name = new char[strlen(temp) + 1];
            strcpy_s(name, strlen(temp) + 1, temp);

            cout << "Enter author: ";
            cin.getline(temp, BUFFER_SIZE);
            author = new char[strlen(temp) + 1];
            strcpy_s(author, strlen(temp) + 1, temp);

            cout << "Enter genre: ";
            cin.getline(temp, BUFFER_SIZE);
            genre = new char[strlen(temp) + 1];
            strcpy_s(genre, strlen(temp) + 1, temp);

            my_library.add_book(Book(name, author, genre));
            cout << "Book added successfully" << endl;

            delete[] name;
            delete[] author;
            delete[] genre;
            name = author = genre = nullptr;
            break;

        case 2:
            cout << "Enter visitor surname: ";
            cin.getline(temp, BUFFER_SIZE);
            surname = new char[strlen(temp) + 1];
            strcpy_s(surname, strlen(temp) + 1, temp);

            cout << "Enter visitor ID: ";
            cin >> id;

            my_library.add_visitor(Human(surname, id));
            cout << "Visitor added successfully" << endl;

            delete[] surname;
            surname = nullptr;
            break;

        case 3:
            cout << "Current books:" << endl;
            my_library.print_all_books();
            cout << "Enter book index: ";
            cin >> book_id;
            cout << "Current visitors:" << endl;
            my_library.print_all_visitors();
            cout << "Enter visitor ID: ";
            cin >> visitor_id;
            my_library.issue_book(book_id, visitor_id);
            break;

        case 4:
            cout << "Current books:" << endl;
            my_library.print_all_books();
            cout << "Enter book index to return: ";
            cin >> book_id;
            my_library.return_book(book_id);
            break;

        case 5:
            my_library.print_all_books();
            break;

        case 6:
            my_library.print_all_visitors();
            break;

        case 7:
            cout << "Enter author name: ";
            cin.getline(temp, BUFFER_SIZE);
            author = new char[strlen(temp) + 1];
            strcpy_s(author, strlen(temp) + 1, temp);

            my_library.find_book_by_author(author);

            delete[] author;
            author = nullptr;
            break;

        case 8:
            cout << "Enter book title: ";
            cin.getline(temp, BUFFER_SIZE);
            name = new char[strlen(temp) + 1];
            strcpy_s(name, strlen(temp) + 1, temp);

            my_library.find_book_by_title(name);

            delete[] name;
            name = nullptr;
            break;

        case 9:
            cout << "Enter genre: ";
            cin.getline(temp, BUFFER_SIZE);
            genre = new char[strlen(temp) + 1];
            strcpy_s(genre, strlen(temp) + 1, temp);

            my_library.find_book_by_genre(genre);

            delete[] genre;
            genre = nullptr;
            break;

        case 10:
            my_library.find_most_frequent_visitor();
            break;

        case 0:
            cout << "Bye" << endl;

            delete[] name;
            delete[] author;
            delete[] genre;
            delete[] surname;

            return 0;

        default:
            cout << "Invalid" << endl;
            break;
        }
    }

    return 0;
}