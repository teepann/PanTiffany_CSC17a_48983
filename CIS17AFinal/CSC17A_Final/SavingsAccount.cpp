/* 
 * File:   SavingsAccount.cpp
 * Author: Tiffany
 * 
 * Created on December 17, 2015, 1:10 AM
 */

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(float balance){
  if(balance<0){
    string negativeException="WithDraw not Allowed\n";
    cout<<negativeException;
    Balance=0;
  }
  else{
    Balance=balance;
  }
  FreqWithDraw=0;
  FreqDeposit=0;
}
void SavingsAccount::Transaction(float trans){
  if(trans>0){
    Balance+=Deposit(trans);
  }
  else
    if(Balance+trans>0)
      Balance+=Withdraw(trans);
    else
      cout<<"WithDraw not Allowed\n";
}
float SavingsAccount::Withdraw(float trans){
  FreqWithDraw++;
  return trans;
}
float SavingsAccount::Deposit(float trans){
  FreqDeposit++;
  return trans;
}
float SavingsAccount::Total(float intrt=0, int year=0){
  float temp=Balance;
  for(int i=0;i<year;i++){
    temp*=(1+intrt);
  }
  return temp;
}
float SavingsAccount::TotalRecursive(float intrt=0, int year=7){
  Balance*=(1+intrt);
  if(year==1){
    return Balance;
  }
  else
    return TotalRecursive(intrt, year-1);
}
void SavingsAccount::toString(){
  cout<<"Balance="<<Balance<<endl;
  cout<<"WithDraws="<<FreqWithDraw<<endl;
  cout<<"Deposit="<<FreqDeposit<<endl;
}