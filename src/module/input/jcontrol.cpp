#include "jcontrol.h"

JControl::JControl(){
    instance = QJoysticks::getInstance();
    instance->setVirtualJoystickAxisSensibility(0);
    connect(instance, SIGNAL(povChanged(const int, const int, const int)), this, SLOT(povCopy(const int, const int, const int)));
    connect(instance, SIGNAL(axisChanged(const int, const int, const qreal)), this, SLOT(axisCopy(const int, const int, const qreal)));
    connect(instance, SIGNAL(buttonChanged(const int, const int, const bool)), this, SLOT(buttonCopy(const int, const int, const bool)));
}

QString JControl::getDeviceInfo(int n){//возвращает информацию об устройстве, согласно его номеру
    return "Axis:"+QString::number(getNumAxisDevice(n))+
           " POV:"+QString::number(getNumPOVsDevice(n))+
           " Button:"+QString::number(getNumButtonsDevice(n));
}
int JControl::getNumberDev(){//количество устройств подключённых к компьютеру
    return instance->count();
}

QStringList JControl::getNamesDev()//пока не определено
{
    QStringList a;
    return a;
}
bool JControl::onVirtualDev(){//включить виртуальный джойстик
    instance->setVirtualJoystickEnabled(1);
    return 0;
}
bool JControl::offVirtualDev(){//выключить виртуальный джойстик
    instance->setVirtualJoystickEnabled(0);
    return 0;
}
QVariantList JControl::getNamesDevQml(){//вернуть имена всех подключённых устройств
    return QVariantList(0);
}
QString JControl::getNameDev(int n){
    return instance->getName(n);
}
int JControl::getNumAxisDevice(int n){
    return instance->getNumAxes(n);
}
int JControl::getNumPOVsDevice(int n){
    return instance->getNumPOVs(n);
}
int JControl::getNumButtonsDevice(int n){
    return instance->getNumButtons(n);
}

bool JControl::scaneDevice()
{
    return 0;
}

int JControl::getPOV(const int index, const int pov)
{
    return instance->getPOV(index, pov);
}

double JControl::getAxis(const int index, const int axis)
{
    return instance->getAxis(index, axis);
}

bool JControl::getButton(const int index, const int button)
{
    return instance->getButton(index, button);
}
void JControl::povCopy(const int js, const int pov, const int angle){
    emit povChanged(js, pov, angle);
}
void JControl::axisCopy(const int js, const int axis, const qreal value){
    emit axisChanged(js, axis, value);
}
void JControl::buttonCopy(const int js, const int button, const bool pressed){
    emit buttonChanged(js, button, pressed);
}
