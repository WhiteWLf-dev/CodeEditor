#ifndef REPLACESEARCH_H
#define REPLACESEARCH_H
#include <QDialog>
#include <QLineEdit>
class ReplaceSearch: public QDialog{

    Q_OBJECT

public:

    ReplaceSearch();
    QString line();
    QString replace_area();

private:

    QLineEdit* Word;
    QLineEdit* replaceWord;
    QPushButton *ok;

private slots:

   void Replace();

signals:

    void SignalofReplace();
};

#endif // REPLACESEARCH_H
