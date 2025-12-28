#include "gaugewidget.h"
#include <QPainter>
#include <QtMath>

GaugeWidget::GaugeWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(80, 80);
}

void GaugeWidget::setRange(double min, double max)
{
    if (min >= max) return;
    m_min = min;
    m_max = max;
}

void GaugeWidget::setValue(double v)
{
    m_value = qBound(m_min, v, m_max);
}

void GaugeWidget::setUnit(const QString &u)
{
    m_unit = u;
}

void GaugeWidget::setTitle(const QString &t)
{
    m_title = t;
}

void GaugeWidget::update_value()
{
    update();
}

void GaugeWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int w = width();
    int h = height();
    int side = qMin(w, h);

    QRectF rect((w - side) / 2 + 6,
                (h - side) / 2 + 6,
                side - 12,
                side - 12);

    // ===== Background circle =====
    QPen bgPen(QColor("#E0E0E0"), 8);
    p.setPen(bgPen);
    p.drawArc(rect, 0, 360 * 16);

    // ===== Ratio theo range =====
    double ratio = (m_value - m_min) / (m_max - m_min);
    ratio = qBound(0.0, ratio, 1.0);

    // ===== Chọn màu theo độ đầy gauge =====
    QColor fgColor;
    if (ratio > 2.0 / 3.0) {
        fgColor = QColor("#F44336");   // đỏ
    } else if (ratio > 0.5) {
        fgColor = QColor("#FF9800");   // cam
    } else {
        fgColor = QColor("#4CAF50");   // xanh
    }

    // ===== Value arc =====
    QPen fgPen(fgColor, 8);
    fgPen.setCapStyle(Qt::RoundCap);
    p.setPen(fgPen);

    int span = static_cast<int>(360.0 * ratio * 16);
    p.drawArc(rect, 90 * 16, -span);

    // ===== Text value =====
    p.setPen(Qt::black);
    QFont f = p.font();
    f.setBold(true);
    f.setPointSize(10);
    p.setFont(f);

    QString valueText = QString::number(m_value, 'f', 1) + m_unit;
    p.drawText(rect, Qt::AlignCenter, valueText);

    // ===== Title (nếu có) =====
    if (!m_title.isEmpty()) {
        QFont tf = p.font();
        tf.setBold(false);
        tf.setPointSize(8);
        p.setFont(tf);

        QRectF titleRect = rect;
        titleRect.translate(0, rect.height() / 2 - 10);
        p.drawText(titleRect, Qt::AlignHCenter | Qt::AlignBottom, m_title);
    }
}
