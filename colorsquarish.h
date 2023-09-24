/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef COLORSQUARISH_H
#define COLORSQUARISH_H

//#include "colorcursor.h"
#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QPaintEvent>
#include <QMessageBox>

class ColorSquarish : public QWidget
{
    Q_OBJECT
public:
    ColorSquarish(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~ColorSquarish();
    //QColor getColor();
protected:
    void paintEvent(QPaintEvent* event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
private:
    //ColorCursor m_colorCursor;
Q_SIGNALS:
    void signalPress(QColor);
};

#endif // COLORSQUARISH_H
