
#include "Huffman.h"
void Huffman::getCode(int i, unsigned *code)
{
  
  if( left && left->check(i) )
  {
    code[0] = code[0] << 0x1 | 0x0;
    code[1]++;
    left->getCode(i, code);
  }
  else if (right && right->check(i) )
  {
    code[0] = code[0] << 0x1 | 0x1;
    code[1]++;
    right->getCode(i, code);
  }
    
  return;
  
  
}

bool Huffman::check(int i)
{
  for (int j = 0 ; j < numberOfValues; j++)
    if(value[j] == i )
      return true;
  
  return false;
}

int Huffman::height()const
{
  int rightCount = 0, leftCount = 0;
  
  if(right)
    rightCount = 1 + right->height();
  
  if(left)
    leftCount = 1 + left->height();
  
  if (rightCount > leftCount)
    return rightCount;
  else
    return leftCount;
}

Huffman::Huffman(Huffman *temp1, Huffman *temp2)
{
  int i, j;
  frequency = temp1->frequency + temp2->frequency;
  numberOfValues = temp1->numberOfValues + temp2->numberOfValues;
  
  value = new int[numberOfValues];
  
  for(i = 0; i < temp1->numberOfValues; i ++)
    value[i] = temp1->value[i];
  
  for(j = 0; j < temp2->numberOfValues; j++, i++)
    value[i] = temp2->value[j];
  
  left = temp1;
  right = temp2;
  
}
