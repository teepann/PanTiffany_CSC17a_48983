/* 
 * File:   Circle.cpp
 * Author: Tiffany Pan
 * 
 * Created on November 10, 2015, 12:09 PM
 */

#include "Circle.h"

Circle::Circle() {
    radius = 0;
}

Circle::Circle(float r){
    radius = r;
}

Circle::Circle(const Circle& orig) {
}

Circle::~Circle() {
}

/*setters*/
void Circle::setRadius(float r){
    radius = r;
}

/*Getters*/
float Circle::getRadius(){
    return radius;
}

float Circle::getArea(){
    return pi * radius * radius;
}

float Circle::getDiameter(){
    return radius*2;
}

float Circle::getCircumference(){
    return 2 * pi * radius;
}

