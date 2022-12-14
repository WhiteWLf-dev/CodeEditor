#include "highlighter.h"
Highlighter::~Highlighter(){}
Highlighter::Highlighter(QTextDocument *parent, int n): QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(colorKeyword);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns11;
    QStringList keywordPatterns18;
    QStringList keywordPatterns14;
    QStringList keywordPatterns17;
    QStringList keywordPatterns20;
    number = n;
    keywordPatterns11 <<"\\auto\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
            << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
            << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
            << "\\bif\\b" << "\\binline\\b" << "\\bint\\b"
            << "\\blong\\b" << "\\bregister\\b" << "\\brestrict\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstruct\\b"
            << "\\bswitch\\b" << "\\btypedef\\b" << "\\bunion\\b"
            << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwhile\\b" << "\\b_Alignas\\b" << "\\b_Alignof\\b"
            << "\\b_Atomic\\b" << "\\b_Bool\\b" << "\\b_Complex\\b"
            << "\\b_Generic\\b" << "\\b_Imaginary\\b" << "\\b_Noreturn\\b"
            << "\\b_Static_assert\\b" << "\\_Thread_local\\b";
    keywordPatterns18
            <<"\\auto\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
            <<"\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
            << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
            << "\\bif\\b" << "\\binline\\b" << "\\bint\\b"
            << "\\blong\\b" << "\\bregister\\b" << "\\brestrict\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstruct\\b"
            << "\\bswitch\\b" << "\\btypedef\\b" << "\\bunion\\b"
            << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwhile\\b" << "\\b_Alignas\\b" << "\\b_Alignof\\b"
            <<"\\b_Atomic\\b" << "\\b_Bool\\b" << "\\b_Complex\\b"
            << "\\b_Generic\\b" << "\\b_Imaginary\\b" << "\\b_Noreturn\\b"
            << "\\b_Static_assert\\b" << "\\_Thread_local\\b";
    keywordPatterns14
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;
    keywordPatterns17
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;
    keywordPatterns20
            << "\\bchar8_t\\b" << "\\bconcept\\b"
            << "\\bconsteval\\b" << "\\bconstinit\\b" << "\\bco_await\\b"
            << "\\bco_return\\b" << "\\bco_yield\\b" << "\\brequires\\b"
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;

    if (number == 1){
        foreach (const QString &pattern, keywordPatterns11) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if (number == 2){
        foreach (const QString &pattern, keywordPatterns18) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 3){
        foreach (const QString &pattern, keywordPatterns14) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 4){
        foreach (const QString &pattern, keywordPatterns17) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 5){
        foreach (const QString &pattern, keywordPatterns20) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(colorClassFormat);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(colorQuotationFormat);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(colorFunctionFormat);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(colorMultiLineFormat);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}
Highlighter::Highlighter(QTextDocument *parent, int n, QColor a,QColor b,QColor c): QSyntaxHighlighter(parent)
{
    colorKeyword=a;colorClassFormat=b;colorFunctionFormat=c;
    HighlightingRule rule;
    keywordFormat.setForeground(a);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns11;
    QStringList keywordPatterns18;
    QStringList keywordPatterns14;
    QStringList keywordPatterns17;
    QStringList keywordPatterns20;
    number = n;
    keywordPatterns11 <<"\\auto\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
            << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
            << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
            << "\\bif\\b" << "\\binline\\b" << "\\bint\\b"
            << "\\blong\\b" << "\\bregister\\b" << "\\brestrict\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstruct\\b"
            << "\\bswitch\\b" << "\\btypedef\\b" << "\\bunion\\b"
            << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwhile\\b" << "\\b_Alignas\\b" << "\\b_Alignof\\b"
            << "\\b_Atomic\\b" << "\\b_Bool\\b" << "\\b_Complex\\b"
            << "\\b_Generic\\b" << "\\b_Imaginary\\b" << "\\b_Noreturn\\b"
            << "\\b_Static_assert\\b" << "\\_Thread_local\\b";
    keywordPatterns18
            <<"\\auto\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
            <<"\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
            << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
            << "\\bif\\b" << "\\binline\\b" << "\\bint\\b"
            << "\\blong\\b" << "\\bregister\\b" << "\\brestrict\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstruct\\b"
            << "\\bswitch\\b" << "\\btypedef\\b" << "\\bunion\\b"
            << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwhile\\b" << "\\b_Alignas\\b" << "\\b_Alignof\\b"
            <<"\\b_Atomic\\b" << "\\b_Bool\\b" << "\\b_Complex\\b"
            << "\\b_Generic\\b" << "\\b_Imaginary\\b" << "\\b_Noreturn\\b"
            << "\\b_Static_assert\\b" << "\\_Thread_local\\b";
    keywordPatterns14
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;
    keywordPatterns17
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;
    keywordPatterns20
            << "\\bchar8_t\\b" << "\\bconcept\\b"
            << "\\bconsteval\\b" << "\\bconstinit\\b" << "\\bco_await\\b"
            << "\\bco_return\\b" << "\\bco_yield\\b" << "\\brequires\\b"
            << "\\balignas\\b" << "\\balignof\\b"
            << "\\bchar16_t\\b" << "\\bchar32_t\\b" << "\\bconstexpr\\b"
            << "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b"
            << "\\bstatic_assert\\b" << "\\bthread_local\\b"
            << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b"
            << "\\bauto\\b" << "\\bbitand\\b" << "\\bbitor\\b"
            << "\\bbool\\b" << "\\bbreak\\b" << "\\bcase\\b"
            << "\\bcatch\\b" << "\\bchar\\b" << "\\bclass\\b"
            << "\\bcompl\\b" << "\\bconst\\b" << "\\bconst_cast\\b"
            << "\\bcontinue\\b" << "\\bdefault\\b" << "\\bdelete\\b"
            << "\\bdo\\b" << "\\bdouble\\b" << "\\bdynamic_cast\\b"
            << "\\belse\\b" << "\\benum\\b" << "\\bexplicit\\b"
            << "\\bexport\\b" << "\\bextern\\b" << "\\bfalse\\b"
            << "\\bfloat\\b" << "\\bfor\\b"  << "\\bfriend\\b"
            << "\\goto\\b" << "\\bif\\b" << "\\binline\\b"
            << "\\bint\\b" << "\\blong\\b" << "\\bmutable\\b"
            << "\\bnamespace\\b" << "\\bnew\\b" << "\\bnot\\b"
            << "\\bnot_eq\\b" << "\\boperator\\b" << "\\bor\\b"
            << "\\bor_eq\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bpublic\\b" << "\\bregister\\b" << "\\breinterpret_cast\\b"
            << "\\breturn\\b" << "\\bshort\\b" << "\\bsigned\\b"
            << "\\bsizeof\\b" << "\\bstatic\\b" << "\\bstatic_cast\\b"
            << "\\struct\\b" << "\\bswitch\\b" << "\\btemplate\\b"
            << "\\this\\b" << "\\bthrow\\b" << "\\btrue\\b"
            << "\\btry\\b" << "\\btypedef\\b" << "\\btypeid\\b"
            << "\\bunion\\b" << "\\unsigned\\b" << "\\busing\\b"
            << "\\bvirtual\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
            << "\\bwchar_t\\b" << "\\bwhile\\b" << "\\bxor\\b"
            << "\\bxor_eq\\b" ;

    if (number == 1){
        foreach (const QString &pattern, keywordPatterns11) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if (number == 2){
        foreach (const QString &pattern, keywordPatterns18) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 3){
        foreach (const QString &pattern, keywordPatterns14) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 4){
        foreach (const QString &pattern, keywordPatterns17) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    else if(number == 5){
        foreach (const QString &pattern, keywordPatterns20) {
            rule.pattern = QRegExp(pattern);
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }

    }
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(colorClassFormat);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    quotationFormat.setForeground(colorQuotationFormat);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(colorFunctionFormat);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(colorMultiLineFormat);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}
void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);
    int startIndex = 0;
        if (previousBlockState() != 1)
            startIndex = commentStartExpression.indexIn(text);
    while (startIndex >= 0) {
           int endIndex = commentEndExpression.indexIn(text, startIndex);
           int commentLength;
           if (endIndex == -1) {
               setCurrentBlockState(1);
               commentLength = text.length() - startIndex;
           } else {
               commentLength = endIndex - startIndex
                               + commentEndExpression.matchedLength();
           }
           setFormat(startIndex, commentLength, multiLineCommentFormat);
           startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
       }
}
QBrush Highlighter::getKeywordColor(){
    return colorKeyword;
}
QBrush Highlighter::getClassColor(){
    return colorClassFormat;
}
QBrush Highlighter::getQuotationColor(){
    return colorQuotationFormat;
}
QBrush Highlighter::getFunctionColor(){
    return colorFunctionFormat;
}
QBrush Highlighter::getMultiLineColor(){
    return colorMultiLineFormat;
}

void  Highlighter::setKeywordColor( QBrush a){
    colorKeyword = a;

}
void  Highlighter::setClassColor( QBrush a){
    colorClassFormat = a;
}
void  Highlighter::setQuotationColor( QBrush a){
    colorQuotationFormat = a;
}
void  Highlighter::setFunctionColor( QBrush a){
    colorFunctionFormat = a;
}
void  Highlighter::setMultiLineColor( QBrush a){
    colorMultiLineFormat = a;
}

