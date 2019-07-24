#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
#include <tracer.h>
#include <track.h>
#include <user.h>


//TODO сделать пстоянную обновлялку для бега
class onARun
{
    Tracer *tracer;
    Track  *track;
    User *user;
    QGeoCoordinate *lastpoint;
    QGeoPositionInfoSource *source;

public:
    onARun(User *user)
    {

    }
};


