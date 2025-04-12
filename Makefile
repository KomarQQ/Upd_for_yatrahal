CC = gcc
CCFLAGS = -g -lncurses

TARGET = ./roguelike
TARGET_DEL = ./roguelike

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -O $@

run: $(TARGET)
	$(TARGET)

clean:
	del $(TARGET_DEL) $(OBJS)
