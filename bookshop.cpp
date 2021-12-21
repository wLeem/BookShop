#include "bookshop.h"

BookShop::BookShop() {
    bsh = new Book*[nb];
    for (size_t i = 0; i < nb; i++)
        bsh[i] = nullptr;
}

BookShop::~BookShop()
{
    clear();
    delete [] bsh;
}

void BookShop::push(const Book& element) {
    std::string s = element.getTitle();
    if ((*this)[s] >= 0) return;
    Book *newBook = new Book(element);
    if (!sz) {
        bsh[0] = newBook;
        sz++;
        return;
    }
    int left = 0, right = sz - 1;
    while (left < right) {
        if (s < bsh[(left + right) / 2]->getTitle()) right = (left + right) / 2 - 1;
        else left = (left + right) / 2 + 1;
        if (right < left) right++;
    }
    if (s > bsh[left]->getTitle()) left++;
    for (right = sz; right > left; right--)
        bsh[right] = bsh [right - 1];
    bsh[left] = newBook;
    sz++;
    if ((float)sz / nb > CRIT_FULL) resize();
}

void BookShop::push(const FictionBook& element) {
    std::string s = element.getTitle();
    if ((*this)[s] >= 0) return;
    FictionBook *newBook = new FictionBook(element);
    if (!sz) {
        bsh[0] = newBook;
        sz++;
        return;
    }
    int left = 0, right = sz - 1;
    while (left < right) {
        if (s < bsh[(left + right) / 2]->getTitle()) right = (left + right) / 2 - 1;
        else left = (left + right) / 2 + 1;
        if (right < left) right++;
    }
    if (s > bsh[left]->getTitle()) left++;
    for (right = sz; right > left; right--)
        bsh[right] = bsh [right - 1];
    bsh[left] = newBook;
    sz++;
    if ((float)sz / nb > CRIT_FULL) resize();
}

void BookShop::push(const ScienceBook& element) {
    std::string s = element.getTitle();
    if ((*this)[s] >= 0) return;
    ScienceBook *newBook = new ScienceBook(element);
    if (!sz) {
        bsh[0] = newBook;
        sz++;
        return;
    }
    int left = 0, right = sz - 1;
    while (left < right) {
        if (s < bsh[(left + right) / 2]->getTitle()) right = (left + right) / 2 - 1;
        else left = (left + right) / 2 + 1;
        if (right < left) right++;
    }
    if (s > bsh[left]->getTitle()) left++;
    for (right = sz; right > left; right--)
        bsh[right] = bsh [right - 1];
    bsh[left] = newBook;
    sz++;
    if ((float)sz / nb > CRIT_FULL) resize();
}

void BookShop::push(const EducationBook& element) {
    std::string s = element.getTitle();
    if ((*this)[s] >= 0) return;
    EducationBook *newBook = new EducationBook(element);
    if (!sz) {
        bsh[0] = newBook;
        sz++;
        return;
    }
    int left = 0, right = sz - 1;
    while (left < right) {
        if (s < bsh[(left + right) / 2]->getTitle()) right = (left + right) / 2 - 1;
        else left = (left + right) / 2 + 1;
        if (right < left) right++;
    }
    if (s > bsh[left]->getTitle()) left++;
    for (right = sz; right > left; right--)
        bsh[right] = bsh [right - 1];
    bsh[left] = newBook;
    sz++;
    if ((float)sz / nb > CRIT_FULL) resize();
}

void BookShop::remove(const std::string& s) {
    if (int k = (*this)[s] < 0) return;
    else {
        delete bsh[k];
        size_t oldsz = sz;
        for (size_t i = k; i < oldsz; i++)
            bsh[i] = bsh[i + 1];
        sz--;
    }
}

int BookShop::operator[](const std::string& s) const {
    if (sz < 1) return -1;
    int midd, left = 0, right = sz - 1;
    while (left <= right) {
        midd = (left + right) / 2;
        if (s < bsh[midd]->getTitle()) right = midd - 1;
        else if (s > bsh[midd]->getTitle()) left = midd + 1;
        else return midd;
    }
    return -1;
}

void BookShop::clear() {
    size_t oldsz = sz;
    for (size_t i = 0; i < oldsz; i++) {
        delete(bsh[i]);
        bsh[i] = nullptr;
        sz--;
    }
}

size_t BookShop::getSize() const {
    return sz;
}

bool BookShop::checkQ(size_t i) const {
    if (bsh[i]->getQuantity()) return true;
    return false;
}

void BookShop::incQ(size_t i) {
    if (i < sz) (*bsh[i])++;
}

void BookShop::decQ(size_t i) {
    if (i < sz) (*bsh[i])--;
}

