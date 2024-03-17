#include "pid_controller.h"

PID_Controller::PID_Controller
(
    double Kp, 
    double Ki, 
    double Kd, 
    double setPoint,
    double errorSum,
    double prevError,
    double maxOutput,
    double minOutput
) :
    m_Kp(Kp),
    m_Ki(Ki),
    m_Kd(Kd),
    m_setpoint(setPoint),
    m_errorSum(errorSum),
    m_prevError(prevError),
    m_maxOutput(maxOutput),
    m_minOutput(minOutput)
{
}

void PID_Controller::setSetpoint(double setpoint) 
{
    m_setpoint = setpoint;
}

double PID_Controller::compute(double error) 
{
    m_errorSum += error;

    double proportional = m_Kp * error;
    double integral = m_Ki * m_errorSum;
    double derivative = m_Kd * (error - m_prevError);

    m_prevError = error;

    double output = proportional + integral + derivative;
    
    if (output > m_maxOutput) 
        output = m_maxOutput;
    else if (output < m_minOutput) 
        output = m_minOutput;

    return output;
}

void PID_Controller::reset() 
{
    m_errorSum = 0.0;
    m_prevError = 0.0;
}