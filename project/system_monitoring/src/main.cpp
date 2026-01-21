#include "view.h"
#include "controller.h"
#include "model.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view w;

    qDebug() << "App started!";

    cpu_info_linux * cpu   = new cpu_info_linux();
    disk_info_linux * disk = new disk_info_linux();
    mem_info_linux * mem = new mem_info_linux();
    system_info_linux * system = new system_info_linux();

    model m(cpu, disk, mem, system);
    m.start_thread();
    controller c(&w, &m);
    w.show();

    return a.exec();

    return 0;
}
