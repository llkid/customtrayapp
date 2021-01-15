#include "customtrayapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customtrayapp w;
    w.show();
    return a.exec();
}
