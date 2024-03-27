#ifndef UNICYCLE_H
#define UNICYCLE_H

#include <invertedpendulum.h>

// create unicycle class inheriting from inverted pendulum
class Unicycle : public InvertedPendulum
{
public:
    // constructor
    Unicycle
    (
        double timeInterval, 
        double massBase, 
        double massPendulum, 
        double lengthPendulum, 
        double xPos, 
        double angle, 
        double xVel, 
        double angleVel, 
        double xAccel, 
        double angleAccel, 
        double appliedForce, 
        double frictionConst,
        double gravityConst,
        double timeElapsed
    ) :
        InvertedPendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, frictionConst, gravityConst, timeElapsed)
    {
    }
    // overrite the drawBase and drawPendulum functions
    void drawBase(int screenWidthPx, int screenHeightPx, int cartWidth, int cartHeight, double scaleFactor) const;
    void drawPendulum(int screenWidthPx, int screenHeightPx, int pendulumLength, double scaleFactor) const;
};

#endif // UNICYCLE_H