#include"mainwindow.h"
#include"fileExplorer.h"
#include"textedit.h"
#include"documentmap.h"
#include"finddialog.h"

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
#include<QScrollBar>
#include<QDialog>
#include<QSplitter>

#include<iostream>


MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
{

	explorer=new FileExplorer;
	CentralTabWidget=new QTabWidget(this);
	CentralTabWidget->setTabsClosable(true);

	//CentralTabWidget->setTabShape(QTabWidget::Triangular);
	CentralTabWidget->setMovable(true);
	tabWidgetList.push_back(CentralTabWidget);

	QDockWidget*rightDockWidget=new QDockWidget;
	documentMap=new textBrowser;
	rightDockWidget->setWindowTitle("Document Map");
	rightDockWidget->setWidget(documentMap);
	addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);

	QDockWidget *leftDock=new QDockWidget;
	leftDock->setWindowTitle("Explorer");
	leftDock->setWidget(explorer);
	addDockWidget(Qt::LeftDockWidgetArea,leftDock);

	splitter=new QSplitter;
	splitter->addWidget(CentralTabWidget);
	setCentralWidget(splitter);


	QString fileName="new file";
	newFile(fileName);
	createMenu();
	createAction();
	createConnection();
	createToolBar();





}
void MainWindow::newSplitter()
{
	CentralTabWidget=new QTabWidget;
	splitter->addWidget(CentralTabWidget);
	tabWidgetList.push_back(CentralTabWidget);
	CentralTabWidget->setTabsClosable(true);
	CentralTabWidget->setMovable(true);
	connect(CentralTabWidget,SIGNAL(tabCloseRequested(int)),this,
	SLOT(closeTab()));
}
void MainWindow::setDocumentMapText(const QString & text)
{
	documentMap->setText(text);
}
void MainWindow::replace()
{
	dialog=new findDialog(this);
	//QPushButton *findButton=dialog->getFindButton();
	//connect(findButton,SIGNAL(clicked()),this,SLOT(findText()));
	dialog->show();
	dialog->raise();
	dialog->activateWindow();
	qDebug()<<dialog->getFindText();

}
void MainWindow::findText()
{
	TextEdit *a=getCurrentWidget();
	QString Text=dialog->getFindText();
	a->findFirstInSelection(Text,false,false,false);
}
void MainWindow::createToolBar()
{
	QToolBar *fileToolBar=addToolBar(tr("File"));
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(saveAction);
	QToolBar *editToolBar=addToolBar(tr("Edit"));
	editToolBar->addAction(copyAction);
	editToolBar->addAction(cutAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addAction(undoAction);
	editToolBar->addAction(redoAction);
	QToolBar *viewToolBar=addToolBar(tr("View"));
	viewToolBar->addAction(zoomInAction);
	viewToolBar->addAction(zoomOutAction);
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
	copyAction=new QAction(QIcon(":/images/copy.png"),tr("Copy"));
	pasteAction=new QAction(QIcon(":/images/paste.png"),tr("Paste"));
	undoAction=new QAction(QIcon(":/images/undo.png"),tr("Undo"));
	redoAction=new QAction(QIcon(":/images/redo.png"),tr("Redo"));

	zoomInAction=new QAction(QIcon(":/images/zoomin.png"),tr("Zoom In"));
	zoomOutAction=new QAction(QIcon(":/images/zoomout.png"),tr("Zoom Out"));
	splitterAction=new QAction(tr("Splitter Editor"));
	explorerAction=new QAction(tr("Explorer"));
	explorerAction->setCheckable(true);
	statusBarAction=new QAction(tr("Status Bar"));
	statusBarAction->setCheckable(true);
	findAction=new QAction(tr("Find"));
	replaceAction=new QAction(tr("Rplace"));

	viewMenu->addAction(zoomInAction);
	viewMenu->addAction(zoomOutAction);
	viewMenu->addAction(splitterAction);
	viewMenu->addAction(explorerAction);
	viewMenu->addAction(statusBarAction);

	editMenu->addAction(redoAction);
	editMenu->addAction(undoAction);
	editMenu->addSeparator();
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(replaceAction);

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
	connect(replaceAction,SIGNAL(triggered()),this,SLOT(replace()));

	connect(zoomInAction,SIGNAL(triggered()),this,SLOT(zoomIn()));
	connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(zoomOut()));
	connect(splitterAction,SIGNAL(triggered()),this,SLOT(newSplitter()));

	connect(CentralTabWidget,SIGNAL(tabCloseRequested(int)),this,
	SLOT(closeTab()));
	QListWidget *widget=explorer->getListWidget();
	connect(widget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
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
	QWidget *temp=splitter->focusWidget();
	TextEdit *a=qobject_cast<TextEdit *>(temp);
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
void MainWindow::zoomIn()
{
	TextEdit *a=getCurrentWidget();
	a->zoomIn();
}
void MainWindow::zoomOut()
{
	TextEdit *a=getCurrentWidget();
	a->zoomOut();
}
void MainWindow::openFile()
{
	QString fileName=QFileDialog::getOpenFileName(this);
	if(!fileName.isEmpty())
	{
		open(fileName);
	}
}
void MainWindow::open(const QString &fileName)
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
void MainWindow::listWidgetOpenFile()
{
	QListWidgetItem *currentItem=explorer->currentListWidgetItem();
	QString fileName=currentItem->text();
	if(!QFileInfo(fileName).isDir())
	{
		open(fileName);
		documentMap->setEditorScrollBar(editor->verticalScrollBar());
		setDocumentMapText(editor->text());
		editor->setCursorPosition(0,0);
	}

}
void MainWindow::saveAllFile()
{
	list<TextEdit*>::iterator itOfBegin=editorList.begin();
	list<TextEdit*>::iterator itOfEnd=editorList.end();
	for(;itOfBegin!=itOfEnd;itOfBegin++)
	{
		QString fileName=(*itOfBegin)->getFileName();
		(*itOfBegin)->saveFile(fileName);
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
	TextEdit * temp=getCurrentWidget();
	qDebug()<<temp;
	list<QTabWidget *>::iterator it=tabWidgetList.begin();
	for(;it!=tabWidgetList.end();it++)
	{
		int id=(*it)->indexOf(temp);
		if(id!=-1){
			qDebug()<<id;
			CentralTabWidget=*it;
			CentralTabWidget->removeTab(id);
			tabCount--;
		}
	}
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
