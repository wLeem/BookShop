#include "mainwin.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Book Shop");
    bshList = new QTableWidget(this);
    bshList->setSelectionBehavior(QAbstractItemView::SelectRows);
    bshList->setSelectionMode(QAbstractItemView::SingleSelection);
    bshList->setColumnCount(12);
    bshList->setHorizontalHeaderLabels(QStringList() << "Type" << "Title" << "Author" << "Language" << "Publisher"
    << "Year" << "Price [RUB]" << "Pages" << "Weight [g]" << "Quantity" << "Area/Subject/Genre" << "Level/Age");

    addMessage.setText("A book with the same title is already in the book shop.");
    addFrame = new QFrame(this);
    addFrame->setFrameStyle(1);
    //addFrame->setFixedHeight(422);
    //addFrame->setMinimumHeight(422);
    addButt = new QPushButton("Add Book", addFrame);
    clearBookButt = new QPushButton("Clear Parameters", addFrame);
    typeL = new QLabel("Book Type", addFrame);
    titleL = new QLabel("Title", addFrame);
    authorL = new QLabel("Author", addFrame);
    langL = new QLabel("Language", addFrame);
    pubL = new QLabel("Publisher", addFrame);
    yearL = new QLabel("Year", addFrame);
    priceL = new QLabel("Price [RUB]", addFrame);
    pagesL = new QLabel("Pages", addFrame);
    weightL = new QLabel("Weight [g]", addFrame);
    quanL = new QLabel("Quantity", addFrame);
    dop1L = new QLabel("Area of Study", addFrame);
    dop2L = new QLabel("", addFrame);
    typeBox = new QComboBox(addFrame);
    typeBox->addItems({"Science", "Education", "Fiction"});
    titleE = new QLineEdit("", addFrame);
    authorE = new QLineEdit("", addFrame);
    langE = new QLineEdit("", addFrame);
    pubE = new QLineEdit("", addFrame);
    yearBox = new QSpinBox(addFrame);
    yearBox->setMaximum(2021);
    yearBox->setMinimum(2000);
    priceBox = new QDoubleSpinBox(addFrame);
    priceBox->setMaximum(10000.f);
    priceBox->setMinimum(10.f);
    pagesBox = new QSpinBox(addFrame);
    pagesBox->setMaximum(10000);
    pagesBox->setMinimum(10);
    weightBox = new QSpinBox(addFrame);
    weightBox->setMaximum(10000);
    weightBox->setMinimum(10);
    quanBox = new QSpinBox(addFrame);
    quanBox->setMaximum(1000);
    dop1E = new QLineEdit("", addFrame);
    dop2E = new QLineEdit("", addFrame);
    ageBox = new QSpinBox(addFrame);
    addLayout = new QGridLayout(addFrame);

    bookFrame = new QFrame(this);
    bookFrame->setFrameStyle(1);
    editQuanL = new QLabel("Edit Book Quantity", bookFrame);
    plusButt = new QPushButton("+1", bookFrame);
    changeButt = new QPushButton("Change Quantity", bookFrame);
    minusButt = new QPushButton("-1", bookFrame);
    quanDopBox = new QSpinBox(bookFrame);
    quanDopBox->setMaximum(1000);
    bookLayout = new QGridLayout(bookFrame);

    filterFrame = new QFrame(this);
    filterFrame->setFrameStyle(1);
    filterL = new QLabel("Filters", filterFrame);
    filterButt = new QPushButton("Show", filterFrame);
    cancelFButt = new QPushButton("Cancel", filterFrame);
    filterBox = new QComboBox(filterFrame);
    filterBox->addItems({"Type", "Author", "Language", "Publisher", "Year", "Price"});
    filterTypeBox = new QComboBox(filterFrame);
    filterTypeBox->addItems({"Science", "Education", "Fiction"});
    filterE = new QLineEdit("", filterFrame);
    yearF1Box = new QSpinBox(filterFrame);
    yearF1Box->setMaximum(2021);
    yearF1Box->setMinimum(2000);
    priceF1Box = new QDoubleSpinBox(filterFrame);
    priceF1Box->setMaximum(10000.f);
    priceF1Box->setMinimum(10.f);
    yearF2Box = new QSpinBox(filterFrame);
    yearF2Box->setMaximum(2021);
    yearF2Box->setMinimum(2000);
    priceF2Box = new QDoubleSpinBox(filterFrame);
    priceF2Box->setMaximum(10000.f);
    priceF2Box->setMinimum(10.f);
    filterLayout = new QGridLayout(filterFrame);

    shopFrame = new QFrame(this);
    shopFrame->setFrameStyle(1);
    clearButt = new QPushButton("Clear Bookshop", shopFrame);
    importTxtButt = new QPushButton("Import (TXT)", shopFrame);
    xportTxtButt = new QPushButton("Export (TXT)", shopFrame);
    importExcelButt = new QPushButton("Import (Excel)", shopFrame);
    xportExcelButt = new QPushButton("Export (Excel)", shopFrame);
    linkButt = new QPushButton("Link to File", shopFrame);
    shopLayout = new QGridLayout(shopFrame);

    layout = new QGridLayout(this);
    this->setLayout(layout);
    layout->addWidget(bshList, 0, 0, 1, 3);
    layout->addWidget(addFrame, 1, 0, 3, 2);
    layout->addWidget(bookFrame, 1, 2);
    layout->addWidget(filterFrame, 2, 2);
    layout->addWidget(shopFrame, 3, 2);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 0);
    layout->setRowStretch(2, 0);
    layout->setRowStretch(3, 0);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 1);
    layout->setColumnStretch(2, 1);

    bookLayout->addWidget(editQuanL, 0, 0, 1, 2);
    bookLayout->addWidget(plusButt, 1, 0);
    bookLayout->addWidget(minusButt, 1, 1);
    bookLayout->addWidget(quanDopBox, 2, 0);
    bookLayout->addWidget(changeButt, 2, 1);
    bookLayout->setRowStretch(0, 1);
    bookLayout->setRowStretch(1, 1);
    bookLayout->setRowStretch(2, 1);
    bookLayout->setColumnStretch(0, 1);
    bookLayout->setColumnStretch(1, 1);

    filterLayout->addWidget(filterL, 0, 0);
    filterLayout->addWidget(filterBox, 0, 1);
    filterLayout->addWidget(filterE, 1, 0, 1, 2);
    filterLayout->addWidget(filterTypeBox, 1, 0, 1, 2);
    filterLayout->addWidget(yearF1Box, 1, 0);
    filterLayout->addWidget(yearF2Box, 1, 1);
    filterLayout->addWidget(priceF1Box, 1, 0);
    filterLayout->addWidget(priceF2Box, 1, 1);
    filterLayout->addWidget(filterButt, 2, 0);
    filterLayout->addWidget(cancelFButt, 2, 1);
    filterLayout->setRowStretch(0, 1);
    filterLayout->setRowStretch(1, 1);
    filterLayout->setRowStretch(2, 1);
    filterLayout->setColumnStretch(0, 1);
    filterLayout->setColumnStretch(1, 1);

    shopLayout->addWidget(clearButt, 0, 0);
    shopLayout->addWidget(importTxtButt, 1, 0);
    shopLayout->addWidget(xportTxtButt, 2, 0);
    shopLayout->addWidget(importExcelButt, 3, 0);
    shopLayout->addWidget(xportExcelButt, 4, 0);
    shopLayout->addWidget(linkButt, 5, 0);
    shopLayout->setColumnStretch(0, 1);

    addLayout->addWidget(typeL, 0, 0);
    addLayout->addWidget(titleL, 1, 0);
    addLayout->addWidget(authorL, 2, 0);
    addLayout->addWidget(langL, 3, 0);
    addLayout->addWidget(pubL, 4, 0);
    addLayout->addWidget(yearL, 5, 0);
    addLayout->addWidget(priceL, 6, 0);
    addLayout->addWidget(pagesL, 7, 0);
    addLayout->addWidget(weightL, 8, 0);
    addLayout->addWidget(quanL, 9, 0);
    addLayout->addWidget(dop1L, 10, 0);
    addLayout->addWidget(dop2L, 11, 0);
    addLayout->addWidget(typeBox, 0, 1);
    addLayout->addWidget(titleE, 1, 1);
    addLayout->addWidget(authorE, 2, 1);
    addLayout->addWidget(langE, 3, 1);
    addLayout->addWidget(pubE, 4, 1);
    addLayout->addWidget(yearBox, 5, 1);
    addLayout->addWidget(priceBox, 6, 1);
    addLayout->addWidget(pagesBox, 7, 1);
    addLayout->addWidget(weightBox, 8, 1);
    addLayout->addWidget(quanBox, 9, 1);
    addLayout->addWidget(dop1E, 10, 1);
    addLayout->addWidget(dop2E, 11, 1);
    addLayout->addWidget(ageBox, 11, 1);
    addLayout->addWidget(addButt, 12, 0);
    addLayout->addWidget(clearBookButt, 12, 1);
    addLayout->setColumnStretch(0, 1);
    addLayout->setColumnStretch(1, 2);

    begin();

    connect(bshList, SIGNAL(itemSelectionChanged()), this, SLOT(checkQuan()));
    connect(typeBox, SIGNAL(currentTextChanged(const QString&)), this,
            SLOT(checkType()));
    connect(filterBox, SIGNAL(currentTextChanged(const QString&)), this,
            SLOT(checkFType()));
    connect(filterE, SIGNAL(textEdited(const QString&)), this, SLOT(checkFilter()));
    connect(filterButt, SIGNAL(clicked(bool)), this, SLOT(showFilter()));
    connect(cancelFButt, SIGNAL(clicked(bool)), this, SLOT(refresh()));
    connect(titleE, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(authorE, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(langE, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(pubE, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(dop1E, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(dop2E, SIGNAL(textEdited(const QString&)), this, SLOT(checkBook()));
    connect(clearBookButt, SIGNAL(clicked(bool)), this, SLOT(clearParam()));
    connect(addButt, SIGNAL(clicked(bool)), this, SLOT(addBook()));
    connect(plusButt, SIGNAL(clicked(bool)), this, SLOT(plus()));
    connect(minusButt, SIGNAL(clicked(bool)), this, SLOT(minus()));
    connect(changeButt, SIGNAL(clicked(bool)), this, SLOT(changeQuan()));
    connect(clearButt, SIGNAL(clicked(bool)), this, SLOT(clear()));
    connect(importTxtButt, SIGNAL(clicked(bool)), this, SLOT(importTxt()));
    connect(xportTxtButt, SIGNAL(clicked(bool)), this, SLOT(xportTxt()));
    connect(importExcelButt, SIGNAL(clicked(bool)), this, SLOT(importExcel()));
    connect(xportExcelButt, SIGNAL(clicked(bool)), this, SLOT(xportExcel()));
    connect(linkButt, SIGNAL(clicked(bool)), this, SLOT(link()));
}

Win::~Win() {}

void Win::begin() const {
    if (!bsh.getSize()) {
        clearButt->setEnabled(false);
        xportTxtButt->setEnabled(false);
        xportExcelButt->setEnabled(false);
    }
    else {
        clearButt->setEnabled(true);
        xportTxtButt->setEnabled(true);
        xportExcelButt->setEnabled(true);
    }
    refresh();
    checkType();
    checkQuan();
    checkFType();
}

void Win::refresh() const {
    bsh.print(bshList);
    addFrame->setEnabled(true);
    bookFrame->setEnabled(true);
    shopFrame->setEnabled(true);
    cancelFButt->setEnabled(false);
    bshList->resizeColumnToContents(0);
    bshList->resizeColumnToContents(1);
    bshList->resizeColumnToContents(2);
    bshList->resizeColumnToContents(3);
    bshList->resizeColumnToContents(4);
    bshList->resizeColumnToContents(5);
    bshList->resizeColumnToContents(6);
    bshList->resizeColumnToContents(7);
    bshList->resizeColumnToContents(8);
    bshList->resizeColumnToContents(9);
    bshList->resizeColumnToContents(10);
    bshList->resizeColumnToContents(11);
}

void Win::showFilter() {
    switch (filterBox->currentIndex()) {
    case 0:
        filter.filterT(bsh, filterTypeBox->currentIndex());
        break;
    case 1:
        filter.filterA(bsh, filterE->text().toStdString());
        break;
    case 2:
        filter.filterL(bsh, filterE->text().toStdString());
        break;
    case 3:
        filter.filterP(bsh, filterE->text().toStdString());
        break;
    case 4:
        filter.filterY(bsh, yearF1Box->value(), yearF2Box->value());
        break;
    case 5:
        filter.filterP(bsh, priceF1Box->value(), priceF2Box->value());
        break;
    }
    filter.print(bshList);
    addFrame->setEnabled(false);
    bookFrame->setEnabled(false);
    shopFrame->setEnabled(false);
    cancelFButt->setEnabled(true);
    bshList->resizeColumnToContents(0);
    bshList->resizeColumnToContents(1);
    bshList->resizeColumnToContents(2);
    bshList->resizeColumnToContents(3);
    bshList->resizeColumnToContents(4);
    bshList->resizeColumnToContents(5);
    bshList->resizeColumnToContents(6);
    bshList->resizeColumnToContents(7);
    bshList->resizeColumnToContents(8);
    bshList->resizeColumnToContents(9);
    bshList->resizeColumnToContents(10);
    bshList->resizeColumnToContents(11);
}

void Win::checkBook() const {
    if (titleE->text().toStdString() == "" ||
        authorE->text().toStdString() == "" ||
        langE->text().toStdString() == "" ||
        pubE->text().toStdString() == "" ||
        dop1E->text().toStdString() == "")
        addButt->setEnabled(false);
    else if (typeBox->currentIndex() == 1) {
        if (dop2E->text().toStdString() == "")
            addButt->setEnabled(false);
        else addButt->setEnabled(true);
    }
    else addButt->setEnabled(true);
}

void Win::checkType() const {
    dop1E->clear();
    dop2E->clear();
    ageBox->setValue(0);
    switch (typeBox->currentIndex()) {
    case 0:
        dop1L->setText("Area of Study");
        dop2L->setText("");
        dop2E->setVisible(false);
        ageBox->setVisible(false);
        break;
    case 1:
        dop1L->setText("Subject");
        dop2L->setText("Level");
        dop2E->setVisible(true);
        ageBox->setVisible(false);
        break;
    case 2:
        dop1L->setText("Genre");
        dop2L->setText("Age Limit");
        dop2E->setVisible(false);
        ageBox->setVisible(true);
        break;
    }
    checkBook();
}

void Win::checkFilter() const {
    if (filterBox->currentIndex() > 0 && filterBox->currentIndex() < 4 && filterE->text() == "")
        filterButt->setEnabled(false);
    else filterButt->setEnabled(true);
    cancelFButt->setEnabled(false);
}

void Win::checkFType() const {
    filterE->clear();
    switch (filterBox->currentIndex()) {
    case 0:
        filterTypeBox->setVisible(true);
        filterE->setVisible(false);
        yearF1Box->setVisible(false);
        yearF2Box->setVisible(false);
        priceF1Box->setVisible(false);
        priceF2Box->setVisible(false);
        break;
    case 4:
        filterTypeBox->setVisible(false);
        filterE->setVisible(false);
        yearF1Box->setVisible(true);
        yearF2Box->setVisible(true);
        priceF1Box->setVisible(false);
        priceF2Box->setVisible(false);
        break;
    case 5:
        filterTypeBox->setVisible(false);
        filterE->setVisible(false);
        yearF1Box->setVisible(false);
        yearF2Box->setVisible(false);
        priceF1Box->setVisible(true);
        priceF2Box->setVisible(true);
        break;
    default:
        filterTypeBox->setVisible(false);
        filterE->setVisible(true);
        yearF1Box->setVisible(false);
        yearF2Box->setVisible(false);
        priceF1Box->setVisible(false);
        priceF2Box->setVisible(false);
        break;
    }
    checkFilter();
}

void Win::checkQuan() const {
    if (bshList->currentItem()) {
        changeButt->setEnabled(true);
        plusButt->setEnabled(true);
        if (bsh.checkQ(bshList->currentRow())) minusButt->setEnabled(true);
        else minusButt->setEnabled(false);
    }
    else {
        minusButt->setEnabled(false);
        plusButt->setEnabled(false);
        changeButt->setEnabled(false);
    }
}

void Win::clearParam() const {
    titleE->setText("");
    authorE->setText("");
    langE->setText("");
    pubE->setText("");
    yearBox->setValue(yearBox->minimum());
    priceBox->setValue(priceBox->minimum());
    pagesBox->setValue(pagesBox->minimum());
    weightBox->setValue(weightBox->minimum());
    quanBox->setValue(quanBox->minimum());
    dop1E->setText("");
    dop2E->setText("");
    ageBox->setValue(ageBox->minimum());
}

void Win::importTxt() {
    QString path = QFileDialog::getOpenFileName(this, "Import Bookshop From .txt", "C:/Users/User/Desktop/OOP/BookShopPro/Files/", "*.txt");
    bsh.read(path.toStdString());
    begin();
}

void Win::xportTxt() const {
    QString path = QFileDialog::getSaveFileName((QWidget*)this, "Export Bookshop To .txt", "C:/Users/User/Desktop/OOP/BookShopPro/Files/", "*.txt");
    bsh.write(path.toStdString());
    begin();
}

void Win::importExcel() {
    QString path = QFileDialog::getOpenFileName(this, "Import Bookshop From .xlsx", "C:/Users/User/Desktop/OOP/BookShopPro/Files/", "*.xlsx");
    bsh.readX(path.toStdString());
    begin();
}

void Win::xportExcel() const {
    QString path = QFileDialog::getSaveFileName((QWidget*)this, "Export Bookshop To .xlsx", "C:/Users/User/Desktop/OOP/BookShopPro/Files/", "*.xlsx");
    bsh.writeX(path.toStdString());
    begin();
}

void Win::clear() {
    bshList->QAbstractItemView::clearSelection();
    bsh.clear();
    begin();
}

void Win::link() const {

}

void Win::addBook() {
    if (titleE->text().toStdString() == "" ||
        authorE->text().toStdString() == "" ||
        langE->text().toStdString() == "" ||
        pubE->text().toStdString() == "" ||
        dop1E->text().toStdString() == "") {
        return;
    }
    if (bsh[titleE->text().toStdString()] > -1) {
        addMessage.exec();
        clearParam();
        return;
    }
    if (typeBox->currentIndex() == 0) {
        ScienceBook sb(titleE->text().toStdString(), authorE->text().toStdString(),
                       langE->text().toStdString(), pubE->text().toStdString(),
                       yearBox->value(), priceBox->value(), pagesBox->value(),
                       weightBox->value(), quanBox->value(), dop1E->text().toStdString());
        this->bsh.push(sb);
    }
    else if (typeBox->currentIndex() == 1) {
        if (dop2E->text().toStdString() == "")
            return;
        else {
            EducationBook eb(titleE->text().toStdString(), authorE->text().toStdString(),
                             langE->text().toStdString(), pubE->text().toStdString(),
                             yearBox->value(), priceBox->value(), pagesBox->value(),
                             weightBox->value(), quanBox->value(), dop1E->text().toStdString(),
                             dop2E->text().toStdString());
            this->bsh.push(eb);
        }
    }
    else {
        FictionBook fb(titleE->text().toStdString(), authorE->text().toStdString(),
                       langE->text().toStdString(), pubE->text().toStdString(),
                       yearBox->value(), priceBox->value(), pagesBox->value(),
                       weightBox->value(), quanBox->value(), dop1E->text().toStdString(),
                       ageBox->value());
        this->bsh.push(fb);
    }
    clearParam();
    begin();
    addButt->setEnabled(false);
}

void Win::plus() {
    if (bshList->currentItem()) {
        size_t row = bshList->currentRow();
        bsh.incQ(row);
        refresh();
        checkQuan();
        bshList->setCurrentCell(row, 0);
    }
}

void Win::minus() {
    if (bshList->currentItem()) {
        size_t row = bshList->currentRow();
        bsh.decQ(row);
        refresh();
        checkQuan();
        bshList->setCurrentCell(row, 0);
        minusButt->setCursor(Qt::ArrowCursor);
    }
}

void Win::changeQuan() {
    if (bshList->currentItem()) {
        size_t row = bshList->currentRow();
        bsh.changeQ(row, quanDopBox->value());
        quanDopBox->setValue(quanDopBox->minimum());
        refresh();
        checkQuan();
        bshList->setCurrentCell(row, 0);
    }
}
