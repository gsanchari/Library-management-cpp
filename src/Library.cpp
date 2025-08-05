#include "../include/Library.h"
#include <iostream>
#include <fstream>
using namespace std;

void Library::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    string line;
    books.clear();

    while (getline(inFile, line)) {
        books.push_back(Book::fromString(line));
    }

    inFile.close();
}

void Library::saveToFile(const string& filename) {
    ofstream outFile(filename);
    for (const auto& book : books) {
        outFile << book.toString() << "\n";
    }
    outFile.close();
}

void Library::addBook(const Book& book) {
    books.push_back(book);
    cout << "Book added successfully!\n";
    saveToFile("data/books.txt"); // Save after adding
}

void Library::displayAll() const {
    if (books.empty()) {
        cout << " No books found.\n";
        return;
    }
    for (const auto& book : books) {
        book.display();
    }
}

Book* Library::searchById(int id) {
    for (auto& book : books) {
        if (book.getId() == id)
            return &book;
    }
    return nullptr;
}

void Library::issueBook(int id) {
    Book* book = searchById(id);
    if (book) {
        if (!book->getStatus()) {
            book->setIssued(true);
            cout << "Book issued successfully.\n";
            saveToFile("data/books.txt"); // Save after issuing
        } else {
            cout << "Book is already issued.\n";
        }
    } else {
        cout << "Book not found.\n";
    }
}

void Library::returnBook(int id) {
    Book* book = searchById(id);
    if (book) {
        if (book->getStatus()) {
            book->setIssued(false);
            cout << " Book returned successfully.\n";
            saveToFile("data/books.txt"); // Save after return

        } else {
            cout << "Book was not issued.\n";
        }
    } else {
        cout << "Book not found.\n";
    }
}

void Library::deleteBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            books.erase(it);
            cout << "Book deleted.\n";
            saveToFile("data/books.txt"); // Save after deletion
            return;
        }
    }
    cout << "Book not found.\n";
}
