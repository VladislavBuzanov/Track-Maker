# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = Hackathon

QT += sql

QT += positioning

QT += positioning

CONFIG += sailfishapp

SOURCES += src/Hackathon.cpp \
    src/OnARun.cpp

DISTFILES += qml/Hackathon.qml \
    qml/cover/CoverPage.qml \
    rpm/Hackathon.changes.in \
    rpm/Hackathon.changes.run.in \
    rpm/Hackathon.spec \
    rpm/Hackathon.yaml \
    translations/*.ts \
    Hackathon.desktop \
    qml/pages/MainPage.qml \
    qml/pages/RunPage.qml \
    qml/pages/TestRunPage.qml \
    qml/pages/Journal.qml \
    qml/js/JournalDB.js \
    qml/js/Utils.js \
    qml/model/JournalModel.qml \
    qml/dialogs/NoteDialog.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/Hackathon-de.ts

HEADERS += \
    Move.h \
    track.h \
    tracer.h \
    user.h \
    trackbulder.h \
    qallificationrun.h
