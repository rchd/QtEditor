#include<QWidget>

class rectOfText;
class QsciScintilla;
class TextEdit;
class QScrollBar;
class textBrowser:public QWidget
{
    Q_OBJECT
public:
    textBrowser(QWidget *parent=0);
    ~textBrowser();
    void setEditorScrollBar(QScrollBar *);
public slots:
    void setText(const QString &);
private:
    QsciScintilla *browser;
    rectOfText *rectContainer;
    QScrollBar *editorScrollBar;
};
