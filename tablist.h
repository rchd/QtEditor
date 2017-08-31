#include<QTabWidget>

class TextEdit;

class TabList :public QWidget
{
    QTabWidget *tabWidget;
    TextEdit * currentEditor;
public:
    static TextEdit* getCurrentWidget();
    void createAction();
    void createConnection();

    void setTabWidget();
    void open(const QString &);

public slots:
    void newFile();
    void openFile();

    void save();

    void cut();
    void copy();
    void paste();

    void undo();
    void redo();

    void zoomIn();
    void zoomOut();
    
    
};