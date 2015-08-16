CC      = gcc
CFLAGS  = -O0 -Wall -g
#LDFLAGS = -fno-stack-protector

objects = pb_opt.o 
default: pb_opt

pb_opt: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^	

pb_opt.o: pb_opt.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) pb_opt

