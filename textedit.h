#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QWidget>
#include<Qsci/qsciscintilla.h>
class QsciLexer;

class  TextEdit
 : public QsciScintilla
{
    	Q_OBJECT
public:
    TextEdit(QWidget *parent = 0);
    void createLineNumber();
    void createCompletion();
    void createFold();
	void getFileName();
	void openFile(const QString &);
	void saveFile(const QString &);
    	~TextEdit();
private:
    QsciLexer *lexer;
	QString curFileName;
};


#endif // TEXTEDIT_H
