#include "invertedpendulum.h"
#include <cmath>
#include <iostream>

void InvertedPendulum::update(double timeInterval)
{
    double xPos = m_xVel * timeInterval + m_xPos;
    double angle = m_angleVel * timeInterval + m_angle;

    // keep angle between -2PI and 2PI
    if (angle > 2 * M_PI)
    {
        angle = angle - 2 * M_PI;
    }
    else if (angle < -2 * M_PI)
    {
        angle = angle + 2 * M_PI;
    }

    double xVel = m_xAccel * timeInterval + m_xVel;
    double angleVel = m_angleAccel * timeInterval + m_angleVel;

    double netForce = m_appliedForce - (m_frictionConst * m_xVel);
    double massTotal = m_massBase + m_massPendulum;

    // TODO: update the equations of motion
    // double xAccel = (netForce + (m_massPendulum * m_lengthPendulum * ((sin(m_angle) * m_angleVel * m_angleVel) - (cos(m_angle) * m_angleAccel)))) / (massTotal);
    // double angleAccel = (netForce - (massTotal * m_xAccel) + (m_massPendulum * m_lengthPendulum * sin(m_angle) * m_angleVel * m_angleVel)) / (m_massPendulum * m_lengthPendulum * cos(m_angle));

    // based on scratch
    // m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle)) + ((-1 * m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle))) + netForce) / ((massTotal) - (m_massPendulum * cos(m_angle) * cos(m_angle)));
    // m_angleAccel = ((massTotal * GRAVITY * sin(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * cos(m_angle) * sin(m_angle)) + (netForce * cos(m_angle))) / ((massTotal * m_lengthPendulum) - (m_massPendulum * m_lengthPendulum * cos(m_angle) * cos(m_angle)));

    // based on lagrangian derived EOM
    // double xAccel = (netForce + (m_massPendulum * m_lengthPendulum * m_angleAccel * cos(m_angle)) - (m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * sin(m_angle))) / (massTotal);
    double angleAccel = ((m_xAccel * cos(m_angle)) + (GRAVITY * sin(m_angle))) / (m_lengthPendulum);
     
    m_xAccel = xAccel;
    m_angleAccel = angleAccel;
    m_xVel = xVel;
    m_angleVel = angleVel;
    m_xPos = xPos;
    m_angle = angle;

    // cout m_xAccel and m_angleAccel with label
    std::cout << "xAccel: " << m_xAccel << " angleAccel: " << m_angleAccel << '\n';

    m_timeElapsed = m_timeElapsed + timeInterval;
}