#ifndef GUIMOD_H
#define GUIMOD_H

//#include "g_interfaces.h"
#include "g_interfaces.h"
#include <gs.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include <QQuickItem>
#include <QVariant>
#include <QQmlProperty>
#include <QUrl>

class GuiMod : public IGui{
    Q_OBJECT

public:
    GuiMod(QObject* parent = nullptr) : IGui(parent){
        setCppContextObject("GUI", this);
    };

    void launchEngine() {
        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        QQuickItem *videoItem;
        QQuickWindow *rootObject;
        QList <QObject *> _buffer = engine.rootObjects();
        qDebug() << _buffer.isEmpty();
        rootObject = static_cast<QQuickWindow *> (_buffer.first());
        videoItem = rootObject->findChild<QQuickItem *> ("videoItem");
        g_assert (videoItem);
        scene.setVideoItem(videoItem, "widget");
        rootObject->scheduleRenderJob (new SetPlaying (scene.getPipeline()),
        QQuickWindow::BeforeSynchronizingStage); // добавление классового объекта который должен запуститься перед стартом рендеринга
    }

    Q_INVOKABLE void updateSett(){
        qDebug()<<"updateSetting";
        emit updateSettings();
    }
signals:
    void updateSettings();
private:
    GS scene;
};

#endif // GUIMOD_H
