#ifndef QALLIFICATIONRUN_H
#define QALLIFICATIONRUN_H
#include <Move.h>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <user.h>
#include <QObject>
#include <tracer.h>


#define CHECK_RATE 2000
enum Task{
    WALK = 1,
    WALK_FAST =2,
    RUN =3
};

class qualificationsRun: public  QObject
{

    Q_ENUM(Task)
    Q_OBJECT
    Q_PROPERTY(int distanceLeft READ getDistanceLeft NOTIFY distanceLeftChanged)
    Q_PROPERTY(int task READ getTask NOTIFY taskChanged)
    Q_PROPERTY(bool over READ isOver NOTIFY isOverNow)
    Move *parts;
    float timeStart;
    float timeEnd;
    float distanceLeft;
    User *user;
    int task = 1;
    bool over = false;
    Tracer tracer;

public:
    qualificationsRun(){}

    bool isOver(){return over;}

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
        distanceLeft = parts[0].getDistance() + parts[1].getDistance() + parts[2].getDistance();
    }
    Q_INVOKABLE void run(){

        QGeoPositionInfoSource *source;
        source = QGeoPositionInfoSource::createDefaultSource(this);
        source->setUpdateInterval(CHECK_RATE);
        QGeoCoordinate pointA, pointB;
        source->startUpdates();

        float delta;
        task = 1;
        pointA = source->lastKnownPosition().coordinate();
        QTime timer;
        timer = timer.currentTime();
        timer.start();
        timeStart = timer.msec();

       tracer = Tracer(source->lastKnownPosition().coordinate());
        for (int i = 0; i < 3; i++) {
            emit taskChanged();
            timeStart = timer.msec();

            while(parts[i].getDistance() > 0){
                pointB = pointA;
                pointA = source->lastKnownPosition().coordinate();
                delta =  pointA.distanceTo(pointB);
                parts[i].decreaseDistance(delta);
                distanceLeft -= delta;
                emit distanceLeftChanged();
                tracer.update(source->lastKnownPosition().coordinate());
            }
            task++;

            timeEnd = timer.msec();
            if(i==0)
            user->updateWallk(getAverageSpeed(i));
            else if(i == 1)
                user->updateFastWallk(getAverageSpeed(i));
            else
                user->updateRun(getAverageSpeed(i));
        }
        emit isOverNow();
        user->updateUserLog();
    }
    int getTask(){
        return task;
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
        return parts[part].getNominalDistance()/(timeEnd - timeStart) * 1000 * 3.6;
    }
    int getDistanceLeft(){
        return (int)distanceLeft;
    }

signals:
    void distanceLeftChanged();
    void taskChanged();
    void isOverNow();
};

#endif // QALLIFICATIONRUN_H
