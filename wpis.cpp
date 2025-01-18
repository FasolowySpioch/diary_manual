#include "wpis.h"
using namespace std;

//KONSTRUKTORY I DESTRUKTORY
wpis::wpis() {}
wpis::wpis(QString text_input, QDateTime dateTime_QTformat){
    setDate(dateTime_QTformat);
    setTextInput(text_input);
}
wpis::~wpis() {}

//PRZECIĄŻENIE OPERATORÓW
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

//GET SET
void wpis::setDate(QDateTime d){ this->date = d; }
void wpis::setTextInput(QString s) { this->text_input = s;}

QDateTime wpis::getDate() {return this->date;}
QString wpis::getTextInput() {return this->text_input; }
QString wpis::getStringDate(){return this->date.toString(); }
std::vector<wpis> wpis::getList() {return this->list; }

//RESZTA
void wpis::setSortList(wpis w /*bool& iS*/) { //sortuje i dodaje do vekrora posortowane obiekty
    if(this->list.empty()) {this->list.push_back(w); qDebug() << "DODANO 1 WPIS";
    }
    else{
        for(wpis& i : this->list){
            if(i == w ){
                //qDebug() << "DATA JUŻ WYSTĘPUJE";
                i.setTextInput(w.getTextInput());
                /*for(wpis a : this->list){
                    qDebug() << "POSORTOWANE WPISY:" << a.getDate().toString() << "\tTEXT: " <<a.getTextInput();
                }*/
                return;
            }
        }
        //qDebug() << "POPRAWNA DATA";
        this->list.push_back(w);
        sortNewList();
        /*for(wpis i : this->list){
            qDebug() << "POSORTOWANE WPISY:" << i.getDate().toString() << "\tTEXT: " <<i.getTextInput();;
        }*/
    }
}

void wpis::sortNewList() { std::sort(this->list.begin(), this->list.end(), [](wpis& w1, wpis& w2) {return w1.getDate() > w2.getDate(); }); qDebug() << "NEWLIST"; } //Nowe wpisy na górze
void wpis::sortOldList() { std::sort(this->list.begin(), this->list.end(), [](wpis& w1, wpis& w2) {return w1.getDate() < w2.getDate(); }); qDebug() << "OLDLIST"; } //Stare daty na górze
