/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef WIDGETCHOOSEPROCESS_H
#define WIDGETCHOOSEPROCESS_H

#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QWidget>
#include <QListView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QStringListModel>
#include <QMessageBox>
#include <vector>
#include <sstream>

#include "process.h"
#include "mainwidget.h"
#include "widgettitlebar.h"

class WidgetChooseProcess : public QWidget
{
    Q_OBJECT

public:
    WidgetChooseProcess(std::vector<DWORD> &m_processIDHandle);
    ~WidgetChooseProcess();
    void SetProcessIDVector(std::vector <DWORD> &processIDHandle);
    void setWindowTitle(const QString &title);
    void paintEvent(QPaintEvent *event);//ok

private:

    QGridLayout m_MainLayout;
    WidgetTitleBar m_TitleBar;
    QSizeGrip m_SizeGrip;
    QPixmap *m_Cache;

    QListView *m_listview;
    QPushButton *m_buttonOK;
    QPushButton *m_buttonSelect;
    QLabel *m_label;
    std::vector<DWORD>m_processIDHandle;
    QVBoxLayout *layoutV = new QVBoxLayout;
    QHBoxLayout *layoutH = new QHBoxLayout;

    QStringList m_listProcess;
    DWORD HandleIDSelected;

signals:
    void WindowTitleChanged();

private slots:
    void WindowSelected();
    void ChooseProcess();
};

#endif // WIDGETCHOOSEPROCESS_H
