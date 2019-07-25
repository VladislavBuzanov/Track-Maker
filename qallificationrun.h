#ifndef QALLIFICATIONRUN_H
#define QALLIFICATIONRUN_H
#include <Move.h>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <user.h>
#include <QObject>


class qualificationsRun: public  QObject
{
    Q_OBJECT

    Move *parts;
    float timeStart;
    float timeEnd;
    User *user;
public:
    explicit qualificationsRun(QObject *parent = nullptr);


    qualificationsRun(User *user, int walkDist, int fastWalkDist, int runDist){
        this->user = user;
        parts = new Move [3];
        parts[0] = Move(walkDist); // идти
        parts[1] = Move(fastWalkDist); // быстро идти
        parts[2] = Move(runDist);
    }


    qualificationsRun(User *user)
    {
        this->user = user;
        parts = new Move [3];
        parts[0] = Move(100); // идти
        parts[1] = Move(200); // быстро идти
        parts[2] = Move(1000);
    }

    void run(){


        QGeoPositionInfoSource *source;
        source = QGeoPositionInfoSource::createDefaultSource(this);
        source->setUpdateInterval(500);
        QGeoCoordinate pointA, pointB;
        source->startUpdates();

        pointA = source->lastKnownPosition().coordinate();
        QTime timer;
        timer = timer.currentTime();
        timer.start();
        timeStart = timer.msec();
        for (int i = 0; i < 3; i++) {
            timeStart = timer.msec();

            while(parts[i].getDistance() > 0){
                pointB = pointA;
                pointA = source->lastKnownPosition().coordinate();
                parts[i].decreaseDistance( pointA.distanceTo(pointB));
            }
            timeEnd = timer.msec();
            if(i==0)
            user->updateWallk(getAverageSpeed(i));
            else if(i == 1)
                user->updateFastWallk(getAverageSpeed(i));
            else
                user->updateRun(getAverageSpeed(i));

        }


    }
    /*void setDisance(float s)
    {
        distance = s;
    }
    void setTimeend(float t)
    {
        timeend = t;
    }
    */
    float getAverageSpeed(int part)
    {
        return parts[part].getNominalDistance()/(timeEnd - timeStart) ;
    }
};

#endif // QALLIFICATIONRUN_H
