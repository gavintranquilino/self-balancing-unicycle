#include "unicycle.h"
#include <raylib.h>
#include <invertedpendulum.h>
#include <cmath>

void Unicycle::drawBase(int screenWidthPx, int screenHeightPx, int cartWidth, int cartHeight, double scaleFactor) const
{
    double screenXPos = (screenWidthPx / 2) + (scaleFactor * m_xPos); // use 0 for initial x, and scale up movement
    int yPos = screenHeightPx / 2;
    DrawCircle(screenXPos, yPos, cartHeight, GRAY);

    // draw spokes for the unicycle wheel that rotate with the wheel. Calculated using the x position and radius of the wheel
    double normalizePosByRadius = m_xPos / cartHeight;
    DrawLine(screenXPos, yPos, screenXPos + (cartHeight * cos(normalizePosByRadius)), yPos + (cartHeight * sin(normalizePosByRadius)), WHITE);

    // repeat the draw line offset to print on all sides of the circle
    DrawLine(screenXPos, yPos, screenXPos + (cartHeight * cos(normalizePosByRadius + PI/2)), yPos + (cartHeight * sin(normalizePosByRadius + PI/2)), WHITE);
    DrawLine(screenXPos, yPos, screenXPos + (cartHeight * cos(normalizePosByRadius + PI)), yPos + (cartHeight * sin(normalizePosByRadius + PI)), WHITE);
    DrawLine(screenXPos, yPos, screenXPos + (cartHeight * cos(normalizePosByRadius + 3*PI/2)), yPos + (cartHeight * sin(normalizePosByRadius + 3*PI/2)), WHITE);

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