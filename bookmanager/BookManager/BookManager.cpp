#include "BookManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

namespace libcli {

    static std::string trim(const std::string& str) {
        std::string result;
        for (char c : str) {
            if (c != '\t' && c != '\n' && c != '\r' && c != ' ' && static_cast<unsigned char>(c) != 0xA0) {
                result += c;
            }
            else if (c == ' ') {
                result += ' ';
            }
        }
        size_t start = result.find_first_not_of(' ');
        size_t end = result.find_last_not_of(' ');
        return (start == std::string::npos) ? "" : result.substr(start, end - start + 1);
    }

    void BookManager::interactive(const std::string& defaultCsv) {
        loadFromCSV(defaultCsv);

        std::string choice;
        while (true) {
            std::cout << "\n=== Book Manager ===\n"
                << "1. List books\n"
                << "2. Add book\n"
                << "3. Remove book\n"
                << "4. Sort books\n"
                << "5. Filter by author\n"
                << "6. Save to file\n"
                << "0. Exit\n"
                << "Choice: ";
            std::getline(std::cin, choice);

            if (choice == "1") {
                listBooks();
            }
            else if (choice == "2") {
                Book book;
                std::string rokStr, pagesStr;
                std::cout << "Title: ";
                std::getline(std::cin, book.title);
                std::cout << "Author: ";
                std::getline(std::cin, book.author);
                std::cout << "Year: ";
                std::getline(std::cin, rokStr);
                std::cout << "Pages: ";
                std::getline(std::cin, pagesStr);
                try {
                    book.rok = std::stoi(trim(rokStr));
                    book.pages = static_cast<Pages>(std::stoi(trim(pagesStr)));
                    addBook(book);
                    std::cout << "Book added.\n";
                }
                catch (...) {
                    std::cout << "Invalid input. Try again.\n";
                }
            }
            else if (choice == "3") {
                std::string title;
                std::cout << "Title to remove: ";
                std::getline(std::cin, title);
                if (removeBook(title)) {
                    std::cout << "Book removed.\n";
                }
                else {
                    std::cout << "Book not found.\n";
                }
            }
            else if (choice == "4") {
                std::string field;
                std::cout << "Sort by (title/author/rok/pages): ";
                std::getline(std::cin, field);
                sortBooks(field);
                std::cout << "Books sorted.\n";
            }
            else if (choice == "5") {
                std::string author;
                std::cout << "Author: ";
                std::getline(std::cin, author);
                filterByAuthor(author);
            }
            else if (choice == "6") {
                std::string file = "books.csv";
                if (saveToCSV(file)) {
                    std::cout << "Books saved to " << file << ".\n";
                }
                else {
                    std::cout << "Error saving file.\n";
                }
            }
            else if (choice == "0") {
                break;
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void BookManager::addBook(const Book& book) {
        books.push_back(book);
    }

    bool BookManager::removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(),
            [&title](const Book& b) { return b.title == title; });
        if (it != books.end()) {
            books.erase(it, books.end());
            return true;
        }
        return false;
    }

    void BookManager::listBooks() const {
        for (const auto& b : books) {
            std::cout << b.title << " | " << b.author << " | " << b.rok << " | " << b.pages << " pages\n";
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
        else if (field == "rok") {
            std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.rok < b.rok;
                });
        }
        else if (field == "pages") {
            std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                return a.pages < b.pages;
                });
        }
    }

    void BookManager::filterByAuthor(const std::string& author) const {
        for (const auto& b : books) {
            if (b.author == author) {
                std::cout << b.title << " | " << b.author << " | " << b.rok << " | " << b.pages << " pages\n";
            }
        }
    }

    bool BookManager::loadFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        books.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, author, rokStr, pagesStr;

            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            std::getline(ss, rokStr, ',');
            std::getline(ss, pagesStr);

            try {
                Book book{ trim(title), trim(author), std::stoi(trim(rokStr)), static_cast<Pages>(std::stoi(trim(pagesStr))) };
                books.push_back(book);
            }
            catch (...) {
                continue;
            }
        }

        return true;
    }

    bool BookManager::saveToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) return false;

        for (const auto& b : books) {
            file << b.title << "," << b.author << "," << b.rok << "," << b.pages << "\n";
        }

        return true;
    }

}