
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

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <stdio.h>
#include <QtWidgets/QPushButton>

#include "node.h"
#include "drilldownchart.h"
#include "drilldownslice.h"

QT_CHARTS_USE_NAMESPACE


int main(int argc, char *argv[])
{
	node X("..");
	X.traverse(&X);

	QApplication a(argc, argv);

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	QMainWindow window;
	QPieSeries *mySeries = new QPieSeries(&window);
	mySeries->setName("Disk Analyzer - Root");

	DrilldownChart *chart = new DrilldownChart();
	chart->setTheme(QChart::ChartThemeLight);
	chart->setAnimationOptions(QChart::AllAnimations);
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignRight);

	QList<node*> childrenNodes;
	for (int i=0; i<X.children.size();i++)
		childrenNodes.push_back(X.children[i]);
	QList<long long int> sizes;
	for (int j=0; j<X.children.size();j++)
		sizes << X.children[j]->size;


			foreach (node* childNode, childrenNodes) {
			QPieSeries *series = new QPieSeries(&window);
			series->setName(QT_STRINGIFY(childNode.name + " as a directory"));
			*series << new DrilldownSlice(childNode->size, childNode->name.c_str(), mySeries, childNode, chart, &window);

			QObject::connect(series, SIGNAL(clicked(QPieSlice*)), chart, SLOT(handleSliceClicked(QPieSlice*)));

			*mySeries << new DrilldownSlice(series->sum(), childNode->name.c_str(), series, childNode, chart, &window);
		}

	QObject::connect(mySeries, SIGNAL(clicked(QPieSlice*)), chart, SLOT(handleSliceClicked(QPieSlice*)));

	chart->changeSeries(mySeries);

/*
	QPushButton *m_button = new QPushButton("&Download", &window);
	DrilldownChart::connect(m_button, SIGNAL (released()), &window, SLOT (handleButton()));
*/


	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	window.setCentralWidget(chartView);
	window.resize(800, 500);

	window.show();
	return a.exec();

}