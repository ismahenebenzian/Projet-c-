// mastermind

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mastermind.h"
using namespace std;


void initialisation_hasard (int secret [],const int taille) {   // const je veux pas changer de taille
    srand(time(0)) ;   // initialiser le generateur de nombre aleatoires avec l'heure actuel
    for (int i =0 ;i<taille;i++){
        secret[i]=rand()% 6+1;     // donne un nombre entre 0 a 5 et on ajoute +1 pour trasformer 1 a 6
    }
    for(int i =0 ; i<taille ; i++){
        cout<<secret[i]<<" " ;
            }
}


void proposition_joueur(int proposition [],int nombre){
    string entree;
    cout<<"entre"<<nombre<<"chiffres (entre 1 et 6) : " << " " <<endl ;
    cin>>entree;
    if(entree.size()!= nombre){
        cout<<"erreur : tu dois entrer exactement" << nombre << "chiffres" <<endl;
        return ;
    }

    for (int i=0 ; i<nombre ; i++){
    proposition[i] = entree[i] - '0';;
    }

    cout <<"tu as propose" ;
    for (int i = 0 ; i<nombre ; i++){
        cout<<proposition[i];
    }
    cout<<endl;
}


// COMPARER UNE COMBINAISON

void compare(int secret[], int proposition[], int taille, int &bienplace, int &malplace){
    bool secretutilise[taille]={false};   // false ici veux dire que la place n'a pas ete encore utilisé
    bool propositionutilise[taille]={false};
    bienplace = 0;
    malplace = 0;

    //BIEN PLACE
    for(int i=0 ; i< taille ; i++){         // i indique quelle position du joueur on regarde
        if (proposition[i]==secret[i]){
            bienplace ++ ;
            secretutilise[i]=true;
            propositionutilise[i]=true;   // Ce chiffre a été utilisé, je le marque pour ne plus le recompter
        }
    }

    // MAL PLACE
    for(int i=0 ; i< taille ; i++){
        for(int j=0;j<taille ; j++){
            if(proposition[i]==secret[j] && i!=j && !secretutilise[j] && !propositionutilise[i]){
                malplace ++ ;
                secretutilise[j] = true;
                propositionutilise[i] = true;
                break ;
            }
        }
    }
}


//FAIRE UNE BOUCLE REPETITIONO DU JEU
void jouer_partie(int secret [],int taille){
    int bienplace = 0;
    int malplace =0;
    int proposition [taille];
    const int maxEssai = 10 ;
    cout <<"Le jeu commence ! tu as "<< maxEssai << " essais"<<endl;

    for (int essai = 1 ; essai<=maxEssai && bienplace !=taille; essai++ ){
        cout<<"essai "<<essai<<" sur "<<maxEssai<<endl;
        proposition_joueur(proposition,taille);

        // Réinitialiser les compteurs à chaque tour
        bienplace = 0;
        malplace = 0;

        compare(secret, proposition, taille, bienplace, malplace);
        cout << "bien place : "<<bienplace<<endl;
        cout<<"mal place : "<<malplace<<endl;

        if (bienplace == taille) {
            cout << " Bravo ! Tu as trouve la combinaison secrete !" << endl;
            return;
        }
        else if (essai < maxEssai) {
            cout << "Reessaie !" << endl;
        }
    }

    cout << "Dommage ! Tu as utilise tous tes essais." << endl;
    cout << "La combinaison secrete est : ";
    for (int i = 0; i < taille; i++) cout << secret[i] << " ";
    cout << endl;
}



namespace mastermind {
void lancer() {

    cout<<"Bienvenue dans le jeu Mastermind !"<<endl;
    cout<<"Devine  la combinaison secrete de chiffres"<<endl;

    const int taille = 4;
    int secret[taille];
    initialisation_hasard(secret,taille);

    jouer_partie(secret,taille);

}
}
