#include "CodeEditor.h"
#include <QTextBlock>
#include <QPainter>
#include <QColor>
#include <QFile>
#include <QDateTime>
#include "LineNumberArea.h"
CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
 {

     lineNumberArea = new LineNumberArea(this);
     installEventFilter(this);

     connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
     connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
     connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

     updateLineNumberAreaWidth(0);
     highlightCurrentLine();
 }

void CodeEditor::undo1(){
   this->undo();
   QFile file(name);
   file.open(QIODevice::Append);
   QDateTime cur=QDateTime::currentDateTime();
   QString s="\n Undo "+cur.toString();
   QByteArray byte=s.toUtf8();
   file.write(byte);
   file.close();
}
void CodeEditor::redo1(){
    this->redo();
    QFile file(name);
    file.open(QIODevice::Append);
    QDateTime cur=QDateTime::currentDateTime();
    QString s="\n Redo "+cur.toString();
    QByteArray byte=s.toUtf8();
    file.write(byte);
    file.close();
}
bool CodeEditor::eventFilter(QObject *object,QEvent *e){
    QFile file(name);
    file.open(QIODevice::Append);int event=static_cast<QKeyEvent*>(e)->key();
    if (QEvent::KeyPress==e->type()){


        if(event==Qt::Key_Enter||event==Qt::Key_Return){
            QDateTime cur=QDateTime::currentDateTime();
            QString s="pressEnter "+cur.toString()+"\n";
            QByteArray byte=s.toUtf8();
            file.write(byte);

        }
        else if(event==Qt::Key_Backspace||event==Qt::Key_Delete){
            QDateTime cur=QDateTime::currentDateTime();
            QString s="press delete symbol "+cur.toString()+"\n";

            QByteArray byte=s.toUtf8();
            file.write(byte);
        }
        else {
            QString str="",s="";int k=event;
            while (k>0){
                s="";
                int a=k%100;
                                if (a==32)
                                s=' ';
                                if (a==33)
                                s='!';
                                if (a==34)
                                s='\'';
                                if (a==35)
                                s='#';
                                if (a==36)
                                s='$';
                                if (a==37)
                                s='%';
                                if (a==38)
                                s='&';
                                if (a==39)
                                s='\'';
                                if (a==40)
                                s='(';
                                if (a==41)
                                s=')';
                                if (a==42)
                                s='*';
                                if (a==43)
                                s='+';
                                if (a==44)
                                s=',';
                                if (a==45)
                                s='-';
                                if (a==46)
                                s='.';
                                if (a==47)
                                s='/';
                                if (a==48)
                                s='\0';
                                if (a==49)
                                s='1';
                                if (a==50)
                                s='2';
                                if (a==51)
                                s='3';
                                if (a==52)
                                s='4';
                                if (a==53)
                                s='5';
                                if (a==54)
                                s='6';
                                if (a==55)
                                s='7';
                                if (a==56)
                                s='8';
                                if (a==57)
                                s='9';
                                if (a==58)
                                s=':';
                                if (a==59)
                                s=';';
                                if (a==60)
                                s='<';
                                if (a==61)
                                s='=';
                                if (a==62)
                                s='>';
                                if (a==63)
                                s='\?';
                                if (a==64)
                                s='@';
                                if (a==65)
                                s='a';
                                if (a==66)
                                s='b';
                                if (a==67)
                                s='c';
                                if (a==68)
                                s='d';
                                if (a==69)
                                s='e';
                                if (a==70)
                                s='f';
                                if (a==71)
                                s='g';
                                if (a==72)
                                s='h';
                                if (a==73)
                                s='i';
                                if (a==74)
                                s='j';
                                if (a==75)
                                s='k';
                                if (a==76)
                                s='l';
                                if (a==77)
                                s='m';
                                if (a==78)
                                s='n';
                                if (a==79)
                                s='o';
                                if (a==80)
                                s='p';
                                if (a==81)
                                s='q';
                                if (a==82)
                                s='r';
                                if (a==83)
                                s='s';
                                if (a==84)
                                s='t';
                                if (a==85)
                                s='u';
                                if (a==86)
                                s='v';
                                if (a==87)
                                s='w';
                                if (a==88)
                                s='x';
                                if (a==89)
                                s='y';
                                if (a==90)
                                s='z';
                                if (a==91)
                                s='[';
                                if (a==92)
                                s='\\';
                                if (a==93)
                                s=']';
                                if (a==94)
                                s='^';
                                if (a==95)
                                s='_';
                                this->s=s;

                str=s+str;
                k/=100;
            }

            QDateTime cur=QDateTime::currentDateTime();
            //QString s1=event;
            str+="  "+cur.toString()+"\n";
            QByteArray byte=str.toUtf8();
            file.write(byte);

        }
    }
        file.flush();
        file.close();


    return QPlainTextEdit::eventFilter(object,e);
}
void CodeEditor::setColorLine(){
    DialogLine = new QColorDialog (this);
    DialogLine->exec();
    current_color = DialogLine->selectedColor();
    selection.format.setBackground(QColor(QColor(current_color).lighter(160)));
    highlightCurrentLine();
}
void CodeEditor::setColorBackground(){
    DialogALL= new QColorDialog (this);
    DialogALL -> exec();
    QPalette pal = this->palette();
    pal.setColor(QPalette::Active, QPalette::Base, DialogALL->selectedColor());
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::white);
    this->setPalette(pal);
}

int CodeEditor::lineNumberAreaWidth()
 {
     int digits = 1;
     int max = qMax(1, blockCount());
     while (max >= 10) {
         max /= 10;
         ++digits;
     }

     int space = 3 + fontMetrics().maxWidth();

     return space;
 }
void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
 {
     setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
 }
void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
 {
     if (dy)
         lineNumberArea->scroll(0, dy);
     else
         lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

     if (rect.contains(viewport()->rect()))
         updateLineNumberAreaWidth(0);
 }
void CodeEditor::resizeEvent(QResizeEvent *e)
 {
     QPlainTextEdit::resizeEvent(e);

     QRect cr = contentsRect();
     lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
 }
void CodeEditor::highlightCurrentLine()
 {
     QList<QTextEdit::ExtraSelection> extraSelections;

     if (!isReadOnly()) {
         QTextEdit::ExtraSelection selection;

         QColor lineColor = QColor(current_color).lighter(170);

         selection.format.setBackground(lineColor);
         selection.format.setProperty(QTextFormat::FullWidthSelection, true);
         selection.cursor = textCursor();
         selection.cursor.clearSelection();
         extraSelections.append(selection);
     }

     setExtraSelections(extraSelections);
 }
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
 {
     QPainter painter(lineNumberArea);
     painter.fillRect(event->rect(), Qt::lightGray);
     QTextBlock block = firstVisibleBlock();
         int blockNumber = block.blockNumber();
         int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
         int bottom = top + (int) blockBoundingRect(block).height();
         while (block.isValid() && top <= event->rect().bottom()) {
                  if (block.isVisible() && bottom >= event->rect().top()) {
                      QString number = QString::number(blockNumber + 1);
                      painter.setPen(Qt::black);
                      painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                                       Qt::AlignRight, number);
                  }
                  block = block.next();
                  top = bottom;
                  bottom = top + (int) blockBoundingRect(block).height();
                  ++blockNumber;
              }
          }
QWidget* CodeEditor::getLineNumberArea(){
    return lineNumberArea;
}
