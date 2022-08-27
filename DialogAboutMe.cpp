#include "DialogAboutMe.h"
#include "QMenuBar"
#include "QMenu"
#include "QDialog"
#include "QPushButton"
#include "QLineEdit"
#include "QBoxLayout"
#include "QLabel"
#include "QFrame"
#include "QListWidget"
#include "QString"
#include <QGridLayout>
DialogAboutMe::DialogAboutMe( QWidget* parent ) : QDialog(parent) {
    setWindowTitle("Info");
    setWindowIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\help.jpg"));
    layout = new QHBoxLayout;
    QGridLayout *l=new QGridLayout;


    imageLabel=new QLabel;
    QPixmap myPixmap=QPixmap("C:\\Users\\The Witcher Hunt\\Documents\\build-labaWORD-Desktop_x86_windows_msvc2019_pe_64bit-Debug\\image.png");
    imageLabel->setPixmap( myPixmap );
    layout->addWidget(imageLabel);

    lw = new QListWidget(this);

        lw->addItem("Author:");
        lw->addItem("Ushakov Aleksandr Nikolaevich SCS201");
        lw->addItem("Build date:");
        lw->addItem(__DATE__);
        lw->addItem(__TIME__);
        lw->addItem("The version of Qt that I was going to use:");
        lw->addItem(QT_VERSION_STR);
        lw->addItem("The version of Qt that is running:");
        lw->addItem(qVersion());

    accept=new QPushButton("OK", this);
    connect(accept, SIGNAL(clicked()), this, SLOT(accept()));
    layout->addWidget(lw);
    l->addLayout(layout,0,0);
    l->addWidget(accept,1, 0);
    setLayout(l);

}
DialogAboutMe::~DialogAboutMe() {
}
