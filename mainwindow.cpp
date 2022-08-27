#include "mainwindow.h"
#include "Search.h"
#include "DialogAboutMe.h"
#include "QMenuBar"
#include "QMenu"
#include "QDialog"
#include "QPushButton"
#include "QLabel"
#include "CodeEditor.h"
#include <QStatusBar>
#include <QApplication>
#include <QFontDialog>
#include <QMessageBox>
#include <QClipboard>
#include "ReplaceSearch.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QToolBar>
#include <QToolButton>
#include <highlighter.h>
#include <QActionGroup>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\word.png"));
    setWindowTitle(tr("[*]%1 - %2").arg("untilted").arg("Laboratory work 5"));
    editor=new CodeEditor(this);
    editor->name=this->name;
    search=new Search;
    rsearch=new ReplaceSearch;
    syntax=new Syntax;
    toolbar = addToolBar("main toolbar");
    setCentralWidget(editor);
    editor->setFocus();
    MenuFile = menuBar()->addMenu("&File");
    MenuEdit = menuBar()->addMenu("&Edit");
    MenuFormat=menuBar()->addMenu("&Format");
    MenuView=menuBar()->addMenu("&View");
    MenuHelp=menuBar()->addMenu("&Help");

    New=MenuFile->addAction("New");
    connect(New,SIGNAL(triggered()),this,SLOT(New_()));
    Open=(*MenuFile).addAction("Open");
    connect(Open,SIGNAL(triggered()),this,SLOT(Open_()));
    Save=MenuFile->addAction("Save");
    connect(Save,SIGNAL(triggered()),this,SLOT(Save_()));
    Save_as=MenuFile->addAction("Save as");
    connect(Save_as,SIGNAL(triggered()),this,SLOT(Save_As_()));
    Exit=MenuFile->addAction("&Exit");
    connect(Exit, SIGNAL(triggered()), this, SLOT(exit()));

    Cancel=MenuEdit->addAction("Undo");
    connect(Cancel, SIGNAL(triggered()), editor, SLOT(undo1()));
    Repeat=MenuEdit->addAction("Redo");
    connect(Repeat, SIGNAL(triggered()), editor, SLOT(redo1()));
    Copy=MenuEdit->addAction("Copy");
    connect(Copy, SIGNAL(triggered()), editor, SLOT(copy()));
    Cut=MenuEdit->addAction("Cut");
    connect(Cut, SIGNAL(triggered()), editor, SLOT(cut()));
    Paste=MenuEdit->addAction("Paste");
    connect(Paste, SIGNAL(triggered()), editor, SLOT(paste()));
    Find=MenuEdit->addAction("Find");
    connect(Find,SIGNAL(triggered()), this, SLOT(ActiveSearch()));
    Find_and_replace=MenuEdit->addAction("Find and Replace");
    connect(Find_and_replace,SIGNAL(triggered()),this,SLOT(SearchandReplace()));
    Highlight=MenuEdit->addAction("Select all");
    connect(Highlight, SIGNAL(triggered()), editor, SLOT(selectAll()));


    Perenos=MenuFormat->addAction("Word wrap");
    MenuFormat->actions().back()->setCheckable(true);
    Perenos->setChecked(true);
    connect(Perenos,SIGNAL(triggered()),this,SLOT(WrapWord()));
    Font=MenuFormat->addAction("Font Selection");
    connect(Font,SIGNAL(triggered()),this,SLOT(SetFontSelection()));


    ColorBackground=MenuView->addAction("Background color selection");
    connect(ColorBackground,SIGNAL(triggered()),this,SLOT(SetColorBackground()));
    ColorCurString=MenuView->addAction("Selecting the color of the current line");
    connect(ColorCurString,SIGNAL(triggered()),this,SLOT(ChangeColorLine()));
    SwitcherNumeration=MenuView->addAction("On/Off line numbering display");
    MenuView->actions().back()->setCheckable(true);
    SwitcherNumeration->setChecked(true);
    connect(SwitcherNumeration,SIGNAL(triggered()),this,SLOT(HideNumberArea()));
    SwitcherPanel=MenuView->addAction("On/Off toolbar display");
    MenuView->actions().back()->setCheckable(true);
    SwitcherPanel->setChecked(true);
    connect(SwitcherPanel,SIGNAL(triggered()),this,SLOT(HideToolBar()));
    SwitcherStatus=MenuView->addAction("On/Off status bar display");
    MenuView->actions().back()->setCheckable(true);
    connect(SwitcherStatus,SIGNAL(triggered()),this,SLOT(HideStatusBar()));
    SwitcherStatus->setChecked(true);
    SwitcherHightlighter=MenuView->addAction("On/off syntaxic highlight");
    MenuView->actions().back()->setCheckable(true);
    SwitcherHightlighter->setChecked(true);
   // SwitcherHightlighter->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\swhl.png"));
    connect(SwitcherHightlighter,SIGNAL(triggered()),this,SLOT(HideHighlighter()));


    QMenu* m = new QMenu( "Switcher Highlight", this);
    m->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\swhl.png"));
    group = new QActionGroup(this);
    C11 = new QAction( "C 11", this);
    C11 ->setCheckable(true);
    connect(C11,SIGNAL(triggered()),this,SLOT(v11()));
    C18 = new QAction( "С 18", this);
    C18 ->setCheckable(true);
    connect(C18,SIGNAL(triggered()),this,SLOT(v18()));
    Cpp14 = new QAction( "C++ 14", this);
    Cpp14 ->setCheckable(true);
    connect(Cpp14,SIGNAL(triggered()),this,SLOT(v14()));
    C17 = new QAction( "C++ 17", this);
    C17 ->setCheckable(true);
    connect(C17,SIGNAL(triggered()),this,SLOT(v17()));
    C20 = new QAction( "C++ 20", this);
    C20->setCheckable(true);
    C20->setChecked(true);
    connect(C20,SIGNAL(triggered()),this,SLOT(v20()));

    group->addAction(C11);
    group->addAction(C18 );
    group->addAction(Cpp14);
    group->addAction(C17);
    group->addAction(C20);
    m->addActions(group->actions());
    Hightlighter=MenuView->addMenu(m);
    MenuView->actions().back()->setCheckable(true);
    cSyn=MenuView->addAction("Change syntax");
    cSyn->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\changesw.png"));
    connect(cSyn,SIGNAL(triggered()),this,SLOT(cSyntax()));


    AboutProgram=MenuHelp->addAction("About the program");
    connect(AboutProgram, SIGNAL(triggered()), this, SLOT(showAboutProgram()));

    len = new QLabel("Lines Count: " + QString::number(editor->document()->blockCount())+" "

                         +  " Words Count: "+ QString::number(editor->toPlainText().split(QRegularExpression("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count())
                         + " " + "Simbols Count: " + QString::number(editor->toPlainText().size())
                         +" | "+ QString::number(floor(double(1024*(editor->toPlainText().size())*8)/1024 + 0.5)/1024)+" KB" );

   curPos = new QLabel("Line: "+QString::number((editor->textCursor().blockNumber()))+" "
                             + "Column: " +QString::number(editor->textCursor().positionInBlock()));
   last_change = new QLabel("Default");
   tool();

    statusBar()->addWidget(curPos);
    statusBar()->addWidget(last_change);
    statusBar()->addWidget(len);
    connect(editor,SIGNAL(cursorPositionChanged()),this ,SLOT(RefreshStatusBar()));
    connect(editor,SIGNAL(cursorPositionChanged()),this ,SLOT(RefreshZv()));
     highlighter = new Highlighter(editor->document(),5);
}
void MainWindow::cSyntax(){
syntax->key->setText(((highlighter->getKeywordColor()).color()).name());
syntax->func->setText(((highlighter->getFunctionColor()).color()).name());
syntax->class_->setText(((highlighter->getClassColor()).color()).name());
syntax->exec();
QColor a;
a.setNamedColor(syntax->key->text());
QColor b;
b.setNamedColor(syntax->func->text());
QColor c;
c.setNamedColor(syntax->class_->text());
int k=highlighter->number;
delete highlighter;
highlighter =new Highlighter(editor->document(),k,a,b,c);
if (!syntax->name.isEmpty())
//setWindowTitle(syntax->name);
setCurName(syntax->name);
//QFile file("config.txt");

//if (file.open(QIODevice::WriteOnly)){
//        file.resize(0);
//        file.write((syntax->key->text()+syntax->func->text()+syntax->class_->text()).toUtf8());
//        file.flush();
//        file.close();
//}
update();
}
void MainWindow::v11(){
    highlighter = new Highlighter(editor->document(),1);
}

void MainWindow::v18(){
    highlighter = new Highlighter(editor->document(),2);
}

void MainWindow::v14(){
    highlighter = new Highlighter(editor->document(),3);
}

void MainWindow::v17(){
    highlighter = new Highlighter(editor->document(),4);
}

void MainWindow::v20(){
    highlighter = new Highlighter(editor->document(),5);
}
void MainWindow::RefreshZv(){
    setWindowModified(true);
}
void MainWindow::HideToolBar(){
if (SwitcherPanel->isChecked()==false)
    toolbar->hide();
else
    toolbar->show();
}
void MainWindow::HideHighlighter(){
        if (SwitcherHightlighter->isChecked()==false){
            delete highlighter;
        }

        else if (C11->isChecked()==true && SwitcherHightlighter->isChecked()== true){
            highlighter = new Highlighter(editor->document(),1);

        }
        else if(C18->isChecked()==true && SwitcherHightlighter->isChecked()== true){
            highlighter = new Highlighter(editor->document(),2);

        }
        else if(Cpp14->isChecked()==true && SwitcherHightlighter->isChecked()== true){
            highlighter = new Highlighter(editor->document(),3);

        }
        else if(C17->isChecked()==true && SwitcherHightlighter->isChecked()== true){
            highlighter = new Highlighter(editor->document(),4);

        }
        else if(C20->isChecked()==true && SwitcherHightlighter->isChecked()== true){
            highlighter = new Highlighter(editor->document(),5);

        }
}
void MainWindow::tool(){
   New->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
   toolbar->addAction(New);
   Open->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\open.png"));
   toolbar->addAction(Open);
   Save->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
   toolbar->addAction(Save);
   Cancel->setIcon(style()->standardIcon(QStyle::SP_ArrowLeft));
   toolbar->addAction(Cancel);
   Repeat->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));
   toolbar->addAction(Repeat);
   Copy->setIcon(style()->standardIcon(QStyle::SP_DialogResetButton));
   toolbar->addAction(Copy);
   Cut->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\cut.png"));
   toolbar->addAction(Cut);
   Paste->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\paste.jpg"));
   toolbar->addAction(Paste);
   Save_as->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\save_as.png"));
   Exit->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\exit.jpg"));
   Font->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\font.png"));
   ColorBackground->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\color1.png"));
   ColorCurString->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\color2.png"));
   Find->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\find.png"));
   Find_and_replace->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\find1.jpg"));
   AboutProgram->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\help.jpg"));
   Highlight->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\selectall.png"));
   QMenu *toolButton_menu = new QMenu("Find/Find and Replace");
   QToolButton* toolButton = new QToolButton();
   toolButton_menu->addAction(Find);
   toolButton_menu->addAction(Find_and_replace);
   toolButton->setMenu(toolButton_menu);
   toolButton->setIcon(QIcon("C:\\Users\\The Witcher Hunt\\Downloads\\find3.jpg"));
   toolButton->setPopupMode(QToolButton::InstantPopup);
   toolbar->addWidget(toolButton);

}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton){
       context();
    }
}
void MainWindow::setCurName(const QString &a)
 {
     NameFile = a;
     QString b;
     editor->document()->setModified(false);
     if (a.isEmpty())
         b = "untitled.txt";
     else
         b = QFileInfo(a).fileName();
     name=b;editor->name=b;
     setWindowTitle(tr("[*]%1 - %2").arg(b).arg("Laboratory work 5"));
     setWindowModified(false);


}
void MainWindow::New_(){
    editor->clear();
    setCurName(QString());
}

