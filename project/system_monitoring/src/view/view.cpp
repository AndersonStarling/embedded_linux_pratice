#include "gaugewidget.h"
#include "view.h"
#include "ui_view.h"
#include <QVBoxLayout>

view::view(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

    /* cpu usage */
    this->cpu_usage = new GaugeWidget(this);
    this->cpu_usage->setTitle("CPU");
    this->cpu_usage->setRange(0, 100);
    this->cpu_usage->setUnit("%");
    this->cpu_usage->setValue(0);
    this->cpu_usage->update_value();
    QVBoxLayout *layout_cpu_usage = new QVBoxLayout(ui->cpu_usage_custom);
    layout_cpu_usage->setContentsMargins(0,0,0,0);
    layout_cpu_usage->addWidget(cpu_usage);

    /* cpu temperature */
    this->cpu_temperature = new GaugeWidget(this);
    this->cpu_temperature->setTitle("TEMP");
    this->cpu_temperature->setRange(0, 100);
    this->cpu_temperature->setUnit("°C");
    this->cpu_temperature->setValue(0);
    this->cpu_temperature->update_value();
    QVBoxLayout *layout_cpu_temperature = new QVBoxLayout(ui->cpu_temperature_custom);
    layout_cpu_temperature->setContentsMargins(0,0,0,0);
    layout_cpu_temperature->addWidget(cpu_temperature);

    /* ram */
    this->ram = new GaugeWidget(this);
    this->ram->setTitle("RAM");
    this->ram->setRange(0, 16.0);
    this->ram->setUnit(" GB");
    this->ram->setValue(0);
    this->ram->update_value();
    QVBoxLayout *layout_ram = new QVBoxLayout(ui->ram_custom);
    layout_ram->setContentsMargins(0,0,0,0);
    layout_ram->addWidget(ram);

    /* init view */
    update_cpu_usage(0);
    update_cpu_temperature(0);
    update_ram(0);
    update_cpu_freq(0);
    update_cpu_load(0);
    update_ram_used(0);
    update_ram_cached(0);
    update_ram_swap(0);
    update_ram_free(0);
    update_kernel_version("");
    update_uptime("");
    update_loadavg(0);

}

void view::switch_tab() 
{
    int idx = (ui->tabWidget->currentIndex() + 1) % ui->tabWidget->count();
    ui->tabWidget->setCurrentIndex(idx);
}

void view::update_cpu_usage(double value)
{
    this->cpu_usage->setValue(value);
    this->cpu_usage->update_value();
}

void view::update_cpu_temperature(double value)
{
    this->cpu_temperature->setValue(value);
    this->cpu_temperature->update_value();
}

void view::update_ram(double value)
{
    this->ram->setValue(value);
    this->ram->update_value();
}

void view::update_ram_total(double value)
{
    ui->ram_used_total->setText(QString::number(value, 'f', 1) + "GB");
    ui->ram_cached_total->setText(QString::number(value, 'f', 1) + "GB");
    ui->ram_swap_total->setText(QString::number(value, 'f', 1) + "GB");
    ui->ram_free_total->setText(QString::number(value, 'f', 1) + "GB");
}


void view::update_cpu_freq(double value)
{
    ui->cpu_freq_label_value->setText(QString::number(value, 'f', 1) + " Ghz");
}

void view::update_cpu_load(double value)
{
    ui->cpu_load_label_value->setText(QString::number(value, 'f', 1));
}

void view::update_ram_used(double value)
{
    ui->ram_used->setText(QString::number(value, 'f', 1));
}

void view::update_ram_cached(double value)
{
    ui->ram_cached->setText(QString::number(value, 'f', 1));
}

void view::update_ram_swap(double value)
{
    ui->ram_swap->setText(QString::number(value, 'f', 1));
}

void view::update_ram_free(double value)
{
    ui->ram_free->setText(QString::number(value, 'f', 1));
}

void view::update_kernel_version(const QString &string_value)
{
    ui->kernel_version_label_value->setText(string_value);
}

void view::update_uptime(const QString &string_value)
{
    ui->uptime_label_value->setText(string_value);
}

void view::update_loadavg(double value)
{
    ui->load_average_label_value->setText(QString::number(value, 'f', 1));
}

view::~view()
{
    delete ui;
}
