#ifndef IOCONTROL_H
#define IOCONTROL_H
#include <QObject>
#include <QVariantList>
#include <QVariant>
#include <QByteArray>
#include "io_interfaces.h"
#include "server.h"
#include "client.h"

class IOControl : public _IC{
    Q_OBJECT
public:
    IOControl(){
        connect(&server, &Server::data, this, &IOControl::serverHandler);
    }
    bool startServer(){
        if(server.start()){
            emit done();
            return 1;
        }
        return 0;
    }
    void stopServer(){ // останавливаем сервер
        server.stop();
    }
    void setClientAP(QString address, int port){
        client.setSocket(address, port);
    }
    void setServerAP(QString address, int port){
        server.setSocket(address, port);
    }
    void sendDataByte(QByteArray data){
        client.sendData(data);
    }
    void sendDataFloat(const float* arr, size_t s){
        temp.append(reinterpret_cast<const char*>(arr), sizeof(float)*s);
        client.sendData(temp);
    }
    void setCRCServer(bool x){ //вкл/выкл проверки пакетов на корректность
        server.setStatus(x);
    }
private slots:
    void serverHandler(QByteArray data){//обработчик сигналов
        QVariantList x;
        QDataStream ds(data);
        while(!ds.atEnd()) {
            ds>>buff;
            x.append(QVariant(buff));
        }
        emit serverData(x);
        emit serverDataByte(data);
    }
private:
    float buff;
    Server server;
    Client client;
    QByteArray temp;
};

#endif // IOCONTROL_H
