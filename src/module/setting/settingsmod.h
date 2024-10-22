#ifndef SETTINGSMOD_H
#define SETTINGSMOD_H

#include <QString>
#include <QHash>
#include <QList>
#include "loader.h"
#include "p_interfaces.h"



class SettingsMod : public _IParss { //отвечает за конвертацию текста в файле в структуру
public:
    SettingsMod(QString path){
        p_load = new Loader(path);
    }
    SettingsMod(){
        p_load = new Loader;
    }
    bool loadFile(Settings& a){ //загрузка файла настроек
        QString str; //переменная куда записываются данные
        QStringList buff, buff2;

        if(a.size()){

        }

        if(p_load->getContent(str)) return 1; //загружаем настройки в переменную

        buff = str.split('\n'); //разбиение строки на подстроки по переносу

        for (int i = 0; i < buff.size(); i++) { //пробегаемся по строкам
            if(buff[i].isEmpty()) break; //если строка пустая
            buff2 = buff[i].split(' '); //разбиваем на подстроки
            if(buff2.size() >= 3){ //проверка на существование в строке всех трёх параметров
                if (a.addSetting(buff2[0], buff2[1], buff2[2])) return 1; //создаём новый элемент
            }
        }
        emit loadDone();
        emit done();
        return 0;
    }
    bool saveFile(const Settings& a){ //сохранение файла настроек
        QString str;
        QList<QString> buff;
        buff = a.getNames(); // получить список имён
        for (int i = 0; i < buff.size(); i++) {
            str += buff[i]
                   +" "
                   +a.getDefaultValue(buff[i])
                   +" "
                   +a.getValue(buff[i])
                   +"\n";
        }
        p_load->setContent(str);
        emit done();
        return false;
    }
    ~SettingsMod(){
        delete(p_load);
    }
private:
    Loader* p_load = nullptr;
};


#endif // SETTINGSMOD_H
