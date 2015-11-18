/* 
 * File:   PersonalInfo.h
 * Author: Tiffany Pan
 *
 * Created on November 10, 2015, 7:46 PM
 */

#ifndef PERSONALINFO_H
#define	PERSONALINFO_H

#include <string>
using namespace std;

class PersonalInfo {
public:
    PersonalInfo();
    PersonalInfo(const PersonalInfo& orig);
    virtual ~PersonalInfo();
    
    void setName(string);
    void setAddress(string);
    void setAge(int);
    void setPhone(string);
    string getName();
    string getAddress();
    int getAge();
    string getPhone();
private:
    string name;
    string address;
    int age;
    string phone;
};

#endif	/* PERSONALINFO_H */

