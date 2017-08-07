#include<QDialog>

namespace Ui {
    class Dialog;
}
class QPushButton;
class findDialog :public QDialog
{
    Q_OBJECT
    private:
        Ui::Dialog *findAndReplaceDialog;

    public:
        findDialog(QWidget *parent=0);
        ~findDialog();
        QString getFindText();
        QString getreplaceText();
        QPushButton * getFindButton();
};