void BookShop::changeQ(size_t i, size_t v) {
    if (i < sz) (*bsh[i]).setQuantity(v);
}

void BookShop::write(const std::string& filename) const {
    std::ofstream outputFile(filename);
    size_t newsz = 0;
    outputFile << sz << std::endl;
    for (size_t i = 0; i < sz; i++) {
        if (bsh[i]) {
            BookType bt = bsh[i]->getBookType();
            outputFile << std::to_string(bt) << std::endl << bsh[i]->getTitle() << std::endl << bsh[i]->getAuthor() << std::endl
                       << bsh[i]->getLanguage()<< std::endl << bsh[i]->getPublisher() << std::endl << bsh[i]->getYear() << std::endl
                       << bsh[i]->getPrice() << std::endl << bsh[i]->getPages() << std::endl << bsh[i]->getWeight() << std::endl
                       << bsh[i]->getQuantity() << std::endl;
            switch (bt) {
            case EBOOK:
                outputFile << ((EducationBook*)bsh[i])->getSphere() << std::endl << ((EducationBook*)bsh[i])->getLevel() << std::endl;
                break;
            case FBOOK:
                outputFile << ((FictionBook*)bsh[i])->getGenre() << std::endl << ((FictionBook*)bsh[i])->getAge() << std::endl;
                break;
            case SBOOK:
                outputFile << ((ScienceBook*)bsh[i])->getArea() << std::endl;
                break;
            default:
                break;
            }
            newsz++;
        }
    }
    outputFile.close();
    if (sz != newsz) std::cerr << "ERROR WHILE WRITING\n";
}

void BookShop::read(const std::string& filename) {
    this->clear();
    std::ifstream inputFile(filename);
    std::string type, title, author, language, publisher, year, price, pages, weight, q, dop1, dop2, lens;
    int len = 0, i;
    if (!inputFile.eof())
        getline(inputFile, lens);
    len = std::stoi(lens);
    for (i = 0; i < len && !inputFile.eof(); i++) {
        getline(inputFile, type);
        getline(inputFile, title);
        getline(inputFile, author);
        getline(inputFile, language);
        getline(inputFile, publisher);
        getline(inputFile, year);
        getline(inputFile, price);
        getline(inputFile, pages);
        getline(inputFile, weight);
        getline(inputFile, q);
        getline(inputFile, dop1);
        if (type == "0") {
            Book b(title, author, language, publisher, std::stoi(year), std::stof(price), std::stoi(pages), std::stoi(weight), std::stoi(q));
            this->push(b);
        }
        else if (type == "1") {
            getline(inputFile, dop2);
            FictionBook fb(title, author, language, publisher, std::stoi(year), std::stof(price), std::stoi(pages), std::stoi(weight),
                           std::stoi(q), dop1, std::stoi(dop2));
            this->push(fb);
        }
        else if (type == "2") {
            ScienceBook sb(title, author, language, publisher, std::stoi(year), std::stof(price), std::stoi(pages), std::stoi(weight),
                           std::stoi(q), dop1);
            this->push(sb);
        }
        else if (type == "3") {
            getline(inputFile, dop2);
            EducationBook eb(title, author, language, publisher, std::stoi(year), std::stof(price), std::stoi(pages), std::stoi(weight),
                             std::stoi(q), dop1, dop2);
            this->push(eb);
        }
    }
    inputFile.close();
    if (i != len) std::cerr << "ERROR WHILE READING" << std::endl;
}

void BookShop::writeX(const std::string& filename) const {
    QXlsx::Document table(QString::fromStdString(filename));
    size_t newsz = 0;
    table.write(1, 1, "Size:");
    table.write(1, 2, sz);
    for (size_t i = 0; i < sz; i++) {
        if (bsh[i]) {
            BookType bt = bsh[i]->getBookType();
            table.write(i + 2, 1, bt);
            table.write(i + 2, 2, QString::fromStdString(bsh[i]->getTitle()));
            table.write(i + 2, 3, QString::fromStdString(bsh[i]->getAuthor()));
            table.write(i + 2, 4, QString::fromStdString(bsh[i]->getLanguage()));
            table.write(i + 2, 5, QString::fromStdString(bsh[i]->getPublisher()));
            table.write(i + 2, 6, bsh[i]->getYear());
            table.write(i + 2, 7, bsh[i]->getPrice());
            table.write(i + 2, 8, bsh[i]->getPages());
            table.write(i + 2, 9, bsh[i]->getWeight());
            table.write(i + 2, 10, bsh[i]->getQuantity());
            switch (bt) {
            case EBOOK:
                table.write(i + 2, 11, QString::fromStdString(((EducationBook*)bsh[i])->getSphere()));
                table.write(i + 2, 12, QString::fromStdString(((EducationBook*)bsh[i])->getLevel()));
                break;
            case FBOOK:
                table.write(i + 2, 11, QString::fromStdString(((FictionBook*)bsh[i])->getGenre()));
                table.write(i + 2, 12, ((FictionBook*)bsh[i])->getAge());
                break;
            case SBOOK:
                table.write(i + 2, 11, QString::fromStdString(((ScienceBook*)bsh[i])->getArea()));
                break;
            default:
                break;
            }
            newsz++;
        }
    }
    table.saveAs(QString::fromStdString(filename));
    if (sz != newsz) std::cerr << "ERROR WHILE WRITING\n";
}

