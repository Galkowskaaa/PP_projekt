#include "BookManager.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace libcli {

    void BookManager::addBook(const Book& book) {
        books.push_back(book);
    }

    bool BookManager::removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(), [&](const Book& b) {
            return b.title == title;
            });
        if (it != books.end()) {
            books.erase(it, books.end());
            return true;
        }
        return false;
    }

    void BookManager::listBooks() const {
        for (const auto& b : books) {
            std::cout << b.title << " | " << b.author << " | " << b.year << " | " << b.pages << " stron\n";
        }
    }

    void BookManager::sortBooks(const std::string& field) {
        if (field == "title") {
            std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.title < b.title;
                });
        }
        else if (field == "author") {
            std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.author < b.author;
                });
        }
        else if (field == "year") {
            std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.year < b.year;
                });
        }
    }

    void BookManager::filterByAuthor(const std::string& author) const {
        for (const auto& b : books) {
            if (b.author == author) {
                std::cout << b.title << " | " << b.year << " | " << b.pages << " stron\n";
            }
        }
    }

    bool BookManager::loadFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, author, yearStr, pagesStr;
            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            std::getline(ss, yearStr, ',');
            std::getline(ss, pagesStr, ',');

            Book b{ title, author, static_cast<unsigned>(std::stoi(yearStr)), static_cast<unsigned>(std::stoi(pagesStr)) };
            books.push_back(b);
        }
        return true;
    }

    bool BookManager::saveToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) return false;
        file << "Tytu³,Autor,Rok,Strony\n";
        for (const auto& b : books) {
            file << b.title << ',' << b.author << ',' << b.year << ',' << b.pages << '\n';
        }
        return true;
    }

}