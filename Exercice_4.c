#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct voitures {
    char* modele;
    char* marque;
    char* annee;
    struct voitures* next;
} Node;

// fonction pour ajouter une voiture dans la liste avec son modele, sa marque et son année.


void AddCars(Node** head, char* modeles, char* marques, char* annees) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->modele = modeles;
    newNode->marque = marques;
    newNode->annee = annees;
    newNode->next = *head;
    *head = newNode;
}

// fonction pour suppr une voiture en donnant son modele
// supprime une seule voiture à la fois,
// donc si il y'a 2 fois la meme voiture alors, supprime celle ajoutée en dernier.
//(c'est la même fonction que celle de l'exo 3 mais avec strcmp pour comparer ducoup )

void delete_a_car(Node** head, char* le_modele) {
    Node* Suppr = *head, *previousNode;
    if (Suppr != 0 && strcmp(Suppr->modele, le_modele) == 0) {
        *head = Suppr->next;
        free(Suppr);
        return;
    }
    while (Suppr != 0 && strcmp(Suppr->modele, le_modele) != 0) {
        previousNode = Suppr;
        Suppr = Suppr->next;
    }
    if (Suppr == 0) return;
    previousNode->next = Suppr->next;
    free(Suppr);
}


// fonction basique d'affichage pour la liste lol

void Display_Car_List(Node* noeud) {
    while (noeud != NULL) {
        printf("  modele : %s , " "marque : %s , " "annee : %s\n", noeud->modele , noeud->marque, noeud->annee);
        noeud = noeud->next;
    }
}

int main() {
    Node* head = 0;
    char choice;
    char modele_value[256];
    char marque_value[256];
    char annee_value[256];

    do {
        printf("\n Menu :\n");
        printf("1.Ajouter  une voiture \n");
        printf("2.Supprimer une voiture de la liste\n");
        printf("3.Afficher la liste des voitures\n");
        printf("4.Quitter systeme\n");
        printf("Choice: \n  ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("entrez un modele :\n");
                scanf(" %s", modele_value);
                printf("entrez une marque :\n");
                scanf(" %s", marque_value);
                printf("entrez une annee :\n");
                scanf(" %s", annee_value);
                AddCars(&head,strdup(modele_value),strdup(marque_value),strdup(annee_value));
                break;
            case '2':
                printf("valeur a supprimer :\n");
                scanf(" %s", modele_value);
                delete_a_car(&head, modele_value);
                break;
            case '3':
                printf("       Liste :\n");
                Display_Car_List(head);
                break;
            case '4':
                printf("Ciao");
                break;
        }

    } while(choice != '4');

    return 0;
}