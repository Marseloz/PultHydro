#ifndef G_INTERFACES_H
#define G_INTERFACES_H
#include "QtQml/qqmlapplicationengine.h"
#include "QtQml/qqmlcontext.h"
#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


class IGui : public QObject
{
    Q_OBJECT

public:
    IGui(QObject* parent = nullptr) : QObject(parent) {
        qputenv("QSG_RHI_BACKEND", "opengl");
    }

    virtual void setCppContextObject(const QString &name, QObject *value){ //передать c++ объект в qml пространство
        (engine.rootContext())->setContextProperty(name, value);
    }

    virtual void setCppContextValue(const QString &name, const QVariant &value){ //создать переменную в qml пространстве
        (engine.rootContext())->setContextProperty(name, value);
    }

    // Метод для запуска QQmlApplicationEngine
    virtual void launchEngine() {
        engine.load(QUrl(QStringLiteral("qrc:/main.qml"))); //подключение интерфейса
    }
signals:
    void done();
    void error(QString msg);
protected:
    // Инкапсулированный QQmlApplicationEngine
    QQmlApplicationEngine engine;
};

#endif // G_INTERFACES_H
