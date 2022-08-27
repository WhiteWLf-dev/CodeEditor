#ifndef SEARCH_H
#define SEARCH_H
#include <QDialog>
#include <QLineEdit>
class Search : public QDialog{

    Q_OBJECT

public:
    Search();
    QString Line();


private:
    QLineEdit *word;
    QPushButton *ok;

};
#endif // SEARCH_H
