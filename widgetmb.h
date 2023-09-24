/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef WIDGETMB_H
#define WIDGETMB_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QSizeGrip>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

//#include "widgettitlebar.h"
#include "widgettitlebar2.h"
#include "design.h"

class widgetMB:public QDialog
{
    Q_OBJECT
public:
    widgetMB(QString title, QString message, QWidget *parent=0);
    ~widgetMB();
    void setWindowTitle(const QString &title);
    void paintEvent(QPaintEvent *event);

private:

    QGridLayout m_MainLayout;
    WidgetTitleBar2 m_TitleBar;
    QSizeGrip m_SizeGrip;
    QPixmap *m_Cache;
    QPushButton *m_ButtonOK;
    QLabel *m_message;
    QHBoxLayout *m_layoutButtonOK = new QHBoxLayout;
    QPixmap *background ;

signals:
  void WindowTitleChanged();
};

#endif // WIDGETMB_H
