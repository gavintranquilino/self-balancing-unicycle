#include "unicycle.h"
#include <raylib.h>
#include <invertedpendulum.h>
#include <cmath>

void Unicycle::drawWheel(int screenWidthPx, int screenHeightPx, int radius, double scaleFactor) const
{
    double screenXPos = (screenWidthPx / 2) + (scaleFactor * m_xPos); // use 0 for initial x, and scale up movement
    int yPos = screenHeightPx / 2;
    DrawCircle(screenXPos, yPos, radius, GRAY);

    // draw spokes for the unicycle wheel that rotate with the wheel. Calculated using the x position and radius of the wheel
    double normalizePosByRadius = screenXPos / radius;
    DrawLine(screenXPos, yPos, screenXPos + (radius * cos(normalizePosByRadius)), yPos + (radius * sin(normalizePosByRadius)), WHITE);

    // repeat the draw line offset to print on all sides of the circle
    DrawLine(screenXPos, yPos, screenXPos + (radius * cos(normalizePosByRadius + PI/2)), yPos + (radius * sin(normalizePosByRadius + PI/2)), WHITE);
    DrawLine(screenXPos, yPos, screenXPos + (radius * cos(normalizePosByRadius + PI)), yPos + (radius * sin(normalizePosByRadius + PI)), WHITE);
    DrawLine(screenXPos, yPos, screenXPos + (radius * cos(normalizePosByRadius + 3*PI/2)), yPos + (radius * sin(normalizePosByRadius + 3*PI/2)), WHITE);

    // TODO: use a loop instead possibly
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

            RED
            );
}