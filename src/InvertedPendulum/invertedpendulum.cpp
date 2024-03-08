#include "invertedpendulum.h"
#include <cmath>
#include <iostream>

void InvertedPendulum::update(double timeInterval)
{
    double netForce = m_appliedForce - (m_frictionConst * m_xVel);
    double massTotal = m_massBase + m_massPendulum;
    
    // TODO: stop movement once the pendulum movement both x and angle have come near rest
    
    // ----- X Equations ----- 
    // personally derived equation for xAccel
    // m_xAccel = (netForce + (m_massPendulum * m_lengthPendulum * m_angleAccel * cos(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle))) / (massTotal);
    // m_xAccel = (netForce + (m_massPendulum * m_lengthPendulum * m_angleAccel * cos(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle))) / (massTotal);

    // from scratch
    // m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle)) + ((netForce) - (m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle)))) / ((massTotal) - (m_massPendulum * cos(m_angle) * cos(m_angle))); // revised scratch
    // m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle)) + ((-1 * m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle))) + netForce) / ((massTotal) - (m_massPendulum * cos(m_angle) * cos(m_angle)));

    // x and y component method 
    m_xAccel = (netForce + (m_massPendulum * m_lengthPendulum * ((sin(m_angle) * m_angleVel * m_angleVel) - (cos(m_angle) * m_angleAccel)))) / (massTotal);

    // Euler's method ordinary differential equation
    m_xVel += m_xAccel * timeInterval;
    m_xPos += m_xVel * timeInterval;

    // ----- Angle Equations -----
    // from scratch
    // m_angleAccel = ((massTotal * GRAVITY * sin(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * cos(m_angle) * sin(m_angle)) + (netForce * cos(m_angle))) / ((massTotal * m_lengthPendulum) - (m_massPendulum * m_lengthPendulum * cos(m_angle) * cos(m_angle)));
    
    // personally derived equation for angleAccel, derived from the lagrangian
    m_angleAccel = ((m_xAccel * cos(m_angle)) + (m_gravityConst * sin(m_angle))) / (m_lengthPendulum);
    // m_angleAccel -= m_angleVel * m_frictionConst; // damping term because of friction
    
    // x and y component method (returns constant value)
    // m_angleAccel = (netForce - (massTotal * m_xAccel) + (m_massPendulum * m_lengthPendulum * sin(m_angle) * m_angleVel * m_angleVel)) / (m_massPendulum * m_lengthPendulum * cos(m_angle));
    
    // Euler's method ordinary differential equation
    m_angleVel += m_angleAccel * timeInterval;
    m_angle += m_angleVel * timeInterval;

    m_timeElapsed = m_timeElapsed + timeInterval;
}