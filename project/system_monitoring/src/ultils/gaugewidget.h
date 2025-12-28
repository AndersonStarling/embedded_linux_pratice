#ifndef GAUGEWIDGET_H
#define GAUGEWIDGET_H

#include <QWidget>

class GaugeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GaugeWidget(QWidget *parent = nullptr);

    void setRange(double min, double max);
    void setValue(double v);
    void setUnit(const QString &u);
    void setTitle(const QString &t);
    void update_value();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    double m_min = 0.0;
    double m_max = 100.0;
    double m_value = 0.0;
    QString m_unit = "%";
    QString m_title;
};

#endif // GAUGEWIDGET_H
