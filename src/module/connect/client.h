#ifndef UDPCLIENT_H
#define UDPCLIENT_H
#include <QUdpSocket>

class Client : public QObject{
    Q_OBJECT
public:
    Client(){
        udpSocket = new QUdpSocket;
        address.setAddress("127.0.0.1");
        port = 5600;
        status = 1;
    }
    void setSocket(QString _address, int _port){
        address.setAddress(_address);
        port = _port;
    }
    void sendData(QByteArray b){
        udpSocket->writeDatagram(b, address, port);
    }
private:
    QUdpSocket *udpSocket;
    QHostAddress address;
    int port;
    bool status;
};

#endif // UDPCLIENT_H
