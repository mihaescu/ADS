#include "DataCompression.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DC w;
    w.show();
    return a.exec();
}
