#ifndef SYNTAX_H
#define SYNTAX_H
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include "highlighter.h"

class Syntax: public QDialog{

    Q_OBJECT


public:
    Syntax();
    QString name="";
    QString b="";
    QLabel* keywords;
    QLabel* functions;
    QLabel* classFormat;
    QPushButton* change;
    QPushButton* download;
    QPushButton* default_;
    QLineEdit* key ;
    QLineEdit* func ;
    QLineEdit* class_ ;
private slots:
    void Default();
    void Download();
    void Download1();
    void accept1();

};
#endif // SYNTAX_H
