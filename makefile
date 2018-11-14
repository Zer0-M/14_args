all: main.o
	gcc -o parse_test  main.o

main.o: main.c parse.h
	gcc -c -g main.c parse.h

run: 
	./parse_test

clean:
	rm *.o
	rm ./parse_test
