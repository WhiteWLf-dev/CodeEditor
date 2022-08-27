#include "Syntax.h"
#include <QFile>
Syntax::Syntax(): QDialog(0){
    setWindowIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\changesw.png"));
    setWindowTitle("Change highlight syntax");
    change = new QPushButton("Change");
    download = new QPushButton("Download");
    default_ = new QPushButton("Default");
    connect(change,SIGNAL(clicked()),this,SLOT(accept1()));
    connect(default_,SIGNAL(clicked()),this,SLOT(Default()));
    connect(download,SIGNAL(clicked()),this,SLOT(Download()));
    keywords = new QLabel("Keywords");
    functions = new QLabel("Functions");
    classFormat = new QLabel("Classes");
    key = new QLineEdit;
    func = new QLineEdit;
    class_ = new QLineEdit;
    QGridLayout* l = new QGridLayout;
    l -> addWidget(key,0,1);
    l -> addWidget(func,1,1);
    l -> addWidget(class_,2,1);
    l -> addWidget(keywords,0,0);
    l -> addWidget(functions,1,0);
    l -> addWidget(classFormat,2,0);
    l ->addWidget(default_,3,0);
    l ->addWidget(change,3,1);
    l ->addWidget(download,3,2);
    bool a=1;
    for (int i=1;a;i++){
         QString b="Style"+QString::number(i)+".txt";
         QFile f(b);
        if (f.open(QIODevice::ReadOnly))
        {
          QPushButton *t=new QPushButton("Style"+QString::number(i));
          t->setObjectName("Style"+QString::number(i));
          connect(t,SIGNAL(clicked()),this,SLOT(Download1()));
          l->addWidget(t);
        }
        else a=0;
    }
    QPushButton *m=new QPushButton("config");
    m->setObjectName("config");
    connect(m,SIGNAL(clicked()),this,SLOT(Download1()));
    l->addWidget(m);

    setLayout(l);
}
void Syntax::accept1(){
    QFile file("config.txt");

    if (file.open(QIODevice::WriteOnly)){
            file.resize(0);
            file.write((key->text()+func->text()+class_->text()).toUtf8());
            file.flush();
            file.close();
    }
    accept();
}
void Syntax::Default(){
    key->setText("#ff00ff");
    class_->setText("#0000ff");
    func->setText("#800080");
    accept();
}
void Syntax::Download1(){

    QString a=QString(QObject::sender()->objectName());
    a+=".txt";
    name=a;

    QFile f(a);
    f.open(QIODevice::ReadOnly);

    QByteArray data = f.readAll();
    QString s = QString::fromUtf8(data);
    QString key_="",func_="",classs="";
    for (int i=0;i<s.size()/3;i++){
        key_.append(s[i]);
    }
   for (int i=7;i<14;i++){
        func_.append(s[i]);
    }
    for (int i=14;i<21;i++){
       classs.append(s[i]);
    }
    key->setText(key_);
    func->setText(func_);
    class_->setText(classs);

    accept();
}
void Syntax::Download(){
    QString a=QFileDialog::getOpenFileName();
    name=a;

    QFile f(a);
    f.open(QIODevice::ReadOnly);

    QByteArray data = f.readAll();
    QString s = QString::fromUtf8(data);
    QString key_="",func_="",classs="";
    for (int i=0;i<s.size()/3;i++){
        key_.append(s[i]);
    }
   for (int i=7;i<14;i++){
        func_.append(s[i]);
    }
    for (int i=14;i<21;i++){
       classs.append(s[i]);
    }
    key->setText(key_);
    func->setText(func_);
    class_->setText(classs);

    accept();
}
