#ifdef QT_QML_DEBUG
#include <QtQuick>
#include <QObject>
#endif

#include <sailfishapp.h>
#include <qallificationrun.h>
#include <user.h>
#include <track.h>

int main(int argc, char *argv[])
{
    qmlRegisterType <qualificationsRun>("qualRun", 1, 0 , "QualRun");
    qmlRegisterType <User>("user", 1, 0, "User");
    qmlRegisterType <Track> ("track", 1, 0, "Track");
    //TODO сделать конструирование юзверя по файлу
    User user;
    Track track;
    qualificationsRun qualRun;


    track.setupUser(&user);

    return SailfishApp::main(argc, argv);
}