void MainWindow::Open_(){
        QString  a = QFileDialog::getOpenFileName(this, "","");
        if (!a.isEmpty())
             openDoc(a);
}

void MainWindow::context(){
    QMenu* m = new QMenu(this);

    QAction* Undo = new QAction("Undo", this);
    connect(Undo,SIGNAL(triggered()), editor, SLOT(undo1()));

    QAction* Redo = new QAction("Redo", this);
    connect(Redo,SIGNAL(triggered()),editor, SLOT(redo1()));

    QAction* select_word = new QAction("Select word", this);
    connect(select_word,SIGNAL(triggered()),this, SLOT(SelectWord()));

    QAction* select_line = new QAction("Select line", this);
    connect(select_line,SIGNAL(triggered()),this, SLOT(SelectLine()));

    QAction* copy = new QAction("Copy", this);
    copy->setEnabled(false);
    connect(copy,SIGNAL(triggered()), editor, SLOT(copy()));
    connect(editor, SIGNAL(copyAvailable(bool)), copy, SLOT(setEnabled(bool)));

    QAction* cut = new QAction("Cut", this);
    cut->setEnabled(false);
    connect(cut,SIGNAL(triggered()),editor, SLOT(cut()));
    connect(editor, SIGNAL(copyAvailable(bool)), cut, SLOT(setEnabled(bool)));

    QAction* paste = new QAction("Paste", this);
    connect(paste,SIGNAL(triggered()),editor, SLOT(paste()));
    paste ->setEnabled(false);

    QAction* Delete = new QAction("Delete", this);
    connect(Delete ,SIGNAL(triggered()),this, SLOT(Delete()));

    QAction* selectAll = new QAction("Select all", this);
    connect(selectAll,SIGNAL(triggered()),editor, SLOT(selectAll()));

    if (editor->textCursor().hasSelection()){
        copy -> setEnabled(true);
        cut -> setEnabled(true);
        paste -> setEnabled(true);
    }

    if (editor->document()->isEmpty()){
        select_word->setEnabled(false);
        select_line->setEnabled(false);
    }
    else if (!editor->document()->isEmpty()){
        select_word->setEnabled(true);
        select_line->setEnabled(true);
    }
    QClipboard *p=QApplication::clipboard();
   if(p->ownsClipboard())
       paste->setEnabled(true);
    m->addAction(Undo);
    m->addAction(Redo);
    m->addAction(select_word);
    m->addAction(select_line);
    m->addAction(copy);
    m->addAction(cut);
    m->addAction(paste);
    m->addAction(selectAll);
    m->addAction(Delete);
    m->exec(QCursor::pos());
}
void MainWindow::SearchandReplace(){
    if (!rsearch)
        rsearch = new ReplaceSearch;
    rsearch -> show();
    connect(rsearch, SIGNAL(SignalofReplace()),this ,SLOT(replaceEND()));
}
void MainWindow::ActiveSearch(){
    if (!search)
        search = new Search;
    search->show();
    connect(search, SIGNAL(accepted()),this,SLOT(FindWord()));
}
void MainWindow::SetFontSelection(){
    bool flag;
    QFont font = QFontDialog::getFont(&flag, QFont("Arial", 12), this);
    if (flag) {
        editor->setFont(font);
    }
}
bool MainWindow::openDoc(const QString &a){
     if (!QFile::exists(a))
         return 0;
     QFile f(a);
     if (!f.open(QFile::ReadOnly))
         return 0;
     QByteArray data = f.readAll();
     QString s = QString::fromLocal8Bit(data);
     editor->setPlainText(s);
     setCurName(a);
     return 1;
 }
