#include <stdio.h>
#include <stdlib.h>

struct lista{
    int val;
    struct lista *urm;
};

typedef struct lista LIST;

void elimina_succesor(LIST *n){
    LIST *t;
    t = n->urm;
    n->urm = t->urm;
    free(t);
    return;
}

int main(){
    int i,nr;
    printf("Tastati numarul de valori: ");
    scanf("%d", &nr);
    LIST *cap_lista, *p, *q;
    p = (LIST*) malloc(sizeof(LIST));
    if(p == NULL){
        printf("Alocare dinamica esuata! ");
        exit(1);
    }
    printf("Introduceti valoarea 1: ");
    scanf("%d", &p->val);
    cap_lista = p;
    for(i = 2; i <= nr; i++){
        q = (LIST*) malloc(sizeof(LIST));
        if(q == NULL){
            printf("Alocare dinamica esuata! ");
            exit(1);
        }
        printf("Introduceti valoarea %d: ", i);
        scanf("%d", &q->val);
        p->urm = q;
        p=q;
    }
    p->urm = NULL;
    LIST *aux1;
    if(nr > 1)
    for (aux1 = cap_lista, i = 1; aux1 != NULL && i < nr-1; aux1 = aux1->urm, i++)
        continue;
    

    for(p = cap_lista; p != NULL; p = p->urm){
        if(p == aux1 && p->urm->val % 2 == 0){
            p->urm = NULL;
        }
        else if(p == cap_lista && p->val % 2 == 0){
            p == NULL;
        }
        else if(p->urm->val % 2 == 0)
            elimina_succesor(p);
    }

    printf("Valorile impare sunt: ");
    for(p = cap_lista; p != NULL; p = p->urm){
        printf("%d ", p->val);
    }

    for(p = cap_lista; p != NULL; p = q) {
        q = p->urm;
        free(p);
    }
    return 0;
}
