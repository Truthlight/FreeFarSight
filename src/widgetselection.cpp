/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "widgetselection.h"

WidgetSelection::WidgetSelection(QWidget *parent):QWidget(),
  m_Normal (NULL        ),
  m_Hovered(NULL        ),
  m_Clicked(NULL        )
{
  setAttribute(Qt::WA_TranslucentBackground);
}

WidgetSelection::~WidgetSelection()
{
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;
}

void WidgetSelection::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  InitPixmaps();
}

void WidgetSelection::paintEvent(QPaintEvent  *event)
{
  Q_UNUSED(event);

  QPainter painter(this);

  if(isEnabled())
  {
    switch(m_State)
    {
    case STATE_NORMAL:
      if(m_Normal  != NULL) painter.drawPixmap(0, 0, *m_Normal );
      break;
    case STATE_HOVERED:
      if(m_Hovered != NULL) painter.drawPixmap(0, 0, *m_Hovered);
      break;
    case STATE_CLICKED:
      if(m_Clicked != NULL) painter.drawPixmap(0, 0, *m_Clicked);
      break;
    }
  }
  else
  {
    if(m_Normal != NULL) painter.drawPixmap(0, 0, *m_Normal);
  }
}

void WidgetSelection::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_HOVERED;

  update();
}

void WidgetSelection::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_NORMAL;

  update();
}

void WidgetSelection::mousePressEvent(QMouseEvent *event)
{
  QWidget::mousePressEvent(event);

  m_State = STATE_CLICKED;

  update();
}

void WidgetSelection::mouseReleaseEvent(QMouseEvent *event)
{
  QWidget::mouseReleaseEvent(event);

  if(underMouse()) m_State = STATE_HOVERED;
  else             m_State = STATE_NORMAL;

  update();
}

void WidgetSelection::InitPixmaps()
{
  // Delete previous button
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;

  m_Normal  = new QPixmap(size());
  m_Hovered = new QPixmap(size());
  m_Clicked = new QPixmap(size());

  m_Normal ->fill(Qt::transparent);
  m_Hovered->fill(Qt::transparent);
  m_Clicked->fill(Qt::transparent);

  Init();
}

void WidgetSelection::Init()
{
    QPolygon border;
      border << QPoint(      0, 0)  // haut gauche
             << QPoint(width(), 0)  //haut droit
             << QPoint(width(), height())  //bas droit
             << QPoint(      0, height());  //bas gauche
      //Button's symbol
      QPolygon symbol;
      symbol << QPoint(width()/2 - 4, height()/2 - 4) //haut gauche
             << QPoint(width()/2 + 4, height()/2 - 4)
             << QPoint(width()/2 + 4, height()/2 + 4)
             << QPoint(width()/2 - 4, height()/2 + 4);

      QPolygon symbol2;
    symbol2 << QPoint(width()/2 - 4, 0)
             << QPoint(width()/2, height()) ;

    QPolygon symbol3;
    symbol3 << QPoint(0, height()/2) //haut gauche
             << QPoint(width(), height()/2) ;


    QPainter painter;
      //Normal
      painter.begin(m_Normal);
      painter.setPen  (QPen(0x201F1F));
      painter.setBrush(QBrush(0x201F1F));
      painter.drawPolygon(border);

      painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(0x201F1F));
      painter.drawPolygon(symbol);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(Qt::NoBrush);
      painter.drawPolygon(symbol2);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(Qt::NoBrush));
      painter.drawPolygon(symbol2);

      painter.end();
      //
      //Hovered
      painter.begin(m_Hovered);
      painter.setPen  (QPen(0x201F1F));
      painter.setBrush(QBrush(0x201F1F));
      painter.drawPolygon(border);

      painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(0x474747));
      painter.drawPolygon(symbol);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(Qt::NoBrush);
      painter.drawPolygon(symbol2);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(Qt::NoBrush));
      painter.drawPolygon(symbol2);

      painter.end();
      //
      //Clicked
      painter.begin(m_Clicked);
      painter.setPen  (QPen(0x201F1F));
      painter.setBrush(QBrush(0x201F1F));
      painter.drawPolygon(border);

      painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(0x80B240));
      painter.drawPolygon(symbol);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(Qt::NoBrush);
      painter.drawPolygon(symbol2);

    painter.setPen  (QPen(0x474747));
      painter.setBrush(QBrush(Qt::NoBrush));
      painter.drawPolygon(symbol2);

      painter.end();
      //

}
