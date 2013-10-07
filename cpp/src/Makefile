CXXSRC = cpp_unit_test_runner.cc \
         my_byte_buffer.cc \
         my_byte_buffer_test.cc \
		 MurmurHash3.cpp

CXXOBJ = $(subst .cpp,.o,$(subst .cc,.o,$(CXXSRC)))

CXXFLAG = -O3 -Wall -Werror

LIBS += -lcppunit

all:test

test:$(CXXOBJ)
	$(CXX) -Wall $^ -o CppUnitTestRunner $(INCLUDES) $(LIBS) $(CXXFLAG)
	./CppUnitTestRunner

clean:
	rm -f *~ *.o *.out CppUnitTestRunner

.cc.o:
	$(CXX) $(INCLUDES) -c $< $(CXXFLAG)
.cpp.o:
	$(CXX) $(INCLUDES) -c $< $(CXXFLAG)

.PHONY:clean


