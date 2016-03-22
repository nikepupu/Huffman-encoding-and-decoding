//  Author: Sean Davis

#include "encoder.h"
#include <iostream>

using namespace std;
Encoder::Encoder()
{
  
} // Encoder()


Encoder::~Encoder()
{
} // ~Encoder()


void Encoder::add(unsigned *code, unsigned char *encodedMessage, unsigned int &temp, int &curPos, int &bytesUsed)
{
 
 if(code[1] > 0x0)
 {
   temp = (temp << code[1] )  | code[0];
   curPos += code[1];
 }
  else
    return;
  
  
  while(curPos >= 0x8 )
  {
    unsigned char inter = temp >> (curPos - 0x8);
    encodedMessage[bytesUsed++] = inter;
    unsigned mask = 0xff << (curPos - 0x8);
    temp = (~mask) & temp;
    curPos -= 0x8;
  }
    
}

//in the following function, code[][] is a 2-D arary. code[][0] stroes the actual code, and code[][1] stores the length of the code





void Encoder::encode(const unsigned char *message, const int size,
  unsigned char *encodedMessage, 
    int *encodedSize)
{
  memset(encodedMessage, 0, size);
  Huffman *total[256];//index frequency
  unsigned frequency[257];
  int curPos = 0;
  unsigned transition = 0;
  int compressedSize = 0;
  int numberOfBits = 0;
  int bytesUsed = 0;
  Huffman *temp1, *temp2;
  Huffman *newTree;
  
  for(int i = 0; i < 256; i++)
    total[i] = new Huffman(0,i);
    
  
  for(int i = 0; i < size; i++)
    total[message[i]]->increaseFrequency();
  
  BinaryHeap<Huffman*> codeTree(256);
  
  for(int i = 0; i < 256; i++)
    codeTree.insert(total[i]);
 
  
  while(codeTree.findMin()->frequency == 0)
    codeTree.deleteMin();
  
  int t = codeTree.getSize();
    
  unsigned  code[256][2];
    
  for(int i = 0; i < 256; i++ )
  {
    code[i][0] = 0;
    code[i][1] = 0;
  }
  
  while (t > 0x1)
  {
    temp1 = codeTree.findMin();
    codeTree.deleteMin();
    temp2 = codeTree.findMin();
    codeTree.deleteMin();
    newTree = new Huffman(temp1, temp2);
    codeTree.insert(newTree);
    t = codeTree.getSize();
  }
  
  temp1 = codeTree.findMin();
 
  for(int i = 0; i < 256; i++)
  {
      temp1->getCode(i, code[i]);
    compressedSize = compressedSize + (total[i]->frequency )* code[i][1];
     frequency[i] = total[i] -> frequency;
  }
    
  frequency[256] = size;
    
  memcpy(encodedMessage, frequency, 1028);
    
   *encodedSize = ((compressedSize +  numberOfBits) >> 0x3)  + 0x0404;
  
  bytesUsed = 1028;
  
  for(int i = 0; i < size; i++)
    add(code[message[i] ], encodedMessage, transition, curPos, bytesUsed);
    
    transition <<= (8-curPos);
    
    encodedMessage[bytesUsed++] = (unsigned char)transition;
  

  
}






// encode()
