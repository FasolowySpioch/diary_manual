#include "wpis.h"
using namespace std;

wpis::wpis() {}
wpis::wpis(QString text_input, QDateTime dateTime_QTformat){
    setDate(dateTime_QTformat);
    setTextInput(text_input);
}
wpis::~wpis() {}

bool wpis::operator==(const wpis& w){
    if(w.date == this->date) {return true;}
    else {return false;}
}
bool wpis::operator!=(const wpis& w){
    return !operator==(w);
}
bool wpis::operator>(const wpis& w){
    if(w.date > this->date) {return true;}
    else {return false;}
}
bool wpis::operator<(const wpis& w){
    return !operator>(w);
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
