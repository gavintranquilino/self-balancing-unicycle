#include "pid_controller.h"

namespace PID
{
    namespace 
    {
            double Kp;           // Proportional gain
            double Ki;           // Integral gain
            double Kd;           // Derivative gain
            double setpoint;     // Desired value
            double errorSum;    // Accumulated error
            double prevError;   // Previous error
            double maxOutput;   // Maximum output value
            double minOutput;   // Minimum output value
    }    

    void init(double _Kp, double _Ki, double _Kd) 
    {
        Kp = _Kp;
        Ki = _Ki;
        Kd = _Kd;
        setpoint = 0.0;
        errorSum = 0.0;
        prevError = 0.0;
        maxOutput = 999;
        minOutput = -999;
    }

    void setSetpoint(double _setpoint) 
    {
        setpoint = _setpoint;
    }

    double compute(double error) 
    {
        errorSum += error;

        // Compute PID terms
        double proportional = Kp * error;
        double integral = Ki * errorSum;
        double derivative = Kd * (error - prevError);

        // Update previous error
        prevError = error;

        // Compute control output
        double output = proportional + integral + derivative;

        // Apply output limits
        if (output > maxOutput) 
            output = maxOutput;
        else if (output < minOutput) 
            output = minOutput;

        return output;
    }

    void reset() 
    {
        errorSum = 0.0;
        prevError = 0.0;
    }
}