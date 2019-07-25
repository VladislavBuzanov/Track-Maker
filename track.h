#ifndef TRACK_H
#define TRACK_H
#include <Move.h>
#include <tracer.h>
#include <user.h>
#include <QTime>
#include <QGeoCoordinate>
#include <QGeoPositionInfoSource>




class Track: QObject{
protected:
    Move *parts;
    int globalDistance; // какое расстояние ожидается быть пройденным
    int avaliableTime; // сколько времени в минутах пользователь может уделить
    int partCounter; // сообщает, сколько сегментов осталось пробежать 
    User *user;
    
public:

    Track(){ //не знаю зачем, но пусть будет
        parts = nullptr;
        globalDistance = 0;
        avaliableTime = 0;
        partCounter = 0;
        user = 0;
    }
    bool isOn(){return partCounter >0;}


};



#endif // TRACK_H
