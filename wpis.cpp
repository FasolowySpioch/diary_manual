#include "wpis.h"
using namespace std;

wpis::wpis() {}
wpis::wpis(QString text_input, QDateTime dateTime_QTformat){
    setDate(dateTime_QTformat);
    setTextInput(text_input);
}
wpis::~wpis() {}

bool wpis::operator==(const wpis& w) const{
    return w.date == this->date;
}
bool wpis::operator!=(const wpis& w) const{ //idk czemu nie działa, wywala mi błąd jak bawie się wektorami więc jest to martwe ;-; => problemem był const spojler
    return w.date != this->date;
}
bool wpis::operator>(const wpis& w) const{
    return w.date > this->date;
}
bool wpis::operator<(const wpis& w) const{
    return w.date < this->date;
}


void wpis::setDate(QDateTime d){
    this->date = d;
}
void wpis::setTextInput(QString s) {
    this->text_input = s;
}

QDateTime wpis::getDate() {return this->date;}
QString wpis::getTextInput() {return this->text_input; }
QString wpis::getStringDate(){return this->date.toString(); }
std::vector<wpis> wpis::getList() {return this->list; }

void wpis::setSortList(wpis w, bool& iS) {
    if(this->list.empty()) {this->list.push_back(w); iS = true; qDebug() << "DODANO 1 WPIS";
    }
    else{
        for(wpis i : this->list){
            if(i == w ){
                qDebug() << "DATA JUŻ WYSTĘPUJE";
                iS = false;
                return;
            }
        }
        qDebug() << "POPRAWNA DATA";
        this->list.push_back(w);
        iS = true;
    }
}
