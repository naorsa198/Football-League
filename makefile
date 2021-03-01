prog:champions_league.o Team.o League.o
	g++ Team.o League.o champions_league.o -o champions_league
champions_league.o: champions_league.cpp Team.h League.h
	g++ -c champions_league.cpp
Team.o:Team.cpp Team.h
	g++ -c Team.cpp
League.o:League.cpp League.h Team.h
	g++ -c League.cpp
clean:
	rm -f *.o champions_league
