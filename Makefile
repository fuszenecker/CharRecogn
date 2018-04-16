
CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lfann -lm

PROG_TR	= char_recogn_train
PROG	= char_recogn
OBJS_TR	= $(PROG_TR).o
OBJS	= $(PROG).o


all:	$(OBJS_TR) $(OBJS)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG_TR) $(OBJS_TR)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROG) $(OBJS)

clean:
		rm $(PROG) $(PROG_TR) $(OBJS_TR) *.net $(OBJS)

