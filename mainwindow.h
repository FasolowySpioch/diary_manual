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

private slots:
    void on_memoSaveButton_clicked();

    void on_oldSortButton_clicked();

    void on_newSortButton_clicked();

    void displayOnMemo();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
