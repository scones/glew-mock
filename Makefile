CC             = g++
INCLUDES       = -IC:/msys/include
CFLAGS         = $(INCLUDES) -O2 -c -Wall -pedantic -std=c++11 -fexec-charset=UTF-8 -finput-charset=UTF-8 -D_GLIBCXX_HAVE_BROKEN_VSWPRINTF -DGLEW_STATIC

LIB_PATHS      = -LC:/msys/lib
LIBS           = 
LDFLAGS        = ${LIB_PATHS} ${LIBS}


find = $(foreach dir,$(1),$(foreach d,$(wildcard $(dir)/*),$(call find,$(d),$(2))) $(wildcard $(dir)/$(strip $(2))))

SOURCES_LIB       = $(call find, src, *.cpp)
OBJECTS_LIB       = $(SOURCES_LIB:.cpp=.o)


STATIC_TARGET  = lib/libglew_mock.a


all: $(STATIC_TARGET) check 


$(STATIC_TARGET): $(OBJECTS_LIB)
	ar rcs $@ $(OBJECTS_LIB)


check: $(STATIC_TARGET)
	+make -C ./tests check


.cpp.o:
	$(CC) ${CFLAGS} $< -o $@


clean:
	make -C ./tests clean
	rm -f $(OBJECTS_LIB)
	rm -f $(STATIC_TARGET)
	rm -f gmon.out

