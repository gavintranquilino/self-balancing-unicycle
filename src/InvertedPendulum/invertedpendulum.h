#ifndef INVERTEDPENDULUM_H
#define INVERTEDPENDULUM_H

namespace InvertedPendulum
{
    // ----- Constants (will be moved to separate file later) ----- 
    const double MASS_BASE = 50;
    const double MASS_PENDULUM = 50;
    const double LENGTH_PENDULUM = 10;

    class InvertedPendulum
    {
    public:
        InvertedPendulum
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
            double timeElapsed
        );

        // InvertedPendulum();

    private:
        double m_timeInterval;
        double m_massBase;
        double m_massPendulum;
        double m_lengthPendulum;
        double m_xPos;
        double m_angle;
        double m_xVel;
        double m_angleVel;
        double m_xAccel;
        double m_angleAccel;
        double m_appliedForce;
        double m_timeElapsed;
    };
}

#endif