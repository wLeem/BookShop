#include "book.h"

Book::Book()
    : title(STRING0)
    , author(STRING0)
    , language(STRING0)
    , publisher(STRING0)
    , year(NUMBER0)
    , price(PRICE0)
    , pages(NUMBER0)
    , weight(NUMBER0)
    , quantity(NUMBER0)
{
#if SHOW_MEM_USAGE
    std::cout << "+ Book\n";
#endif
}

Book::Book(std::string title, std::string author, std::string language, std::string publisher, size_t year,
    float price, size_t pages, size_t weight, size_t quantity)
    : title(title)
    , author(author)
    , language(language)
    , publisher(publisher)
    , year(year)
    , price(price)
    , pages(pages)
    , weight(weight)
    , quantity(quantity)
{
#if SHOW_MEM_USAGE
    std::cout << "+ Book\n";
#endif
}

Book::Book(const Book& b)
    : title(b.title)
    , author(b.author)
    , language(b.language)
    , publisher(b.publisher)
    , year(b.year)
    , price(b.price)
    , pages(b.pages)
    , weight(b.weight)
    , quantity(b.quantity)
{
#if SHOW_MEM_USAGE
    std::cout << "+ Book\n";
#endif
}

Book::~Book() {
#if SHOW_MEM_USAGE
     std::cout << "- Book\n";
#endif
}

bool Book::operator==(const Book& b) const {
    if (this->author != b.getAuthor() || this->title != b.getTitle() || this->language != b.getLanguage() ||
        this->pages != b.getPages() || this->publisher != b.getPublisher() || this->year != b.getYear())
        return 0;
    return 1;
}

bool Book::operator!=(const Book& b) const {
    if (this->author != b.getAuthor() || this->title != b.getTitle() || this->language != b.getLanguage() ||
        this->pages != b.getPages() || this->publisher != b.getPublisher() || this->year != b.getYear())
        return 1;
    return 0;
}

void Book::operator++(int) {
    this->setQuantity(this->quantity + 1);
}

bool Book::operator--(int) {
    if (!quantity) return 0;
    quantity--;
    return 1;
}

void Book::operator+=(int i) {
    this->setQuantity(this->quantity + i);
}

size_t Book::operator-=(int i) {
    if (i < 0 || !quantity) return 0;
    size_t removed;
    if (quantity <= i) {
        removed = quantity;
        quantity = 0;
    }
    else {
        removed = i;
        quantity -= i;
    }
    return removed;
}
