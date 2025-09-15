#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed mainArea = triangleArea(a, b, c);
    if (mainArea == Fixed(0))
        return false;
    Fixed area1 = triangleArea(point, b, c);  
    Fixed area2 = triangleArea(a, point, c);  
    Fixed area3 = triangleArea(a, b, point); 
    Fixed sumAreas = area1 + area2 + area3;
    return (sumAreas == mainArea);
}