#pragma once
#include <vector>
#include <string>
#include "Book.h"

namespace libcli {

    class BookManager {
    private:
        std::vector<Book> books;
    public:
        void addBook(const Book& book);
        bool removeBook(const std::string& title);
        void listBooks() const;
        void sortBooks(const std::string& field);
        void filterByAuthor(const std::string& author) const;
        bool loadFromCSV(const std::string& filename);
        bool saveToCSV(const std::string& filename) const;
    };

}