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
        cout << "Ingrese la cantidad de routers que desea\n -> ";
        getline(cin, aux[0]); system("cls");

        _network_.random(stoi(aux[0]));
        cout << "Red generada con exito.\n" << endl;
    }

    cout << _network_ << endl;

    while(true){
        system("pause"); system("cls");
        option = menu(1);

        if(option == 1){
            router newRouter;

            cout << "Ingrese el nombre del nuevo enrutador\n -> ";
            getline(cin, aux[0]); system("cls");

            if(!_network_.exist(aux[0])){
                newRouter.setName(aux[0]);

                for(size_t i=0; i < _network_.size(); ++i){
                    cout << "Ingrese el valor de la conexion con " << _network_.names()[i] << "\n -> ";
                    getline(cin, aux[0]); system("cls");

                    if(aux[0] == "~"){ newRouter.addConection(_network_.names()[i], INF); }
                    else{ newRouter.addConection(_network_.names()[i], stoi(aux[0])); }
                }
                _network_.addRouter(newRouter);

                cout << "Enrutador agregado con exito.\n" << endl;
                cout << _network_ << endl;

            }else{ cout << "El enrutador ya esta en la red.\n" << endl; }

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

            if(_network_.exist(aux[0])){
                cout << "Ingrese el enrutador destino\n -> ";
                getline(cin, aux[1]); system("cls");

                if(_network_.exist(aux[1])){
                    cout << "El menor costo mas bajo de " << aux[0] << " hasta " << aux[1]
                         << " es de " << _network_.bestCost(aux[0], aux[1]) << ".\n" << endl;
                    continue;
                }
            }
            cout << "El enrutador ingresado no existe.\n" << endl;

        }else if(option == 4){
            cout << "Camino de envio\n" << endl;

        }else{
            _network_.save_network();
            break;
        };
    }

    return 0;
}
