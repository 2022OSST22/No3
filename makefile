dessert : order.c dessert.o
	gcc -o dessertorder order.c dessert.o
dessert.o : dessert.c dessert.h
	gcc -c dessert.c
clean :
	rm *.o dessertorder
