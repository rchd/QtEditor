#include"finddialog.h"
#include "ui_finddialog.h"

#include<QLineEdit>

findDialog::findDialog(QWidget *parent)
:QDialog(parent),findAndReplaceDialog(new Ui::Dialog)
{
    findAndReplaceDialog->setupUi(this);
    connect(findAndReplaceDialog->closeButton,
    SIGNAL(clicked()),this,SLOT(close()));
}
QString findDialog::getFindText()
{
    return findAndReplaceDialog->findText->text();
}
findDialog::~findDialog()
{

}