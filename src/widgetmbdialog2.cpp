/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "widgetmbdialog2.h"


widgetMBDialog2::widgetMBDialog2(QString title, QString message, QStringList list, QWidget *parent, Qt::WindowFlags f):QDialog(parent,f),
    m_MainLayout(this),
    m_TitleBar  (this),
    m_SizeGrip  (NULL),
    //m_Cache     (NULL),
    background(NULL)
{
    connect(this       , SIGNAL(WindowTitleChanged()),
            &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    resize(200, 200);

    setWindowTitle(title);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_DeleteOnClose,true);

    m_MainLayout.setMargin (0); // No space between window's element and the window's border
    m_MainLayout.setSpacing(5); // No space between window's element

    m_TitleBar.setMinimumWidth(this->width());
    setLayout(&m_MainLayout);
    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);
    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    m_message = new QLabel (this);
    m_message->setText(message);
    m_message->setAlignment(Qt::AlignCenter);

    m_listWidget = new QListWidget (this);
    m_stringList = list;
    m_listWidget->addItems(m_stringList);
    m_listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_lineEdit = new QLineEdit (this);

    /*m_model = new QStringListModel (list);

    m_listView = new QListView (this);
    m_listView->setModel(m_model);
    m_listView->setEditTriggers(0); //Content list uneditable*/

    /*m_label = new QLabel;

    m_label->setText("\nSelect file :");
    m_label->setAlignment(Qt::AlignCenter);
    m_label->setStyleSheet("font-size:12px;");*/

    m_label2 = new QLabel (this);
    m_label2->setText("Or choose a new file name :");
    m_label2->setAlignment(Qt::AlignCenter);

    m_ButtonOK = new QPushButton (this);
    m_ButtonOK->setText("OK");
    m_ButtonOK->setMaximumWidth(100);
    m_layoutButtonOK->addWidget(m_ButtonOK);
    m_ButtonCancel = new QPushButton (this);
    m_ButtonCancel->setText("Cancel");
    m_ButtonCancel->setMaximumWidth(100);
    m_layoutButtonOK->addWidget(m_ButtonCancel);
    m_layoutButton->addLayout(m_layoutButtonOK);
    m_layoutButton->addLayout(m_layoutButtonCancel);
    m_MainLayout.addWidget(m_message,1,0);
    m_MainLayout.addWidget(m_listWidget,2,0);
    m_MainLayout.addWidget(m_label2,3,0);
    m_MainLayout.addWidget(m_lineEdit,4,0);
    m_MainLayout.addLayout(m_layoutButton,5,0);
    this->setLayout(&m_MainLayout);

    setWindowModality(Qt::WindowModal);
    //this->show();

    Design design;
    QString style = design.getStyle();
    this->setStyleSheet(style+"QWidget {background-color: #2F2F2F;}"
                        +"QPushButton {background-color:#2F2F2F;color :#AAAAAA;border: 1px solid #474747;margin-bottom:10px;max-width:80px;}"
                        +"QPushButton::Disabled {background-color : #474747;border:none;color:#AAAAAA}"
                        +"QPushButton::hover {background-color:#201F1F;}"
                        +"QPushButton::pressed {background-color:#201F1F;color:#474747;}"
                        +"QListWidget {color: #AAAAAA;background-color: #2F2F2F;border: 1px solid #474747;margin:10px;}"
                        +"QLineEdit {color: #AAAAAA;background-color: #2F2F2F;border: 1px solid #474747;margin-bottom:10px;margin-left:10px;margin-right:10px;}");
    m_message->setStyleSheet("QLabel{margin-left:10px;margin-right:10px;}");

    //QObject::connect(m_listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(setFileName()));
    QObject::connect(m_lineEdit,SIGNAL(textChanged(QString)),this,SLOT(setFileName2(QString)));
    QObject::connect(m_ButtonOK,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(m_ButtonCancel,SIGNAL(clicked()),this,SLOT(reject()));
}

/*QString widgetMBDialog2::setFileName()
{
    fileName = m_listWidget->currentItem()->text();

}*/

void widgetMBDialog2::setFileName2(QString st)
{
    //fileName = st;
    m_listWidget->clearSelection();
}

widgetMBDialog2::~widgetMBDialog2()
{
if (background  != NULL) delete background ;
//if (m_Cache !=NULL) delete m_Cache;
//if (m_ButtonOK !=NULL) delete m_ButtonOK;
//if (m_ButtonCancel !=NULL) delete m_ButtonCancel;
//if (m_message !=NULL) delete m_message;
//if (m_model !=NULL) delete m_model;
//if (m_label !=NULL) delete m_label;
//if (m_label2 !=NULL) delete m_label2;
//if (m_listWidget !=NULL) delete m_listWidget;
//if (m_lineEdit !=NULL) delete m_lineEdit;
//if (m_listView !=NULL) delete m_listView;
}


void widgetMBDialog2::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);
  emit WindowTitleChanged();
}

void widgetMBDialog2::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

  QPolygon border;
  border << QPoint(0,0)//haut gauche
         << QPoint(width(),0)//haut droit
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

QString widgetMBDialog2::getNameFile()
{
    if (m_listWidget->selectionModel()->hasSelection())
    {
        fileName = m_listWidget->currentItem()->text();
        return fileName;
    }
    else// if (m_lineEdit->text()!=NULL)
    {
        fileName = m_lineEdit->text();
        return fileName;
    }
}
