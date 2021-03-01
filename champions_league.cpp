#include "Team.h"
#include "League.h"

#include <iostream>
using namespace std;

int main() {

    League league;
    league.addTeam(new Team((char*)"Arsenal",33,21));
    league.addTeam(new Team((char*)"Arsenal",13,11));
    league.addTeam(new Team((char*)"Real Madrid",21,22));
    league.addTeam(new Team((char*)"Liverpool",25,17));
    league.addTeam(new Team((char*)"Borussia Dortmund",20,23));


    league.printTeams();
    Team *bd = league[(char*)"Borussia Dortmund"];
    Team *ars = league[(char*)"Arsenal"];
    *(league[(char*)"Arsenal"]) = *(bd);
    if(*ars==*bd)
        cout<<ars->getName()<< " belongs to two teams"<<endl;
    league.printTeams();
    league.removeTeam((char*)"Arsenal");
    league.removeTeam((char*)"Borussia Dortmund");
    league.printTeams();



    League::printLeagueDetails();
    cout <<*(league[(char*)"Liverpool"]);
    league.removeTeam((char*)"Liverpool");
    League::printLeagueDetails();



    if(*league[(char*)"Real Madrid"]>*league[(char*)"Borussia Dortmund"])
        cout<<"Real Madrid have more points than Borussia Dortmund"<<endl;


    cout <<++(*league[(char*)"Real Madrid"]);
    cout <<"Real Madrid and Borussia Dortmund have "<<*league[(char*)"Real Madrid"]+*league[(char*)"Borussia Dortmund"]<<" points together"<<endl;
    *league[(char*)"Real Madrid"]+=*league[(char*)"Borussia Dortmund"];
    League::printLeagueDetails();
    league.printTeams();

return 0;
}