void BookShop::readX(const std::string& filename) {
    this->clear();
    QXlsx::Document table(QString::fromStdString(filename));
    std::string title, author, language, publisher, dop1, dop2, lens;
    size_t len = 0, i, type, year, pages, weight, q;
    float price;
    len = table.cellAt(1, 2)->readValue().toInt();
    for (i = 0; i < len; i++) {
        type = table.cellAt(i + 2, 1)->readValue().toInt();
        title = table.cellAt(i + 2, 2)->readValue().toString().toStdString();
        author = table.cellAt(i + 2, 3)->readValue().toString().toStdString();
        language = table.cellAt(i + 2, 4)->readValue().toString().toStdString();
        publisher = table.cellAt(i + 2, 5)->readValue().toString().toStdString();
        year = table.cellAt(i + 2, 6)->readValue().toInt();
        price = table.cellAt(i + 2, 7)->readValue().toFloat();
        pages = table.cellAt(i + 2, 8)->readValue().toInt();
        weight = table.cellAt(i + 2, 9)->readValue().toInt();
        q = table.cellAt(i + 2, 10)->readValue().toInt();
        dop1 = table.cellAt(i + 2, 11)->readValue().toString().toStdString();
        if (type == 1) {
            dop2 = table.cellAt(i + 2, 12)->readValue().toString().toStdString();
            FictionBook fb(title, author, language, publisher, year, price, pages, weight, q, dop1, std::stoi(dop2));
            this->push(fb);
        }
        else if (type == 2) {
            ScienceBook sb(title, author, language, publisher, year, price, pages, weight, q, dop1);
            this->push(sb);
        }
        else if (type == 3) {
            dop2 = table.cellAt(i + 2, 12)->readValue().toString().toStdString();
            EducationBook eb(title, author, language, publisher, year, price, pages, weight, q, dop1, dop2);
            this->push(eb);
        }
    }
    table.saveAs(QString::fromStdString(filename));
    if (i != len) std::cerr << "ERROR WHILE READING" << std::endl;
}

void BookShop::resize() {
    nb *= 2;
    Book **newBsh = new Book*[nb];
    for (size_t i = 0; i < nb; i++)
        if (i < nb / 2) newBsh[i] = bsh[i];
        else newBsh[i] = nullptr;
    delete [] bsh;
    bsh = newBsh;
}

void BookShop::print() const {
    std::cout << "   BOOK SHOP: sz = " << sz << ", nb = " << nb << std::endl;
    for (size_t i = 0; i < sz; i++)
    {
        if (bsh[i]) {
            BookType bt = bsh[i]->getBookType();
            std::cout << i << ": {" << bsh[i]->getQuantity() << "} ";
            switch (bt) {
            case EBOOK:
                std::cout << "[E] ";
                break;
            case FBOOK:
                std::cout << "[F] ";
                break;
            case SBOOK:
                std::cout << "[SCI] ";
                break;
            default:
                break;
            }
            std::cout << "'" << bsh[i]->getTitle()
                      << "' by " << bsh[i]->getAuthor()
                      << "; Language: " << bsh[i]->getLanguage()
                      << "; Published by " << bsh[i]->getPublisher()
                      << " in " << bsh[i]->getYear()
                      << "; Price: RUB" << bsh[i]->getPrice()
                      << "; Number of pages: " << bsh[i]->getPages()
                      << "; Weight: " << bsh[i]->getWeight() << "g";
            switch (bt) {
            case EBOOK:
                std::cout << "; Sphere: " << ((EducationBook*)bsh[i])->getSphere()
                          << "; Level: " << ((EducationBook*)bsh[i])->getLevel();
                break;
            case FBOOK:
                std::cout << "; Genre: " << ((FictionBook*)bsh[i])->getGenre()
                          << "; Age limit: " << ((FictionBook*)bsh[i])->getAge();
                break;
            case SBOOK:
                std::cout << "; Area of study: " << ((ScienceBook*)bsh[i])->getArea();
                break;
            default:
                break;
            }
            std::cout << std::endl;
        }
    }
}

