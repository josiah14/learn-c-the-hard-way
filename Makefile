CFLAGS=-Wall -g

all: ex1

# the above is the same as the below, interestingly
# build:
# 	cc $(CFLAGS) ex1.c -o ex1

clean:
	rm -f ex1
	rm -f ex1.o
