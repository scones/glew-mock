CC             = g++
INCLUDES       = -IC:/msys/include
CFLAGS         = $(INCLUDES) -O3 -c -Wall -pedantic -std=c++11 -fexec-charset=UTF-8 -finput-charset=UTF-8

LIB_PATHS      = -LC:/msys/lib
LIBS           = 
LDFLAGS        = ${LIB_PATHS} ${LIBS}


SOURCES        = \
	src/glew.cpp \
	src/stubber.cpp

OBJECTS        = $(SOURCES:.cpp=.o)
STATIC_TARGET  = lib/libglew_mock.a

all: $(SOURCES) $(STATIC_TARGET) check $(SHARED_TARGET)


$(STATIC_TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)


$(SHARED_TARGET): $(OBJECTS)
#	$(CC) -shared $(OBJECTS) -o $@ $(LDFLAGS)


check: $(STATIC_TARGET)
	make -C ./tests check


.cpp.o:
	$(CC) ${CFLAGS} $< -o $@


clean:
	make -C ./tests clean
	rm -f $(OBJECTS)
	rm -f $(STATIC_TARGET)
	rm -f $(SHARED_TARGET)
	rm -f gmon.out

