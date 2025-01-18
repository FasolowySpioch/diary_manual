#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->memoryDisplay->append("<b> WSPOMNIENIA </b>");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_memoSaveButton_clicked()
{
    entry_info.setDate(ui->dateInput->dateTime());
    entry_info.setTextInput(ui->memoryInput->toPlainText());
    entry_info.setSortList(this->entry_info);
    displayOnMemo();
}

void MainWindow::displayOnMemo(){
    ui->memoryInput->clear();
    ui->memoryDisplay->clear();
    QString html_style = R"(
        <style>
        .date_txt_format {
            text-align:left;
        }
        .devider_format hr{
            text-align:center;
        }
        </style>
    )";
    for(wpis& i : entry_info.getList()){
        html_style += QString(R"(<div class="date_txt_format"> <b>Data: </b>%1<br><b>Treść: </b>%2 <hr> </div>)").arg(i.getStringDate(), i.getTextInput());
    }
    ui->memoryDisplay->setHtml(html_style);
}

void MainWindow::on_oldSortButton_clicked()
{
    entry_info.sortOldList();
    displayOnMemo();
}


void MainWindow::on_newSortButton_clicked()
{
    entry_info.sortNewList();
    displayOnMemo();
}

