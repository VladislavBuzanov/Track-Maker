#ifndef TRACK_H
#define TRACK_H
#include <tracer.h>
#include <user.h>
#include <QTime>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>
#include <tracer.h>

#define STD_RUN  12
#define STD_WALK 5



class Track: public QObject{


    Q_OBJECT
    Q_PROPERTY(int phase READ getPhase NOTIFY phaseChanged)
    Q_PROPERTY(int globalDistance READ getGlobalDistance NOTIFY distanceChanged)
    Q_PROPERTY(int phaseTime READ getPhaseTime  NOTIFY phaseTimeChanged)
    Q_PROPERTY(int timeRemain READ getRemainTime NOTIFY timeChanged)

    float globalDistance; // какое расстояние ожидается быть пройденным
    float avaliableTime; // сколько времени в секундах пользователь может уделить
    float wallkTime, runeTime; // в секундах !
    User *user;
    int phase;
    float phaseTimeRemain;
    Tracer tracer;

public:

    int getRemainTime(){
        return (int) avaliableTime;
    }
    int getPhaseTime(){
        return (int) phaseTimeRemain;
    }
    int getPhase(){
        return phase;
    }
    void setupUser(User *user){
        this->user = user;
    }

    void setup(int avaliableTime){
        this->avaliableTime = avaliableTime;

        wallkTime =  60 * STD_WALK / user->getFastWallkSpeed();
        runeTime = 60 * user->getRunSpeed() / STD_RUN;
    }


    int getGlobalDistance(){
        return (int) globalDistance;
    }

    Q_INVOKABLE void start(int allTimeInSeconds){//....................................................
        setup(allTimeInSeconds);
        phase = 0;

        QGeoPositionInfoSource *source;
        source = QGeoPositionInfoSource::createDefaultSource(this);
        source->setUpdateInterval(500);
        QGeoCoordinate pointA, pointB;
        source->startUpdates();

        float delta, momentA, momentB;
        float phaseTime;
        float phasesTime[] ={wallkTime, runeTime};

        QTime timer;
        timer.start();
        momentA = timer.second();
        momentB = momentA;

        tracer = Tracer(source->lastKnownPosition().coordinate());
        pointA = source->lastKnownPosition().coordinate();
        pointB = pointB;

        while( avaliableTime > 0 ){//...............................................................

            tracer.update(source->lastKnownPosition().coordinate());


            phaseTime = phasesTime[phase];

            while(phaseTime > 0){//...............................................................
                tracer.update(source->lastKnownPosition().coordinate()); //обрабатывыаем расстояние
                pointB = pointA;
                pointA = source->lastKnownPosition().coordinate();
                globalDistance += pointA.distanceTo(pointB);
                emit distanceChanged();

                momentB = momentA; // обрабатываем время
                momentA = timer.second();
                delta = momentB - momentA;
                phaseTime -= delta;
                avaliableTime -= delta;
                emit phaseChanged();
                emit timeChanged();

                if(avaliableTime < 0){
                    emit isOver();
                    break;
                }


            }//.....................................................................................
            phase = (phase + 1) % 2;
            emit phaseChanged();

        }//...................................................................................................
        emit isOver();


    }//..........................................................................................................

signals:
    void phaseChanged();
    void isOver();
    void phaseTimeChanged();
    void distanceChanged();
    void timeChanged();

};



#endif // TRACK_H
