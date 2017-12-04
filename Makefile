all:
	g++ -std=c++11 main.cpp MSTree.cpp edge.cpp -o prog2

clean:
	rm prog2
