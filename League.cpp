#include "League.h"

int League::counter = 0;
int League::arrlen;

League::League(){
    arrTeams = new Team*[3];
    if (arrTeams == nullptr) exit(1);

    for (int i = 0; i < 3; i++)
    {
        arrTeams[i] = nullptr;
    }
    arrlen=3;
}

League::League(const  League& other)
{
    this->arrlen=other.arrlen;

    this->counter=other.counter;
    this->arrTeams=new Team*[other.arrlen];
    if (arrTeams == nullptr) exit(1);
    for (int i = 0; i < other.counter; i++)
    {
        Team* sourceTeam=(other.arrTeams[i]);
        Team* temp= new Team(sourceTeam->getName(),sourceTeam->getNumOfPoints(),sourceTeam->getNumOfPlayers());
        this->arrTeams[i] =temp;
    }
}

bool League::addTeam(Team* other) {
    if (other == nullptr) return false;
    if (isExistTeam((*this), (*other).getName()) == true) {
        cout << "This Team is already in the League"<< endl;
        delete other;
        return false;
    }
    if (this->counter < this->arrlen) {
        this->arrTeams[counter] = other;
        this->counter++;
        return true;
    } else  {
        Team **temp;
        temp = new Team *[this->arrlen * 2];
        if (!temp)
            return false;

        for (int i = 0; i < this->counter; i++)
            temp[i] = this->arrTeams[i];

        temp[this->counter] = other;
        this->counter++;
        delete[] this->arrTeams;
        this->arrTeams=temp;
        if(this->arrlen==0)
            this->arrlen=2;
        else
            this->arrlen = this->arrlen * 2;
        return true;
    }
}

bool League::removeTeam(char *name){
    if(name == nullptr)
        return false;
    if (isExistTeam((*this), name)== false) {
        cout << "This Team isn't in the League"<< endl;
        return false;
    }
    int index=getIndex(*this,name);
    Team* temp;
    temp=this->arrTeams[index];
    while(index<counter-1){
        this->arrTeams[index]=this->arrTeams[index+1];
        index++;
    }
    delete temp;
    this->counter--;
    if (this->counter <= this->arrlen/2) {
        Team **temp2;
        temp2 = new Team *[this->arrlen / 2];
        if (!temp2) return false;
        for (int i = 0; i < this->counter; i++)
            temp2[i] = this->arrTeams[i];

        delete[] this->arrTeams;
        this->arrTeams=temp2;
        this->arrlen = this->arrlen / 2;
    }
    return true;
}

League::~League() {
    for (int i=0; i<this->counter; i++)
    {
        delete this->arrTeams[i];
    }
    delete [] this->arrTeams;
}


void League::printTeams()const
{
    cout<<"---Teams---\n";
    for (int i=0; i<this->counter; i++)
    {
        Team temp=*(this->arrTeams[i]);
        cout<< temp;
    }
}

bool isExistTeam(const League& lg,const char* name){
    if(lg.counter == 0 || name == nullptr) return false;
    for(int i=0;i<lg.counter;i++){
        if(strcmp(lg.arrTeams[i]->getName(),name)==0)
            return true;
    }
    return false;
}

Team* League::operator[](char *name) const
{
    int index;
    index=getIndex(*this, name);
    if(index==-1)
    	return nullptr;
    return this->arrTeams[index];
}

int getIndex(const League& lg,const char* name){
    if (name == nullptr) return -1;
    for(int i=0;i<lg.counter;i++){
        if(strcmp(lg.arrTeams[i]->getName(),name)==0)
            return i;
    }
    return -1;
}
