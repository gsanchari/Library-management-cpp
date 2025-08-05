#include "../include/Book.h"
#include <iostream>
#include <sstream>
using namespace std;

Book::Book() : id(0), title(""), author(""), isIssued(false) {}

Book::Book(int id, const string& title, const string& author, bool isIssued)
    : id(id), title(title), author(author), isIssued(isIssued) {}

void Book::display() const {
    cout << "ID: " << id << " | Title: " << title << " | Author: " << author
              << " | Status: " << (isIssued ? "Issued" : "Available") << "\n";
}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::getStatus() const { return isIssued; }
void Book::setIssued(bool status) { isIssued = status; }

string Book::toString() const {
    return std::to_string(id) + ";" + title + ";" + author + ";" + (isIssued ? "1" : "0");
}

Book Book::fromString(const std::string& line) {
    stringstream ss(line);
    string token;
    int id;
    string title, author;
    bool isIssued;

    getline(ss, token, ';');
    id = stoi(token);
    getline(ss, title, ';');
    getline(ss, author, ';');
    getline(ss, token, ';');
    isIssued = (token == "1");

    return Book(id, title, author, isIssued);
}
