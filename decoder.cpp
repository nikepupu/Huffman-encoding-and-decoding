#include "decoder.h"
#include <iostream>
#include <cstring>
#include "tries.h"
#include "BinaryHeap.h"
using namespace std;

Decoder::Decoder()
{
} // Decoder()


Decoder::~Decoder()
{
} // ~Decoder()


void Decoder::decode(const unsigned char* encodedMessage, const int encodedSize,
  unsigned char* decodedMessage, int *decodedSize)
{
  
  Tries *total[256];//index frequency
  unsigned frequency[257]; // last byte stores size
  unsigned bitsUsed = 0x0404<<3;
  Tries *temp1, *temp2;
  Tries *newTree;
  
     memcpy(frequency, encodedMessage, 1028);
    BinaryHeap<Tries*> codeTree(256);
  for(int i = 0; i < 256; i++)
  {
    total[i] = new Tries(0,i);
    total[i] -> frequency = frequency[i];
  }
  for(int i = 0; i < 256; i++)
    codeTree.insert(total[i]);
  
  while(codeTree.findMin()->frequency == 0x0)
    codeTree.deleteMin();
  
  int t = codeTree.getSize();
  
  while (t > 0x1)
  {
    temp1 = codeTree.findMin();
    codeTree.deleteMin();
    temp2 = codeTree.findMin();
    codeTree.deleteMin();
    newTree = new Tries(temp1, temp2);
    codeTree.insert(newTree);
    t = codeTree.getSize();
  }
  
  temp1 = codeTree.findMin();

  //decoding(encodedMessage, temp1, bitsUsed, decodedMessage, decodeByte, temp1, frequency[256]);

    Tries *original = temp1;
    Tries *tree =temp1;
    unsigned char curByte = 0x0;
    unsigned curPos = 0x0;
    
    unsigned int count = 0;
    unsigned int i = 0;
    unsigned int size = frequency[256];
    
    while (i < size)
    {
            while (tree->left)
            {
            curPos = bitsUsed & 0x7;
                
              if(curPos == 0x0)
                curByte = encodedMessage[bitsUsed>>3]; // shift left

                curPos = curByte >> (7-curPos);
                
                tree = curPos & 0x1 ? tree -> right : tree -> left;
            
                bitsUsed++;
            }
            
                decodedMessage[count++] = tree -> value;
                tree = original;
        i++;
    }
    

  *decodedSize = size;
  //cout <<"size:" <<sizeof(decodedMessage)*4;
  
} // decode()
