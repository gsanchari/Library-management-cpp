#pragma once
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book();
    Book(int, const string&, const string&, bool);

    void display() const;

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool getStatus() const;
    void setIssued(bool);

    string toString() const;
    static Book fromString(const string& line);
};
