#ifndef VIEW_H
#define VIEW_H

#include "gaugewidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class view;
}
QT_END_NAMESPACE

class view : public QWidget
{
    Q_OBJECT

public:
    view(QWidget *parent = nullptr);
    ~view();
    void update_cpu_usage(double);
    void update_cpu_temperature(double);
    void update_ram(double);
    void update_cpu_freq(double);
    void update_cpu_load(double);
    void update_ram_used(double);
    void update_ram_cached(double);
    void update_ram_swap(double);
    void update_ram_free(double);
    void update_ram_total(double);
    void update_kernel_version(const QString &t);
    void update_uptime(const QString &string_value);
    void update_loadavg(double);

private:
    Ui::view *ui;
    GaugeWidget *cpu_usage;
    GaugeWidget *cpu_temperature;
    GaugeWidget *ram;
};
#endif // VIEW_H
