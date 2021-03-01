#include "Team.h"

Team::Team()
{
    this->teamName= nullptr;
    setName("default");
    this->team_points=0;
    this->numPlayers=0;
}


Team::Team(const char* name, int team_points, int numPlayers)
{
    if(name == nullptr || team_points < 0 || numPlayers < 0 ) exit(1);
    this->team_points = team_points;
    this->numPlayers = numPlayers;
    this->teamName = nullptr;
    setName(name);
}

bool Team::setName(const char* name)
{
    if (name==nullptr)
        return false;
    char* temp;
    temp = new char[strlen(name) + 1];
    if (temp == nullptr)
        return false;
    strcpy(temp,name);
    delete [] this->teamName;
    this->teamName = temp;
    return true;
}

Team::Team(Team& other)
{
    team_points = other.team_points;
    numPlayers = other.numPlayers;
    teamName = nullptr;
    setName(other.teamName);
}

bool Team::operator==(const Team& other)const
{
    if(strcmp(this->teamName,other.teamName)==0)
        return true;
    return false;
}

bool Team::operator>(const Team& other)const
{
    if(this->team_points-other.team_points>0)
        return true;
    return false;
}

Team& Team::operator=(const Team& other) {
    if(this==&other)
        return *this;

    this->team_points = other.team_points;
    this->numPlayers = other.numPlayers;
    setName(other.teamName);
    return *this;
}

int Team::operator+(const Team& other)const
{
    int sum;
    sum=this->team_points+other.team_points;
    return sum;
}

Team& Team::operator++()
{
    this->team_points+=1;
    return *this;
}

Team Team::operator++(int x) {
    Team temp(*this);
    this->team_points += 1;
    return temp;
}

Team& Team::operator+=(const Team& other)
{
    int LenThis;
    int LenOther;
    int j=0,i=0;
    LenThis=(strlen(this->teamName));
    LenOther=strlen(other.teamName);
    int both;
    both=LenThis+LenOther;
    char name[both+1];
    memset(name,0,sizeof(name));
    do{
        name[i]=this->teamName[i];
        ++i;
    }while(i<LenThis);
    do{
        name[i]=other.teamName[j];
        j++;
        ++i;
    }while(i<both || j<LenOther);

    this->setName(name);
    return *this;
}

ostream& operator<<(ostream& out, const Team& other)
{
    out<<"---"<<"\n"<<"name: "<<other.teamName<<"\n"<<"number of players: "<<other.numPlayers<<
       "\n"<<"points: "<<other.team_points<<endl;
    return out;
}