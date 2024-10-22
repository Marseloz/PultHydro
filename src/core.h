#ifndef CORE_H
#define CORE_H
#include <QObject>
#include "guimod.h"
#include "jcontrol.h"
#include "settingsmod.h"
#include "iocontrol.h"
#include <ds.h>
#include <QDebug>


class coremod: public QObject{
    Q_OBJECT
public:
    coremod(){
        x.onVirtualDev();
    }
    void init(){
        //n.loadFile(temp);
        //qDebug()<<temp.isEmpty();
        //qDebug()<<temp.getNames();
        //temp.addSetting("FORT","X","ss");
        //n.saveFile(temp);
        //interface.setCppContextObject("IOControl", &b);
        //interface.setCppContextObject("joy", &x);
        //interface.setCppContextObject("fixtr", &interface);
        interface.launchEngine();
    }
private:
//Settings temp;
JControl x;
SettingsMod n;
IOControl b;
GuiMod interface;
};

#endif // CORE_H
