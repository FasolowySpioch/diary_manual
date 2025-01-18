#ifndef WPIS_H
#define WPIS_H
#include <vector>
#include <QApplication>
#include <QDateTimeEdit>
#include <QTextBrowser>

class wpis
{
private:
    QDateTime date; //data z ostatniego wpisu przed kliknięciem zapisz
    QString text_input; //temp przed zapisaniem
    //std::vector<QString> all_tedt_sorted; //Przechowuje wszystkie dodane wpisy już posortowane datą
    std::vector<QDateTime> dates;
    std::vector<QString> texts;
public:
    wpis();
    wpis(QString text_input, QDateTime dateTime_QTformat);
    ~wpis();

    bool operator!=(const wpis& w);
    bool operator==(const wpis&w);
    bool operator>(const wpis& w);
    bool operator<(const wpis& w);

    //std::vector<std::string> getVectorTEDT();
   // void setVectorTEDT();

   // std::string importToTextBrowser();

    void setDate(QDateTime d);
    void setTextInput(QString s);

    QDateTime getDate();
    QString getStringDate();
    QString getTextInput();
};

#endif // WPIS_H
