
#include<QAction>
#include<set>
using std::set;
class QMenu;
class ActionManager
{

    static set<QString,QMenu *> actionContainer;
public:
    void addAction(QAction *);
    void addMenu(QMenu *);
    ActionManager();
    ~ActionManager();
};