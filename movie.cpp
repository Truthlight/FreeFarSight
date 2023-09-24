/*This file is part of Free Far Sight (FFS)

Copyright 2013-2023, Kyssah, Khamúl

Free Far Sight is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Free Far Sight is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with Free Far Sight. If not, see <https://www.gnu.org/licenses/>.*/

#include "movie.h"
#include "slowmo.h"


Movie::Movie(double speed) : QObject()
{
    m_terminate = false;
    speedMachinima = speed;
}

void Movie::setVectorP(std::vector<std::vector<float> > &V)
{
    P = V;
}

//factorial
quint64 Movie::fact(qint32 value)
{
  quint64 resultFact = 1;
  for(int i = 1; i <= value; i++)
  {
    resultFact *= i;
  }
  return resultFact;
}

quint64 Movie::binomial_coefficient(quint32 n , quint32 k) //https://gist.github.com/jeetsukumaran/5392166 (thx)
{
    quint32 i;
    quint64 b;
    if (0 == k || n == k) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    if (k > (n - k)) {
        k = n - k;
    }
    if (1 == k) {
        return n;
    }
    b = 1;
    for (i = 1; i <= k; ++i) {
        b *= (n - (k - i));
        if (b < 0) return -1;
        b /= i;
    }
    return b;
}


