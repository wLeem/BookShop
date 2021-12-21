#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include <fstream>
#include <QTableWidget>
#include <QLabel>

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

#include "educationbook.h"
#include "fictionbook.h"
#include "sciencebook.h"

class BookShop {
public:
    BookShop();
    ~BookShop();

    void push(const Book&);
    void push(const FictionBook&);
    void push(const ScienceBook&);
    void push(const EducationBook&);
    void remove(const std::string&);
    int operator[](const std::string&) const;
    void incQ(size_t);
    void decQ(size_t);
    void changeQ(size_t, size_t);
    void clear();
    bool checkQ(size_t) const;
    void print() const;
    void print(QTableWidget*) const;
    size_t getSize() const;

    void read(const std::string&);
    void write(const std::string&) const;
    void readX(const std::string&);
    void writeX(const std::string&) const;

    void filterT(const BookShop&, size_t);
    void filterA(const BookShop&, const std::string&);
    void filterL(const BookShop&, const std::string&);
    void filterP(const BookShop&, const std::string&);
    void filterP(const BookShop&, float, float);
    void filterY(const BookShop&, size_t, size_t);
private:
    void resize();

    Book **bsh;
    size_t sz = 0, nb = SIZE0;

};

#endif // BOOKSHOP_H
