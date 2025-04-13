all:
	g++ -std=c++17 Aleynik_LR3-4_main.cpp -o program

run:
	./program

clean:
	rm -f program
