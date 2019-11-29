RM = rm -rf
CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -ggdb -Og
INCLUDES =
LFLAGS =
LIBS =

SRCS := exercise-2-02.c exercise-2-03.c
OBJS = $(SRCS:.c=.o)
MAIN = $(SRCS:.c=.x)

all: $(MAIN)
	@echo  Build ${MAIN}

$(MAIN):%.x: %.o
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean cleanall

clean:
	$(RM) $(OBJS)

cleanall: clean
	$(RM) $(MAIN)
