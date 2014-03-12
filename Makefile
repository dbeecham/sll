ll.o: ll.c
	clang -g -c -o ll.o ll.c

clean:
	rm ll.o
