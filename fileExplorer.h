#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>

class QCompleter;
class QLabel;
class QLineEdit;
class QTreeView;
class QListView;
class QFileSystemModel;
class QListWidgetItem;
class QModelIndex;

class FileExplorer : public QWidget
{
    Q_OBJECT
public:
    FileExplorer(QWidget *parent = 0);
    void createWidget();
    void getFileInfo(const QString &);
    void createConnection();
    QString currentListWidgetItem();
    QListView *getListWidget();
    ~FileExplorer();
public slots:
    void printTreePosition();
protected:
    void closeEvent(QCloseEvent *event);
private:
    QListView *widget;
    QLabel *rootLabel;
    QLineEdit *rootEdit;
    QTreeView *view;

    QFileSystemModel *model;
    QCompleter *fileCompleter;
};

#endif // DIALOG_H
