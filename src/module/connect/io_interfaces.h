#ifndef IO_INTERFACES_H
#define IO_INTERFACES_H
#include <QObject>
#include <QList>
#include <QVariant>
#include <QByteArray>
#include <QVariantList>

class _IC : public QObject{
    Q_OBJECT
public:
    virtual bool startServer() = 0;
    virtual void stopServer() = 0;
    virtual void setClientAP(QString address, int port) = 0;
    virtual void setServerAP(QString address, int port) = 0;
    virtual void sendDataByte(QByteArray data) = 0;
    virtual void sendDataFloat(const float* arr, size_t s) = 0;
signals:
    void error(QString msg);
    void done();//сигнал об успехе операции
    void serverData(QVariantList a);//передаём массив float
    void serverDataByte(QByteArray a);//передаём массив
};

#endif // IO_INTERFACES_H
