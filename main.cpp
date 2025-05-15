#include "mainwindow.h"
#include <QApplication>

// ==================== Точка входа ====================
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

