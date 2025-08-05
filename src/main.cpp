#include "../include/Library.h"
#include <iostream>

int main() {
    Library lib;
    std::string filename = "../data/books.txt";
    lib.loadFromFile(filename);

    int choice;
    while (true) {
        std::cout << "\n------Library Menu ------\n";
        std::cout << "1. Add Book\n2. Display All Books\n3. Search Book by ID\n";
        std::cout << "4. Issue Book\n5. Return Book\n6. Delete Book\n0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 0) {
            lib.saveToFile(filename);
            std::cout << " Data saved. Exiting...\n";
            break;
        }

        int id;
        std::string title, author;
        switch (choice) {
            case 1:
                std::cout << "Enter ID: "; std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Title: "; getline(std::cin, title);
                std::cout << "Enter Author: "; getline(std::cin, author);
                lib.addBook(Book(id, title, author, false));
                lib.saveToFile(filename);  // ✅ Add this line
                break;
            case 2:
                lib.displayAll();
                break;
            case 3:
                std::cout << "Enter ID: "; std::cin >> id;
                if (Book* b = lib.searchById(id))
                    b->display();
                else
                    std::cout << " Book not found.\n";
                break;
            case 4:
                std::cout << "Enter ID to issue: "; std::cin >> id;
                lib.issueBook(id);
                break;
            case 5:
                std::cout << "Enter ID to return: "; std::cin >> id;
                lib.returnBook(id);
                break;
            case 6:
                std::cout << "Enter ID to delete: "; std::cin >> id;
                lib.deleteBook(id);
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
