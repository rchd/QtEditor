#include"documentmap.h"

#include<QPainter>
#include<QTextBrowser>

#include<QHBoxLayout>

textBrowser::textBrowser(QWidget *parent)
    :QWidget(parent)
{
    browser=new QTextBrowser;
    QHBoxLayout *mainLayout=new QHBoxLayout;
    browser->setFontPointSize(3);
    mainLayout->addWidget(browser);
    setLayout(mainLayout);
}
void textBrowser::setText(const QString & text)
{
    browser->setText(text);
}
void textBrowser::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5)); 
}
textBrowser::~textBrowser()
{
    
}