/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QCHARTVIEW_H
#define QCHARTVIEW_H

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QChart>
#include <QtWidgets/QGraphicsView>

class QGraphicsScene;
class QRubberBand;

QT_CHARTS_BEGIN_NAMESPACE

class QChartViewPrivate;

class QT_CHARTS_EXPORT QChartView : public QGraphicsView
{
    Q_OBJECT
    Q_ENUMS(RubberBand)
public:

    enum  RubberBand {
        NoRubberBand = 0x0,
        VerticalRubberBand = 0x1,
        HorizonalRubberBand = 0x2,
        RectangleRubberBand = 0x3
    };

    Q_DECLARE_FLAGS(RubberBands, RubberBand)

    explicit QChartView(QWidget *parent = 0);
    explicit QChartView(QChart *chart, QWidget *parent = 0);
    ~QChartView();

    void setRubberBand(const RubberBands &rubberBands);
    RubberBands rubberBand() const;

    QChart *chart() const;
    void setChart(QChart *chart);

protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    QScopedPointer<QChartViewPrivate> d_ptr;
    Q_DISABLE_COPY(QChartView)
};

QT_CHARTS_END_NAMESPACE

#endif // QCHARTVIEW_H