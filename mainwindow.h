#include<QMainWindow>

#include<list>
using std::list;

class FileExplorer;
class TextEdit;
class QMenu;
class QAction;
class QTabWidget;
class textBrowser;

class MainWindow :public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
	void createMenu();
	void createAction();
	void createConnection();
	void createToolBar();
	void setActionEnabled(bool flag);
	TextEdit * getCurrentWidget();
	void setDocumentMapText(const QString &);
public slots:
	void openFile();
	void saveFile();
	void saveAllFile();
	void save();	
	void closeTab();
	void listWidgetOpenFile();
	void closeAllTab();
	void newFile(const QString &);
	void undo();
	void redo();
	void copy();
	void paste();
	void cut();
	void replace();

private:
	textBrowser * documentMap;
	FileExplorer *explorer;
	TextEdit * editor;
	
	QTabWidget * CentralTabWidget;

	int tabCount=-1;

	QMenu *fileMenu;
	QAction *newAction;
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
	QAction *redoAction;
	QAction *findAction;
	QAction *replaceAction;

	QMenu *viewMenu;
	QAction *zoomInAction;
	QAction *zoomOutAction;
	QAction *explorerAction;
	QAction *statusBarAction;

	QMenu *LanguageMenu;
	QAction *cppAction;
	QAction *htmlAction;
	QAction *sqlAction;

	list<TextEdit*> editorList;

	static void printEditorList();

};
