#include"finddialog.h"
#include "ui_finddialog.h"
#include"textedit.h"
#include<QLineEdit>
#include<QDebug>

findDialog::findDialog(QWidget *parent,TextEdit *editor)
:QDialog(parent),findAndReplaceDialog(new Ui::Dialog)
{
    findAndReplaceDialog->setupUi(this);
    connect(findAndReplaceDialog->closeButton,
    SIGNAL(clicked()),this,SLOT(close()));
    setEditor(editor);
    createConnection();
}
void findDialog::findText()
{
    qDebug()<<(findAndReplaceDialog->matchCaseCheckBox->checkState());
    /*MatchEntireWordOnlyCheckBox;
    regularExpressionCheckBox;
    searchBackWordsCheckBox;
    warpAroundCheckBox;*/
    QString text=findAndReplaceDialog->findText->text();
    editorInfo()->findFirst(text,false,false,true,true);
}
void findDialog::replace()
{
    QString text=findAndReplaceDialog->lineEdit->text();
    editorInfo()->replace(text);
}
void findDialog::createConnection()
{
    connect(findAndReplaceDialog->findButton,SIGNAL(clicked()),
    this,SLOT(findText()));
    connect(findAndReplaceDialog->replaceButton,SIGNAL(clicked())
    ,this,SLOT(replace()));
}
findDialog::~findDialog()
{

}