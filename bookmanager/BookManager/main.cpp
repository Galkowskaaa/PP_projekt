#include "BookManager.h"
#include <iostream>
#include <locale>
#include <clocale>

int main(int argc, char* argv[]) {
    std::setlocale(LC_ALL, "");
    std::locale::global(std::locale(""));

    const std::string defaultCsv = "books.csv";
    libcli::BookManager manager;

    if (argc > 1) {
        std::string cmd = argv[1];
        if (cmd == "--import" && argc > 2) {
            if (manager.loadFromCSV(argv[2])) {
                std::cout << "Za³adowano i wyœwietlam: \n";
                manager.listBooks();
            }
            else {
                std::cerr << "B³¹d importu!\n";
            }
            return 0;
        }
        else if (cmd == "--sort" && argc > 2) {
            manager.loadFromCSV(defaultCsv);
            manager.sortBooks(argv[2]);
            manager.listBooks();
            return 0;
        }
    }

    manager.interactive(defaultCsv);
    return 0;
}