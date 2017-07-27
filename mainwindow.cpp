#include"mainwindow.h"
#include"fileExplorer.h"
#include"textedit.h"

#include<QDockWidget>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
#include<QTabWidget>
#include<QStatusBar>
#include<QListWidgetItem>
#include<QDebug>

#include<iostream>


MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
{

    explorer=new FileExplorer;
	
	CentralTabWidget=new QTabWidget(this);
	CentralTabWidget->setTabsClosable(true);
	setCentralWidget(CentralTabWidget);
	CentralTabWidget->setTabShape(QTabWidget::Triangular);
	CentralTabWidget->setMovable(true);

	QDockWidget *leftDock=new QDockWidget;
	leftDock->setWidget(explorer);
	addDockWidget(Qt::LeftDockWidgetArea,leftDock);

	createMenu();
	createAction();
	createConnection();

}
void MainWindow::createMenu()
{
	fileMenu=new QMenu(tr("File"));
	menuBar()->addMenu(fileMenu);
	
}
void MainWindow::createAction()
{
	openAction=new QAction(tr("open"));
	fileMenu->addAction(openAction);

	saveAction=new QAction(tr("save"));
	fileMenu->addAction(saveAction);
}
void MainWindow::createConnection()
{
	connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));

	connect(CentralTabWidget,SIGNAL(tabCloseRequested(int)),this,
	SLOT(tabCloseEvent()));
	connect(explorer->widget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
	this,SLOT(listWidgetOpenFile()));
}
void MainWindow::openFile()
{
	QString fileName=QFileDialog::getOpenFileName(this);
	editor=new TextEdit;
	editor->openFile(fileName);
	CentralTabWidget->addTab(editor,fileName);
	editorList.push_back(editor);

	statusBar()->showMessage(tr("Ready"));

}
void MainWindow::listWidgetOpenFile()
{
	QListWidgetItem *currentItem=explorer->currentListWidgetItem();
	QString fileName=currentItem->text();
	editor=new TextEdit;
	editor->openFile(fileName);
	CentralTabWidget->addTab(editor,fileName);
	editorList.push_back(editor);
	statusBar()->showMessage(tr("Ready"));
}

void MainWindow::saveFile()
{
	QString fileName=QFileDialog::getSaveFileName(this);
	editor->saveFile(fileName);
}
void MainWindow::tabCloseEvent()
{
	int id=CentralTabWidget->currentIndex();
	CentralTabWidget->removeTab(id);
	std::cout<<id;
}
MainWindow::~MainWindow()
{

}
void printFileList()
{
	
}
