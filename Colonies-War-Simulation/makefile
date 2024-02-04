all:derle bagla calistir

derle:
	gcc -c -I "./include" ./src/AUretim.c -o ./lib/AUretim.o
	gcc -c -I "./include" ./src/BUretim.c -o ./lib/BUretim.o
	gcc -c -I "./include" ./src/Koloni.c -o ./lib/Koloni.o
	gcc -c -I "./include" ./src/Oyun.c -o ./lib/Oyun.o
	gcc -c -I "./include" ./src/Taktik.c -o ./lib/Taktik.o
	gcc -c -I "./include" ./src/BTaktik.c -o ./lib/BTaktik.o
	gcc -c -I "./include" ./src/ATaktik.c -o ./lib/ATaktik.o
	gcc -c -I "./include" ./src/Test.c -o ./lib/Test.o

bagla:
	gcc ./lib/AUretim.o ./lib/BUretim.o ./lib/Koloni.o ./lib/Oyun.o ./lib/Taktik.o ./lib/ATaktik.o ./lib/BTaktik.o ./lib/Test.o -o ./bin/program

calistir:
	./bin/program	