#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
   struct nod *nextNode;
   int num;
}nod;

typedef struct{
    nod *firstNode;
}list;

list * alocList(){
    list *lista = (list*)malloc(sizeof(list));
    lista->firstNode = NULL;
    return lista;
};
void addInt(list *l, int num){
    nod *Node;
    Node = (nod*)malloc(sizeof(nod));
    Node->num = num;
    Node->nextNode = NULL;
    nod *p = l->firstNode;
    if(p != NULL){
        while(p->nextNode != NULL)
        {
            p = p->nextNode;
        }
        p->nextNode = Node;
    }
    else l->firstNode = Node;
}
void afisareLista(list *l){
    nod *p;
    p = l->firstNode;
    while(p != NULL)
    {
        printf("%d ", p->num);
        p = p->nextNode;
    }
}
int main(){
    list *List;
    List = alocList();
    addInt(List, 1);
    addInt(List, 2);
    addInt(List, 3);
    addInt(List, 4);
    afisareLista(List);
    return 0;
}
