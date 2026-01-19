#include "controller.h"
#include "view.h"
#include <QDebug>
#include <fcntl.h>
#include <unistd.h>
#include "model.h"

controller::controller(view *v, model *m, QObject *parent)
    : QObject(parent),
    m_view(v), m_model(m)
{
    // connect timer
    connect(&m_timer, &QTimer::timeout,
            this, &controller::update_data);

    this->fifo_fd = open("/tmp/qt_cmd", O_RDWR | O_NONBLOCK);
    if(this->fifo_fd < 0)
    {
        qDebug() << "open failed";
    }

    this->fifo_notifier = new QSocketNotifier(this->fifo_fd, QSocketNotifier::Read, this);

    connect(this->fifo_notifier, &QSocketNotifier::activated, this, [=](int)
    {
        char buf[64] = {0};
        int n = read(this->fifo_fd, buf, sizeof(buf)-1);
        if (n > 0) {
            QString cmd = QString::fromLocal8Bit(buf).trimmed();
            if (cmd == "tab") 
            {
                m_view->switch_tab();
            }
        }
    });

    m_timer.start(2000);
}

void controller::update_data(void)
{

    double cpu_usage = m_model->get_cpu_usage();
    double cpu_temperature = m_model->get_cpu_temp();
    double cpu_freq = m_model->get_cpu_freq();
    double cpu_load = m_model->get_load_average();
    double ram_used = ((double)m_model->get_mem_total() - (double)m_model->get_mem_free()) / (1024 * 1024);
    double ram_cached = (double)m_model->get_cached() / (1024 * 1024);
    double ram_swap = (double)m_model->get_swap_cached() / (1024 * 1024);
    double ram_free = (double)m_model->get_mem_free() / (1024 * 1024);
    double ram_total = (double)m_model->get_mem_total() / (1024 * 1024);
    QString kernel_version =  QString::fromStdString(m_model->get_kernel_version());
    double uptime = m_model->get_up_time();
    QString uptime_label_bottom = QString::fromStdString("test");
    double load_avg = m_model->get_load_average();
    QString date_time = QString::fromStdString(m_model->get_date_time());

    m_view->update_ram_total(ram_total);
    m_view->update_cpu_usage(cpu_usage);
    m_view->update_cpu_temperature(cpu_temperature);
    m_view->update_ram(ram_used);
    m_view->update_cpu_freq(cpu_freq);
    m_view->update_cpu_load(cpu_load);
    m_view->update_ram_used(ram_used);
    m_view->update_ram_cached(ram_cached);
    m_view->update_ram_swap(ram_swap);
    m_view->update_ram_free(ram_free);
    m_view->update_kernel_version(kernel_version);
    m_view->update_uptime(uptime);
    m_view->update_uptime_label_bottom(date_time);
    m_view->update_loadavg(load_avg);
}










