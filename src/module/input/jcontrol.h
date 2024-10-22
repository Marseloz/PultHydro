#ifndef JCONTROL_H
#define JCONTROL_H

#include "j_interfaces.h"
#include <QJoysticks>
#include <QObject>
#include <QList>
#include <QVariant>

class JControl : public ICont
{
    Q_OBJECT
public:
    JControl();
    bool onVirtualDev();//включить виртуальный джойстик
    bool offVirtualDev();//выключить виртуальный джойстик
    QString getDeviceInfo(int x);//возвращает информацию об устройстве, согласно его номеру
    QString getNameDev(int n);//вернуть имя подключённого устройства по номеру
    int getNumberDev();//количество устройств подключённых к компьютеру
    QStringList getNamesDev();//вернуть имена всех подключённых устройств
    QList<QVariant> getNamesDevQml();//вернуть имена всех подключённых устройств
    int getNumAxisDevice(int n);//кол-во осей у устройства
    int getNumPOVsDevice(int n);//кол-во кнопок крестовин у устройства
    int getNumButtonsDevice(int n);//кол-во доп кнопок у устройства
    bool scaneDevice(); //сканирование системы на наличие устройств (джойстики/геймпады)
    Q_INVOKABLE int getPOV(const int index, const int pov);
    Q_INVOKABLE qreal getAxis(const int index, const int axis);
    Q_INVOKABLE bool getButton(const int index, const int button);
private slots:
    void povCopy(const int js, const int pov, const int angle);
    void axisCopy(const int js, const int axis, const qreal value);
    void buttonCopy(const int js, const int button, const bool pressed);
private:
    QJoysticks *instance;
};

#endif // JCONTROL_H
