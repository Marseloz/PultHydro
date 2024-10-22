#include <QTest>
#include "client.h"
#include "server.h"
#include "iocontrol.h"
#include <QUdpSocket>
//класс для эмуляции запроса
class testr: public QThread{
    Q_OBJECT
public:
    testr(QString a, int p){
        port = p;
        address.setAddress(a);
        udpSocket = new QUdpSocket(this);
        connect(udpSocket, &QUdpSocket::readyRead, this, &testr::read);
    }
    QString getVar1(){
        return var1;
    }
    QString getVar2(){
        return var2;
    }
    QByteArray getVar3(){
        return var3;
    }
    void _emiter(QString str){
        QNetworkDatagram datagram;
        QByteArray tempData(str.toStdString().c_str());
        datagram.setData(tempData);
        udpSocket->writeDatagram(tempData, address, port);
    }
    void start(){
        if(!udpSocket->bind(address, port, QAbstractSocket::ShareAddress)){
            qDebug()<<"ошибка";
        }
    }
    void stop(){
        udpSocket->abort();
    }
public slots:
    void read(){
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        QByteArray tempData = datagram.data();
        var1 = tempData.data();
        //qDebug()<<var1;
    }

    void test3(QVariantList n){
        qDebug()<<"n";
        qDebug()<<n;
    }

    void test2(QByteArray n){
        var2 = n.data();
    }
private:
    QHostAddress address;
    QString var1 = "";
    QString var2 = "";
    QByteArray var3;
    QUdpSocket *udpSocket;
    int port;
};

class TestConnect: public QObject
{
    Q_OBJECT
private slots:
    void testClient(){
        testr var(addres, port);
        QByteArray b(messg.toStdString().c_str());
        Client a;
        a.setSocket(addres, port);
        var.start();
        QTest::qWait(25);
        a.sendData(b);
        QTest::qWait(25);
        qDebug()<<var.getVar1();
        QCOMPARE(var.getVar1(), messg);
        var.stop();
    }

    void testServer(){
        testr var(addres, port);
        Server b;
        connect(&b, &Server::data, &var, &testr::test2);
        b.start();
        QTest::qWait(25);
        var._emiter(messg);
        QTest::qWait(25);
        qDebug()<<var.getVar2();
        b.stop(); //без этого следующие тесты не запустятся
        QCOMPARE(var.getVar2(), messg);
    }

    void testIOControl(){
        testr var(addres, port);
        QByteArray x(messg.toStdString().c_str());
        IOControl c;
        c.setClientAP(addres, port);
        c.setServerAP(addres, port);
        connect(&c, &IOControl::serverDataByte, &var, &testr::test2);
        qDebug()<<c.startServer();
        QTest::qWait(25);
        c.sendDataByte(x);
        QTest::qWait(25);
        qDebug()<<var.getVar2();
        QCOMPARE(var.getVar2(), x);
    }

    void cleanupTestCase(){

    }
private:
    QString addres = "127.0.0.1";
    int port = 5600;
    QString messg = "Test test 12";
};

QTEST_MAIN(TestConnect);
#include "testconnect.moc"
