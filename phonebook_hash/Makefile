CC      = gcc
CFLAGS  = -O0 -Wall -g
#LDFLAGS = -fno-stack-protector

objects = pb_hash.o 
default: pb_hash

pb_hash: $(objects)
	$(CC) $(LDFLAGS) -o $@ $^	

pb_hash.o: pb_hash.c phonebook_hash.h

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) pb_hash

