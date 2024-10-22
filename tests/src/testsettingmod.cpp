#include <QTest>
#include "ds.h"
#include "qtestcase.h"
#include "settingsmod.h"
#include "loader.h"

class TestSetting: public QObject
{
    Q_OBJECT
private slots:
    void testSettingData(){
        Settings a;
        QCOMPARE(a.addSetting("TEST", "1"), false);
        QCOMPARE(a.addSetting("TEST", "1"), true);
        QCOMPARE(a.removeSetting("TEST"), false);
        QCOMPARE(a.removeSetting("TEST"), true);
        QCOMPARE(a.addSetting("TEST", "1", "1"), false);
        QCOMPARE(a.addSetting("TEST", "1", "1"), true);
        a.removeSettingsAll();
        a.addSetting("TEST", "1", "5");
        QCOMPARE(a.getValue("TEST"), "5");
        QCOMPARE(a.getDefaultValue("TEST"), "1");
        QCOMPARE(a.existsName("TEST"), true);
        a.resetAllSettings();
        QCOMPARE(a.getValue("TEST"), "1");
        QCOMPARE(a.getNames(), {"TEST"});
        QCOMPARE(a.size(), 1);
        a.removeSettingsAll();
        QCOMPARE(a.size(), 0);
        QCOMPARE(a.isEmpty(), 1);
    }
    void testLoader(){
        QString str = "TEST 1 4", str2;
        QFile file("test.txt");
        file.remove();
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << str;
            file.close();
        }
        Loader a("test.txt");
        QCOMPARE(a.getContent(str2), 0);
        QCOMPARE(str, str2);
        QCOMPARE(a.setContent(str+str), 0);
        QCOMPARE(a.getContent(str2), 0);
        QCOMPARE(str+str, str2);
    }
    void testSettingMod(){
        QString str = "TEST 1 4\nTEST2 5 9";
        QFile file("test.txt");
        file.remove();
        if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            QTextStream stream(&file);
            stream << str;
            file.close();
        }
        SettingsMod a("test.txt");
        Settings b;
        a.loadFile(b);
        qDebug() << b.getNames();
        QCOMPARE(b.existsName("TEST"), true);
        QCOMPARE(b.existsName("TEST2"), true);
    }
};

QTEST_MAIN(TestSetting);
#include "testsettingmod.moc"
