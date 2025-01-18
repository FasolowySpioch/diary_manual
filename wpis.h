#ifndef WPIS_H
#define WPIS_H
#include <vector>
#include <QApplication>
#include <QDateTimeEdit>
#include <QTextBrowser>
#include <QMessageBox>

class wpis
{
private:
    QDateTime date;
    QString text_input;
    std::vector<wpis> list;
public:
    wpis();
    wpis(QString text_input, QDateTime dateTime_QTformat);
    ~wpis();

    bool operator!=(const wpis& w) const;
    bool operator==(const wpis&w) const;
    bool operator>(const wpis& w) const;
    bool operator<(const wpis& w) const;

    void setDate(QDateTime d);
    void setTextInput(QString s);
    void setSortList(wpis w, bool& iS);

    QDateTime getDate();
    QString getStringDate();
    QString getTextInput();
    std::vector<wpis> getList();
};

#endif // WPIS_H
