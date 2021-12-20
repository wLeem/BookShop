#include "fictionbook.h"

FictionBook::FictionBook()
    : Book()
    , genre(STRING0)
    , age(NUMBER0)
{
#if SHOW_MEM_USAGE
    std::cout << "+ FBook\n";
#endif
}

FictionBook::FictionBook(std::string title, std::string author, std::string language, std::string publisher, size_t year,
    float price, size_t pages, size_t weight, size_t quantity, std::string genre, size_t ageLimit)
    : Book(title, author, language, publisher, year, price, pages, weight, quantity)
	, genre(genre)
    , age(ageLimit)
{
#if SHOW_MEM_USAGE
    std::cout << "+ FBook\n";
#endif
}

FictionBook::FictionBook(const FictionBook& b)
    : Book(b.getTitle(), b.getAuthor(), b.getLanguage(), b.getPublisher(), b.getYear(), b.getPrice(), b.getPages(), b.getWeight(), b.getQuantity())
    , genre(b.genre)
    , age(b.age)
{
#if SHOW_MEM_USAGE
    std::cout << "+ FBook\n";
#endif
}

FictionBook::~FictionBook() {
#if SHOW_MEM_USAGE
    std::cout << "- FBook\n";
#endif
}
