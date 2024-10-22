/*
Модуль отвечает за загрузку файла настроек
*/
#ifndef LOADER_H
#define LOADER_H
#include <QString>
#include <QFile>
#include <QTextStream>

class Loader
{
public:
    Loader(){
        path = "settings.txt";
    }
    Loader(QString str){
        path = str;
    }
    //чтение файла
    bool getContent(QString &str){
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return 0;
        QTextStream in(&file);
        if (!file.atEnd()){
            str = in.readAll(); //выводим значение текста файла
        }
        file.close();
        return 0;
    }
    bool setContent(const QString &str){ //запись в файл
        if(str == nullptr) return 1;
        QFile file(path);
        file.remove();
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return 0;
        QTextStream out(&file);
        out << str;
        file.close();
        return 0;
    }

private:
    QString path = "";
};

#endif // LOADER_H
