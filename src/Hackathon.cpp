#include <QtQuick>
#include <QObject>
#include <sailfishapp.h>
#include <qallificationrun.h>
#include <user.h>

int main(int argc, char *argv[])
{
   // qmlRegisterType <qualificationsRun>("qualRun", 1, 0 , "QualRun");
    qmlRegisterType <User>("user", 1, 0, "User");


    // SailfishApp::main() will display "qml/Hackathon.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //   - SailfishApp::pathToMainQml() to get a QUrl to the main QML file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    return SailfishApp::main(argc, argv);
}
