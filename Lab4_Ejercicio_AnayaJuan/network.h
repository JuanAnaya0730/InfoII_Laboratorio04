#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
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

    void complete();
    int cost(const string &startRouter, const string &destinationRouter);

    void deleteRouter(string &name);

    friend ostream& operator<<(ostream &out, const network &network)
    {
        out << left << setw(7) << " name ";
        for(size_t i=0; i < network.topology.size(); ++i){
            out << setw(7) << network.topology[i].getName();
        }out << endl;

        for(size_t i=0; i < network.topology.size(); ++i){
            out << setw(7) << network.topology[i].getName();
            for(size_t j=0; j < network.topology.size(); ++j){
                if(!(network.topology[i].getCost(network.topology[j].getName()) == INF)){
                    out << setw(7) << network.topology[i].getCost(network.topology[j].getName());
                }else{ out << setw(7) << "~"; }
            }out << endl;
        }

        return out;
    }
};

#endif // NETWORK_H
