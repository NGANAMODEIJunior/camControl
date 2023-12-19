#include <QtCore/QCoreApplication>
#include <QThread> 
#include "camera.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    camera cacamera;
    //cacamera.sendOn();
    cacamera.sendBottom();
    QThread::msleep(5000);
    cacamera.sendTop();
    return a.exec();
}
