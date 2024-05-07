#include <stdio.h>

typedef struct {
    char nom[50];
    int age;
    int taille;
} Personne;

int main() {
    Personne personnes[3];

    for (int i = 0; i < 3; i++) {
        Personne *ptr = &personnes[i];
        printf("Donne un nom, un age, puis une taille en cm pour l'individu %d: \n", i+1);
        scanf("%s %d %d", ptr->nom, &ptr->age, &ptr->taille);
    }

    for (int i = 0; i < 3; i++) {
        printf("Individu %d:\n Nom = %s, Age = %d, Taille = %d cm\n", i+1, personnes[i].nom, personnes[i].age, personnes[i].taille);
    }

    return 0;
}