// Author: Sean Davis
#ifndef ENCODER_H
#define	ENCODER_H
#define NOTFOUND -1

#include <cstdlib>
#include "BinaryHeap.h"
#include <cstring>
#include "Huffman.h"
using namespace std;


class Encoder
{
public:
  Encoder();
  void encode(const unsigned char *message, const int size, 
    unsigned char *encodedMessage, int *encodedSize);
  ~Encoder();
    inline void add(unsigned *code, unsigned char *encodedMessage, unsigned int &temp, int &curPos, int &bytesUsed);
private:
};



#endif	/* ENCODER_H */

