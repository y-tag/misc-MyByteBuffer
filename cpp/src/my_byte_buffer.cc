#include "my_byte_buffer.h"

#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "MurmurHash3.h"

MyByteBuffer::MyByteBuffer() : position_(0) {
  byte_buffer_ = new char[128];
}

MyByteBuffer::MyByteBuffer(int capasity) : position_(0) {
  byte_buffer_ = new char[capasity];
}

MyByteBuffer::~MyByteBuffer() {
  if (byte_buffer_ != NULL) {
    delete byte_buffer_;
    byte_buffer_ = NULL;
  }
}

MyByteBuffer* MyByteBuffer::Clear() {
  position_ = 0;
  return this;
}

int MyByteBuffer::HashCode() {
  return HashCode(0);
}

int MyByteBuffer::HashCode(int seed) {
  int hash = 0;
  MurmurHash3_x86_32(byte_buffer_, position_, seed, &hash);
  return hash;
}

MyByteBuffer* MyByteBuffer::AddString(const std::string &value) {
  int len = value.length();
  memmove(byte_buffer_ + position_, value.c_str(), len);
  position_ += len;
  return this;
}

MyByteBuffer* MyByteBuffer::AddInt(int value) {
  int len = sizeof(value);
  memmove(byte_buffer_ + position_, &value, len);
  position_ += len;
  return this;
}

MyByteBuffer* MyByteBuffer::AddLong(int64_t value) {
  int len = sizeof(value);
  memmove(byte_buffer_ + position_, &value, len);
  position_ += len;
  return this;
}

MyByteBuffer* MyByteBuffer::AddFloat(float value) {
  int len = sizeof(value);
  memmove(byte_buffer_ + position_, &value, len);
  position_ += len;
  return this;
}

MyByteBuffer* MyByteBuffer::AddDouble(double value) {
  int len = sizeof(value);
  memmove(byte_buffer_ + position_, &value, len);
  position_ += len;
  return this;
}
