#ifndef TRACER_H
#define TRACER_H


#define XYZ float x, float y, float z
#define _xyz_ x, y, z


class Point{
    float _xyz_;
    Point *prev;
    Point *next;
public:
    Point(XYZ){
        this = Point(_xyz_, nullptr, nullptr);
    }
    Point(XYZ, Point *prev){
        this = Point(_xyz_, prev, nullptr);
    }
    Point(XYZ, Point *prev, Point *next){
        this->x = x;
        this->y = y;
        this->z = z;
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
    
public:
    Tracer(XYZ){
        traceHead = Point(_xyz_); //объявили старт
        traceEnd = &traceHead; 
    }
    void addPoint(XYZ){
        Point tmp(_xyz_, traceEnd);
        traceEnd->setNext(&tmp);
        traceEnd = &tmp;
    }
}

#endif // TRACER_H
