#include "fileExplorer.h"

#include<QLabel>
#include<QLineEdit>
#include<QCompleter>
#include<QFileSystemModel>
#include<QDir>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTreeView>
#include<QListView>
#include<QListWidgetItem>
#include<QItemSelectionModel>
#include<QIcon>
#include<QFileIconProvider>
#include<QDebug>
#include<QModelIndex>

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
void FileExplorer::closeEvent(QCloseEvent *event)
{
    this->hide();

}

void FileExplorer::getFileInfo(const QString & fileName)
{
    widget->setModel(model);
    widget->setRootIndex(view->currentIndex());
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

    widget=new QListView;

    getFileInfo(QDir::currentPath());
}
QListView * FileExplorer::getListWidget()
{
    return widget;
}
QString  FileExplorer::currentListWidgetItem()
{
    return model->fileName(widget->currentIndex());
}


FileExplorer::~FileExplorer()
{

}
