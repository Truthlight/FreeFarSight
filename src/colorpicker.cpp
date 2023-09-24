/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "colorpicker.h"

ColorPicker::ColorPicker(QColor color2, QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL),
    //m_Cache     (NULL),
    background  (NULL)
{
    color = color2;
    colorIni = color2;
    colorDef = color2;
    connect(this       , SIGNAL(WindowTitleChanged()),
            &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(440, 360);

    setWindowTitle("Free Far Sight");
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_DeleteOnClose,true);

    m_MainLayout.setMargin (0); // No space between window's element and the window's border
    m_MainLayout.setSpacing(3); // space between window's element

    m_TitleBar.setMinimumWidth(this->width());
    setLayout(&m_MainLayout);
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    squarish = new ColorSquarish(this);
    m_sliderColor = new QSlider (this);
    m_sliderColor->setOrientation(Qt::Vertical);
    m_sliderColor->setStyleSheet("QSlider::groove:vertical{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0"+color.name()+", stop:1 black);}"
                                 "QSlider::handle:vertical{background-color:white;height:3px;margin:0 -4px;border: 1px solid grey;}");
    m_sliderColor->setMaximum(255);
    m_sliderColor->setValue(255);
    m_labelColorPick = new QLabel (this);
    m_labelColorPick->setStyleSheet("QLabel{background-color:"+color.name()+";margin-bottom:10px;max-width:100px;}");
    m_spinRed = new QSpinBox (this);
    m_spinGreen = new QSpinBox (this);
    m_spinBlue = new QSpinBox (this);
    m_spinRed->setMaximum(255);
    m_spinGreen->setMaximum(255);
    m_spinBlue->setMaximum(255);
    m_spinRed->setValue(color.red());
    m_spinGreen->setValue(color.green());
    m_spinBlue->setValue(color.blue());
    m_labelRed = new QLabel(this);
    m_labelRed->setText("Red");
    m_labelRed->setMaximumWidth(40);
    m_labelGreen = new QLabel(this);
    m_labelGreen->setText("Green");
    m_labelGreen->setMaximumWidth(40);
    m_labelBlue = new QLabel(this);
    m_labelBlue->setText("Blue");
    m_labelBlue->setMaximumWidth(40);
    m_layoutRed->addWidget(m_labelRed);
    m_layoutRed->addWidget(m_spinRed);
    m_layoutGreen->addWidget(m_labelGreen);
    m_layoutGreen->addWidget(m_spinGreen);
    m_layoutBlue->addWidget(m_labelBlue);
    m_layoutBlue->addWidget(m_spinBlue);
    m_buttonOK = new QPushButton(this);
    m_buttonOK->setText("OK");
    m_buttonCancel = new QPushButton(this);
    m_buttonCancel->setText("Cancel");

    m_layoutH->addWidget(squarish);
    m_layoutH->addWidget(m_sliderColor);

    m_layoutV2->addWidget(m_labelColorPick);
    m_layoutV2->setMargin(5);

    m_layoutV3->addLayout(m_layoutRed);
    m_layoutV3->addLayout(m_layoutGreen);
    m_layoutV3->addLayout(m_layoutBlue);
    m_layoutV3->setMargin(8);

    m_layoutV4->addWidget(m_buttonOK);
    m_layoutV4->addWidget(m_buttonCancel);
    m_layoutV4->setMargin(5);

    m_layoutH2->addLayout(m_layoutV2);
    m_layoutH2->addLayout(m_layoutV3);
    m_layoutH2->addLayout(m_layoutV4);

    m_layoutV->addLayout(m_layoutH);
    m_layoutV->addLayout(m_layoutH2);

    m_MainLayout.addLayout(m_layoutV,1,0);

    QString style = design.getStyle();
    this->setStyleSheet(style+"QPushButton{max-width:100px;}");
    this->setLayout(&m_MainLayout);
    setWindowModality(Qt::WindowModal);
    this->show();

    QObject::connect (squarish,SIGNAL(signalPress(QColor)),this,SLOT(signalMousePressed(QColor)));
    QObject::connect (m_sliderColor,SIGNAL(valueChanged(int)),this,SLOT(reactToSliderColor(qint32)));
    QObject::connect (m_buttonOK,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect (m_buttonCancel,SIGNAL(clicked()),this,SLOT(reject()));
    QObject::connect (m_spinBlue,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::connect (m_spinRed,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::connect (m_spinGreen,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
}

ColorPicker::~ColorPicker()
{
    if(background  != NULL) delete background ;
    //if(m_Cache  != NULL) delete m_Cache ;
    //if(squarish  != NULL) delete squarish ;
    //if(m_labelColorPick  != NULL) delete m_labelColorPick ;
    //if(m_spinRed  != NULL) delete m_spinRed ;
    //if(m_spinGreen  != NULL) delete m_spinGreen ;
    //if(m_spinBlue  != NULL) delete m_spinBlue ;
    //if(m_labelRed  != NULL) delete m_labelRed ;
    //if(m_labelGreen  != NULL) delete m_labelGreen ;
    //if(m_labelBlue  != NULL) delete m_labelBlue ;
    //if(m_buttonOK  != NULL) delete m_buttonOK ;
    //if(m_buttonCancel  != NULL) delete m_buttonCancel ;
    //if(m_sliderColor  != NULL) delete m_sliderColor ;
}

QColor ColorPicker::getColor()
{
    return colorDef;
}

void ColorPicker::setColor(QColor color)
{
    disconnectSlots();
    reconnectSlots();
}

void ColorPicker::disconnectSlots()
{
    QObject::disconnect (squarish,SIGNAL(signalPress(QColor)),this,SLOT(signalMousePressed(QColor)));
    QObject::disconnect (m_sliderColor,SIGNAL(valueChanged(int)),this,SLOT(reactToSliderColor(qint32)));
    QObject::disconnect (m_spinBlue,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::disconnect (m_spinRed,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::disconnect (m_spinGreen,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
}

void ColorPicker::reconnectSlots()
{

    QObject::connect (squarish,SIGNAL(signalPress(QColor)),this,SLOT(signalMousePressed(QColor)));
    QObject::connect (m_sliderColor,SIGNAL(valueChanged(int)),this,SLOT(reactToSliderColor(qint32)));
    QObject::connect (m_spinBlue,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::connect (m_spinRed,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
    QObject::connect (m_spinGreen,SIGNAL(valueChanged(int)),this,SLOT(reactToSpinBox()));
}

void ColorPicker::signalMousePressed(QColor color2)
{
    disconnectSlots();
    color = color2;
    m_labelColorPick->setStyleSheet("QLabel{background-color:"+color.name()+";margin-bottom:10px;max-width:100px;}");
    m_sliderColor->setStyleSheet("QSlider::groove:vertical{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0"+color.name()+", stop:1 black);}"
                                 "QSlider::handle:vertical{background-color:white;height:3px;width:10px;margin:0 -4px;border: 1px solid grey;}");
    m_spinRed->setValue(color.red());
    m_spinGreen->setValue(color.green());
    m_spinBlue->setValue(color.blue());
    colorDef = color;
    reconnectSlots();
}

void ColorPicker::reactToSliderColor(qint32 i)
{
    disconnectSlots();
    qint32 red = static_cast<qint32> (i/(255/static_cast<float>(color.red())));
    qint32 green = static_cast<qint32> (i/(255/static_cast<float>(color.green())));
    qint32 blue = static_cast<qint32> (i/(255/static_cast<float>(color.blue())));
    QColor colorSlider (red,green,blue);
    m_labelColorPick->setStyleSheet("QLabel{background-color:"+colorSlider.name()+";margin-bottom:10px;max-width:100px;}");
    m_spinRed->setValue(colorSlider.red());
    m_spinGreen->setValue(colorSlider.green());
    m_spinBlue->setValue(colorSlider.blue());
    colorDef = colorSlider;
    reconnectSlots();
}

void ColorPicker::reactToSpinBox()
{
    disconnectSlots();
    colorDef = QColor (m_spinRed->value(),m_spinGreen->value(),m_spinBlue->value());
    m_sliderColor->setStyleSheet("QSlider::groove:vertical{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0"+colorDef.name()+", stop:1 black);}"
                                 "QSlider::handle:vertical{background-color:white;height:3px;width:10px;margin:0 -4px;border: 1px solid grey;}");
    m_labelColorPick->setStyleSheet("QLabel{background-color:"+colorDef.name()+";margin-bottom:10px;max-width:100px;}");
    reconnectSlots();
}

void ColorPicker::updateLabel()
{

}

void ColorPicker::updateSpinBox()
{
    m_spinRed->setValue(colorDef.red());
        m_spinGreen->setValue(colorDef.green());
        m_spinBlue->setValue(colorDef.blue());
}

void ColorPicker::updateSlider()
{

}

void ColorPicker::setWindowTitle(const QString &title)
{
  QDialog::setWindowTitle(title);
  emit WindowTitleChanged();
}

void ColorPicker::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

  QPolygon border;
  border << QPoint(0,0)
         << QPoint(width(),0)
         << QPoint(width(), height())
         << QPoint(0, height());

  QPainter painter (this);

  background  = new QPixmap(size());
  background ->fill(Qt::transparent);

  painter.setPen(QPen(QBrush(0x201F1F),2));
  painter.setBrush(QBrush(0x2F2F2F));

  painter.drawPolygon(border);
  painter.end();
  painter.drawPixmap(0, 0, *background );
}
