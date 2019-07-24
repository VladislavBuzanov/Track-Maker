#ifndef TRACER_H
#define TRACER_H
#include <QGeoCoordinate>

#define XYZ float x, float y, float z
#define QGC QGeoCoordinate *location

//TODO пофиксить координаты

class Point{
    QGeoCoordinate *location;
    Point *prev;
    Point *next;
    QGeoCoordinate:: a;
    float deltaTime = 0;
public:
    Point(QGC){
        this = Point(QGC, nullptr, nullptr);
    }
    Point(QGC, Point *prev){
        this = Point(QGC, prev, nullptr);
    }
    Point(QGC, Point *prev, Point *next){

        this->location = location;
        this->prev = prev;
        this->next = next;
    }
    
    void setNext(Point *next ){
        this->next = next;
    }
};

class Tracer{
    Point traceHead;
    Point *traceEnd;
    
    void addPoint(QGC){
        Point tmp(location, traceEnd);
        traceEnd->setNext(&tmp);
        traceEnd = &tmp;
    }

public:
    Tracer(QGC){
        traceHead = Point(_xyz_); //объявили старт
        traceEnd = &traceHead; 
    }

    void update(){
        ;
    }

}

#endif // TRACER_H
