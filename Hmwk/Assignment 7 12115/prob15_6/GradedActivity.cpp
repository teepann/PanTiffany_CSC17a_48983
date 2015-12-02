/* 
 * File:   GradedActivity.cpp
 * Author: Tiffany
 * 
 * Created on December 1, 2015, 8:13 PM
 */

#include "GradedActivity.h"

//******************************************************
// Member function GradedActivity::getLetterGrade      *
//******************************************************

char GradedActivity::getLetterGrade() const
{
   char letterGrade; // To hold the letter grade
   
   if (score > 89)
      letterGrade = 'A';
   else if (score > 79)
      letterGrade = 'B';
   else if (score > 69)
      letterGrade = 'C';
   else if (score > 59)
      letterGrade = 'D';
   else
      letterGrade = 'F';
   
   return letterGrade;
}