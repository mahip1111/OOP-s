#include<iostream>
#include<string>

using namespace std;

class Vehicle{
public:
    string name;
    string model;
    int noofTyres;

    Vehicle(string name, string model,int noofTyres){
        this->name = name;
        this->model = model;
        this->noofTyres = noofTyres;
    }
    
void start_engine(){
    cout<<"Engine is starting" <<name<< " "<<model <<endl;
}

void stop_engine(){
    cout<<"Engine is stopping"<<name<<" "<<model<<endl;
}
};

class Car: public Vehicle{
    public:
        int noofDoors;
        string trasmisionType;

        void start_ac(){
            cout<< "Ac has started of "<< name<< endl;
        }
};

int main(){
    Car a;

    return 0;
}