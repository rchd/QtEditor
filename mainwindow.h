#include<QMainWindow>

#include<list>
using std::list;

class FileExplorer;
class TextEdit;
class QMenu;
class QAction;
class QTabWidget;

class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
	void createMenu();
	void createAction();
	void createConnection();
public slots:
	void openFile();
	void saveFile();
	void tabCloseEvent();
	void listWidgetOpenFile();
private:
	FileExplorer *explorer;
	TextEdit * editor;
	
	QTabWidget * CentralTabWidget;

	QMenu *fileMenu;
	QAction *openAction;
	QAction *saveAction;
	QAction *saveAsAction;
	QAction *printAction;
	QAction *closeAction;
	QAction *closeAllAction;
	QAction *exitAcion;

	QMenu *editMenu;
	QAction *cutAction;
	QAction *copyAction;
	QAction *pasteAction;
	QAction *undoAction;
	QAction *reduAction;

	list<TextEdit *> editorList;

	static void printEditorList();

};
