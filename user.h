#ifndef USER_H
#define USER_H
#include <QObject>


class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float averWalkSpeed READ averWalkSpeed)
    Q_PROPERTY(float  averRunSpeed READ averRunSpeed)
    Q_PROPERTY(float fastWalk READ fastWalk)

float reiting;
float averRunSpeed;
float averWalkSpeed;
float fastWalk;

public:

explicit User(QObject *parent = nullptr);




float getWallkSpeed()
{
    return averWalkSpeed;
}
void updateWallk(float newOne)
{
    averWalkSpeed = newOne;
}
float getRunSpeed()
{
    return averRunSpeed;
}

void updateRun(float newOne)
{
    averRunSpeed = newOne;
}

float getRating()
{
    return reiting;
}
void updateRating(float newOne)
{
    reiting = newOne;
}
float getFastWallkSpeed()
{
    return fastWalk;
}
void updateFastWallk(float newOne)
{
    fastWalk = newOne;
}
};
#endif // USER_H
