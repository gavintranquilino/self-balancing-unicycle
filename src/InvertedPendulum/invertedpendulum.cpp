#include "invertedpendulum.h"
#include <cmath>

void InvertedPendulum::update(double timeInterval)
{
    m_xPos = m_xVel * timeInterval + m_xPos;
    m_angle = m_angleVel * timeInterval + m_angle;
    m_xVel = m_xAccel * timeInterval + m_xVel;
    m_angleVel = m_angleAccel * timeInterval + m_angleVel;

    // TODO: update the equations of motion
    m_xAccel = ((m_massPendulum * m_lengthPendulum * m_angleAccel * sin(m_angle)) + ((-1 * m_massPendulum * GRAVITY * cos(m_angle) * sin(m_angle)) + m_appliedForce)) / ((m_massBase + m_massPendulum) - (m_massPendulum * cos(m_angle) * cos(m_angle)));
    m_angleAccel = (((m_massPendulum + m_massBase) * GRAVITY * sin(m_angle)) - ((m_massPendulum * m_lengthPendulum * m_angleAccel * m_angleAccel * cos(m_angle) * sin(m_angle)) + (m_appliedForce * cos(m_angle)))) / (((m_massBase + m_massPendulum) * m_lengthPendulum) - (m_massPendulum * m_lengthPendulum * cos(m_angle) * cos(m_angle)));
 
    m_timeElapsed = m_timeElapsed + timeInterval;
}