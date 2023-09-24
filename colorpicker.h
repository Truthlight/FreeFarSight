/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QSizeGrip>
#include <QWidget>
#include <QPushButton>
#include <QColor>
#include <QLabel>
#include <QPalette>
#include <QSpinBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QGroupBox>

#include "colorsquarish.h"
#include "design.h"
#include "widgettitlebar2.h"

class ColorPicker : public QDialog
{
    Q_OBJECT
public:
    ColorPicker(QColor color2, QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~ColorPicker();
    QColor getColor();
    void setColor(QColor color);
    void setWindowTitle(const QString &title);
    void paintEvent(QPaintEvent *event);
    void updateSpinBox();
    void updateSlider();
    void updateLabel();
    void disconnectSlots();
    void reconnectSlots();

private slots:
    void signalMousePressed(QColor color2);
    void reactToSliderColor(qint32 i);
    void reactToSpinBox();

Q_SIGNALS:
    void colorPicked(QColor color);
signals:
  void WindowTitleChanged();
private:
    QGridLayout m_MainLayout;
    WidgetTitleBar2 m_TitleBar;
    QSizeGrip m_SizeGrip;
    //QPixmap *m_Cache;

    ColorSquarish *squarish;
    QLabel *m_labelColorPick;
    QVBoxLayout *m_layoutV = new QVBoxLayout;
    QVBoxLayout *m_layoutV2 = new QVBoxLayout;
    QVBoxLayout *m_layoutV3 = new QVBoxLayout;
    QVBoxLayout *m_layoutV4 = new QVBoxLayout;
    QHBoxLayout *m_layoutH = new QHBoxLayout;
    QHBoxLayout *m_layoutH2 = new QHBoxLayout;
    QHBoxLayout *m_layoutH3 = new QHBoxLayout;
    QHBoxLayout *m_layoutH4 = new QHBoxLayout;
    QHBoxLayout *m_layoutRed = new QHBoxLayout;
    QHBoxLayout *m_layoutGreen = new QHBoxLayout;
    QHBoxLayout *m_layoutBlue = new QHBoxLayout;
    QSpinBox *m_spinRed;
    QSpinBox *m_spinGreen;
    QSpinBox *m_spinBlue;
    QLabel *m_labelRed;
    QLabel *m_labelGreen;
    QLabel *m_labelBlue;
    QPushButton *m_buttonOK;
    QPushButton *m_buttonCancel;
    QSlider *m_sliderColor;
    Design design;
    QColor color;
    QColor colorDef;
    QColor colorIni;
    QPixmap *background ;
};

#endif // COLORPICKER_H
