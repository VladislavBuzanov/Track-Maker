#ifndef TRACKBULDER_H
#define TRACKBULDER_H
#include <track.h>
#include <user.h>
class TrackBuilder{
public:
    static Track buildTrack(User *user, TrainType type){
        switch (type) {
        case MARATHON:
            buildMarathon(user);
            break;
        case CROSS:
            buildCross(user);
            break;
        default:
            buildPartialRun(user);
            break;
        }
    }

private: //TODO fix
    void buildMarathon(User *user){}
    void buildPartialRun(User *user){}
    void buildCross(User *user){}
};

#endif // TRACKBULDER_H
