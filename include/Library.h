#pragma once
#include "Book.h"
#include <vector>
#include <string>
using namespace std;

class Library {
private:
    vector<Book> books;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);

    void addBook(const Book&);
    void displayAll() const;
    Book* searchById(int id);
    void issueBook(int id);
    void returnBook(int id);
    void deleteBook(int id);
};
