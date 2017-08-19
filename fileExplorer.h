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
    void getFileInfo(const QString &);
    void createConnection();
	QListWidgetItem * currentListWidgetItem();
    QListWidget *getListWidget();
    ~FileExplorer();
public slots:
    void printTreePosition();
protected:
    void closeEvent(QCloseEvent *event);
private:
    QListWidget *widget;
    QLabel *rootLabel;
    QLineEdit *rootEdit;
    QTreeView *view;

    QFileSystemModel *model;
    QCompleter *fileCompleter;
};

#endif // DIALOG_H
