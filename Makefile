CC = gcc
OBJS = game.o main.o player.o utils.o
EXEC = 2048
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

game.o: game.c game.h player.h utils.h
main.o: main.c game.h
player.o: player.c player.h game.h utils.h
utils.o: utils.c utils.h game.h player.h


clean:
	rm -f $(CC) $(OBJS)

