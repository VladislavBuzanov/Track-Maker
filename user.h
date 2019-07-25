#ifndef USER_H
#define USER_H
class User
{
float reiting;
float v_beg;
float v_hod;
float fastWolk;

public:
User()
{
    reiting = 0;
    v_beg = 0;
    v_hod = 0;
    fastWolk=0;
}

float getWallkSpeed()
{
    return v_hod;
}
void updateWallk(float newOne)
{
    v_hod = newOne;
}
float getRunSpeed()
{
    return v_beg;
}

void updateRun(float newOne)
{
    v_beg = newOne;
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
    return fastWolk;
}
void updateFastWallk(float newOne)
{
    fastWolk = newOne;
}
};
#endif // USER_H