void MainWindow::FindWord(){
    bool flag = 0;
    QString str = search->Line();
    QTextDocument *doc = editor->document();

    QTextCursor highlightCursor(doc);
    QTextCursor cursor(doc),cursor1(doc);

    cursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    colorFormat.setForeground(Qt::blue);

    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {

        highlightCursor = doc->find(str, highlightCursor);


        if (!highlightCursor.isNull()) {
            flag = true;


            highlightCursor.mergeCharFormat(colorFormat);
        }
    }
    cursor.endEditBlock();
    f = false;
    if (flag == false)
        QMessageBox::information(this,"Text not found","Please, repeat your action again");
}
void MainWindow::HideNumberArea(){
    if (SwitcherNumeration->isChecked()==false){

         editor->getLineNumberArea()->hide();
    }
    else{
       editor->getLineNumberArea()->show();
    }
}
void MainWindow::WrapWord(){
    if (Perenos->isChecked()==0){
        editor->setWordWrapMode(QTextOption::NoWrap);
        update();
    }
    else{
        editor->setWordWrapMode(QTextOption::WrapAnywhere);
           update();
    }
}
void MainWindow::exit()
    {
    setting = new QSettings("editor.ini", QSettings::IniFormat, this);

    setting->beginGroup("Settings");
    if (SwitcherPanel->isChecked()){
        setting->setValue("ToolBar", "On");
    }
    else{
        setting->setValue("ToolBar", "Off");
    }

    if (C11->isChecked()){
        setting->setValue("C", "11");
    }
    if (C18->isChecked()){
       setting->setValue("C", "18");
    }
    if (Cpp14->isChecked()){
       setting->setValue("C", "14");
    }
    if (C17->isChecked()){
       setting->setValue("C", "17");
    }
    if (C20->isChecked()){
        setting->setValue("C", "20");
    }

    if (SwitcherNumeration->isChecked()){
        setting->setValue("NumerationLine", "On");
    }
    else{
        setting->setValue("NumerationLine", "Off");
    }

    if (SwitcherHightlighter->isChecked()){
        setting->setValue("SyntaxHighlight", "On");
    }
    else{
        setting->setValue("SyntaxHighlight", "Off");
    }
    if (SwitcherStatus->isChecked()){
        setting->setValue("StatusBar", "On");
    }
    else{
        setting->setValue("StatusBar", "Off");
    }
    setting->endGroup();
    this->close();
    }