void Movie::run()
{
    //for n+1 waypoints
    qint32 n = P.size() -1;
    float x,y,z;
    float zoom;
    float yaw,pitch;
    float sinyaw,cosyaw;

    Commentator WowCommentator;



    for (float t=0;t<1;t+=0.0001*speedMachinima)
    {
        for (qint32 i=0;i<=n;i++)
        {
            //bezier curve
            /*x += P.at(i).at(0)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            y += P.at(i).at(1)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            z += P.at(i).at(2)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            zoom += P.at(i).at(3)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            sinyaw += sin(P.at(i).at(4))*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            cosyaw += cos(P.at(i).at(4))*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            pitch += P.at(i).at(5)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);*/

            //roll += P.at(i).at(6)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);

            x += P.at(i).at(0)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            y += P.at(i).at(1)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            z += P.at(i).at(2)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            zoom += P.at(i).at(3)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            sinyaw += sin(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            cosyaw += cos(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            pitch += P.at(i).at(5)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
        }
        std::vector <float>location (3);
        location.at(0)=x;
        location.at(1)=y;
        location.at(2)=z;
        std::vector<float>orientation (2);
        yaw=atan2(sinyaw,cosyaw);
        if (yaw<0)
        {
            yaw = 2*pi+yaw;
        }
        orientation.at(0)=yaw;
        orientation.at(1)=pitch;
        //orientation.at(2)=roll;
        WowCommentator.viewPoint(location);
        CameraWow.SetOrientation(orientation);
        CameraWow.setZoom(zoom);
        x=0,y=0,z=0, zoom =0,yaw=0, pitch =0, cosyaw=0, sinyaw=0;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        if (m_terminate == true)
        {
            break;
        }

    }
    emit end();
}

void Movie::run360()
{
    //for n+1 waypoints
    qint32 n = P.size() -1;
    float x,y,z;
    float zoom;
    float yaw,pitch;
    float sinyaw,cosyaw;

    Commentator WowCommentator;

        for(qint32 j=1;j<=6;j++)
        {
            for (float t=0;t<1;t+=0.0001*speedMachinima)
            {
                for (qint32 i=0;i<=n;i++)
                {
                    P.at(i).at(3) = 1.47; //zoom must be always 1.47
                    if(j==5)
                    {
                        P.at(i).at(4) = 6.2;
                        P.at(i).at(5) = 1.53589;
                    }
                    if(j==6)
                    {
                        P.at(i).at(4) = 6.2;
                        P.at(i).at(5) = -1.53589;
                    }
                    if(j != 6 && j != 5)
                    {
                        P.at(i).at(4) = 1.55*j;
                        P.at(i).at(5) = 0;
                    }
                    //bezier curve
                    x += P.at(i).at(0)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    y += P.at(i).at(1)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    z += P.at(i).at(2)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    zoom += P.at(i).at(3)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    sinyaw += sin(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    cosyaw += cos(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                    pitch += P.at(i).at(5)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
                }
                std::vector <float>location (3);
                location.at(0)=x;
                location.at(1)=y;
                location.at(2)=z;
                std::vector<float>orientation (2);
                yaw=atan2(sinyaw,cosyaw);
                if (yaw<0)
                {
                    yaw = 2*pi+yaw;
                }
                orientation.at(0)=yaw;
                orientation.at(1)=pitch;
                //orientation.at(2)=roll;
                WowCommentator.viewPoint(location);
                CameraWow.SetOrientation(orientation);
                CameraWow.setZoom(zoom);
                x=0,y=0,z=0, zoom =0,yaw=0, pitch =0, cosyaw=0, sinyaw=0;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                if (m_terminate == true)
                {
                    break;
                }
            }
        }
    emit end();
}

void Movie::runDoF()
{
    //for n+1 waypoints
    qint32 n = P.size() -1;
    float x,y,z;
    float zoom;
    float yaw,pitch;
    float sinyaw,cosyaw;
    int m=1;

    Commentator WowCommentator;
    Light WowLight;
    ScreenShot scrsh;
    slowmo SM;
    SM.enableSlowMo();
    SM.setSpeed(0.001);
    WowLight.EnableCustomEnv();
    WowLight.saveLight("temp");


    for (float t=0;t<1;t+=0.01*speedMachinima)
    {
        for (qint32 i=0;i<=n;i++)
        {
            //bezier curve
            /*x += P.at(i).at(0)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            y += P.at(i).at(1)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            z += P.at(i).at(2)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            zoom += P.at(i).at(3)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            sinyaw += sin(P.at(i).at(4))*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            cosyaw += cos(P.at(i).at(4))*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            pitch += P.at(i).at(5)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);*/
            //roll += P.at(i).at(6)*(fact(n)/(fact(i)*fact(n-i)))*pow(t,i)*pow(1-t,n-i);
            x += P.at(i).at(0)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            y += P.at(i).at(1)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            z += P.at(i).at(2)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            zoom += P.at(i).at(3)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            sinyaw += sin(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            cosyaw += cos(P.at(i).at(4))*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
            pitch += P.at(i).at(5)*(binomial_coefficient(n,i))*pow(t,i)*pow(1-t,n-i);
        }
        std::vector <float>location (3);
        location.at(0)=x;
        location.at(1)=y;
        location.at(2)=z;
        std::vector<float>orientation (2);
        yaw=atan2(sinyaw,cosyaw);
        if (yaw<0)
        {
            yaw = 2*pi+yaw;
        }
        orientation.at(0)=yaw;
        orientation.at(1)=pitch;
        //orientation.at(2)=roll;
        WowCommentator.viewPoint(location);
        CameraWow.SetOrientation(orientation);
        CameraWow.setZoom(zoom);

        SM.setSpeed(0);
        scrsh.takeScreenShot("screen"+QString::number(m));//inclure nom du screen
        WowLight.loadLight("DOF");
        std::this_thread::sleep_for(std::chrono::milliseconds(200000));
        scrsh.takeScreenShot("screenDoF"+QString::number(m));//inclure nom DOF
        WowLight.loadLight("temp");
        SM.setSpeed(0.001);

        x=0,y=0,z=0, zoom =0,yaw=0, pitch =0, cosyaw=0, sinyaw=0;
        m+=1;

        std::this_thread::sleep_for(std::chrono::milliseconds(200000));
        if (m_terminate == true)
        {
            break;
        }

    }
    emit end();
}

void Movie::stop()
{
    m_terminate = true;
}

bool Movie::getBoolTerminate()
{
    return m_terminate;
}
