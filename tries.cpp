#include "tries.h"


Tries::Tries(Tries *temp1, Tries *temp2)
{
  frequency = temp1->frequency + temp2->frequency;
  numberOfValues = temp1->numberOfValues + temp2->numberOfValues;
  left = temp1;
  right = temp2;
  
}