void BookShop::print(QTableWidget *list) const {
    list->clearContents();
    list->setRowCount(sz);
    for (size_t i = 0; i < sz; i++) {
        BookType bt = bsh[i]->getBookType();
        switch (bt) {
        case EBOOK:
            list->setItem(i, 0, new QTableWidgetItem("[E]"));
            list->setItem(i, 10, new QTableWidgetItem(QString::fromStdString(((EducationBook*)bsh[i])->getSphere())));
            list->setItem(i, 11, new QTableWidgetItem(QString::fromStdString(((EducationBook*)bsh[i])->getLevel())));
            break;
        case FBOOK:
            list->setItem(i, 0, new QTableWidgetItem("[F]"));
            list->setItem(i, 10, new QTableWidgetItem(QString::fromStdString(((FictionBook*)bsh[i])->getGenre())));
            list->setItem(i, 11, new QTableWidgetItem(QString::number(((FictionBook*)bsh[i])->getAge())));
            break;
        case SBOOK:
            list->setItem(i, 0, new QTableWidgetItem("[S]"));
            list->setItem(i, 10, new QTableWidgetItem(QString::fromStdString(((ScienceBook*)bsh[i])->getArea())));
            list->setItem(i, 11, new QTableWidgetItem("-"));
            break;
        default:
            break;
        }
        list->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(bsh[i]->getTitle())));
        list->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(bsh[i]->getAuthor())));
        list->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(bsh[i]->getLanguage())));
        list->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(bsh[i]->getPublisher())));
        list->setItem(i, 5, new QTableWidgetItem(QString::number(bsh[i]->getYear())));
        list->setItem(i, 6, new QTableWidgetItem(QString::number(bsh[i]->getPrice(), 'f', 2)));
        list->setItem(i, 7, new QTableWidgetItem(QString::number(bsh[i]->getPages())));
        list->setItem(i, 8, new QTableWidgetItem(QString::number(bsh[i]->getWeight())));
        list->setItem(i, 9, new QTableWidgetItem(QString::number(bsh[i]->getQuantity())));
    }
}

void BookShop::filterT(const BookShop& bsh, size_t type) {
    if (this->sz) this->clear();
    BookType t;
    switch (type) {
    case 0:
        t = SBOOK;
        break;
    case 1:
        t = EBOOK;
        break;
    default:
        t = FBOOK;
        break;
    }
    for (size_t i = 0; i < bsh.sz; i++)
        if (bsh.bsh[i]->getBookType() == t) {
            if (t == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (t == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}

void BookShop::filterA(const BookShop& bsh, const std::string& a) {
    if (this->sz) this->clear();
    for (size_t i = 0; i < bsh.sz; i++)
        if (bsh.bsh[i]->getAuthor() == a) {
            if (bsh.bsh[i]->getBookType() == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (bsh.bsh[i]->getBookType() == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}

void BookShop::filterL(const BookShop& bsh, const std::string& l) {
    if (this->sz) this->clear();
    for (size_t i = 0; i < bsh.sz; i++)
        if (bsh.bsh[i]->getLanguage() == l) {
            if (bsh.bsh[i]->getBookType() == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (bsh.bsh[i]->getBookType() == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}

void BookShop::filterP(const BookShop& bsh, const std::string& p) {
    if (this->sz) this->clear();
    for (size_t i = 0; i < bsh.sz; i++)
        if (bsh.bsh[i]->getPublisher() == p) {
            if (bsh.bsh[i]->getBookType() == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (bsh.bsh[i]->getBookType() == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}

void BookShop::filterP(const BookShop& bsh, float p1, float p2) {
    if (this->sz) this->clear();
    for (size_t i = 0; i < bsh.sz; i++)
        if ((bsh.bsh[i]->getPrice() <= p1 && bsh.bsh[i]->getPrice() >= p2) || (bsh.bsh[i]->getPrice() <= p2 && bsh.bsh[i]->getPrice() >= p1)) {
            if (bsh.bsh[i]->getBookType() == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (bsh.bsh[i]->getBookType() == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}

void BookShop::filterY(const BookShop& bsh, size_t y1, size_t y2) {
    if (this->sz) this->clear();
    for (size_t i = 0; i < bsh.sz; i++)
        if ((bsh.bsh[i]->getYear() <= y1 && bsh.bsh[i]->getYear() >= y2) || (bsh.bsh[i]->getYear() <= y2 && bsh.bsh[i]->getYear() >= y1)) {
            if (bsh.bsh[i]->getBookType() == EBOOK) this->push((*(EducationBook*)bsh.bsh[i]));
            else if (bsh.bsh[i]->getBookType() == FBOOK) this->push((*(FictionBook*)bsh.bsh[i]));
            else this->push((*(ScienceBook*)bsh.bsh[i]));
        }
}
