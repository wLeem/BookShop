#include "sciencebook.h"

ScienceBook::ScienceBook()
    : Book()
    , area(STRING0)
{
#if SHOW_MEM_USAGE
    std::cout << "+ SBook\n";
#endif
}

ScienceBook::ScienceBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
    float price, size_t pages, size_t weight, size_t quantity, std::string area)
    : Book(title, author, language, publisher, year, price, pages, weight, quantity)
	, area(area)
{
#if SHOW_MEM_USAGE
    std::cout << "+ SBook\n";
#endif
}

ScienceBook::ScienceBook(const ScienceBook& b)
    : Book(b.getTitle(), b.getAuthor(), b.getLanguage(), b.getPublisher(), b.getYear(), b.getPrice(), b.getPages(), b.getWeight(), b.getQuantity())
    , area(b.area)
{
#if SHOW_MEM_USAGE
    std::cout << "+ SBook\n";
#endif
}

ScienceBook::~ScienceBook() {
#if SHOW_MEM_USAGE
    std::cout << "- SBook\n";
#endif
}
