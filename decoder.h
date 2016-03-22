// Author: Sean Davis
#ifndef DECODER_H
#define	DECODER_H
#include "Huffman.h"

class Decoder
{
public:
  Decoder();
  ~Decoder();
  void decode(const unsigned char* encodedMessage, const int encodedSize,
    unsigned char* decodedMessage, int *decodedSize);
    inline void decoding(const unsigned char *encodedMessage, Huffman *tree, unsigned &bitsUsed, unsigned char *decodedMessage, unsigned &decodeByte, Huffman *original, unsigned size);
private:

};

#endif	/* DECODER_H */

