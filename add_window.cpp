#include "add_window.h"
#include "ui_add_window.h"


Add_window::Add_window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_window)
{
    ui->setupUi(this);
}

Add_window::~Add_window()
{
    delete ui;
}


QString Add_window::getName() const {
    return ui->lineEdit_2->text();  // nameEdit - QLineEdit для имени
}

double Add_window::getWeight() const {
    return ui->lineEdit_3->text().toDouble();  // weightEdit - QLineEdit для веса
}

QString Add_window::getFlavor() const {
    return ui->lineEdit_4->text();  // flavorEdit - QLineEdit для вкуса
}

void Add_window::on_pushButton_clicked()
{
    this->accept();
}

void Add_window::on_pushButton_2_clicked()
{
    this->close();
}

