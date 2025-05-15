#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_window.h"
#include "edit_window.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTotalWeight() {
    ui->totalWeightEdit->setText(QString(" %1 г").arg(totalWeight));
}

void MainWindow::on_pushButton_2_clicked()
{

    Add_window window(this);

    if(window.exec() == QDialog::Accepted){

        QString name = window.getName();
        double weight = window.getWeight();
        QString flavor = window.getFlavor();

        QString itemText = QString("%1 (%2г, %3)")
                           .arg(name)
                           .arg(weight)
                           .arg(flavor);

    // Добавляем в QListWidget
    ui->sweetsList->addItem(itemText);
          // sweetsList - имя QListWidget в UI
    totalWeight+=weight;
    updateTotalWeight();
    }
}




void MainWindow::on_pushButton_3_clicked()
{
    int currentRow = ui->sweetsList->currentRow();
    if (currentRow < 0) return; // Проверка на выбор элемента

    QString currentText = ui->sweetsList->item(currentRow)->text();

    // Парсим текущие данные
    QRegularExpression regex("^(.*?) \\((\\d+\\.?\\d*)г, (.*?)\\)$");
    QRegularExpressionMatch match = regex.match(currentText);
    if (!match.hasMatch()) return;

    double oldWeight = match.captured(2).toDouble(); // Запоминаем старый вес

    // Создаём диалог редактирования
    Edit_window dialog(this,
                       match.captured(1),  // name
                       oldWeight,         // weight
                       match.captured(3)); // flavor

    if (dialog.exec() == QDialog::Accepted) {
        double newWeight = dialog.getWeight();

        // Обновляем totalWeight
        totalWeight = totalWeight - oldWeight + newWeight;

        // Формируем обновлённую строку
        QString updatedText = QString("%1 (%2г, %3)")
                                  .arg(dialog.getName())
                                  .arg(newWeight)
                                  .arg(dialog.getFlavor());

        // Обновляем элемент в списке
        ui->sweetsList->item(currentRow)->setText(updatedText);
        updateTotalWeight();
    }
}


void MainWindow::on_pushButton_clicked()
{
    int currentRow = ui->sweetsList->currentRow();


    // Получаем текст удаляемого элемента
    QString itemText = ui->sweetsList->item(currentRow)->text();

    // Парсим вес из строки формата "Название (весг, вкус)"
    QRegularExpression regex("\\((\\d+\\.?\\d*)г");
    QRegularExpressionMatch match = regex.match(itemText);

    if (match.hasMatch()) {
        double weight = match.captured(1).toDouble();
        totalWeight -= weight;  // Уменьшаем общий вес
    }

    // Удаляем элемент из списка
    delete ui->sweetsList->takeItem(currentRow);

    // Обновляем отображение общего веса
    updateTotalWeight();
}


void MainWindow::on_checkBox_clicked()
{

}

