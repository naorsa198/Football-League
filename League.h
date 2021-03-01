#ifndef LIGA_LEAGUE_H
#define LIGA_LEAGUE_H
#include "Team.h"

class League {
    Team **arrTeams;
    static int arrlen;
    static int counter;
public:
    League();

    League(const League &other);

    ~League();

    bool addTeam(Team* other);

    bool removeTeam(char *name);

    void printTeams()const;

    static void printLeagueDetails()
    {
        cout<<"---League Details---\n"<<"number of teams: "<<counter<<"\n"<<"league size: "<<arrlen<<endl;
    }

    Team* operator[](char *name) const;

    friend bool isExistTeam(const League& lg,const char *name);

    friend int getIndex(const League& lg,const char* name);
};

#endif //LIGA_LEAGUE_H