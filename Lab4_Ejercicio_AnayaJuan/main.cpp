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
        getline(cin, aux); system("cls");

        _network_.load_network(aux);

    }else{
        cout << "red aleatoria aun no se hace XD" << endl;
    }

    while(true){
        option = menu(1);

        if(option == 1){
            cout << "agregar enrutador" << endl;

        }else if(option == 2){
            cout << "eliminar enrutador" << endl;

        }else if(option == 3){
            cout << "Costo de envio" << endl;

        }else if(option == 4){
            cout << "Camino de envio" << endl;

        }else{ break; };
    }

    return 0;
}
