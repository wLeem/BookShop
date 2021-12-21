#pragma once

#include <string>
#include <iostream>
#include "consts.h"

enum BookType {
    BOOK,
    FBOOK,
    SBOOK,
    EBOOK
};

class Book {
public:
    Book();
    Book(std::string title, std::string author, std::string language, std::string publisher, size_t year,
         float price, size_t countPage, size_t weight, size_t quantity);
    Book(const Book&);
    virtual ~Book();

    bool operator>(const Book& b) const { return this->title > b.title; } // лексикограф. сравнение названий
    bool operator>=(const Book& b) const { return this->title >= b.title; } // лексикограф. сравнение названий
    bool operator<(const Book& b) const { return this->title < b.title; } // лексикограф. сравнение названий
    bool operator<=(const Book& b) const { return this->title <= b.title; } // лексикограф. сравнение названий
    bool operator==(const Book& b) const; // сравнение объектов книг на полную идентичность
    bool operator!=(const Book& b) const;
    void operator++(int); // увеличение количества книг
    bool operator--(int); // уменьшение количества книг; bool для определения удачного совершения операции
    void operator+=(int); // увеличение количества книг
    size_t operator-=(int); // уменьшение количества книг; int для определения удачного совершения операции

    std::string getTitle() const { return title; }
    void setTitle(std::string title) { this->title = title; }

    std::string getAuthor() const { return author; }
    void setAuthor(std::string author) { this->author = author; }

    std::string getLanguage() const { return language; }
    void setLanguage(std::string language) { this->language = language; }

    std::string getPublisher() const { return publisher; }
    void setPublisher(std::string publisher) { this->publisher = publisher; }

    size_t getYear() const { return year; }
    void setYear(size_t year) { this->year = year; }

    float getPrice() const { return price; }
    void setPrice(float price) { this->price = price; }

    size_t getPages() const { return pages; }
    void setPages(size_t pages) { this->pages = pages; }

    size_t getWeight() const { return weight; }
    void setWeight(size_t weight) { this->weight = weight; }

    size_t getQuantity() const { return quantity; }
    void setQuantity(size_t quantity) { this->quantity = quantity; }

    virtual BookType getBookType() { return BOOK; }

private:
    std::string title, author, language, publisher;
    size_t year;
    float price;
    size_t pages, weight, quantity;
};
