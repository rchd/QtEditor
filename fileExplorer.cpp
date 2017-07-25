#include "fileExplorer.h"

#include<QLabel>
#include<QLineEdit>
#include<QCompleter>
#include<QFileSystemModel>
#include<QDir>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTreeView>
#include<QListWidget>
#include<QListWidgetItem>

FileExplorer::FileExplorer(QWidget *parent)
    : QWidget(parent)
{

    createWidget();
    QHBoxLayout *topLayout=new QHBoxLayout;
    topLayout->addWidget(rootLabel);
    topLayout->addWidget(rootEdit);

    QVBoxLayout * mainLayout=new QVBoxLayout;
    mainLayout->addLayout(topLayout);

    mainLayout->addWidget(view);
    mainLayout->addWidget(widget);

    setLayout(mainLayout);
    createConnection();


}
void FileExplorer::createConnection()
{
    //connect(view,SIGNAL(doubleClicked(QModelIndex)),rootEdit,SLOT(setText(QString)));
}

void FileExplorer::getFileInfo()
{
    QDir dir;
    dir.setCurrent(QDir::currentPath());
    QFileInfoList list=dir.entryInfoList();
    for(int i=2;i<list.size();i++)
    {
        QFileInfo info=list.at(i);
        QString fileName=info.fileName();
        widget->addItem(new QListWidgetItem(fileName));
    }
}

void FileExplorer::createWidget()
{
    rootEdit=new QLineEdit(QDir::currentPath());
    rootLabel=new QLabel(tr("root content:"));
    fileCompleter=new QCompleter;
    model=new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    fileCompleter->setModel(model);

    rootEdit->setCompleter(fileCompleter);

    view=new QTreeView;
    view->setModel(model);

    widget=new QListWidget;

    getFileInfo();
}



FileExplorer::~FileExplorer()
{

}
