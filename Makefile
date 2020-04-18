market: market.c product.o
	gcc -o market market.c product.o

product.o: product.c product.h
	gcc -c product.c -o product.o

clean:
	rm *.o market
