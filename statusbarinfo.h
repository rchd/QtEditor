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
        QHBoxLayout *mainLayout=new QHBoxLayout;
        mainLayout->addWidget(tabWidthLabel);
        mainLayout->addWidget(posLabel);
        setLayout(mainLayout);
    }
    ~DocumentInfo()
    {

    }
public slots:
    void setTextEdit(TextEdit *textedit)
    {
        int line,index;
        textedit->getCursorPosition(&line,&index);
        posLabel->setText(QString(Ln %1,Col %2).arg(line).arg(index));
        
    }
};