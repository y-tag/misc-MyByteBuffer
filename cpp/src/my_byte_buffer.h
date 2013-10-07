#ifndef MY_BYTE_BUFFER_H
#define MY_BYTE_BUFFER_H

#include <string>
#include "stdint.h"

class MyByteBuffer {
  public:
    MyByteBuffer();
    explicit MyByteBuffer(int capacity);
    virtual ~MyByteBuffer();
    
    MyByteBuffer* Clear();
    int HashCode();
    int HashCode(int seed);
    MyByteBuffer* AddString(const std::string &value);
    MyByteBuffer* AddInt(int value);
    MyByteBuffer* AddLong(int64_t value);
    MyByteBuffer* AddFloat(float value);
    MyByteBuffer* AddDouble(double value);

  private:
    char* byte_buffer_;
    int position_;
};


#endif // MY_BYTE_BUFFER_H
