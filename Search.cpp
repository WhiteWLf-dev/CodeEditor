#include "Search.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
Search::Search(): QDialog(0)
{
    setWindowTitle("Search word");
    setWindowIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\find3.jpg"));
    QLabel *l=new QLabel("Find:");
    word = new QLineEdit;
    ok = new QPushButton("OK");
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(l);
    layout->addWidget(word,1,0);
    layout->addWidget(ok,2,0);
    setLayout(layout);
    connect(ok, SIGNAL(clicked()),SLOT(accept()));

}
QString Search::Line(){
    return word->text();
}
