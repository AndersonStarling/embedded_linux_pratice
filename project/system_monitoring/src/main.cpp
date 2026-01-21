#include "view.h"
#include "controller.h"
#include "model.h"
#include "factory.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view w;

    qDebug() << "App started!";

    model_factory * f = new model_factory();
    model m(f->create_cpu(), f->create_disk(), f->create_mem(), f->create_system());
    m.start_thread();
    controller c(&w, &m);
    w.show();

    return a.exec();

    return 0;
}
