#include"mainwindow.h"
#include"fileExplorer.h"
#include"textedit.h"
#include"documentmap.h"

#include<QApplication>
#include<QDockWidget>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
#include<QTabWidget>
#include<QStatusBar>
#include<QListWidgetItem>
#include<QDebug>
#include<QToolBar>
#include<QMimeData>
#include<QClipboard>
#include<QTextBrowser>

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

	QDockWidget*rightDockWidget=new QDockWidget;
	documentMap=new textBrowser;
	rightDockWidget->setWindowTitle("Document Map");
	rightDockWidget->setWidget(documentMap);
	addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);

	QDockWidget *leftDock=new QDockWidget;
	leftDock->setWindowTitle("Explorer");
	leftDock->setWidget(explorer);
	addDockWidget(Qt::LeftDockWidgetArea,leftDock);


	QString fileName="new file";
	newFile(fileName);
	createMenu();
	createAction();
	createConnection();
	createToolBar();





}
void MainWindow::setDocumentMapText(const QString & text)
{
	documentMap->setText(text);
}
void MainWindow::createToolBar()
{
	QToolBar *fileToolBar=addToolBar(tr("File"));
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(saveAction);
	QToolBar *editToolBar=addToolBar(tr("Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(pasteAction);
}
void MainWindow::newFile(const QString & fileName)
{
		tabCount++;
		editor=new TextEdit;
		editor->setModified(true);
		editor->newFile();
		editor->setFileName(fileName);
		CentralTabWidget->addTab(editor,fileName);
		editorList.push_back(editor);
		statusBar()->showMessage(tr("Ready"));
		//setActionEnabled(true);
		CentralTabWidget->setCurrentIndex(tabCount);
}
void MainWindow::createMenu()
{
	fileMenu=new QMenu(tr("File"));
	editMenu=new QMenu(tr("Edit"));
	viewMenu=new QMenu(tr("View"));
	menuBar()->addMenu(fileMenu);
	menuBar()->addMenu(editMenu);
	menuBar()->addMenu(viewMenu);
}
void MainWindow::createAction()
{
	newAction=new QAction(QIcon(":/images/new.png"),tr("New"));
	openAction=new QAction(QIcon(":/images/open.png"),tr("Open"));
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));
	saveAction=new QAction(QIcon(":/images/save.png"),tr("Save"));
	saveAsAction=new QAction(tr("Save as"));
	closeAllAction=new QAction(tr("Close All"));
	closeAction=new QAction(tr("Close"));
	printAction=new QAction(tr("Print"));


	cutAction=new QAction(QIcon(":/images/cut.png"),tr("Cut"));
	//cutAction->setShortCuts(QKeySequence::Cut);
	copyAction=new QAction(tr("Copy"));
	pasteAction=new QAction(QIcon(":/images/paste.png"),tr("Paste"));
	undoAction=new QAction(tr("Undo"));
	redoAction=new QAction(tr("Redo"));

	zoomInAction=new QAction(tr("Zoom In"));
	zoomOutAction=new QAction(tr("Zoom Out"));
	explorerAction=new QAction(tr("Explorer"));
	explorerAction->setCheckable(true);
	statusBarAction=new QAction(tr("Status Bar"));
	statusBarAction->setCheckable(true);

	viewMenu->addAction(zoomInAction);
	viewMenu->addAction(zoomOutAction);
	viewMenu->addAction(explorerAction);
	viewMenu->addAction(statusBarAction);


	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(redoAction);
	editMenu->addAction(undoAction);

	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addSeparator();
	fileMenu->addAction(closeAction);
	fileMenu->addAction(closeAllAction);
	fileMenu->addAction(printAction);




}
void MainWindow::createConnection()
{
	connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
	connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveFile()));
	connect(closeAction,SIGNAL(triggered()),this,SLOT(closeTab()));
	connect(closeAllAction,SIGNAL(triggered()),this,SLOT(closeAllTab()));

	connect(cutAction,SIGNAL(triggered()),editor,SLOT(cut()));
	connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));
	connect(pasteAction,SIGNAL(triggered()),this,SLOT(paste()));
	connect(undoAction,SIGNAL(triggered()),this,SLOT(undo()));
	connect(redoAction,SIGNAL(triggered()),this,SLOT(redo()));

	connect(CentralTabWidget,SIGNAL(tabCloseRequested(int)),this,
	SLOT(closeTab()));
	connect(explorer->widget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
	this,SLOT(listWidgetOpenFile()));
}
void MainWindow::cut()
{
	copy();
	TextEdit *a=getCurrentWidget();
	a->removeSelectedText ();
}
TextEdit * MainWindow::getCurrentWidget()
{
	QWidget *curTabEditor=CentralTabWidget->currentWidget();
	TextEdit *a=qobject_cast<TextEdit *>(curTabEditor);
	return a;
}
void MainWindow::copy()
{
	TextEdit *a=getCurrentWidget();
	QString text=a->selectedText();
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(text);
}
void MainWindow::paste()
{
	QClipboard* clipboard=QApplication::clipboard();
	TextEdit *a=getCurrentWidget();
	a->append(clipboard->text());
}
void MainWindow::undo()
{
	TextEdit *a=getCurrentWidget();
	a->undo();
}
void MainWindow::redo()
{
	TextEdit *a=getCurrentWidget();
	a->redo();
}
void MainWindow::openFile()
{
	QString fileName=QFileDialog::getOpenFileName(this);
	if(!fileName.isEmpty())
	{
		tabCount++;
		editor=new TextEdit;
		editor->openFile(fileName);
		editor->setFileName(fileName);
		CentralTabWidget->addTab(editor,fileName);
		editorList.push_back(editor);
		statusBar()->showMessage(tr("Ready"));
		setActionEnabled(true);
		CentralTabWidget->setCurrentIndex(tabCount);
	}
}
void MainWindow::listWidgetOpenFile()
{
	QListWidgetItem *currentItem=explorer->currentListWidgetItem();
	QString fileName=currentItem->text();
	if(!QFileInfo(fileName).isDir())
	{
		editor=new TextEdit;
		editor->openFile(fileName);
		editor->setFileName(fileName);
		CentralTabWidget->addTab(editor,fileName);
		editorList.push_back(editor);
		statusBar()->showMessage(tr("Ready"));
		tabCount++;
		CentralTabWidget->setCurrentIndex(tabCount);
		setDocumentMapText(editor->text());
	}


}
void MainWindow::saveAllFile()
{
	list<TextEdit*>::iterator itOfBegin=editorList.begin();
	list<TextEdit*>::iterator itOfEnd=editorList.end();
	for(;itOfBegin!=itOfEnd;itOfBegin++)
	{
		//QString fileName=itOfBegin->getFileName();
		//itOfBegin->saveFile(fileName);
	}
}
void MainWindow::saveFile()
{
	QString fileName=QFileDialog::getSaveFileName(this);
	editor->saveFile(fileName);
}
void MainWindow::save()
{
	int id=CentralTabWidget->currentIndex();
	QWidget *curTabEditor=CentralTabWidget->widget(id);
	TextEdit *a=qobject_cast<TextEdit *>(curTabEditor);
	a->save();
}
void MainWindow::closeTab()
{
	int id=CentralTabWidget->currentIndex();
	CentralTabWidget->removeTab(id);
	std::cout<<id;
	tabCount--;
	if(tabCount<0)
		setActionEnabled(false);
}
void MainWindow::closeAllTab()
{
	/*int count=CentralTabWidget->count();
	for(int i=0;i<count;i++)
		CentralTabWidget->removeTab(i);*/
	CentralTabWidget->clear();
	setActionEnabled(false);
	tabCount=-1;
}	
void MainWindow::setActionEnabled(bool flag)
{
		saveAsAction->setEnabled(flag);
		saveAction->setEnabled(flag);
		closeAllAction->setEnabled(flag);
		closeAction->setEnabled(flag);
}
MainWindow::~MainWindow()
{

}
void printFileList()
{
	
}
