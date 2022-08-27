#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include "CodeEditor.h"
#include "Search.h"
#include "highlighter.h"
#include "ReplaceSearch.h"
#include "Syntax.h"
#include <QToolBar>
#include <QSettings>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString name="untitled";
    bool f;
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);
private slots:
    void exit();
    void showAboutProgram();
    void New_();
    void Open_();
    bool Save_();
    bool Save_As_();
    void setCurName(const QString &fileName);
    void RefreshStatusBar();
    void SetFontSelection();
    void HideStatusBar();
    void WrapWord();
    void HideNumberArea();
    void ChangeColorLine();
    void SetColorBackground();
    void ActiveSearch();
    void FindWord();
    void SearchandReplace();
    void replaceEND();
    void SelectWord();
    void SelectLine();
    void Delete();
    void HideToolBar();
    void RefreshZv();
    void HideHighlighter();
    void v11();
    void v18();
    void v14();
    void v17();
    void v20();
    void cSyntax();
private:
    void context();
    void tool();
    bool openDoc(const QString &a);
    QMenuBar *MainMenuBar;
    QMenu *MenuFile,*MenuEdit,*MenuFormat,*MenuView,*MenuHelp;
    QAction *New,*Open,*Save,*Save_as,*Exit;
    QAction *Cancel,*Repeat,*Copy,*Cut,*Paste,*Find,*Find_and_replace,*Highlight;
    QAction *Perenos,*Font;
    QAction *ColorBackground,*ColorCurString,*SwitcherNumeration,*SwitcherPanel,*SwitcherStatus,*SwitcherHightlighter,*Hightlighter,*cSyn;
    QAction *AboutProgram;
    QAction* C11;
    QAction* C18;
    QAction* Cpp14;
    QAction* C17;
    QAction* C20;
    QActionGroup* group;
    QLabel *len,* curPos,* last_change;
    CodeEditor *editor;
    Search *search;
    ReplaceSearch *rsearch;
    QString NameFile;
    QDateTime *dateTime;
    QDateTime *sdateTime;
    QToolBar *toolbar;
    Highlighter *highlighter;
    Syntax* syntax;
    QSettings* setting;


};
#endif // MAINWINDOW_H
