#include "network.h"
#include "tools.h"

using namespace std;

int main()
{
    network _network_;
    int option = menu(0);
    string aux[2];

    if(option == 1){
        cout << "Ingrese el nombre del archivo donde se encuentra la red\n -> ";
        getline(cin, aux[0]); system("cls");

        _network_.load_network(aux[0]);
        cout << "Red cargada con exito.\n" << endl;

    }else{
        cout << "red aleatoria aun no se hace XD" << endl;
    }

    cout << _network_ << endl;

    while(true){
        system("pause"); system("cls");
        option = menu(1);

        if(option == 1){
            cout << "agregar enrutador" << endl;

        }else if(option == 2){
            cout << "Ingrese el nombre del enrutador a eliminar\n -> ";
            getline(cin, aux[0]); system("cls");

            if(_network_.exist(aux[0])){
                _network_.deleteRouter(aux[0]);

                cout << "Enrutador eliminado con exito.\n" << endl;
                cout << _network_ << endl;

            }else{cout << "El enrutador " << aux[0] << " no existe.\n" << endl; }

        }else if(option == 3){
            cout << "Ingrese el enrutador de partida\n -> ";
            getline(cin, aux[0]); system("cls");

            cout << "Ingrese el enrutador destino\n -> ";
            getline(cin, aux[1]); system("cls");

            cout << "El menor costo de envio de " << aux[0] << " hasta " << aux[1]
                 << " es de " << _network_.bestCost(aux[0], aux[1]) << endl;

        }else if(option == 4){
            cout << "Camino de envio" << endl;

        }else{ break; };                
    }

    return 0;
}
