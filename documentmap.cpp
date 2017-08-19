
#include"documentmap.h"
#include"rectOfText.h"
#include"textedit.h"

#include<QPainter>
#include<QTextBrowser>
#include<Qsci/qsciscintilla.h>
#include<QStackedLayout>
#include<QLabel>
#include<QPalette>
#include<QDebug>
#include<QScrollBar>
#include<QFont>

textBrowser::textBrowser(QWidget *parent)
    :QWidget(parent)
{
    browser=new QsciScintilla;
   QStackedLayout *mainLayout=new QStackedLayout;
   mainLayout->setStackingMode(QStackedLayout::StackAll);
   QFont font;
   font.setPointSize(3);
   browser->setFont(font);
   rectContainer=new rectOfText;

   //rect->setWindowOpacity(0.7);
 

    //browser->setFontPointSize(3);
    mainLayout->addWidget(browser);
    mainLayout->addWidget(rectContainer);
    setLayout(mainLayout);
    browser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    browser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
