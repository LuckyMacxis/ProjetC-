all: CMatrice.hh main.cpp Exception.hh Exception.cpp CListeMatrice.h CListeMatrice.cpp

	g++ main.cpp Exception.cpp CListeMatrice.cpp -o main.o
