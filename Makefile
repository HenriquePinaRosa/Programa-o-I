all: dedos

hello: dedos.o
	$(CC) -o $@ $^

clean:
	rm -f *.o dedos

%.o: %.c
	$(CC) -c $^