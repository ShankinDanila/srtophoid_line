#ifndef LIB_STROPHOID_H
#define LIB_STROPHOID_H

const double Pi = 3.1415926535;

namespace lab2{
    struct Point{
        double x, y;
        Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
    };

    class Strophoid {
    private:
        Point m_topLoop;
    public:
        explicit Strophoid(double topLoop = 0); //without unforeseen casts
        //setters
        Strophoid& setPoint(const Point& topLoop) { m_topLoop = topLoop; return *this; }
        //getters
        Point getPoint() const;
        //analyzing functions
        Point value(double x) const;
        double distant(double angle) const;
        double radius() const;
        double squareLoop() const;
        double volume() const;
        double squareBranches() const;
    };

    inline double DegToRad(double angle){
        return (angle*Pi/180);
    }
}

#endif //LIB_STROPHOID_H
