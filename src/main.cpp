#include <QApplication>
#include "core.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    coremod x;
    x.init();

    return a.exec();
}

