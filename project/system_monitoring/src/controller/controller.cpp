#include "controller.h"
#include "view.h"
#include <QRandomGenerator>
#include "model.h"

controller::controller(view *v, model *m, QObject *parent)
    : QObject(parent),
    m_view(v), m_model(m)
{
    // connect timer
    connect(&m_timer, &QTimer::timeout,
            this, &controller::update_data);

    m_timer.start(2000);
}

void controller::update_data(void)
{

    // double cpuUsage = m_model->cpuUsage();
    // double cpuTemp  = m_model->cpuTemp();
    // double ramUsed  = m_model->ramUsed();
    // double ramTotal = m_model->ramTotal();
    // double cpuFreq  = m_model->cpuFreq();

    // double cpu_usage = QRandomGenerator::global()->bounded(0, 100);
    // double cpu_temperature = QRandomGenerator::global()->generateDouble() * 100.0;
    // double ram = QRandomGenerator::global()->generateDouble() * 10.0;
    // double cpu_freq = QRandomGenerator::global()->generateDouble();
    // double cpu_load = QRandomGenerator::global()->generateDouble() + 2.0;
    // double ram_used = QRandomGenerator::global()->generateDouble() + 3.0;
    // double ram_cached = QRandomGenerator::global()->generateDouble();
    // double ram_swap = QRandomGenerator::global()->generateDouble() + 1.0;
    // double ram_free = QRandomGenerator::global()->generateDouble() + 3.0;
    // QString kernel_version = "linux_6.4";
    // QString uptime = "15:38:40";
    // double load_avg = QRandomGenerator::global()->generateDouble() + 1.0;

    double cpu_usage = m_model->get_cpu_usage();
    double cpu_temperature = m_model->get_cpu_temp();
    double cpu_freq = QRandomGenerator::global()->generateDouble();
    double cpu_load = QRandomGenerator::global()->generateDouble() + 2.0;
    double ram_used = (m_model->get_mem_total() - m_model->get_mem_free()) / (1024 * 1024);
    double ram_cached = m_model->get_cached() / (1024 * 1024);
    double ram_swap = m_model->get_swap_cached() / (1024 * 1024);
    double ram_free = m_model->get_mem_free() / (1024 * 1024);
    double ram_total = m_model->get_mem_total() / (1024 * 1024);
    QString kernel_version =  QString::fromStdString(m_model->get_kernel_version());
    QString uptime = QString::fromStdString("15:38:40");
    double load_avg = m_model->get_load_average();

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
    m_view->update_loadavg(load_avg);
}










