#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_window.h"
#include "edit_window.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    totalWeight = 0.0; // Инициализация общего веса
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTotalWeight() {
    ui->totalWeightEdit->setText(QString(" %1 г").arg(totalWeight));
}

void MainWindow::on_pushButton_2_clicked() // Добавление элемента
{
    Add_window window(this);

    if(window.exec() == QDialog::Accepted){
        QString name = window.getName();
        double weight = window.getWeight();
        QString flavor = window.getFlavor();

        // Проверка на отрицательный вес
        if(weight <= 0) {
            QMessageBox::warning(this, "Ошибка", "Вес должен быть положительным числом");
            return;
        }

        QString itemText = QString("%1 (%2г, %3)").arg(name).arg(weight).arg(flavor);
        ui->sweetsList->addItem(itemText);
        totalWeight += weight;
        updateTotalWeight();
    }
}

void MainWindow::on_pushButton_3_clicked() // Редактирование элемента
{
    int currentRow = ui->sweetsList->currentRow();
    if (currentRow < 0) {
        QMessageBox::information(this, "Информация", "Выберите элемент для редактирования");
        return;
    }

    QString currentText = ui->sweetsList->item(currentRow)->text();
    QRegularExpression regex("^(.*?) \\((\\d+\\.?\\d*)г, (.*?)\\)$");
    QRegularExpressionMatch match = regex.match(currentText);
    if (!match.hasMatch()) return;

    double oldWeight = match.captured(2).toDouble();
    Edit_window dialog(this, match.captured(1), oldWeight, match.captured(3));

    if (dialog.exec() == QDialog::Accepted) {
        double newWeight = dialog.getWeight();

        // Проверка на отрицательный вес
        if(newWeight <= 0) {
            QMessageBox::warning(this, "Ошибка", "Вес должен быть положительным числом");
            return;
        }

        totalWeight = totalWeight - oldWeight + newWeight;
        QString updatedText = QString("%1 (%2г, %3)")
                                  .arg(dialog.getName())
                                  .arg(newWeight)
                                  .arg(dialog.getFlavor());
        ui->sweetsList->item(currentRow)->setText(updatedText);
        updateTotalWeight();
    }
}

void MainWindow::on_pushButton_clicked() // Удаление элемента
{
    int currentRow = ui->sweetsList->currentRow();
    if (currentRow < 0 || currentRow >= ui->sweetsList->count()) {
        QMessageBox::information(this, "Информация", "Выберите элемент для удаления");
        return;
    }

    QListWidgetItem* item = ui->sweetsList->item(currentRow);
    if (!item) return;

    QString itemText = item->text();
    QRegularExpression regex("\\((\\d+\\.?\\d*)г");
    QRegularExpressionMatch match = regex.match(itemText);

    if (match.hasMatch()) {
        double weight = match.captured(1).toDouble();
        totalWeight -= weight;
        if (totalWeight < 0) totalWeight = 0; // Защита от отрицательного веса
    }

    delete ui->sweetsList->takeItem(currentRow);
    updateTotalWeight();
}
