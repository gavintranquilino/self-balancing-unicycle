#ifndef INVERTEDPENDULUM_H
#define INVERTEDPENDULUM_H

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

    // ----- Getters -----
    double getTimeInterval() const { return m_timeInterval; }
    double getMassBase() const { return m_massBase; }
    double getMassPendulum() const { return m_massPendulum; }
    double getLengthPendulum() const { return m_lengthPendulum; }
    double getXPos() const { return m_xPos; }
    double getAngle() const { return m_angle; }
    double getXVel() const { return m_xVel; }
    double getAngleVel() const { return m_angleVel; }
    double getXAccel() const { return m_xAccel; }
    double getAngleAccel() const { return m_angleAccel; }
    double getAppliedForce() const { return m_appliedForce; }
    double getTimeElapsed() const { return m_timeElapsed; }

    // ----- Setters -----
    void setXPos(double xPos) { m_xPos = xPos; }
    void setAngle(double angle) { m_angle = angle; }
    void setXVel(double xVel) { m_xVel = xVel; }
    void setAngleVel(double angleVel) { m_angleVel = angleVel; }
    void setXAccel(double xAccel) { m_xAccel = xAccel; }
    void setAngleAccel(double angleAccel) { m_angleAccel = angleAccel; }
    void setAppliedForce(double appliedForce) { m_appliedForce = appliedForce; }
    void setTimeElapsed(double timeElapsed) { m_timeElapsed = timeElapsed; }

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

#endif