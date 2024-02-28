#include "invertedpendulum.h"
#include <cmath>
#include <iostream>

void InvertedPendulum::update(double timeInterval)
{
    double xPos = m_xVel * timeInterval + m_xPos;
    double angle = m_angleVel * timeInterval + m_angle;
    double xVel = m_xAccel * timeInterval + m_xVel;
    double angleVel = m_angleAccel * timeInterval + m_angleVel;

    double netForce = m_appliedForce - (m_frictionConst * m_xVel);
    double massTotal = m_massBase + m_massPendulum;

    // TODO: update the equations of motion
    // double xAccel = (netForce + (m_massPendulum * m_lengthPendulum * ((sin(m_angle) * m_angleVel * m_angleVel) - (cos(m_angle) * m_angleAccel)))) / (massTotal);
    // double angleAccel = (netForce - (massTotal * m_xAccel) + (m_massPendulum * m_lengthPendulum * sin(m_angle) * m_angleVel * m_angleVel)) / (m_massPendulum * m_lengthPendulum * cos(m_angle));

    // calculate the new xAccel and angleAccel based on the member variables. Use inverted pendulum equations of motion. dont forget GRAVITY
    m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle)) + ((-1 * m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle))) + netForce) / ((massTotal) - (m_massPendulum * cos(m_angle) * cos(m_angle)));
    m_angleAccel = ((massTotal * GRAVITY * sin(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * cos(m_angle) * sin(m_angle)) + (netForce * cos(m_angle))) / ((massTotal * m_lengthPendulum) - (m_massPendulum * m_lengthPendulum * cos(m_angle) * cos(m_angle)));
     
    m_xPos = xPos;
    m_angle = angle;
    m_xVel = xVel;
    m_angleVel = angleVel;

    // cout m_xAccel and m_angleAccel with label
    std::cout << "xAccel: " << m_xAccel << " angleAccel: " << m_angleAccel << '\n';

    m_timeElapsed = m_timeElapsed + timeInterval;
}