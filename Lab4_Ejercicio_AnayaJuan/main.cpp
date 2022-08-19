#include "network.h"
#include "tools.h"

using namespace std;

int main()
{
    network _network_;
    int option = menu(0);
    string aux;

    if(option == 1){
        cout << "Ingrese el nombre del archivo donde se encuentra la red\n -> ";
        getline(cin, aux);

        _network_.load_network(aux);

    }else{
        cout << "red aleatoria aun no se hace XD" << endl;
    }

    return 0;
}
