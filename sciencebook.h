#pragma once

#include "book.h"

class ScienceBook : public Book {
public:
    ScienceBook();
    ScienceBook(const ScienceBook&);
    ScienceBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
                float price, size_t pages, size_t weight, size_t quantity, std::string area);
    virtual ~ScienceBook();

    std::string getArea() const { return area; }
    void setArea(std::string area) { this->area = area; }

    virtual BookType getBookType() { return SBOOK; }
private:
    std::string area;
};
