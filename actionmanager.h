
#include<QAction>
#include<set>
using std::set;
class QMenu;
class actionManager
{
public:
    static set<QString,QMenu *> *actionContainer;

    void addAction(QAction *);
    void addMenu(QMenu *);
};