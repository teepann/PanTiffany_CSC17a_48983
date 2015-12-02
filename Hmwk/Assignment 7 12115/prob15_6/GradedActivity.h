/* 
 * File:   GradedActivity.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 8:13 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

// GradedActivity class declaration

class GradedActivity
{
protected:
   float score;   // To hold the numeric score
public:
   // Default constructor
   GradedActivity()
      { score = 0.0; }

   // Constructor
   GradedActivity(double s)
      { score = s; }

   // Mutator function
   void setScore(double s) 
      { score = s; }
   
   // Accessor functions
   float getScore() const
      { return score; }
   
   char getLetterGrade() const;
};
#endif 