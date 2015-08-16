CC      = gcc
CFLAGS  = -O0 -Wall -g
#LDFLAGS = -fno-stack-protector

objects = pb_orig.o 
default: pb_orig

pb_orig: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^	

pb_orig.o: pb_orig.c phonebook_orig.h

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) pb_orig

