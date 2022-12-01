//Programmer: Daniel Lai
//ID: 1685269

#ifndef Rider_h
#define Rider_h


using namespace std;

struct Rider 
{
    const bool goingUp, goingDown;
    const int from, to;
    Rider(int, int);
    Rider& operator =(const Rider&);

};

#endif