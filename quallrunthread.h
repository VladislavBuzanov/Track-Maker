#ifndef QUALLRUNTHREAD_H
#define QUALLRUNTHREAD_H
#include <qallificationrun.h>
#include <QThread>

class QualRunThread: public QThread
{
    qualificationsRun *q;


public:
    QualRunThread(qualificationsRun *q1) {
        this->q = q1;
    }
    void run(){
        q->run();
    }

};
#endif // QUALLRUNTHREAD_H
