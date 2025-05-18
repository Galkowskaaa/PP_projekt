#pragma once
#include "Book.h"
#include <vector>
#include <string>

namespace libcli {

    class BookManager {
    private:
        std::vector<Book> books;
    public:
        void interactive(const std::string& defaultCsv);
        void addBook(const Book& book);
        bool removeBook(const std::string& title);
        void listBooks() const;
        void sortBooks(const std::string& field);
        void filterByAuthor(const std::string& author) const;
        bool loadFromCSV(const std::string& filename);
        bool saveToCSV(const std::string& filename) const;
    };

}