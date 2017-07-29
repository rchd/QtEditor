#include<QDialog>


class QLabel;
class QLineEdit;
class QPushButton;
class findDialog :public QDialog
{
    private:
        QLabel *findLabel;
        QLineEdit *findLineEdit;
        QPushButton *findButton;
        QPushButton *replaceButton;
        QPushButton *closeButton;

    public:
        QString getFindText();
        QString getreplaceText();
        void createWidget();
        void createLayout();
        void createConnection();


};