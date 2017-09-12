#include"funcationlist.h"
#include<QListWidget>
#include<QDebug>
#include<QListWidgetItem>
#include<QHBoxLayout>
#include<QRegularExpression>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
FuncationList::FuncationList(QWidget *parent)
	:QListWidget(parent)
{
	editItem();
}
FuncationList::~FuncationList()
{

}
void FuncationList::editItem()
{
	QFile file("tags");
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return ;	
	QTextStream out(&file);
	out.readLine(6);
	while(!out.atEnd())
	{
	QString item=out.readLine();
	QStringList list=item.split(QRegularExpression("\\s+"));
	qDebug()<<list[0];
	addItem(new QListWidgetItem(list[0]+"("+list[1]+")"));
	}
}
