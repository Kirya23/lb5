#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

#include <QDialog>

namespace Ui {
class Add_window;
}

class Add_window : public QDialog
{
    Q_OBJECT

public:
    explicit Add_window(QWidget *parent = nullptr);
    ~Add_window();
    QString getName() const;
    double getWeight() const;
    QString getFlavor() const;

private slots:

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Add_window *ui;
};

#endif // ADD_WINDOW_H
