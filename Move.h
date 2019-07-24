#ifndef HEADERS_H
#define HEADERS_H

#define DROPS_DOWN 2
#define DROPS_UP 2
//погрешность в определении скорости
class Move{
protected:
    int distance; //в метрах
    float acceptableSpeed; //скорость метр в секунду
    int nominalDistance;

public:
    int getNominalDistance(){return realDistance;}
    int getDistance(){
        return distance;
    }
    int decreaseDistance(float delta){
        distance = (float)distance - delta;
        return distance;
    }

    bool isSpeedAcceptable(float currentSpeed){ //переопределить для бега и джога
        return currentSpeed >= acceptableSpeed - DROPS_DOWN;
    }

    Move(int distance){

        this->distance = distance;
        nominalDistance = distance;
    }

};



//TODO добавить конструкторы через пользователя



class Run : Move{
public:

    bool isSpeedAcceptable(float currentSpeed){
        return currentSpeed >= acceptableSpeed - DROPS_DOWN && currentSpeed <= acceptableSpeed + DROPS_UP;
    }
};

class Jog : Move{
public:
    return currentSpeed >= acceptableSpeed - DROPS_DOWN && currentSpeed <= acceptableSpeed + DROPS_UP;
};
class Walk: Move{};

#endif // HEADERS_H
