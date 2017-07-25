#include"mainwindow.h"
#include"fileExplorer.h"
#include"textedit.h"

#include<QDockWidget>
#include<QMenuBar>
#include<QMenu>
#include<QAction>

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
{
    editor=new TextEdit;
    explorer=new FileExplorer;

	setCentralWidget(editor);
	QDockWidget *leftDock=new QDockWidget;
	leftDock->setWidget(explorer);
	addDockWidget(Qt::LeftDockWidgetArea,leftDock);

	QMenu *file=new QMenu(tr("File"));
	QAction *open=new QAction(tr("Open"));
	file->addAction(open);
	menuBar()->addMenu(file);
	connect(open,SIGNAL(triggered()),editor,SLOT(open()));
}
MainWindow::~MainWindow()
{

}

