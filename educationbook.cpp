#include "educationbook.h"

EducationBook::EducationBook()
    : Book()
    , sphere(STRING0)
    , level(STRING0)
{
#if SHOW_MEM_USAGE
    std::cout << "+ EBook\n";
#endif
}

EducationBook::EducationBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
    float price, size_t pages, size_t weight, size_t quantity, std::string sphere, std::string level)
    : Book(title, author, language, publisher, year, price, pages, weight, quantity)
	, sphere(sphere)
    , level(level)
{
#if SHOW_MEM_USAGE
    std::cout << "+ EBook\n";
#endif
}

EducationBook::EducationBook(const EducationBook& b)
    : Book(b.getTitle(), b.getAuthor(), b.getLanguage(), b.getPublisher(), b.getYear(), b.getPrice(), b.getPages(), b.getWeight(), b.getQuantity())
    , sphere(b.sphere)
    , level(b.level)
{
#if SHOW_MEM_USAGE
    std::cout << "+ EBook\n";
#endif
}

EducationBook::~EducationBook() {
#if SHOW_MEM_USAGE
    std::cout << "- EBook\n";
#endif
}
