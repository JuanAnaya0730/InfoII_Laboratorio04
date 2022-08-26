#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "router.h"

using namespace std;

class network
{
private:
    string name;
    vector<router> topology;

    string read();
    void write(const string &data);
    size_t findRouter(const string &nameRout);    

public:
    network();

    void load_network(const string &name);
    void save_network();

    void random(const size_t &numRouters);
    size_t bestCost(const string &startRouter, const string &destinationRouter);

    void addRouter(const router &newRouter);
    void deleteRouter(const string &name);

    bool exist(const string &name);
    const vector<string> names() const;
    size_t size() const;

    friend ostream& operator<<(ostream &out, const network &network)
    {
        if(!network.topology.size()){
            out << "La red esta vacia." << endl;
            return out;
        }
        int width = 7;
        string line(1, char(196));

        out << left;
        for(size_t i=0; i < (network.size()+1)*width; ++i){ line += char(196); }
        out << line << endl;

        out << setw(width) << "|||||||";
        for(size_t i=0; i < network.topology.size(); ++i){
            out << setw(width) << "| " +  network.topology[i].getName();
        }out << "|" << endl << line << endl;

        for(size_t i=0; i < network.topology.size(); ++i){
            out << setw(width) << "| " + network.topology[i].getName();
            for(size_t j=0; j < network.topology.size(); ++j){
                if(!(network.topology[i].getCost(network.topology[j].getName()) == INF)){
                    out << setw(width) << "| " + to_string(network.topology[i].getCost(network.topology[j].getName()));
                }else{ out << setw(width) << "| ~"; }
            }out << "|" << endl << line << endl;
        }
        return out;
    }
};

#endif // NETWORK_H
