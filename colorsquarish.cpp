/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "colorsquarish.h"

ColorSquarish::ColorSquarish(QWidget *parent, Qt::WindowFlags f) : QWidget (parent,f)//,
    //m_colorCursor(this)
{
    setFixedSize(360,255);
    //m_colorCursor.move(-5,-5);
    //m_colorCursor.resize(10,10);
}

ColorSquarish::~ColorSquarish()
{

}

void ColorSquarish::paintEvent(QPaintEvent* event)
{
    event->accept();
    QPainter painter(this);

    for(unsigned int i = 0; i < 360; ++i) // i = column (hue)
    {
        for(unsigned int j = 0; j < 255; ++j) // j = raw (saturation)
        {
            painter.setPen(QColor::fromHsv(i, j, 200));
            painter.drawPoint(i, 255 - j);
        }
    }
}

void ColorSquarish::mousePressEvent(QMouseEvent *event)
{
        QColor m_color = QColor::fromHsv(event->pos().x(),255-event->pos().y(),200);
        emit signalPress(m_color);
        //m_colorCursor.move(event->pos().x()-5,event->pos().y()-5);
}

void ColorSquarish::mouseMoveEvent(QMouseEvent *event)
{
    if (event->pos().x()<360 && event->pos().x()>0 && event->pos().y()<255 && event->pos().y()>0)
    {
        QColor m_color = QColor::fromHsv(event->pos().x(),255-event->pos().y(),200);
        emit signalPress(m_color);
        //m_colorCursor.move(event->pos().x()-5,event->pos().y()-5);
    }
}
