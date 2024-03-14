#include "PID.h"
#include "../InvertedPendulum/invertedpendulum.h"
#include <iostream>

namespace PID
{
    void control(InvertedPendulum pendulum)
    {
        std::cout << "length: " << pendulum.getLengthPendulum() << '\n';
    }
}