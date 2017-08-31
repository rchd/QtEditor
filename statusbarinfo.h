#include<QLabel>
#include<QPoint>
#include<QHBoxLayout>
#include<QWidget>
class DocumentInfo :public QWidget
{
    int tabWidth;
    QPoint pos;
    QLabel *tabWidthLabel;
    QLabel *posLabel;
public:
    DocumentInfo(QWidget *parent=0)
    :QWidget(parent)
    {
        tabWidthLabel=new QLabel(tr("Spaces:"));
        posLabel=new QLabel(tr("Ln 0,Col 0"));
        QHBoxLayout mainLayout;
        mainLayout.addWidget(tabWidthLabel);
        mainLayout.addWidget(posLabel);
    }
    ~DocumentInfo()
    {

    }
    void setTabWidth(int width)
    {
        tabWidth=width;
    }
    void setCursorPos(QPoint point)
    {
        pos=point;
    }
};