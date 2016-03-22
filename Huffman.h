#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include "BinaryHeap.h"
#include <cstring>
#include <cstdlib>
class Huffman
{
public:
  int frequency;
  int *value;
  Huffman *left;
  Huffman *right;
  int numberOfValues;
  
  Huffman(int fre = 0, int val = 0, Huffman *l = NULL, Huffman *r = NULL):frequency(fre), left(l),right(r){
    numberOfValues = 1;
    value = new int[1];
    value[0] = val;
  }
  inline void increaseFrequency(){ frequency++; }
    
  Huffman(const Huffman &rhs)
  {
    frequency = rhs.frequency;
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    numberOfValues = rhs.numberOfValues;
  }
  int height()const;
  //Huffman* address()const{return this;}
  Huffman(Huffman *temp1, Huffman *temp2);
  //friend class Encoder;
  //friend class BinaryHeap<Huffman*>;
  //friend class Decoder;
  void getCode(int i, unsigned *code);
  inline bool check(int i);
   //inline void decoding(const unsigned char *encodedMessage, Huffman *tree, unsigned &bitsUsed, unsigned char *decodedMessage, unsigned &decodeByte, Huffman *original, unsigned size);
};


#endif