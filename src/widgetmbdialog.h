/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef WIDGETMBDIALOG_H
#define WIDGETMBDIALOG_H

#include <QString>
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QSizeGrip>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QListView>
#include <QStringListModel>
#include <QDirModel>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QListWidget>
#include <QMessageBox>
#include <QDialogButtonBox>

//#include "UIressources\widgettitlebar.h"
#include "widgettitlebar2.h"
#include "design.h"
#include "widgetmb.h"

class widgetMBDialog:public QDialog
{
    Q_OBJECT
public:
    widgetMBDialog(QString title, QString message, QStringList list, QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~widgetMBDialog();
    void setWindowTitle(const QString &title);
    void paintEvent(QPaintEvent *event);
    QString getNameFile();
private slots:
    //QString setFileName();

Q_SIGNALS:

private:

    QGridLayout m_MainLayout;
    WidgetTitleBar2 m_TitleBar;
    QSizeGrip m_SizeGrip;
    //QPixmap *m_Cache;
    QPushButton *m_ButtonOK;
    QPushButton *m_ButtonCancel;
    QLabel *m_message;
    QHBoxLayout *m_layoutButtonOK = new QHBoxLayout;
    QHBoxLayout *m_layoutButtonCancel = new QHBoxLayout;
    QHBoxLayout *m_layoutButton = new QHBoxLayout;
    QPixmap *background ;
    QListView *m_listView;
    QStringListModel *m_model;
    QLabel *m_label;
    QString fileName;
    QListWidget *m_listWidget;
    QStringList m_stringList;
    QDialogButtonBox *m_dialogButton;

signals:
  void WindowTitleChanged();
};

#endif // WIDGETMBDIALOG_H

