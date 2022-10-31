#include "include/Strophoid.h"
#include "include/Errors.h"
#include <cmath>

namespace lab2{
    Strophoid::Strophoid(double topLoop) {}

    Point Strophoid::value(double x) const {
        Point result;
        result.x = x;
        result.y = x* sqrt((-m_topLoop.x + x)/(-m_topLoop.x - x));
        return result;
        //we should take both signs!!
    }

    double Strophoid::distant(double angle) const { return (std::abs(m_topLoop.x*cos(2*DegToRad(angle))/cos(DegToRad(angle)))); }

    double Strophoid::radius() const { return sqrt(2)*(std::abs(m_topLoop.x)); }

    double Strophoid::squareLoop() const { return (std::abs(m_topLoop.x)*std::abs(m_topLoop.x)*(2 - Pi/2)); }

    double Strophoid::squareBranches() const { return (std::abs(m_topLoop.x*m_topLoop.x)*(2 + Pi/2)); }

    double Strophoid::volume() const { return (std::abs(m_topLoop.x*m_topLoop.x*m_topLoop.x)*Pi*(2 * log(2) - 4.0 / 3.0)); }

    Point Strophoid::getPoint() const { return m_topLoop; }
}
