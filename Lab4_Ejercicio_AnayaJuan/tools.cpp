#include "tools.h"

int menu(const int &type)
{
    // type es el menu que debe ser mostrado

    string option; // Esta es la opcion tomada por el usuario

    while(true){
        if(type == 0){ /* Se imprime el menu principal para type 0 */
            cout << "Menu:\n"
                    "  1. Subir red.\n"
                    "  2. Generar red.\n"
                    " Opcion: ";

            cin >> option; cin.ignore(); // Se toma la opcion ingresada

            system("cls"); // Se limpia la consola

            /* Se valida la opcion ingresada */
            if(option[0] < 49 || option[0] > 50 || option.length() > 1){
                cout << "Opcion no valida, Intente de nuevo.\n" << endl;
            }else{ break; }

        }else{ /* Se imprime el menu principal para type 1 */
            cout << "Que desea hacer?\n"
                    "  1. Agregar enrutador.\n"
                    "  2. Eliminar enrutador.\n"
                    "  3. Costo de envio.\n"
                    "  4. Camino para envio\n"
                    "  5. Salir\n "
                    " Opcion: ";
            cin >> option; cin.ignore(); // Se toma la opcion ingresada

            system("cls"); // Se limpia la consola

            /* Se valida la opcion ingresada */
            if(option[0] < 49 || option[0] > 53 || option.length() > 1){
                cout << "Opcion no valida, Intente de nuevo.\n" << endl;
            }else{ break; }
        }
    }

    return stoi(option); // Se retorna la opcion tomada por el usuario
}
