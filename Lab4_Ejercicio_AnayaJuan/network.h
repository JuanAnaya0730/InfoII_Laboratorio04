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
    vector<router> optimizedTopology;

    string read();
    void write(const string &data);
    size_t findRouter(const string &nameRout);    

public:
    network();

    void load_network(const string &name);
    void save_network();

    void complete();
    int cost(const string &startRouter, const string &destinationRouter);

    void addRouter(const router &newRouter);
    void deleteRouter(const string &name);

    bool exist(const string &name);

    friend ostream& operator<<(ostream &out, const network &network)
    {
        out << left << setw(7) << " name ";
        for(size_t i=0; i < network.optimizedTopology.size(); ++i){
            out << setw(7) << network.optimizedTopology[i].getName();
        }out << endl;

        for(size_t i=0; i < network.optimizedTopology.size(); ++i){
            out << setw(7) << network.optimizedTopology[i].getName();
            for(size_t j=0; j < network.optimizedTopology.size(); ++j){
                if(!(network.optimizedTopology[i].getCost(network.optimizedTopology[j].getName()) == INF)){
                    out << setw(7) << network.optimizedTopology[i].getCost(network.optimizedTopology[j].getName());
                }else{ out << setw(7) << "~"; }
            }out << endl;
        }

        return out;
    }
};

#endif // NETWORK_H
