#include "ReplaceSearch.h"
#include "QPushButton"
#include "QGridLayout"
#include "QLabel"
ReplaceSearch::ReplaceSearch(){
    setWindowTitle("Search word and replace");
    setWindowIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\find3.jpg"));
    Word = new QLineEdit;
    replaceWord = new QLineEdit;
    ok = new QPushButton("Replace");

    QLabel *a=new QLabel("Find:");
    QLabel *b=new QLabel("Replace on:");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(Word,1,0);
    layout->addWidget(a,0,0);
    layout->addWidget(replaceWord,3,0);
    layout->addWidget(b,2,0);
    layout->addWidget(ok,4,0);
    setLayout(layout);

    connect(ok, SIGNAL(clicked()),SLOT(Replace()));
}
QString ReplaceSearch::line(){
    return Word->text();
}

QString ReplaceSearch::replace_area(){
    return replaceWord->text();
}

void ReplaceSearch::Replace(){
    emit SignalofReplace();
}


