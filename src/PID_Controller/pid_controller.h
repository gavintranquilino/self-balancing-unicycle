#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID_Controller
{
public:
    PID_Controller(
        double Kp,
        double Ki,
        double Kd,
        double setPoint,
        double errorSum,
        double prevError,
        double maxOutput,
        double minOutput
                );

    void setSetpoint(double setpoint);

    double getSetpoint();

    // Compute the control output based on the current process variable (feedback)
    double compute(double current_value);

    // Reset the PID controller (clear accumulated error and previous error)
    void reset();

private:
    double m_Kp;           // Proportional gain
    double m_Ki;           // Integral gain
    double m_Kd;           // Derivative gain
    double m_setpoint;     // Desired value
    double m_errorSum;    // Accumulated error
    double m_prevError;   // Previous error
    double m_maxOutput;   // Maximum output value
    double m_minOutput;   // Minimum output value
};

#endif