/* 
 * File:   PersonalInfo.cpp
 * Author: Tiffany Pan
 * 
 * Created on November 10, 2015, 7:46 PM
 */

#include "PersonalInfo.h"

PersonalInfo::PersonalInfo() {
    name = "";
    address = "";
    age = 0;
    phone = "(000)000-0000";
}

PersonalInfo::PersonalInfo(const PersonalInfo& orig) {
}

PersonalInfo::~PersonalInfo() {
}

string PersonalInfo::getAddress(){
    return address;
}

string PersonalInfo::getName(){
    return name;
}

string PersonalInfo::getPhone(){
    return phone;
}

int PersonalInfo::getAge(){
    return age;
}

void PersonalInfo::setAddress(string a){
    address = a;
}

void PersonalInfo::setName(string n){
    name = n;
}

void PersonalInfo::setAge(int a){
    age = a;
}

void PersonalInfo::setPhone(string p){
    phone = p;
}