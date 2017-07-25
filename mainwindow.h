#include<QMainWindow>

class FileExplorer;
class TextEdit;

class MainWindow :public QMainWindow
{
public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
private:
	FileExplorer *explorer;
	TextEdit * editor;

};
