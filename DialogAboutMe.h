#ifndef DIALOGABOUTME_H
#define DIALOGABOUTME_H
#include "mainwindow.h"
#include "QMenuBar"
#include "QMenu"
#include "QDialog"
#include "QPushButton"
#include "QLineEdit"
#include "QBoxLayout"
#include "QLabel"
#include "QListWidget"
class DialogAboutMe : public QDialog {

    Q_OBJECT

public:
    DialogAboutMe( QWidget* parent = 0 );
    ~DialogAboutMe();

private:
    QBoxLayout* layout;
    QLabel *imageLabel;
    QListWidget *lw;
    QPushButton *accept;
};


#endif // DIALOGABOUTME_H
