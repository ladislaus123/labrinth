all:
	g++ -Iheaders src/*.cpp main.cpp -o game

clean:
	rm -f game
