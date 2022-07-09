SRC=../src
TARGET=../bin/release
GCC=g++
CFLAGS = -o $(TARGET)/main.exe
RM = rm -rf

all: clean main clean_object

clean:
	$(RM) $(TARGET)/*.exe *.o

main:
	$(GCC) $(SRC)/main.cpp $(CFLAGS)

clean_object:
	$(RM) *.o

run:
	$(TARGET)/main.exe
