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
#include<QItemSelectionModel>
#include<QIcon>
#include<QFileIconProvider>
//agverbgvhrxsbrtfghnxdydkajfivdvnfuiogjnbhgkhaigbjmittttttthkgnlkllgb,flblg
#include<QDebug>

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
    connect(view,SIGNAL(clicked(const QModelIndex &)),this,
    SLOT(printTreePosition()));
}
void FileExplorer::printTreePosition()
{
    QModelIndex index=view->currentIndex();
    QString filePath=model->filePath(index);
    qDebug()<<filePath;
    getFileInfo(filePath);
}

void FileExplorer::getFileInfo(const QString & fileName)
{
    widget->clear();
    QDir dir;
    dir.setCurrent(fileName);
    QFileInfoList list=dir.entryInfoList();
    QIcon folderIcon,icon,fileIcon;
    QFileIconProvider iconProvider;
    fileIcon=iconProvider.icon(QFileIconProvider::File);
    folderIcon=iconProvider.icon(QFileIconProvider::Folder);
    for(int i=2;i<list.size();i++)
    {
        QFileInfo info=list.at(i);
        QString fileName=info.fileName();
        if(info.isDir())
            icon=folderIcon;
        widget->addItem(new QListWidgetItem(icon,fileName));
        icon=fileIcon;
    }
    rootEdit->setText(fileName);
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

    getFileInfo(QDir::currentPath());
}
QListWidgetItem * FileExplorer::currentListWidgetItem()
{
        return widget->currentItem();
}


FileExplorer::~FileExplorer()
{

}
