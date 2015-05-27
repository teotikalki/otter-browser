/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_SOURCEVIEWERWIDGET_H
#define OTTER_SOURCEVIEWERWIDGET_H

#include <QtWidgets/QPlainTextEdit>

namespace Otter
{

class SourceViewerWidget;

class MarginWidget : public QWidget
{
	Q_OBJECT

public:
	MarginWidget(SourceViewerWidget *parent = NULL);

public slots:
	void updateNumbers(const QRect &rectangle, int offset);
	void setAmount(int amount = -1);

protected:
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	bool event(QEvent *event);

private:
	SourceViewerWidget *m_sourceViewer;
	int m_lastClickedLine;
};

class SourceViewerWidget : public QPlainTextEdit
{
	Q_OBJECT

public:
	explicit SourceViewerWidget(QWidget *parent = NULL);

	void setZoom(int zoom);
	int getZoom() const;

protected:
	void resizeEvent(QResizeEvent *event);

private:
	MarginWidget *m_marginWidget;
	int m_zoom;

friend class MarginWidget;
};

}

#endif