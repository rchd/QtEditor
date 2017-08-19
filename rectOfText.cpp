#include "rectOfText.h"

#include<QMouseEvent>
#include<QDebug>
#include<QLabel>
#include<QScrollBar>
#include<QPalette>


rectOfText::rectOfText(QWidget *parent)
:QWidget(parent)
{
       rect=new QLabel(this);
   // rect->setAttribute(Qt::WA_TranslucentBackground, false);
   rect->setStyleSheet("background-color:red");
   /*QPalette pa;

pa.setColor(QPalette::Background, QColor(0xff,0xff,0xff,0x55));

rect->setPalette(pa);*/
   rect->resize(this->width(),60);
}
void rectOfText::setScrollBar(QScrollBar *scrollBar)
{
    this->textBrowserScrollBar=scrollBar;
}
void rectOfText::setEditorScrollBar(QScrollBar *scrollBar)
{
    this->editorOfScrollBar=scrollBar;
}
void rectOfText::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePositon=event->pos();
    if(event->button()==Qt::LeftButton && mousePositon.y()>=0 && mousePositon
    .y()+60<this->width())
    {
        int height=mousePositon.y();
        rect->move(0,height);
        qDebug()<<editorOfScrollBar<<editorOfScrollBar->maximum();
        if(textBrowserScrollBar->maximum()!=0 &&editorOfScrollBar->maximum()!=0)
        {
            int vscrollBar=textBrowserScrollBar->maximum()*height/this->height();
            textBrowserScrollBar->setValue(vscrollBar);
            vscrollBar=editorOfScrollBar->maximum()*height/this->height();
            //qDebug()<<vscrollBar;
            editorOfScrollBar->setValue(vscrollBar);
            //qDebug()<<mousePositon;
        }
    }
}
void rectOfText::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePositon=event->pos();
    if ((event->buttons() & Qt::LeftButton)&&mousePositon.y()>=0 && mousePositon
    .y()+60<this->height())
    {
        int height=mousePositon.y();
        rect->move(0,height);
        if(textBrowserScrollBar->maximum()!=0&&editorOfScrollBar->maximum()!=0)
        {
            int vscrollBar=textBrowserScrollBar->maximum()*height/this->height();
            textBrowserScrollBar->setValue(vscrollBar);
            vscrollBar=editorOfScrollBar->maximum()*height/this->height();
            editorOfScrollBar->setValue(vscrollBar);
        }
    }
}
rectOfText::~rectOfText()
{

}