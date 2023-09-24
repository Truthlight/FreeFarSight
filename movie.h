/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef MOVIE_H
#define MOVIE_H

#include "memory.h"
#include "commentator.h"
#include "camera.h"
#include "math.h"
#include "light.h"
#include "screenshot.h"
//#include <unistd.h>
#include <sstream>
#include <string>
#include <QThread>
#include <QObject>
//#include <QMessageBox>
#define pi 3.14159265

class Movie : public QObject
{
    Q_OBJECT
public:
    Movie(double speed);
    void setVectorP(std::vector<std::vector<float> > &V);
    quint64 fact(qint32 value);
    bool getBoolTerminate();
    quint64 binomial_coefficient(quint32 n, quint32 k);

public slots:
    void run();
    void run360();
    void runDoF();
    void stop();

Q_SIGNALS:
    void finished();
    void end();
private:
    std::vector<std::vector<float> > P;
    bool m_terminate;
    double speedMachinima;

};

#endif // MOVIE_H
