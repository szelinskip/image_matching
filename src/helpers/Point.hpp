#pragma once

namespace helpers {

class Point
{
public:
    Point();
    Point(const double xDim, const double yDim);
    ~Point();
    Point(const Point&);
    Point& operator=(const Point&);
    Point(Point&&);
    Point& operator=(Point&&);

    bool operator==(const Point& other) const;

    double& X();
    double& Y();

private:
    double xDim;
    double yDim;
};

} // namespace helpers
