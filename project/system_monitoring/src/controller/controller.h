#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class view;
class model;

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(view *v, model * m, QObject *parent = nullptr);

private slots:
    void update_data(void);

private:
    view * m_view;
    model *m_model;
    QTimer m_timer;
};

#endif
