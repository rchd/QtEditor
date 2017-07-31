#include<QWidget>

class rectOfText;
class QTextBrowser;
class QScrollBar;
class textBrowser:public QWidget
{
    Q_OBJECT
public:
    textBrowser(QWidget *parent=0);
    ~textBrowser();
    void setEditorScrollBar(QScrollBar *);
    void setText(const QString &);
private:
    QTextBrowser *browser;
    rectOfText *rectContainer;
    QScrollBar *editorScrollBar;
};
