#include "unicycle.h"
#include <raylib.h>
#include <invertedpendulum.h>
#include <cmath>

void Unicycle::drawBase(int screenWidthPx, int screenHeightPx, int cartWidth, int cartHeight, double scaleFactor) const
{
    double screenXPos = (screenWidthPx / 2) + (scaleFactor * m_xPos); // use 0 for initial x, and scale up movement
    int yPos = screenHeightPx / 2;
    DrawRectangle((screenXPos - (cartWidth / 2)), yPos, cartWidth, cartHeight, BLUE);    
}

void Unicycle::drawPendulum(int screenWidthPx, int screenHeightPx, int pendulumLength, double scaleFactor) const
{
    double screenXPos = (screenWidthPx / 2) + (scaleFactor * m_xPos); // use 0 for initial x, and scale up movement
    int yPos = screenHeightPx / 2;
    DrawLine(
            screenXPos, yPos, // start line at base of cart

            // Get the end of the pendulum (updated)
            screenXPos + ((pendulumLength) * sin(m_angle)),
            yPos - (pendulumLength) * cos(m_angle), 

            BLACK
            );
}