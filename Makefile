all: CMatrice.hh main.cpp Exception.hh Exception.cpp CListeMatrice.h CListeMatrice.cpp

	g++ -Wall main.cpp Exception.cpp CListeMatrice.cpp -o main.o
