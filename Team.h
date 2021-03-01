#ifndef LIGAB_TEAM_H
#define LIGAB_TEAM_H
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Team {
    char *teamName;
    int team_points;
    int numPlayers;
public:
    Team();

    Team(const char* name, int team_points, int numPlayers);

    Team(Team& other);

    ~Team() {delete[] this->teamName;}

    bool operator==(const Team& other) const;

    bool operator>(const Team& other) const;

    Team& operator=(const Team& other);

    int operator+(const Team& other) const;

    Team& operator++();

    Team operator++(int x);

    Team& operator+=(const Team &other);

    friend ostream& operator<<(ostream& out, const Team& other);

    bool setName(const char* name);

    char* getName()const{return this->teamName;}

    int getNumOfPlayers()const{return this->numPlayers;}

    int getNumOfPoints()const{return this->team_points;}

};
#endif //LIGA_TEAM_H
