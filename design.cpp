/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "design.h"

Design::Design()
{

}

QString Design::getStyle()
{
    QString style =
            "QTabBar::tab {"
                "background-color: #201F1F;"
                "color : #474747;"
                "min-width: 7em;"
                "min-height:1.5em;"
                "border: 1px solid #2F2F2F;"
                "}"
            "QTabBar::tab:selected {"
                "color : #AAAAAA;"
                "background-color: #2F2F2F;"
                "}"
            "QTabWidget::pane { border: 0; } "
            "QWidget {background-color: #2F2F2F;selection-background-color: #80B240;font-family: Myriad Roman;font-size: 11px;}"//;
            "QCheckBox::Enabled {"
                "color : #AAAAAA;"
                "}"
            "QCheckBox::Disabled {color : #474747;}"
            "QCheckBox::indicator:unchecked:Enabled {"
                "image: url(:/images/checkbox_unchecked.png);"
                "}"
            "QCheckBox::indicator:unchecked:hover:Enabled {"
                "image: url(:/images/checkbox_unchecked_hover.png);"
                "}"
            "QCheckBox::indicator:unchecked:pressed:Enabled {"
                "image: url(:/images/checkbox_unchecked_pressed.png);"
                "}"
            "QCheckBox::indicator:checked:Enabled {"
                "image: url(:/images/checkbox_checked.png);"
                "}"
            "QCheckBox::indicator:checked:hover:Enabled {"
                "image: url(:/images/checkbox_checked_hover.png);"
                "}"
            "QCheckBox::indicator:checked:pressed:Enabled {"
                "image: url(:/images/checkbox_checked_pressed.png);"
                "}"
            "QCheckBox::indicator:checked:Disabled {"
                "image: url(:/images/checkbox_checked_disabled.png);"
                "}"
            "QCheckBox::indicator:unchecked:Disabled {"
                "image: url(:/images/checkbox_unchecked_disabled.png);"
                "}"

            "QDoubleSpinBox:Enabled {color: #AAAAAA; border: 1px solid #201F1F; border-radius: 0px; background-color: #201F1F; min-height: 15px; min-width: 7px; max-width:57px;}"

            "QDoubleSpinBox::up-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QDoubleSpinBox::up-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F; "
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QDoubleSpinBox::up-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F; "
                "border-right: 3.3px solid #201F1F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QDoubleSpinBox::up-button:Enabled {border: 5px solid #2F2F2F;min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QDoubleSpinBox::up-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QDoubleSpinBox::up-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"

            "QDoubleSpinBox::down-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QDoubleSpinBox::down-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QDoubleSpinBox::down-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F;"
                "border-right: 3.3px solid #201F1F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QDoubleSpinBox::down-button:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QDoubleSpinBox::down-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QDoubleSpinBox::down-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"

            "QDoubleSpinBox:Disabled {color: #AAAAAA; border: 0.5px solid #474747; border-radius: 0px; background-color: #474747; min-height: 15px; min-width: 7px; max-width:57px;}"

            "QDoubleSpinBox::up-arrow:Disabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QDoubleSpinBox::up-button:Disabled {border: 5px solid #2F2F2F;min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"

            "QDoubleSpinBox::down-arrow:Disabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QDoubleSpinBox::down-button:Disabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"

            "QGroupBox {"
                //"color : #AAAAAA;"
                "margin: 0.2em;"
                "margin-top:0.2em;  "
                "border: 1px solid #474747;"
                //"border-radius: 0px;"
                "}"
            "QGroupBox::title {"
                "color : #AAAAAA;"
                //"background-color:transparent;"
                //"subcontrol-origin: margin;"
                "subcontrol-position: left top;"
                "left: 5px;"
                "padding:2 2px;"
                "margin-top: -0.9em;"
                "}"
            "QGroupBox::title:Disabled {"
                "color:#474747;"
                "}"
            /*"QGroupBox::indicator {"
                //"color : #AAAAAA;"
                "height:17px;"
                "width:17px"
                "}"

            "QGroupBox::indicator:unchecked:Enabled {"
                "image: url(:/images/checkbox_unchecked.png);"
                "}"
            "QGroupBox::indicator:unchecked:hover:Enabled {"
                "image: url(:/images/checkbox_unchecked_hover.png);"
                "}"
            "QGroupBox::indicator:unchecked:pressed:Enabled {"
                "image: url(:/images/checkbox_unchecked_pressed.png);"
                "}"
            "QGroupBox::indicator:checked:Enabled {"
                "image: url(:/images/checkbox_checked.png);"
                "}"
            "QGroupBox::indicator:checked:hover:Enabled {"
                "image: url(:/images/checkbox_checked_hover.png);"
                "}"
            "QGroupBox::indicator:checked:pressed:Enabled {"
                "image: url(:/images/checkbox_checked_pressed.png);"
                "}"
            "QGroupBox::indicator:checked:Disabled {"
                "image: url(:/images/checkbox_checked_disabled.png);"
                "}"
            "QGroupBox::indicator:unchecked:Disabled {"
                "image: url(:/images/checkbox_unchecked_disabled.png);"
                "}"*/

            "QLabel::Enabled {color : #AAAAAA;}"
            "QLabel::Disabled {color : #474747;}"

            "QLabelClickable::hover {color : white;}"
            //"QLabelClickable::pressed {color : green;}"

            "QListView {color: #AAAAAA;background-color: #201F1F;border: 5px solid #2F2F2F;}"
            "QListView::item:hover { background:#474747;}"
            "QListView::item:selected { background: #80B240; color:white}"

            "QPushButton {color :#AAAAAA;border: 1px solid #474747;/*max-width:100px;*/}"
            "QPushButton::Disabled {background-color : #474747;border:none;color:#AAAAAA}"
            "QPushButton::hover {background-color:#201F1F;}"
            "QPushButton::pressed {background-color:#201F1F;color:#474747;}"

            "QScrollBar { border: 1px solid #474747; background: #201F1F; height: 10px; margin: 0px 10px 0px 10px; }"
            "QScrollBar::handle:horizontal {"
               "background: #474747;"
                "min-height: 13px;"
                "}"
            "QScrollBar::add-line:horizontal  {"
                "border: 1px solid #474747;"
                "background: #2F2F2F;"
                "width: 10px;"
                "subcontrol-position: right;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::add-line:horizontal:pressed  {"
                "border: 1px solid #474747;"
                "background: #201F1F;"
                "width: 10px;"
                "subcontrol-position: right;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::sub-line:horizontal  {"
                "border: 1px solid #474747;"
                "background: #2F2F2F;"
                "width: 10px;"
                "subcontrol-position: left;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::sub-line:horizontal:pressed  {"
                "border: 1px solid #474747;"
                "background: #201F1F;"
                "width: 10px;"
                "subcontrol-position: left;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::left-arrow:horizontal  {"
                "border-top: 3.3px solid #2F2F2F;border-bottom: 3.3px solid #2F2F2F; border-right: 3.5px solid #AAAAAA;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::left-arrow:horizontal:hover  {"
                "border-top: 3.3px solid #2F2F2F;border-bottom: 3.3px solid #2F2F2F; border-right: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::left-arrow:horizontal:pressed  {"
                "border-top: 3.3px solid #201F1F;border-bottom: 3.3px solid #201F1F; border-right: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::right-arrow:horizontal  {"
                "border-top: 3.3px solid #2F2F2F;border-bottom: 3.3px solid #2F2F2F; border-left: 3.5px solid #AAAAAA;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::right-arrow:horizontal:hover  {"
                "border-top: 3.3px solid #2F2F2F;border-bottom: 3.3px solid #2F2F2F; border-left: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::right-arrow:horizontal:pressed  {"
                "border-top: 3.3px solid #201F1F;border-bottom: 3.3px solid #201F1F; border-left: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal  {"
                "background: none;"
            "}"

            "QScrollBar::vertical { border: 1px solid #474747; background: #201F1F; width: 10px; margin: 10px 0px 10px 0px; }"
            "QScrollBar::handle:vertical {"
                "background: #474747;"
                "min-height: 13px;"
                "}"
            "QScrollBar::add-line:vertical  {"
                "border: 1px solid #474747;"
                "background: #2F2F2F;"
                "height: 10px;"
                "subcontrol-position: bottom;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::add-line:vertical:pressed  {"
                "border: 1px solid #474747;"
                "background: #201F1F;"
                "height: 10px;"
                "subcontrol-position: bottom;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::sub-line:vertical  {"
                "border: 1px solid #474747;"
                "background: #2F2F2F;"
                "height: 10px;"
                "subcontrol-position: top;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::sub-line:vertical:pressed  {"
                "border: 1px solid #474747;"
                "background: #201F1F;"
                "height: 10px;"
                "subcontrol-position: top;"
                "subcontrol-origin: margin;"
                "}"
            "QScrollBar::up-arrow:vertical  {"
                "border-right: 3.3px solid #2F2F2F;border-left: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::up-arrow:vertical:hover  {"
                "border-right: 3.3px solid #2F2F2F;border-left: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::up-arrow:vertical:pressed  {"
                "border-right: 3.3px solid #201F1F;border-left: 3.3px solid #201F1F; border-bottom: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::down-arrow:vertical  {"
                "border-right: 3.3px solid #2F2F2F;border-left: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::down-arrow:vertical:hover  {"
                "border-right: 3.3px solid #2F2F2F;border-left: 3.3px solid #2F2F2F; border-top: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::down-arrow:vertical:pressed  {"
                "border-right: 3.3px solid #201F1F;border-left: 3.3px solid #201F1F; border-top: 3.5px solid #777777;"
                "width: 0px;"
                "height: 0px;"
                //"background: #AAAAAA;"
            "}"
            "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical  {"
                "background: none;"
            "}"

            "QSlider::groove:horizontal::Disabled {"
                "border: 1px solid #474747;"
                "height: 0.5px;"
                "background-color: #474747;"
                "margin: 2px 0;"
                "}"
            "QSlider::handle:horizontal::Disabled {"
                 "background-color: #474747;"
                 "border: 1px solid #474747;"
                 "width: 5px;"
                 "margin: -8px 0 -8px 0;"
                 "border-radius: 0px;"
                 "}"
            "QSlider::groove:horizontal::Enabled {"
                "border: 1px solid #AAAAAA;"
                "height: 0.5px;"
                "background-color: #AAAAAA;"
                "margin: 2px 0;"
                "}"
            "QSlider::handle:horizontal::Enabled {"
                 "background-color: #AAAAAA;"
                 "border: 1px solid #474747;"
                 "width: 5px;"
                 "margin: -8px 0 -8px 0;"
                 "border-radius: 0px;"
                 "}"

            "QSpinBox:Enabled {color: #AAAAAA; border: 1px solid #201F1F; border-radius: 0px; background-color: #201F1F; min-height: 15px; min-width: 7px; max-width:57px;}"

            "QSpinBox::up-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QSpinBox::up-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F; "
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QSpinBox::up-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F; "
                "border-right: 3.3px solid #201F1F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QSpinBox::up-button:Enabled {border: 5px solid #2F2F2F;min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QSpinBox::up-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QSpinBox::up-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"

            "QSpinBox::down-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QSpinBox::down-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QSpinBox::down-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F;"
                "border-right: 3.3px solid #201F1F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QSpinBox::down-button:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QSpinBox::down-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QSpinBox::down-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"

            "QSpinBox:Disabled {color: #AAAAAA; border: 0.5px solid #474747; border-radius: 0px; background-color: #474747; min-height: 15px; min-width: 7px; max-width:57px;}"

            "QSpinBox::up-arrow:Disabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QSpinBox::up-button:Disabled {border: 5px solid #2F2F2F;min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"

            "QSpinBox::down-arrow:Disabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QSpinBox::down-button:Disabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"

            "QTableView {"
                "border-radius: 0px;"
                "background-color: #201F1F;"
                "gridline-color: #2F2F2F;"
                "color: #AAAAAA;"
                "}"
            "QTableView::item:hover { background:#474747;}"
            "QTableView::item:selected { background: #80B240; color:#201F1F;}"

            //probably really ugly but don't know how to do better. Remains a useless border-right in horizontal header, and a useless border-bottom in vertical header
            "QHeaderView {background-color: #201F1F;border-bottom: 0.5px solid #2F2F2F;border-right: 0.5px solid #2F2F2F;}"
            "QHeaderView::section:horizontal {"
                "color:#474747;"
                "border-style: none;"
                //"border-top: 0.5px solid #2F2F2F;"
                "border-right: 0.5px solid #2F2F2F;"
                "border-bottom: 0.5px solid #2F2F2F;"
                "background-color: #201F1F;"
                "}"
            "QHeaderView::section:vertical {"
                "color:#474747;"
                "border-style: none;"
                //"border-left: 0.5px solid #2F2F2F;"
                "border-right: 0.5px solid #2F2F2F;"
                "border-bottom: 0.5px solid #2F2F2F;"
                "background-color: #201F1F;"
                "}"
            "QTableView QTableCornerButton::section {"
                "background: #201F1F;"
                "border-style: none;"
                "border-right: 0.5px solid #2F2F2F;"
                "border-bottom: 0.5px solid #2F2F2F;"
                "}"

            "QTextEdit {color: #AAAAAA;background-color: #201F1F;border-style: none;height: 5px;/*border: 0.5px solid #474747;*/}"

            "QTimeEdit:Enabled {color: #AAAAAA; border: 1px solid #201F1F; border-radius: 0px; background-color: #201F1F; min-height: 15px; min-width: 7px; max-width:57px;}"

            "QTimeEdit::up-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QTimeEdit::up-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F; "
                "border-right: 3.3px solid #2F2F2F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QTimeEdit::up-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F; "
                "border-right: 3.3px solid #201F1F; border-bottom: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QTimeEdit::up-button:Enabled {border: 5px solid #2F2F2F;min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QTimeEdit::up-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QTimeEdit::up-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"

            "QTimeEdit::down-arrow:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #AAAAAA; width: 0px; height: 0px; }"
            "QTimeEdit::down-arrow:hover:Enabled { border-left: 3.3px solid #2F2F2F;"
                "border-right: 3.3px solid #2F2F2F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QTimeEdit::down-arrow:pressed:Enabled { border-left: 3.3px solid #201F1F;"
                "border-right: 3.3px solid #201F1F; border-top: 3.5px solid #777777; width: 0px; height: 0px; }"
            "QTimeEdit::down-button:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QTimeEdit::down-button:hover:Enabled {border: 5px solid #2F2F2F; min-width: 7px; min-height: 5px; background-color: #2F2F2F; }"
            "QTimeEdit::down-button:pressed:Enabled {border: 5px solid #201F1F; min-width: 7px; min-height: 5px; background-color: #201F1F; }"
            ;
    return style;
}

QString Design::getSliderColorStyle(QColor color)
{
    return "QSlider::groove:vertical{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0"+color.name()+", stop:1 black);}";
            //"QSlider::handle:vertical{background-color:black;height:2px;width:10px;}";
}
