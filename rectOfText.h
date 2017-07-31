#include<QWidget>
class QLabel;
class QScrollBar;
class rectOfText:public QWidget
{
    Q_OBJECT
public:
    rectOfText(QWidget *parent=0);
    void setScrollBar(QScrollBar *scrollBar);
    void setEditorScrollBar(QScrollBar *scrollBar);
    ~rectOfText();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QLabel *rect;
    QScrollBar *textBrowserScrollBar;
    QScrollBar *editorOfScrollBar;
};