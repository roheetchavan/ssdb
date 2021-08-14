
db.exe: main.o ssdb.o
	gcc main.o ssdb.o -o db.exe

ssdb.o: ssdb.c
	gcc -g -c ssdb.c -o ssdb.o

main.o: main.c
	gcc -g -c main.c -o main.o

clean:
	rm -rf *.o
	rm -rf *.exe