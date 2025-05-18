#include "BookManager.h"
#include <iostream>
using namespace libcli;

int main(int argc, char* argv[]) {
    BookManager manager;

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--import" && argc > 2) {
            if (manager.loadFromCSV(argv[2])) {
                std::cout << "Za³adowano dane z pliku.\n";
                manager.listBooks();
            }
            else {
                std::cerr << "Nie uda³o siê wczytaæ pliku.\n";
            }
            return 0;
        }
        else if (arg == "--sort" && argc > 2) {
            manager.loadFromCSV("data/books.csv");
            manager.sortBooks(argv[2]);
            manager.listBooks();
            return 0;
        }
    }

    int opcja;
    do {
        std::cout << "\n1. Wczytaj z pliku\n2. Dodaj ksi¹¿kê\n3. Usuñ ksi¹¿kê\n4. Poka¿ wszystkie\n5. Sortuj\n6. Zapisz do pliku\n0. Wyjœcie\nWybierz opcjê: ";
        std::cin >> opcja;
        std::cin.ignore();

        if (opcja == 1) {
            if (manager.loadFromCSV("data/books.csv"))
                std::cout << "Za³adowano dane.\n";
            else
                std::cout << "B³¹d przy wczytywaniu.\n";
        }
        else if (opcja == 2) {
            Book b;
            std::cout << "Tytu³: "; std::getline(std::cin, b.title);
            std::cout << "Autor: "; std::getline(std::cin, b.author);
            std::cout << "Rok: "; std::cin >> b.year;
            std::cout << "Strony: "; std::cin >> b.pages; std::cin.ignore();
            manager.addBook(b);
        }
        else if (opcja == 3) {
            std::string title;
            std::cout << "Tytu³ do usuniêcia: "; std::getline(std::cin, title);
            if (manager.removeBook(title))
                std::cout << "Usuniêto.\n";
            else
                std::cout << "Nie znaleziono.\n";
        }
        else if (opcja == 4) {
            manager.listBooks();
        }
        else if (opcja == 5) {
            std::string field;
            std::cout << "Sortuj po (title/author/year): ";
            std::getline(std::cin, field);
            manager.sortBooks(field);
        }
        else if (opcja == 6) {
            if (manager.saveToCSV("data/books.csv"))
                std::cout << "Zapisano.\n";
            else
                std::cout << "B³¹d zapisu.\n";
        }
    } while (opcja != 0);

    return 0;
}
