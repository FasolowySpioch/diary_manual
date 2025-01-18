#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "wpis.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    wpis entry_info;
    bool is_succes=false; //zmienna do sprawdzenia czy użytkownik wprowadził poprawną datę
    //std::vector<wpis> sort;


private slots:
    void on_memoSaveButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
