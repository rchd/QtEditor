#include "actionmanager.h"


#include<QMenu>
#include<QAction>

static set<QString,QMenu *> * actionManager::actionContainer=new set<QString ,QMenu *>();

void actionManager::addAction(QAction *action)
{
  
}
void actionManager::addMenu(QMenu *)
{
    
}