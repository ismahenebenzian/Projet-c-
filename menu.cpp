// menu
#include <iostream>
#include "bataille.h"
#include "pendu.h"
#include "PFC.h"
#include "nbMystere.h"
#include "morpion.h"
#include "mastermind.h"
#include "bataille_navale.h"

int main() {
    int choix = 0;

    do {
        std::cout << "=====================\n";
        std::cout << " PAGE ACCUEIL - MENU \n";
        std::cout << "=====================\n";
        std::cout << "[1] Lancer Bataille \n";
        std::cout << "[2] Lancer Pendu \n";
        std::cout << "[3] Lancer Pierre-feuille-ciseaux \n";
        std::cout << "[4] Lancer Nombre Mystere \n";
        std::cout << "[5] Lancer Morpion \n";
        std::cout << "[6] Lancer Mastermind \n";
        std::cout << "[7] Lancer Bataille Navale \n";
        std::cout << "[0] Quitter\n";

        std::cout << "Votre choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                bataille::lancer();
                break;

            case 2:
                pendu::lancer();
                break;

            case 3:
                PFC::lancer();
                break;

            case 4:
                nbMystere::lancer();
                break;

            case 5:
                morpion::lancer();
                break;

            case 6:
                mastermind::lancer();
                break;

            case 7:
                bataille_navale::lancer();
                break;

            case 0:
                std::cout << "Quitter\n" << std::endl;
                break;

            default:
                std::cout << "Choix invalide, reessayer.\n";
        }

        std::cout << "\n";

    } while (choix != 0);

    return 0;
}
