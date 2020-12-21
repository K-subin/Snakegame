CC=g++
TARGET=snakegame
OBJECTS=main.cpp

all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) -lncursesw -std=c++11

clean:
	rm $(TARGET)
