#ifndef P_INTERFACES_H
#define P_INTERFACES_H
#include <QObject>
#include "ds.h"


class _IParss : public QObject { //отвечает за конвертацию текста в файле в структуру
    Q_OBJECT
public:
    virtual bool loadFile(Settings& a) = 0;//загрузка файла настроек
    virtual bool saveFile(const Settings& a) = 0; //сохранение файла настроек
signals:
    void error(QString msg);
    void loadDone();//сигнал успешного окончания загрузки
    void done();//сигнал успеха
};

#endif // P_INTERFACES_H
