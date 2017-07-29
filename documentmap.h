#include<QWidget>

class QTextBrowser;


class textBrowser:public QWidget
{
    Q_OBJECT
public:
    textBrowser(QWidget *parent=0);
    ~textBrowser();
    void setText(const QString &);
private:
    QTextBrowser *browser;
protected:
    void paintEvent(QPaintEvent *event);
};