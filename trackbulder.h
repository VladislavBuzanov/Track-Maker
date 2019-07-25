#ifndef TRACKBULDER_H
#define TRACKBULDER_H
#include <track.h>
#include <user.h>
class TrackBuilder{
public:
    static Track buildTrack(User *user){

            buildPartialRun(user);

    }

private: //TODO fix
    void buildPartialRun(User *user){}

};

#endif // TRACKBULDER_H
