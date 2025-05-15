#include "edit_window.h"
#include "ui_edit_window.h"

Edit_window::Edit_window(QWidget *parent, const QString& name, double weight, const QString& flavor)
    : QDialog(parent)
    , ui(new Ui::Edit_window)
{
    ui->setupUi(this);
    ui->lineEdit_5->setText(name);
    ui->lineEdit_6->setText(QString::number(weight));
    ui->lineEdit_7->setText(flavor);
}

Edit_window::~Edit_window()
{
    delete ui;
}

QString Edit_window::getName() const {
    return ui->lineEdit_5->text();
}

double Edit_window::getWeight() const {
    return ui->lineEdit_6->text().toDouble();
}

QString Edit_window::getFlavor() const {
    return ui->lineEdit_7->text();
}
void Edit_window::on_pushButton_3_clicked()
{
    this->accept();
}


void Edit_window::on_pushButton_4_clicked()
{
    this->close();
}

