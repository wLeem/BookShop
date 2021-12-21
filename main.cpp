#include "mainwin.h"

int main(int argc, char *argv[]){

#if SHOW_GUI
    QApplication a(argc, argv);
    Win w;
    w.show();
    return a.exec();
#else
    return 0;
#endif
}
