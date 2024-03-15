#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

namespace PID
{
    void init(double Kp, double Ki, double Kd);

    void setSetpoint(double setpoint);

    // Compute the control output based on the current process variable (feedback)
    double compute(double current_value);

    // Reset the PID controller (clear accumulated error and previous error)
    void reset();
}

#endif