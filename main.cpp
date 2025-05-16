#include "mainwindow.h"
#include <QApplication>

  // "example" - префикс для пути к тестам
// ==================== Точка входа ====================
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}

