#include "invertedpendulum.h"
#include <cmath>

void InvertedPendulum::update
(
    double timeInterval 
)
{
    m_xPos = m_xVel * timeInterval + m_xPos;
    m_angle = m_angleVel * timeInterval + m_angle;
    m_xVel = m_xAccel * timeInterval + m_xVel;
    m_angleVel = m_angleAccel * timeInterval + m_angleVel;

    m_xAccel = (m_appliedForce + m_massPendulum * sin(m_angle) * (m_lengthPendulum * m_angleVel * m_angleVel + 9.8 * cos(m_angle))) / (m_massBase + m_massPendulum * (1 - cos(m_angle) * cos(m_angle)));
    m_angleAccel = (-m_appliedForce * cos(m_angle) - m_massPendulum * m_lengthPendulum * m_angleVel * m_angleVel * cos(m_angle) * sin(m_angle) + (m_massBase + m_massPendulum) * 9.8 * sin(m_angle)) / (m_lengthPendulum * (m_massBase + m_massPendulum * (1 - cos(m_angle) * cos(m_angle))));

    m_timeElapsed = m_timeElapsed + timeInterval;
}