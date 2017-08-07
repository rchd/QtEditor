#include<QApplication>
#include<QTranslator>

#include"mainwindow.h"
int main(int argc,char * argv[])
{
	QApplication app(argc,argv);
	QTranslator translator;
translator.load("zh_CN");
app.installTranslator(&translator); 
    MainWindow w;
    w.show();
	w.resize(800,800);
	return app.exec();
}
