#include "network.h"

network::network()
{

}

void network::load_network(const string &name)
{
    this->name = name;
    string data = read();
    string node;
    string cost;

    for(size_t i=0; !data.empty(); ++i){
        node = data.substr(0, data.find('}')+1);
        topology.push_back(router(node.substr(0, node.find(':'))));

        cost = node.substr(0, node.find('{')+1);
        cost = node.substr(node.find('{')+1, node.length() - 1 - cost.length());

        while(!cost.empty()){
            if(cost.substr(cost.find(":")+1, cost.find(" ")-2) == "-"){
                topology[i].addConection(cost.substr(0, cost.find(':')), INF);
            }else{
                topology[i].addConection(cost.substr(0, cost.find(':')), stoi(cost.substr(cost.find(":")+1, cost.find(" ")-2)));
            }

            if(cost.find(' ') != string::npos){ cost = cost.substr(cost.find(' ')+1, cost.length()); }
            else{ cost.clear(); }
        }

        data = data.substr(data.find('}')+1, data.length());
    }
}

void network::save_network()
{

}

void network::complete()
{
    for(size_t k=0; k < topology.size(); ++k){
        for(size_t i=0; i < topology.size(); ++i){
            for(size_t j=0; j < topology.size(); ++j){
                if(topology[i].getCost(topology[k].getName()) + topology[k].getCost(topology[j].getName()) < topology[i].getCost(topology[j].getName())){
                    topology[i].addConection(topology[j].getName(), topology[i].getCost(topology[k].getName()) + topology[k].getCost(topology[j].getName()));
                }
            }
        }
    }
}

void network::random(const size_t &numRouters)
{
    srand(time(NULL));
    vector<char> letters;
    for(int i=65; i<=90; ++i){ letters.push_back(i); }

    for(size_t i=0; i < numRouters; ++i){
        size_t random = rand()%letters.size();
        topology.push_back(router(string(1, letters[random])));
        letters.erase(letters.begin()+random);
    }

    for(size_t i=0; i < topology.size(); ++i){
        for(size_t j=0; j<topology.size(); ++j){
            if(j != i){
                if(rand()%3){ topology[i].addConection(topology[j].getName(), 1+rand()%15); }
                else{ topology[i].addConection(topology[j].getName(), INF); }

                topology[j].addConection(topology[i].getName(), topology[i].getCost(topology[j].getName()));
            }
        }
    }
}

size_t network::bestCost(const string &startRouter, const string &destinationRouter)
{
    vector<router> optimizedTopology = topology;
    for(size_t k=0; k < optimizedTopology.size(); ++k){
        for(size_t i=0; i < optimizedTopology.size(); ++i){
            for(size_t j=0; j < optimizedTopology.size(); ++j){
                if(optimizedTopology[i].getCost(optimizedTopology[k].getName()) + optimizedTopology[k].getCost(optimizedTopology[j].getName()) < optimizedTopology[i].getCost(optimizedTopology[j].getName())){
                    optimizedTopology[i].addConection(optimizedTopology[j].getName(), optimizedTopology[i].getCost(optimizedTopology[k].getName()) + optimizedTopology[k].getCost(optimizedTopology[j].getName()));
                }
            }
        }
    }

    return optimizedTopology[findRouter(startRouter)].getCost(destinationRouter);
}

void network::addRouter(const router &newRouter)
{
    for(size_t i=0; i < topology.size(); ++i){
        topology[i].addConection(newRouter.getName(), newRouter.getCost(topology[i].getName()));
    }
    topology.push_back(newRouter);
}

void network::deleteRouter(const string &name)
{
    for(size_t i=0; i < topology.size(); ++i){
        topology[i].deleteConnection(name);
    }
    topology.erase(topology.begin() + findRouter(name));
}

bool network::exist(const string &name)
{
    for(size_t i=0; i < topology.size(); ++i){
        if(topology[i].getName() == name){ return true; }
    }
    return false;
}

const vector<string> network::names() const
{
    vector<string> names;
    for(size_t i=0; i < topology.size(); ++i){
        names.push_back(topology[i].getName());
    }
    return names;
}

size_t network::size() const
{
    return topology.size();
}

string network::read()
{
    ifstream file; // Archivo a leer
    string data; // Esto almacenara el contenido del archivo a leer
    string aux; // Esto almacenara temporalmente cada linea del archivo a leer

    file.open("../networks/" + name); // Se abre el archivo
    if (file.is_open()){ // Se verifica si el archivo abrio correctamente

        /* Se recorre todo el archivo */
        while (!file.eof()) {
            getline(file, aux); // Se lee cada linea del archivo

            /* Se guarda la linea del archivo y se le agrega un salto de linea ya que la
             * funcion anterior los ignora*/
            data += aux;
        }

        file.close(); // Se cierra el archivo
    }
    else{ // Si el archivo no se pudo abrir se muestra el mensaje correspondiente y finaliza el programa
        cout << "Error al abrir el archivo " << name << endl;
        exit(1);
    }

    return data; // Se retorna el contenido del archivo
}

void network::write(const string &data)
{
    // data sera el contenido del archivo

    ofstream file; // Archivo a escribir

    file.open("../networks/" + name); // Se abre el archivo
    if (file.is_open()){ // Se verifica si el archivo abrio correctamente

        file << data; // Se escribe en el archivo

        file.close(); // Se cierra el archivo
    }
    else{ // Si el archivo no se pudo abrir se muestra el mensaje correspondiente y finaliza el programa
        cout << "Error al crear o abrir el archivo " << name << endl;
        exit(1);
    }
}

size_t network::findRouter(const string &nameRout)
{
    for(size_t i=0; i < topology.size(); ++i){
        if(topology[i].getName() == nameRout){ return i; }
    }

    return 0;
}
