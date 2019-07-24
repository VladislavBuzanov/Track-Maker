#ifndef TRACK_H
#define TRACK_H
#include <Move.h>
#include <tracer.h>
#include <user.h>



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

#endif // TRACK_H
