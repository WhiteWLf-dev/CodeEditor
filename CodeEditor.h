#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QPlainTextEdit>
#include <QColorDialog>
#include <QFontDialog>
class CodeEditor : public QPlainTextEdit
 {
     Q_OBJECT

 public:
     CodeEditor(QWidget *parent = 0);


     void lineNumberAreaPaintEvent(QPaintEvent *event);
     int lineNumberAreaWidth();
     void setColorLine();
     void setColorBackground();
     QString name;
     QWidget* getLineNumberArea();

 protected:
     void resizeEvent(QResizeEvent *event);
     bool eventFilter(QObject *object,QEvent *event);


 private slots:
     void updateLineNumberAreaWidth(int newBlockCount);
     void highlightCurrentLine();
     void updateLineNumberArea(const QRect &, int);
     void undo1();
     void redo1();

 private:
     QWidget *lineNumberArea;
     QColor current_color="red";
     QString s="";
     QColorDialog *DialogLine;
     QColorDialog *DialogALL;
     QTextEdit::ExtraSelection selection;

 };
#endif // CODEEDITOR_H
