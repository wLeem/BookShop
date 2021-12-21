#ifndef MAINWIN_H
#define MAINWIN_H

#include <QApplication>
#include <QLayout>
#include <QFrame>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "bookshop.h"

class Win : public QWidget {
    Q_OBJECT

protected:
    QMessageBox addMessage;
    QFrame *shopFrame, *addFrame, *bookFrame, *filterFrame;
    QLabel *typeL, *titleL, *authorL, *langL, *pubL, *yearL, *priceL, *pagesL,
    *weightL, *quanL, *dop1L, *dop2L, *editQuanL, *filterL;
    QLineEdit *titleE, *authorE, *langE, *pubE, *dop1E, *dop2E, *filterE;
    QPushButton *xportTxtButt, *xportExcelButt, *importTxtButt, *importExcelButt,
    *clearButt, *linkButt, *addButt, *clearBookButt, *changeButt, *plusButt, *minusButt,
    *filterButt, *cancelFButt;;
    QComboBox *typeBox, *filterBox, *filterTypeBox;
    QSpinBox *yearBox, *pagesBox, *weightBox, *quanBox, *dopBox, *quanDopBox, *ageBox,
    *yearF1Box, *yearF2Box;
    QDoubleSpinBox *priceBox, *priceF1Box, *priceF2Box;
    QTableWidget *bshList;
    QGridLayout *layout, *shopLayout, *addLayout, *bookLayout, *filterLayout;
    BookShop bsh, filter;

public:
    Win(QWidget* parent = 0);
    ~Win();

    void begin() const;

public slots:
    void refresh() const;
    void checkBook() const;
    void checkType() const;
    void checkFType() const;
    void checkQuan() const;
    void checkFilter() const;
    void showFilter();
    void clearParam() const;
    void importTxt();
    void xportTxt() const;
    void importExcel();
    void xportExcel() const;
    void clear();
    void link() const;
    void addBook();
    void plus();
    void minus();
    void changeQuan();
};

#endif // MAINWIN_H
