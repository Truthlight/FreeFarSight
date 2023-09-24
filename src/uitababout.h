/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef UITABABOUT_H
#define UITABABOUT_H

//#include "mainwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTextEdit>

class UITabAbout : public QWidget
{
public:
    UITabAbout(QWidget *parent=0);
    ~UITabAbout();
protected:
    QLabel *m_label = new QLabel;
    QLabel *m_label2 = new QLabel;
    QLabel *m_labelTuto = new QLabel;
    QLabel *m_labelDisclaimer = new QLabel;
    QTextEdit *m_textTuto = new QTextEdit;
    QTextEdit *m_textDisclaimer = new QTextEdit;
    QVBoxLayout *m_layout = new QVBoxLayout;
};

#endif // UITABABOUT_H
