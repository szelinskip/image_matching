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

    double getX() const;
    void setX(const double xDim);
    double getY() const;
    void setY(const double yDim);

private:
    double xDim;
    double yDim;
};

} // namespace helpers
