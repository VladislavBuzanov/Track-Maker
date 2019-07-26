#ifndef USER_H
#define USER_H
#include <QObject>
#include <QFile>
#include <QTextStream>

#define FILE_NAME "userLog.txt"

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float averWalkSpeed READ getWallkSpeed NOTIFY noteWallk)
    Q_PROPERTY(float  averRunSpeed READ getRunSpeed NOTIFY noteRun)
    Q_PROPERTY(float fastWalk READ getFastWallkSpeed NOTIFY noteFastWallk)

QFile userLog;

float reiting = 0;
float averRunSpeed = 0;
float averWalkSpeed = 0;
float fastWalk = 0;

public:

float getWallkSpeed()
{
    return averWalkSpeed;
}
void updateWallk(float newOne)
{
    averWalkSpeed = newOne;
    emit noteWallk();
}
float getRunSpeed()
{
    return averRunSpeed;
}

void updateRun(float newOne)
{
    averRunSpeed = newOne;
    emit noteRun();
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
    emit noteFastWallk();
}

void updateUserLog(){
    userLog.setFileName(FILE_NAME);
    userLog.open(QIODevice::WriteOnly | QIODevice::Text);


    userLog.write(QString::number((double) averWalkSpeed).toUtf8());
    userLog.write("\n");
    userLog.write(QString::number((double) fastWalk).toUtf8());
    userLog.write("\n");
    userLog.write(QString::number((double) averRunSpeed).toUtf8());

    userLog.close();

}

signals:
void noteWallk();
void noteRun();
void noteFastWallk();


};
#endif // USER_H
