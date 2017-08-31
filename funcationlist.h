#include<QListWidget>
class FuncationList:public QListWidget
{
	public:
		FuncationList(QWidget *parent=0);
		~FuncationList();
		void editItem();

};
