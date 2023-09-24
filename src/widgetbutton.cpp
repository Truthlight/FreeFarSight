/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/
#include "widgetbutton.h"


WidgetButton::WidgetButton(ButtonType type, QWidget *parent) : QAbstractButton(parent),
  m_Type   (type        ),
  m_State  (STATE_NORMAL),
  m_Normal (NULL        ),
  m_Hovered(NULL        ),
  m_Clicked(NULL        )
{
  setAttribute(Qt::WA_TranslucentBackground);
}

WidgetButton::~WidgetButton()
{
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;
}

void WidgetButton::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  InitPixmaps();
}

void WidgetButton::paintEvent(QPaintEvent  *event)
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

void WidgetButton::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_HOVERED;

  update();
}

void WidgetButton::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_NORMAL;

  update();
}

void WidgetButton::mousePressEvent(QMouseEvent *event)
{
  QAbstractButton::mousePressEvent(event);

  m_State = STATE_CLICKED;

  update();
}

void WidgetButton::mouseReleaseEvent(QMouseEvent *event)
{
  QAbstractButton::mouseReleaseEvent(event);

  if(underMouse()) m_State = STATE_HOVERED;
  else             m_State = STATE_NORMAL;

  update();
}

void WidgetButton::InitPixmaps()
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

  switch(m_Type)
  {
  case BUTTON_MINIMIZE:
    InitMinimize();
    break;
  case BUTTON_MAXIMIZE:
    InitMaximize();
    break;
  case BUTTON_CLOSE:
    InitClose();
    break;
  }
}

void WidgetButton::InitMinimize()
{
  //Button's border
  QPolygon border;

  border << QPoint(          0,            0)  // haut gauche
         << QPoint(width() - 1,            0)  //haut droit
         << QPoint(width() - 1, height() - 8)  //bas droit
         << QPoint(          0, height() - 8);  //bas gauche

  //Button's symbol
  QPolygon symbol;

  symbol << QPoint(          6.5, height() - 12) //haut gauche
         << QPoint(width() - 6.5, height() - 12)
         << QPoint(width() - 6.5, height() - 11)
         << QPoint(          6.5, height() - 11);

  //
  QPainter painter;

  //Normal
  painter.begin(m_Normal);

  painter.setPen  (QPen(0x2F2F2F));
  painter.setBrush(QBrush(0x2F2F2F));

  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen);
  painter.setBrush(QBrush(0xAAAAAA));

  painter.drawPolygon(symbol);

  painter.end();
  //

  //Hovered
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen);
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol);

  painter.end();
  //

  //Clicked
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen        );
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol);

  painter.end();
  //
}

void WidgetButton::InitMaximize()
{
  //Button's border
  QPolygon border;

  border << QPoint(          0,            0)//haut gauche
         << QPoint(width() - 1,            0)//haut droit
         << QPoint(width() - 1, height() - 8)
         << QPoint(          0, height() - 8);
  //

  //Button's symbol
  QPolygon symbol1, symbol2;

  symbol1 << QPoint(          6, height() - 14.5)
          << QPoint(width() - 6, height() - 14.5)
          << QPoint(width() - 6, height() - 15)
          << QPoint(          6, height() - 15);

  symbol2 << QPoint(          6, height() - 15)
          << QPoint(width() - 6, height() - 15)
          << QPoint(width() - 6, height() - 11)
          << QPoint(          6, height() - 11);
  //

  QPainter painter;

  //Normal
  painter.begin(m_Normal);

  painter.setPen  (QPen(0x2F2F2F));//couleur icone
  painter.setBrush(QBrush(0x2F2F2F)); //fond de l'icone

  painter.drawPolygon(border);

  painter.setPen  (QPen  (0xAAAAAA));//couleur dessin
  painter.setBrush(QBrush(0xAAAAAA));//remplissage

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(0xAAAAAA));//couleur dessin
  painter.setBrush(Qt::NoBrush);

  painter.drawPolygon(symbol2);

  painter.end();
  //

  //Hovered
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen  (QPen  (Qt::white));
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(Qt::white));
  painter.setBrush(Qt::NoBrush    );

  painter.drawPolygon(symbol2);

  painter.end();
  //

  //Clicked
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen  (QPen  (Qt::white));
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(Qt::white));
  painter.setBrush(Qt::NoBrush    );

  painter.drawPolygon(symbol2);

  painter.end();
  //
}

void WidgetButton::InitClose()
{
  //Button's border
  QPolygon border;

  border << QPoint(          0,            0)//haut gauche
         << QPoint(width() - 1,            0)//haut droit
         << QPoint(width() - 1, height() - 8)
         << QPoint(          0, height() - 8);
  //

  //Button's symbol
  QLine symbol1(QPoint(          7.5, height() - 15), QPoint(width() - 7.5, height() - 10));
  QLine symbol2(QPoint(          7.5, height() - 10), QPoint(width() - 7.5, height() - 15));
  //Qline (haut,bas)

  QPainter painter;

  //Normal
  painter.begin(m_Normal);

  painter.setPen  (QPen(0x2F2F2F));
  painter.setBrush(QBrush(0x2F2F2F));

  painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(0xAAAAAA), 1.4));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  //

  //Hovered
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(Qt::white), 1.4));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  //

  //Clicked
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (0x474747));
  painter.setBrush(QBrush(0x474747));

  painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(Qt::white), 1.4));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  //
}

