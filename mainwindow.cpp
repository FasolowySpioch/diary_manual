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
    qDebug() << "I AM CLICKED";
    //QString tekst = ui->memoryDisplay->toPlainText();
    //qDebug().noquote() << "TEKST Z memoryDisplay" << tekst;s
    //QMessageBox::information(this, "Tekst z QTextBrowser", tekst);
    entry_info.setDate(ui->dateInput->dateTime());
    qDebug() << "WPROWADZONA DATA: " << entry_info.getDate();
    entry_info.setTextInput(ui->memoryInput->toPlainText());
    qDebug() << "WPROWADZONY TEXT: " << entry_info.getTextInput();

}

