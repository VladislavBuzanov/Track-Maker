#include <QtQuick>
#include <QObject>
#include <QFile>
#include <sailfishapp.h>
#include <qallificationrun.h>
#include <user.h>
#include <track.h>


#define FILE_NAME "userLog.txt"

void fillUserLog(QFile *file){

    file->open(QIODevice::ReadWrite);
    file->write("3\n5\n10");
    file->close();
}

void buildUser(QFile *file, User *user){
    file->open(QIODevice::ReadOnly);
    user->updateWallk(file->readLine().toFloat());
    user->updateFastWallk(file->readLine().toFloat());
    user->updateRun(file->readLine().toFloat());
    file->close();
}

int main(int argc, char *argv[])
{    User user;

    QFile userLog(FILE_NAME);

    if( !(QFile::exists(FILE_NAME)))
        fillUserLog(&userLog);

    buildUser(&userLog, &user);
    qualificationsRun qualRun(& user);
    Track track;
    track.setupUser(&user);

    QQuickView view;
    view.rootContext()->setContextProperty("User", &user);
    view.rootContext()->setContextProperty("QualRun", &qualRun);
    view.rootContext()->setContextProperty("Track", &track);
    view.show();







    track.setupUser(&user);

    return SailfishApp::main(argc, argv);
}
