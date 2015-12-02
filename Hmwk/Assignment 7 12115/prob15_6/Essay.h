/* 
 * File:   Essay.h
 * Author: Tiffany
 *
 * Created on December 1, 2015, 8:19 PM
 */

#ifndef ESSAY_H
#define	ESSAY_H
#include "GradedActivity.h"

class Essay: public GradedActivity {
public:
    Essay();
    Essay(const Essay& orig);
    virtual ~Essay();
    void determineScore();
private:
};

#endif	/* ESSAY_H */

