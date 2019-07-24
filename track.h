#ifndef TRACK_H
#define TRACK_H
#include <Move.h>
#include <tracer.h>
#include <user.h>
#include <QTime>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>



class Track{
protected:
    Move *parts;
    int globalDistance; // какое расстояние ожидается быть пройденным
    int avaliableTime; // сколько времени в минутах пользователь может уделить
    int partCounter; // сообщает, сколько сегментов осталось пробежать 
    User *user;
    
public:
    Track(){ //не знаю зачем, но пусть будет
        parts = nullptr;
        globalDistance = nullptr;
        avaliableTime = 0;
        partCounter = 0;
        user = 0;
    }
    bool isOn(){return partCounter >0;}


};

enum TrainType{
    PARTIALRUN = 1,
    MARATHON = 2,
    CROSS = 3
};


class PartialRun: Track{

};

class Marathon : Track{

};

class Cross : Track{

};

class qualificationsRun: Track
{
    float timeStart;
    float timeEnd;
public:
    qualificationsRun()
    {
        parts = new Move [3];
        parts[0] = Move(100); // идти
        parts[1] = Jog(500); // быстро идти
        parts[2] = Run(1000)
        ;
    }

    void run(User *user){


        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        source->setUpdateInterval(500);
        QGeoCoordinate pointA, pointB;
        source->startUpdates();

        pointA = source->lastKnownPosition();
        QTime timer();
        timer.start();
        timeStart = timer.currentTime();
        for (int i = 0; i < 3; i++) {
            timeStart = timer.currentTime();

            while(parts[i].getDistance() > 0){
                pointB = pointA;
                pointA = source->lastKnownPosition();
                parts[i].decreaseDistance( pointA.distanceTo(pointB));
            }
            timeEnd = timer.currentTime();
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
        return parts[i].getNominalDistance()/(timeEnd - timeStart) ;
    }
};

#endif // TRACK_H
