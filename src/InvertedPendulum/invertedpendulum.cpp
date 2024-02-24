#include "invertedpendulum.h"

InvertedPendulum::InvertedPendulum
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
) :
    m_timeInterval(timeInterval),
    m_massBase(massBase),
    m_massPendulum(massPendulum),
    m_lengthPendulum(lengthPendulum),
    m_xPos(xPos),
    m_angle(angle),
    m_xVel(xVel),
    m_angleVel(angleVel),
    m_xAccel(xAccel),
    m_angleAccel(angleAccel),
    m_appliedForce(appliedForce),
    m_timeElapsed(timeElapsed)
{
}

// InvertedPendulum::InvertedPendulum()
// {
//     timeInterval = 0;
//     massBase = InvertedPendulum::MASS_BASE;
//     massPendulum = InvertedPendulum::MASS_PENDULUM;
//     lengthPendulum = InvertedPendulum::LENGTH_PENDULUM;
//     xPos = 0;
//     angle = 0;
//     xVel = 0;
//     angleVel = 0;
//     xAccel = 0;
//     angleAccel = 0;
//     appliedForce = 0;
//     timeElapsed = 0;
// }
