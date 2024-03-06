#include "invertedpendulum.h"
#include <cmath>
#include <iostream>

void InvertedPendulum::update(double timeInterval)
{
    double netForce = m_appliedForce - (m_frictionConst * m_xVel);
    double massTotal = m_massBase + m_massPendulum;

    // double xAccel = (netForce + (m_massPendulum * m_lengthPendulum * ((sin(m_angle) * m_angleVel * m_angleVel) - (cos(m_angle) * m_angleAccel)))) / (massTotal);
    // double angleAccel = (netForce - (massTotal * m_xAccel) + (m_massPendulum * m_lengthPendulum * sin(m_angle) * m_angleVel * m_angleVel)) / (m_massPendulum * m_lengthPendulum * cos(m_angle));

    // based on scratch
    // m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle)) + ((-1 * m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle))) + netForce) / ((massTotal) - (m_massPendulum * cos(m_angle) * cos(m_angle)));
    // m_angleAccel = ((massTotal * GRAVITY * sin(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * cos(m_angle) * sin(m_angle)) + (netForce * cos(m_angle))) / ((massTotal * m_lengthPendulum) - (m_massPendulum * m_lengthPendulum * cos(m_angle) * cos(m_angle)));

    // based on lagrangian derived EOM
    // double xAccel = (netForce + (m_massPendulum * m_lengthPendulum * m_angleAccel * cos(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle))) / (massTotal);
    // double angleAccel = ((m_xAccel * cos(m_angle)) + (GRAVITY * sin(m_angle))) / (m_lengthPendulum);
    
    // revised march 3 2024, update from highest order and go down
    m_angleAccel = ((m_xAccel * cos(m_angle)) + (GRAVITY * sin(m_angle))) / (m_lengthPendulum);
    m_angleAccel -= m_angleVel * m_frictionConst; // damping term because of friction

    m_angleVel += m_angleAccel * timeInterval;
    m_angle += m_angleVel * timeInterval;

    m_xAccel = (netForce + (m_massPendulum * m_lengthPendulum * m_angleAccel * cos(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle))) / (massTotal);
    m_xVel += m_xAccel * timeInterval;
    m_xPos += m_xVel * timeInterval;

    // cout m_xAccel and m_angleAccel with label
    std::cout << "xAccel: " << m_xAccel << " angleAccel: " << m_angleAccel << '\n';

    m_timeElapsed = m_timeElapsed + timeInterval;
}