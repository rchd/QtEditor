#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

class QCompleter;
class QLabel;
class QLineEdit;
class QTreeView;
class QListWidget;
class QFileSystemModel;
class QListWidgetItem;

class FileExplorer : public QWidget
{
    Q_OBJECT

public:
    FileExplorer(QWidget *parent = 0);
    void createWidget();
    void getFileInfo();
    void createConnection();
	QListWidgetItem * currentListWidgetItem();
    QListWidget *widget;
    ~FileExplorer();
private:
    QLabel *rootLabel;
    QLineEdit *rootEdit;
    QTreeView *view;

    QFileSystemModel *model;
    QCompleter *fileCompleter;
};

#endif // DIALOG_H
