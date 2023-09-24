/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "widgettitlebar2.h"

#include "widgettitlebar.h"

WidgetTitleBar2::WidgetTitleBar2(QWidget *parent) : QWidget(parent),
  m_Cache   (NULL),
  m_Title   (this)
{
  setFixedHeight(29);
  //setFixedWidth(parent->width());

  setAttribute(Qt::WA_TranslucentBackground);

  m_Title.setStyleSheet("color: #80B240; font-family: BOLD; font-weight: bold; font-size: 12px; background-color:#201F1F");

  UpdateWindowTitle();
}

WidgetTitleBar2::~WidgetTitleBar2()
{
  if(m_Cache != NULL) delete m_Cache;
}

void WidgetTitleBar2::UpdateWindowTitle()
{
  m_Title.setText(window()->windowTitle());
}

void WidgetTitleBar2::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  if(m_Cache != NULL) delete m_Cache; // Remove old cache

  m_Cache = new QPixmap(size());  // Create a cache with same size as the widget

  m_Cache->fill(QColor(32, 31, 31));  // Create a the transparent background

  QLabel *logo = new QLabel(this);
  logo->setPixmap(QPixmap(":/images/logo.png"));
  logo->setStyleSheet("QLabel {background-color:transparent;}");

  logo->move(8,2);
  logo->resize(25,25);


  m_Title.move(28,7);
}

void WidgetTitleBar2::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  if(m_Cache != NULL)
  {
    QPainter painter(this);

    painter.drawPixmap(0, 0, *m_Cache);
  }
}

void WidgetTitleBar2::mousePressEvent(QMouseEvent *event)//bouger fenetre
{
  m_DiffX = event->x();
  m_DiffY = event->y();

  setCursor(QCursor(Qt::SizeAllCursor));
}

void WidgetTitleBar2::mouseReleaseEvent(QMouseEvent *event)//bouger fenetre
{
  Q_UNUSED(event);

  setCursor(QCursor(Qt::ArrowCursor));
}

void WidgetTitleBar2::mouseMoveEvent(QMouseEvent *event)//bouger fenetre
{
  QPoint p = event->globalPos();

  window()->move(p.x() - m_DiffX, p.y() - m_DiffY);
}
