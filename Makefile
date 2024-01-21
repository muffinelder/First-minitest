Dependencies/Renderlib.o: Dependencies/Renderlib.cpp
	g++ -c Dependencies/Renderlib.cpp -o Dependencies/Renderlib.o
	g++ Minigame.cpp -o Minigame Dependencies/Renderlib.o

Minigame.exe: Minigame.cpp
	g++ Minigame.cpp -o Minigame Dependencies/Renderlib.o