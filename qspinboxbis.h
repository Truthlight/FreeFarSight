/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#ifndef QSPINBOXBIS_H
#define QSPINBOXBIS_H

#include <QSpinBox>
#include <QVector>
#include <QObject>
#include <QWidget>

class QSpinBoxBis : public QSpinBox
{
    Q_OBJECT
public:
    explicit QSpinBoxBis(const QVector<int> & values, QWidget * parent = 0) :
        QSpinBox(parent),
        mValues(values),
        mIndex(0)
    {
        qSort(mValues);
        setMinimum(mValues.at(0));
        setMaximum(mValues.at(mValues.size() - 1));
        setValue(mValues.at(0));
    }

protected:
    void stepBy(int steps) // re-implementaion
    {
        mIndex += steps;
        mIndex = qBound(0, mIndex, mValues.size() - 1);
        setValue(mValues.at(mIndex));
    }

private:
    QVector<int>    mValues;
    int             mIndex;
};

#endif // QSPINBOXBIS_H
