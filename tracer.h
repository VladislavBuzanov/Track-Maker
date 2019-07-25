#ifndef TRACER_H
#define TRACER_H
#include <QGeoCoordinate>
#include <QString>

//TODO пофиксить координаты

class Point{


    QGeoCoordinate *location;
    Point *prev;
    Point *next;
    float deltaTime = 0;
public:

    int size;
    Point(){
        size = 0;
        this->location = nullptr;
        this->prev = nullptr;
        this->next = nullptr;
    }

    Point(QGeoCoordinate *location){
        *this = Point(location, nullptr, nullptr);
    }
    Point(QGeoCoordinate *location, Point *prev){
        *this = Point( location, prev, nullptr);
    }
    Point(QGeoCoordinate *location, Point *prev, Point *next){

        this->location = location;
        this->prev = prev;
        this->next = next;
    }
    
    void setNext(Point *next ){
        this->next = next;
    }
};

class Tracer{

    float *messageToVlad;

    Point traceHead;
    Point *traceEnd;
    


public:
    Tracer(){}
    Tracer(QGeoCoordinate location){
        Point tmp(&location);
        traceHead = tmp; //объявили старт
        traceEnd = &traceHead; 
    }

    void update(QGeoCoordinate location){
        Point tmp(&location, traceEnd);
        traceEnd->setNext(&tmp);
        traceEnd = &tmp;
    }

};

#endif // TRACER_H


