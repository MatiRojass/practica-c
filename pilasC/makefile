OBJS = main.o pila.o
OUT = output
FLAGS = -Wall -g

build: $(OBJS)
	gcc $(FLAGS) -o $(OUT) $(OBJS)

main.o: main.c pila.h
	gcc $(FLAGS) -c main.c

pila.o: pila.c pila.h
	gcc $(FLAGS) -c pila.c

clean:
	rm -f $(OBJS) $(OUT)
