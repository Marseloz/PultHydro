#ifndef UDPSERVER_H
#define UDPSERVER_H
#include <QUdpSocket>
#include <QNetworkDatagram>
class Server: public QObject{
    Q_OBJECT
public:
    Server(){
        udpSocket = new QUdpSocket;
        address.setAddress("127.0.0.1");
        port = 5600;
        connect(udpSocket, &QUdpSocket::readyRead, this, &Server::readDat);
        status = 0; //режим обработки пакетов (0-без проверки хэшсуммы, 1-с хэшсуммой)
    }
    void setSocket(QString _address, int _port){
        address.setAddress(_address);
        port = _port;
    }
    bool start(){
        return udpSocket->bind(address, port, QAbstractSocket::ShareAddress);
    }
    void stop(){
        udpSocket->abort();
    }
    void setStatus(bool a){
        status = a;
    }
signals:
    void data(QByteArray x);

private:
    void readDat(){
        while (udpSocket->hasPendingDatagrams()) {
            QNetworkDatagram datagram = udpSocket->receiveDatagram();
            tempData = datagram.data();
            if(!tempData.isEmpty()){
                if(status) {
                    tempHash = tempData.last(sizeof(quint16)).toUShort();//получаем контрольную сумму из сообщения
                    tempData = tempData.first(tempData.size()-sizeof(quint16));//убираем кусок байт с контрольной суммой
                    if (tempHash == qChecksum(tempData)){//сравниваем полученную контрольную сумму с вычисленной
                        emit data(tempData);//если данные целые, то отправляем дальше
                    }
                }
                else{
                    emit data(tempData);//приём пакетов без проверки
                }
            }
        }
    }
    QUdpSocket *udpSocket;
    int port;
    QHostAddress address;
    QByteArray tempData;
    quint16 tempHash;
    bool status; // режим связи (проверка пакетов на ошибки)
};

#endif // UDPSERVER_H
