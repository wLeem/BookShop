#pragma once

#include "book.h"

class FictionBook : public Book {
    public:
    FictionBook();
    FictionBook(const FictionBook&);
    FictionBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
                float price, size_t pages, size_t weight, size_t quantity, std::string genre, size_t ageLimit);
    virtual ~FictionBook();

    std::string getGenre() const { return genre; }
    void setGenre(std::string genre) { this->genre = genre; }

    size_t getAge() const { return age; }
    void setAge(size_t ageLimit) { this->age = ageLimit; }

    virtual BookType getBookType() { return FBOOK; }
private:
    std::string genre;
    size_t age;
};
