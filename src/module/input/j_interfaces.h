#ifndef J_INTERFACES_H
#define J_INTERFACES_H
#include <QObject>
#include <QVariant>


class ICont : public QObject {
    Q_OBJECT
public:
    virtual bool onVirtualDev() = 0;//включить виртуальный джойстик
    virtual bool offVirtualDev() = 0;//выключить виртуальный джойстик
    virtual QString getDeviceInfo(int x) = 0;//возвращает информацию об устройстве, согласно его номеру
    virtual QString getNameDev(int n) = 0;//вернуть имя подключённого устройства по номеру
    virtual int getNumberDev() = 0;//количество устройств подключённых к компьютеру
    virtual QStringList getNamesDev() = 0;//вернуть имена всех подключённых устройств
    virtual QList<QVariant> getNamesDevQml() = 0;//вернуть имена всех подключённых устройств
    virtual int getNumAxisDevice(int n) = 0;//кол-во осей у устройства
    virtual int getNumPOVsDevice(int n) = 0;//кол-во кнопок крестовин у устройства
    virtual int getNumButtonsDevice(int n) = 0;//кол-во доп кнопок у устройства
    virtual bool scaneDevice() = 0; //сканирование системы на наличие устройств (джойстики/геймпады)
signals:
    void error(QString msg);
    void done();
    void multiChanged(const QVector<float> pov, const QVector<float> axis, const QVector<bool> button);
    void multiChangedQml(const int js, const QVariantList pov, const QVariantList axis, const QVariantList button);
    void povChanged(const int js, const int pov, const int angle);
    void axisChanged(const int js, const int axis, const double value);
    void buttonChanged(const int js, const int button, const bool pressed);
};

#endif // J_INTERFACES_H