void MainWindow::ChangeColorLine(){
    editor->setColorLine();

}
MainWindow::~MainWindow()
{
}
void MainWindow::SelectWord(){
   QTextCursor a = editor->textCursor();
   a.select(QTextCursor::WordUnderCursor);
   editor->setTextCursor(a);
}
 void MainWindow::showAboutProgram()
{

     DialogAboutMe *p=new DialogAboutMe(this);
     p->exec();
}
 void MainWindow::RefreshStatusBar(){
     curPos->setText("Line: "+QString::number((editor->textCursor().blockNumber())+1)+" "
                               + "Column: " +QString::number(editor->textCursor().positionInBlock()+1));
     len->setText("Lines Count: " + QString::number(editor->document()->blockCount())+" "

                  +  " Words Count: "+ QString::number(editor->toPlainText().split(QRegularExpression("(\\s|\\n|\\r)+"), Qt::SkipEmptyParts).count())
                  + " " + "Simbols Count: " + QString::number(editor->toPlainText().size())
                  +" | "+ QString::number(floor(double(1024*(editor->toPlainText().size())*8)/1024 + 0.5)/1024)+" KB" );
      last_change->setText((dateTime->currentDateTime()).toString("HH-mm")/*+" "+(sdateTime->currentDateTime()).toString()*/);
 }
 void MainWindow::HideStatusBar(){
     if (SwitcherStatus->isChecked()==false){
         statusBar()->hide();
     }
     else {
         statusBar()->show();
     }
 }
 void MainWindow::SetColorBackground(){
    editor->setColorBackground();
 }
 void MainWindow::replaceEND(){
     if(!editor->find(rsearch->line())){
         QMessageBox::information(this, "Text not found" ,"Please, repeat your action again.");
         rsearch->hide();
         return;
     }
     editor->textCursor().clearSelection();
     editor->textCursor().movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
     editor->textCursor().insertText(rsearch->replace_area());
 }
 void MainWindow::SelectLine(){
    QTextCursor a = editor->textCursor();
    a.select(QTextCursor::LineUnderCursor);
    editor->setTextCursor(a);
 }
 void MainWindow::Delete(){
     if (editor->textCursor().hasSelection())
         editor->textCursor().removeSelectedText();
 }
 bool MainWindow::Save_(){
     setWindowModified(false);
      if (NameFile.isEmpty())
         return Save_As_();
      QFile file(NameFile);
      if (file.open(QFile::WriteOnly))
          file.write(editor->toPlainText().toUtf8());
      curPos->setText((dateTime->currentDateTime()).toString("yyyy-MM-dd")+" " + (dateTime->currentDateTime()).toString("HH-mm"));
      return 0;
 }
 bool MainWindow::Save_As_(){
     QString a = QFileDialog::getSaveFileName(this, "","");
     if (a.isEmpty())
        return false;
     setCurName(a);
     return Save_();
 }
