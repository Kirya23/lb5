#ifndef EDIT_WINDOW_H
#define EDIT_WINDOW_H

#include <QDialog>

namespace Ui {
class Edit_window;
}

class Edit_window : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_window(QWidget *parent = nullptr,
                         const QString& name = "",
                         double weight = 0.0,
                         const QString& flavor = "");
    ~Edit_window();

    QString getName() const;
    double getWeight() const;
    QString getFlavor() const;
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Edit_window *ui;
};

#endif // EDIT_WINDOW_H
