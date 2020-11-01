CC=g++
CPPFLAGS=-W -Wall
TARGET=snakegame
OBJECTS=main.cpp

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJECTS) -lncursesw -std=c++11

clean:
	rm -rf *.o
