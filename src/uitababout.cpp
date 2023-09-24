/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "uitababout.h"

UITabAbout::UITabAbout(QWidget *parent):QWidget(parent)
{
    m_label = new QLabel (this);
    m_label->setText(("Free Far Sight, Machinima tool for World of Warcraft 6.2.4.21355 32bits\n"
                   "by Kyssah and Khamúl, design : nooSens\n"));
    m_label->setAlignment(Qt::AlignCenter);
    m_labelTuto = new QLabel (this);
    m_labelTuto->setText("TUTORIAL VIDEO :");
    m_labelTuto->setAlignment(Qt::AlignCenter);
    m_textTuto = new QTextEdit (this);
    m_textTuto->setText(("<html><center>https://www.youtube.com/watch?v=mBxkJveH_os</center></html>"));
    m_textTuto->setReadOnly(true);
    m_textTuto->setFixedHeight(22);
    m_label2 = new QLabel (this);
    m_label2->setText(/*QString::fromLatin1*/("Special thanks to Malu05 for the original tool that made this one possible"));
    m_label2->setAlignment(Qt::AlignCenter);
    m_labelDisclaimer = new QLabel (this);
    m_labelDisclaimer->setText("DISCLAIMER :");
    m_labelDisclaimer->setAlignment(Qt::AlignCenter);
    m_textDisclaimer = new QTextEdit (this);
    m_textDisclaimer->setText(("<html>World of Warcraft® is a trademark or registered trademark of Blizzard Entertainment.<br>"
                              "This tool is not associated with nor endorsed by Blizzard Entertainment.<br><br>"
                              "<u>This is for 6.2.4.21355 only, don't use it with other versions</u><br>"
                              "This tool has been made for machinima purpose only. It is not intended to give unfair advantages in game. This tool is against the ToS but if you use it for what it has been created, you shouldn't be worried, "
                              "WMT was used for years without any problems, and this tool works exactly the same, however, it isn't completely risk-free.<br>"
                              "If you find some bugs, please, send an email to kyssah.wow@gmail.com<br>Find us on Facebook : https://www.facebook.com/Free-Far-Sight/</html>"));
    m_textDisclaimer->setReadOnly(true);
    m_layout->addWidget(m_label);
    m_layout->addWidget(m_labelTuto);
    m_layout->addWidget(m_textTuto);
    m_layout->addWidget(m_labelDisclaimer);
    m_layout->addWidget(m_textDisclaimer);
    m_layout->addWidget(m_label2);
    this->setLayout(m_layout);
}

UITabAbout::~UITabAbout()
{

}
