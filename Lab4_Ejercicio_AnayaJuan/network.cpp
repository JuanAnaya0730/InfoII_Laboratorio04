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
