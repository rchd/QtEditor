#include"mainwindow.h"
#include"fileExplorer.h"
#include"textedit.h"
#include"documentmap.h"
#include"finddialog.h"
#include"statusbarinfo.h"
#include"funcationlist.h"

#include<QApplication>
#include<QCloseEvent>
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
#include<QSettings>
#include<QLabel>

#include<iostream>


MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
{


	CentralTabWidget=new QTabWidget(this);
	CentralTabWidget->setTabsClosable(true);

	//CentralTabWidget->setTabShape(QTabWidget::Triangular);
	CentralTabWidget->setMovable(true);

	QDockWidget*rightDockWidget=new QDockWidget;
	documentMap=new textBrowser;
	rightDockWidget->setWindowTitle("Document Map");
	rightDockWidget->setWidget(documentMap);
	addDockWidget(Qt::RightDockWidgetArea,rightDockWidget);

	explorer=new FileExplorer;
	leftDock=new QDockWidget;
	leftDock->setWindowTitle("Explorer");
	leftDock->setWidget(explorer);
addDockWidget(Qt::LeftDockWidgetArea,leftDock);
leftDock->hide();
	splitter=new QSplitter;
	splitter->addWidget(CentralTabWidget);
	setCentralWidget(splitter);

	FuncationList *funcation=new FuncationList();
	QDockWidget *funcationDock=new QDockWidget();
	funcationDock->setWidget(funcation);
	funcationDock->setWindowTitle("Funcation List");
	addDockWidget(Qt::RightDockWidgetArea,funcationDock);

	QString fileName="new file";
	newFile(fileName);
	createMenu();
	createAction();
	createConnection();
	createToolBar();

	readSettings();

	//DocumentInfo *a=new DocumentInfo();
	//statusBar()->addPermanentWidget(a);

}
/*void MainWindow::newSplitter()
{
	CentralTabWidget=new QTabWidget;
	splitter->addWidget(CentralTabWidget);
	tabWidgetList.push_back(CentralTabWidget);
	CentralTabWidget->setTabsClosable(true);
	CentralTabWidget->setMovable(true);
	connect(CentralTabWidget,SIGNAL(tabCloseRequested(int)),this,
	SLOT(closeTab()));
}*/
void MainWindow::setDocumentMapText(const QString & text)
{
	documentMap->setText(text);
}
void MainWindow::replace()
{
		TextEdit *a=getCurrentWidget();
	dialog=new findDialog(this,a);
	//QPushButton *findButton=dialog->getFindButton();
	//connect(findButton,SIGNAL(clicked()),this,SLOT(findText()));

	//dialog->setEditor(a);
	dialog->show();
	dialog->raise();
	dialog->activateWindow();

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
	newAction->setShortcuts(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new file"));

	openAction=new QAction(QIcon(":/images/open.png"),tr("Open"));
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));

	saveAction=new QAction(QIcon(":/images/save.png"),tr("Save"));
	saveAction->setShortcuts(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save the document to disk"));

	saveAsAction=new QAction(tr("Save As"));
	saveAsAction->setShortcuts(QKeySequence::SaveAs);
	saveAsAction->setStatusTip(tr("Save the document under a new name"));

	closeAllAction=new QAction(tr("Close All"));
	closeAction=new QAction(tr("Close"));
	printAction=new QAction(tr("Print"));


	cutAction=new QAction(QIcon(":/images/cut.png"),tr("Cut"));
	cutAction->setShortcuts(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));

	copyAction=new QAction(QIcon(":/images/copy.png"),tr("Copy"));
	copyAction->setShortcuts(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));

	pasteAction=new QAction(QIcon(":/images/paste.png"),tr("Paste"));
	pasteAction->setShortcuts(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
	undoAction=new QAction(QIcon(":/images/undo.png"),tr("Undo"));
	undoAction->setShortcuts(QKeySequence::Undo);
	redoAction=new QAction(QIcon(":/images/redo.png"),tr("Redo"));
	redoAction->setShortcuts(QKeySequence::Redo);
	zoomInAction=new QAction(QIcon(":/images/zoomin.png"),tr("Zoom In"));
	zoomInAction->setShortcuts(QKeySequence::ZoomIn);
	zoomOutAction=new QAction(QIcon(":/images/zoomout.png"),tr("Zoom Out"));
	zoomOutAction->setShortcuts(QKeySequence::ZoomOut);
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
	connect(explorerAction,SIGNAL(toggled(bool)),this,SLOT(showExplorer()));

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
	QWidget *temp=CentralTabWidget->currentWidget();
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
void MainWindow::showExplorer()
{
	if(explorerAction->isChecked())
		leftDock->show();
	else
		leftDock->hide();

	
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
		CentralTabWidget->addTab(editor,QIcon(":/images/new.png"),fileName);
		editorList.push_back(editor);
		statusBar()->showMessage(tr("Ready"));
		setActionEnabled(true);
		CentralTabWidget->setCurrentIndex(tabCount);
				setWindowTitle(fileName);
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
	int id=CentralTabWidget->indexOf(temp);
	CentralTabWidget->removeTab(id);
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
void MainWindow::readSettings()
{
    QSettings settings("Trolltech", "Application Example");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void MainWindow::writeSettings()
{
    QSettings settings("Trolltech", "Application Example");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
}
MainWindow::~MainWindow()
{

}
void printFileList()
{
	
}
