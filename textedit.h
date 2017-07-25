#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QWidget>
#include<Qsci/qsciscintilla.h>
class QsciLexerCPP;

class  TextEdit
 : public QsciScintilla
{
    Q_OBJECT
public:
    TextEdit(QWidget *parent = 0);
    void createLineNumber();
    void createCompletion();
    void  createFold();
    ~TextEdit();
private:
    QsciLexerCPP *lexer;
public slots:
	void open();
};


#endif // TEXTEDIT_H
