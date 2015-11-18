/* 
 * File:   Circle.h
 * Author: Tiffany Pan
 *
 * Created on November 10, 2015, 12:09 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

class Circle {
public:
    Circle();
    Circle(float);
    Circle(const Circle& orig);
    virtual ~Circle();
    void setRadius(float);
    float getRadius();
    float getArea();
    float getDiameter();
    float getCircumference();
private:
    float radius;
    static const float pi = 3.14159;
};

#endif	/* CIRCLE_H */

