heap : main.o heap.o
	g++ -o heap main.o heap.o

main.o : main.cpp heap.h
	g++ -c main.cpp

heap.o : heap.cpp heap.h
	g++ -c heap.cpp

clean :
	rm heap heap.o main.o
