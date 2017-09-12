#include<QMainWindow>

#include<list>
using std::list;

class FileExplorer;
class TextEdit;
class QMenu;
class QAction;
class QTabWidget;
class textBrowser;
class findDialog;
class QSplitter;
class QDockWIdget;

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

	void open(const QString &);
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
	void zoomIn();
	void zoomOut();
	void showExplorer();
	void setDocumentMapText();
protected:
	void closeEvent(QCloseEvent *event);
private:
	void writeSettings();
	void readSettings();
	textBrowser * documentMap;
	FileExplorer *explorer;
	TextEdit * editor;
	
	QSplitter *splitter;

	QTabWidget * CentralTabWidget;
	QDockWidget *leftDock;

	int tabCount=-1;
	findDialog *dialog;
	QMenu *fileMenu;
	QAction *newAction;
	QAction *openAction;
	QAction *saveAction;
	QAction *saveAllAction;
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
	QAction *splitterAction;
	QAction *explorerAction;
	QAction *statusBarAction;

	QMenu *LanguageMenu;
	QAction *cppAction;
	QAction *htmlAction;
	QAction *sqlAction;

	list<TextEdit*> editorList;

};
