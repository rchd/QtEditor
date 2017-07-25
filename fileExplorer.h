#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

class QCompleter;
class QLabel;
class QLineEdit;
class QTreeView;
class QListWidget;
class QFileSystemModel;

class FileExplorer : public QWidget
{
    Q_OBJECT

public:
    FileExplorer(QWidget *parent = 0);
    void createWidget();
    void getFileInfo();
    void createConnection();
    ~FileExplorer();
private:
    QLabel *rootLabel;
    QLineEdit *rootEdit;
    QTreeView *view;
    QListWidget *widget;
    QFileSystemModel *model;
    QCompleter *fileCompleter;
};

#endif // DIALOG_H
