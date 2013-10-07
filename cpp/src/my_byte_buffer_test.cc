#include "stdint.h"

#include <cppunit/extensions/HelperMacros.h>

#include "my_byte_buffer.h"

class MyByteBufferTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(MyByteBufferTest);
  CPPUNIT_TEST(testHashCodeForString);
  CPPUNIT_TEST(testHashCodeForMix);
  CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();
    void testHashCodeForString();
    void testHashCodeForMix();
};

CPPUNIT_TEST_SUITE_REGISTRATION(MyByteBufferTest);

void MyByteBufferTest::setUp() { }

void MyByteBufferTest::tearDown() { }

void MyByteBufferTest::testHashCodeForString() {
  int seed = 12345;
  int hash = 0;
  MyByteBuffer* bb = new MyByteBuffer();

  bb->Clear();
  hash = bb->AddString("")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(1011272156, hash);

  bb->Clear();
  hash = bb->AddString("abcde:123456789")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(2115837011, hash);

  bb->Clear();
  hash = bb->AddString("term:foobarhoge")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(1746195674, hash);

  bb->Clear();
  hash = bb->AddString("term:ふーばーほげ")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(933544832, hash);

  bb->Clear();
  hash = bb->AddString("キー:バリュー")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(385955771, hash);

  delete bb;
  bb = NULL;
}

void MyByteBufferTest::testHashCodeForMix() {
  int seed = 12345;
  int hash = 0;
  MyByteBuffer* bb = new MyByteBuffer();

  bb->Clear();
  hash = bb->AddString("abc")->AddInt(12345)->AddString("def")->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(629088618, hash);

  bb->Clear();
  hash = bb->AddString("key")->AddInt(12345)->AddString("value")->AddFloat(0.789f)->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(506168901, hash);

  bb->Clear();
  hash = bb->AddString("きー")->AddLong(1234567890123LL)->AddString("バリュー")->AddDouble(0.123)->HashCode(seed);
  CPPUNIT_ASSERT_EQUAL(68316556, hash);

  delete bb;
  bb = NULL;
}
