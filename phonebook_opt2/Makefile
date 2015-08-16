CC      = gcc
CFLAGS  = -O0 -Wall
#LDFLAGS = -fno-stack-protector

objects = pb_opt2.o 
default: pb_opt2

pb_opt2: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^	

pb_opt2.o: pb_opt2.c

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) pb_opt2

