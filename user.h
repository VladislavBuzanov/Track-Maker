#ifndef USER_H
#define USER_H
class User
{
float reiting;
float v_beg;
float v_hod;

public:
User()
{
    reiting = 0;
    v_beg = 0;
    v_hod = 0;
}

float getWallkSpeed()
{
    return v_hod;
}
void updateWallk(float newOne)
{
    v_hod = neOne;
}
float getRunSpeed()
{
    return v_beg;
}

void updateRun(float newOne)
{
    v_beg = neOne;
}

float getRating()
{
    return reiting;
}
void updateRating(float newOne)
{
    reiting = newOne;
}

};
#endif // USER_H
