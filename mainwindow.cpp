#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_memoSaveButton_clicked()
{
    entry_info.setDate(ui->dateInput->dateTime());
    entry_info.setTextInput(ui->memoryInput->toPlainText());
    entry_info.setSortList(this->entry_info, is_succes);
    qDebug() << is_succes;
    if(is_succes == true) {
        ui->memoryInput->clear();
    }
    else{
        QMessageBox::information(this, "Data już występuje", "Wprowadź ponownie datę");
    }
    is_succes = false;

}

