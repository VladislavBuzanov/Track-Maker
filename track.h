#ifndef TRACK_H
#define TRACK_H
#include <Move.h>
#include <tracer.h>
#include <user.h>



class Track{
pivate:
    Move *parts;
    int globalDistance; // какое расстояние ожидается быть пройденным
    int avaliableTime; // сколько времени в минутах пользователь может уделить
    int partCounter; // сообщает, сколько сегментов осталось пробежать
    Tracer *tracer; 
    User *user;
    
    void setup(User *user){
        //TODO add building parts with user's params
    }
    
};

#endif // TRACK_H
