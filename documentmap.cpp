
#include"documentmap.h"
#include"rectOfText.h"

#include<QPainter>
#include<QTextBrowser>

#include<QStackedLayout>
#include<QLabel>
#include<QPalette>
#include<QDebug>
#include<QScrollBar>


textBrowser::textBrowser(QWidget *parent)
    :QWidget(parent)
{
    browser=new QTextBrowser;
   QStackedLayout *mainLayout=new QStackedLayout;
   mainLayout->setStackingMode(QStackedLayout::StackAll);


   rectContainer=new rectOfText;

   //rect->setWindowOpacity(0.7);
 

    browser->setFontPointSize(3);
    mainLayout->addWidget(browser);
    mainLayout->addWidget(rectContainer);
    setLayout(mainLayout);
}
void textBrowser::setEditorScrollBar(QScrollBar *scrollbar)
{
    editorScrollBar=scrollbar;
}
void textBrowser::setText(const QString & text)
{
    browser->setText(text);
    rectContainer->setScrollBar(browser->verticalScrollBar());
    rectContainer->setEditorScrollBar(editorScrollBar);
   // qDebug()<<editorScrollBar->maximum();
}
textBrowser::~textBrowser()
{
    
}
