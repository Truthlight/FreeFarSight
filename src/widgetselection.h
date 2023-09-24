/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef WIDGETSELECTION_H
#define WIDGETSELECTION_H

#include <string>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>

class WidgetSelection : public QWidget
{
    Q_OBJECT

public:

    enum SelectionState
    {
        STATE_NORMAL, STATE_HOVERED, STATE_CLICKED
    };

    WidgetSelection(QWidget *parent = 0);
    ~WidgetSelection();

protected:
    void resizeEvent      (QResizeEvent *event);
    void paintEvent       (QPaintEvent  *event);
    void enterEvent       (QEvent       *event);
    void leaveEvent       (QEvent       *event);
    void mousePressEvent  (QMouseEvent  *event);
    void mouseReleaseEvent(QMouseEvent  *event);

private:
    SelectionState m_State  ;
    QPixmap    *m_Normal ;
    QPixmap    *m_Hovered;
    QPixmap    *m_Clicked;

    void InitPixmaps ();
    void Init();
};

#endif // WIDGETSELECTION_H
