#ifndef DS_H
#define DS_H

#include <QObject>
#include <QString>
#include <QHash>
#include <QFile>
#include <QTextStream>

//Settings оперирует только строками, пееревод в числа, пути и имена должен производить сам пользователь
class Settings : public QObject {
public:
    Settings() = default; //конструктор по умолчанию

    Q_INVOKABLE bool addSetting(QString name, QString a) { //создать и установить значение
        return addSetting(name, a, a);
    }

    Q_INVOKABLE bool addSetting(QString name, QString a, QString b) { //создать настройку, где a-значение по умолчанию, b-текущее значение
        if (name.isEmpty()) return 1;//если имя настройки пустое
        if(existsName(name)) return 1; //если настройка уже есть
        if (!isCorrect(a)) return 1; //если в строке есть пробел
        if (!isCorrect(b)) return 1; //если в строке есть пробел

        tab.insert(name, SettingData(a, b));
        return 0;
    }

    Q_INVOKABLE bool setValue(QString name, QString a) { //обновить текущее значение
        if (!isCorrect(a)) return 1; //если в строке есть пробел
        if (!tab.contains(name)) return 1; //если имени нету в таблице
        tab[name]._present = a;
        return 0;
    }

    QList<QString> getNames() const { //получить список существующих имён настроек
        return tab.keys();
    }

    Q_INVOKABLE bool existsName(QString name) const { //проверяет на наличие имени в таблице (1-есть, 0-нету)
        return tab.contains(name);
    }

    Q_INVOKABLE QString getValue(QString name) const { //получить текущее значение по имени
        if (!tab.contains(name)) return 0; //если имени нету в таблице
        return tab[name]._present;
    }

    Q_INVOKABLE QString getDefaultValue(QString name) const { //получить значение по умолчанию по имени
        if (!tab.contains(name)) return 0; //если имени нету в таблице
        return tab[name]._default;
    }

    Q_INVOKABLE bool resetSetting(QString name) { //сбросить значение конкретного элемента
        if (!tab.contains(name)) return 1;
        tab[name].reset();
        return 0;
    }

    Q_INVOKABLE void resetAllSettings() { //сбросить значения всех элементов
        for (auto i = tab.cbegin(); i != tab.cend(); ++i){ //перебор всех имён элементов
            tab[i.key()].reset(); //сброс элемента
        }
    }

    Q_INVOKABLE size_t size() const { //получить количество настроек
        return tab.size();
    }

    Q_INVOKABLE bool isEmpty() const { //проверяет, пуста ли таблица настроек
        return tab.isEmpty();
    }

    Q_INVOKABLE bool removeSetting(QString name) { //удаляет настройку по имени
        if (!tab.contains(name)) return 1;
        tab.remove(name);
        return 0;
    }

    Q_INVOKABLE void removeSettingsAll() { //удаляет все настройки
        tab.clear();
    }

private:
    struct SettingData { //структура хранения значений настроек
        QString _default = ""; //значение по умолчанию
        QString _present = ""; //текущее значение

        SettingData() = default; //конструктор по умолчанию

        SettingData(QString _d, QString _p) {
            _default = _d;
            _present = _p;
        }

        void reset() { //сброс к значению по умолчанию
            _present = _default;
        }
    };

    QHash<QString, SettingData> tab;
    bool isCorrect(QString a){
        if(a.indexOf(" ") == -1) return 1;
        return 0;
    }
};

#endif // DS_H
