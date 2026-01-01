#include "view.h"
#include "controller.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view w;
    model m;
    controller c(&w, &m);

    m.start_thread();

    w.show();

    return a.exec();

    return 0;
}
