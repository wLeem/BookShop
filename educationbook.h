#pragma once

#include "book.h"

class EducationBook : public Book {
public:
    EducationBook();
    EducationBook(const EducationBook&);
    EducationBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
                  float price, size_t pages, size_t weight, size_t quantity, std::string sphere, std::string level);
    virtual ~EducationBook();

    std::string getSphere() const { return sphere; }
    void setSphere(std::string sphere) { this->sphere = sphere; }

    std::string getLevel() const { return level; }
    void setLevel(std::string level) { this->level = level; }

    virtual BookType getBookType() { return EBOOK; }
private:
    std::string sphere, level;
};
