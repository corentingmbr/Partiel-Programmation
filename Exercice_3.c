#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Nodevalue;
    struct Node* next;
} Node;

// fonction qui ajoute un entier dans la liste
void addInteger(Node** head, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->Nodevalue = val;

    newNode->next = *head;
    *head = newNode;
}

// fonction pour suppr un noeud en donnant sa value (val)
// supprime une seule valeure à la fois,
// donc si il y'a 2 fois la meme valeure alors, supprime celle ajoutée en dernier.

void deleteNode(Node** head, int val) {
    Node* Suppr = *head, *previousNode;
    if (Suppr != 0 && Suppr->Nodevalue == val) {
        *head = Suppr->next;
        free(Suppr);
        return;
    }
    while (Suppr != 0 && Suppr->Nodevalue != val) {
        previousNode = Suppr;
        Suppr = Suppr->next;
    }
    if (Suppr == 0) return;
    previousNode->next = Suppr->next;
    free(Suppr);
}





























//fonction basique d'affichage pour la liste lol

void displayList(Node* noeud) {
    while (noeud != NULL) {
        printf(" %d ", noeud->Nodevalue);
        noeud = noeud->next;
    }
}

int main() {
    Node* head = 0;
    char choice;
    int value;

    //Petit menu comme d'habitude

    do {
        printf("\n Menu :\n");
        printf("1.Ajouter  un entier \n");
        printf("2.Supprimer un entier de la liste\n");
        printf("3.Afficher la liste\n");
        printf("4.Quitter\n");
        printf("Choice: \n  ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("valeur :\n");
                scanf(" %d", &value);
                addInteger(&head,value );
                break;
            case '2':
                printf("valeur a supprimer :\n");
                scanf(" %d", &value);
                deleteNode(&head, value);
                break;
            case '3':
                printf("Liste :\n");
                displayList(head);
                break;
            case '4':
                printf("Ciao");
                break;
        }

    } while(choice != '4');

    return 0;

}