
#include "textedit.h"

#include<Qsci/qscilexercpp.h>
#include<Qsci/qsciapis.h>
#include<QFile>
#include<QFileDialog>
#include<QIODevice>
#include<QTextStream>
#include<QStringList>
#include<QMessageBox>

#include<iostream>

TextEdit::TextEdit(QWidget *parent)
    : QsciScintilla(parent)
{
    lexer=new QsciLexerCPP;
    this->setLexer(lexer);

    createLineNumber();
    createCompletion();
    createFold();

	
}
void TextEdit::createFold()
{
    setFolding(QsciScintilla::BoxedTreeFoldStyle);
}

void TextEdit::createLineNumber()
{
    setMarginType(0,QsciScintilla::NumberMargin);
    setMarginWidth(0,30);
    setMarginLineNumbers(0,true);
}
void TextEdit::createCompletion()
{
    setAutoCompletionSource(QsciScintilla::AcsAll);
    setAutoCompletionThreshold(1);

    QsciAPIs * stlKeywords=new QsciAPIs(lexer);
    stlKeywords->load(":/keywords.txt");
    stlKeywords->prepare();
}
void TextEdit::openFile(const QString &fileName)
{
	QFile file(fileName);
	file.open(QIODevice::ReadOnly);
	QTextStream out(&file);
	this->setText(out.readAll());
}

void TextEdit::saveFile(const QString &fileName)
{
	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly))
		QMessageBox::question(this,tr("Error"),tr("The file has a error,save failed"),
        QMessageBox::Yes | QMessageBox::No);
	QTextStream out(&file);
	out<<text();
}
TextEdit::~TextEdit()
{

}
