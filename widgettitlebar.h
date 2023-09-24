/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef WIDGETTITLEBAR_H
#define WIDGETTITLEBAR_H

//#include <string>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QBitmap>
#include <QApplication>
#include <QMouseEvent>

#include "widgetbutton.h"


class WidgetTitleBar : public QWidget
{
    Q_OBJECT

    public:
      WidgetTitleBar(QWidget *parent = 0);
      ~WidgetTitleBar();

    public slots:
      void UpdateWindowTitle();
      void Minimized();
      void Maximized();
      void Quit();

    protected:
      void resizeEvent (QResizeEvent *event);
      void paintEvent (QPaintEvent *event);
      void mousePressEvent (QMouseEvent *event);
      void mouseReleaseEvent (QMouseEvent *event);
      void mouseMoveEvent (QMouseEvent *event);

    private:
      QPixmap *m_Cache;
      QLabel m_Title;
      WidgetButton m_Minimize;
      //WidgetButton m_Maximize;
      WidgetButton m_Close;

      int m_DiffX;
      int m_DiffY;
};

#endif // WIDGETTITLEBAR_H
