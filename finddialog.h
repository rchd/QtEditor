#include<QDialog>

namespace Ui {
    class Dialog;
}
class findDialog :public QDialog
{
    private:
        Ui::Dialog *findAndReplaceDialog;

    public:
        findDialog(QWidget *parent=0);
        ~findDialog();
        QString getFindText();
        QString getreplaceText();
};