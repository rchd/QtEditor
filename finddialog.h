#include<QDialog>
#include"base.h"
namespace Ui {
    class Dialog;
}
class editorBase;
class QPushButton;
class TextEdit;
class findDialog :public QDialog,public editorBase
{
    Q_OBJECT
private:
    Ui::Dialog *findAndReplaceDialog;
public:
    findDialog(){}
    findDialog(QWidget *parent,TextEdit *);
    ~findDialog();
    void createConnection();
public slots:
    void findText();
    void replace();  
};