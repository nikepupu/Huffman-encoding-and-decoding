#ifndef _TRIES_H
#define _TRIES_H
#include <cstdlib>
class Tries
{
public:
  int frequency;
  int value;
  Tries *left;
  Tries *right;
  int numberOfValues;
  
  Tries(int fre = 0, int val = 0, Tries *l = NULL, Tries *r = NULL):frequency(fre), left(l),right(r){
    numberOfValues = 1;
    value = val;
  }
  Tries(const Tries &rhs)
  {
    frequency = rhs.frequency;
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    numberOfValues = rhs.numberOfValues;
  }
  Tries(Tries *temp1, Tries *temp2);


};


#endif