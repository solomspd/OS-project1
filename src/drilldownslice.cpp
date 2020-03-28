/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "drilldownslice.h"

QT_CHARTS_USE_NAMESPACE

DrilldownSlice::DrilldownSlice(qreal value, QString prefix, QAbstractSeries *drilldownSeries, node *n, DrilldownChart *chart, QMainWindow* window)
        : m_drilldownSeries(drilldownSeries),
          m_prefix(prefix) {
    setValue(value);
    updateLabel();
    setLabelFont(QFont("Arial", 8));
    connect(this, SIGNAL(percentageChanged()), this, SLOT(updateLabel()));
    connect(this, SIGNAL(hovered(bool)), this, SLOT(showHighlight(bool)));
    this->n = n;
    this->w = window;
    this->chart = chart;
}

DrilldownSlice::~DrilldownSlice() {

}

QAbstractSeries *DrilldownSlice::drilldownSeries() {
    QPieSeries* mySeries = static_cast<QPieSeries *>(m_drilldownSeries);
    mySeries->clear();
            foreach (node *childNode, n->children) {
            QPieSeries *series = new QPieSeries(w);
            series->setName(QT_STRINGIFY(childNode.name + " as a directory"));
            *series << new DrilldownSlice(childNode->children.size(), childNode->name.c_str(), mySeries,
                                          childNode, chart, w);

            QObject::connect(series, SIGNAL(clicked(QPieSlice * )), chart, SLOT(handleSliceClicked(QPieSlice * )));

            (*mySeries) << new DrilldownSlice(series->sum(), childNode->name.c_str(), series, childNode, chart, w);
        }
    return m_drilldownSeries;
}

void DrilldownSlice::updateLabel() {
    QString label = m_prefix;
    label += ", ";
    label += QString::number(this->value());
    label += ", ";
    label += QString::number(this->percentage() * 100, 'f', 1);
    label += "%";
    setLabel(label);
}

void DrilldownSlice::showHighlight(bool show) {
    setLabelVisible(show);
    setExploded(show);
}

node *DrilldownSlice::getNode() {
    return n;
}

#include "moc_drilldownslice.cpp"
