#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
   struct nod *nextNode;
   int num;
}nod;

typedef struct{
    nod *firstNode;
    nod *lastNode;
}list;

list * alocList(){
    list *lista = (list*)malloc(sizeof(list));
    lista->firstNode = NULL;
    lista->lastNode = NULL;
    return lista;
};
void addInt(list *l, int num){
    nod *Node;
    Node = (nod*)malloc(sizeof(nod));
    Node->num = num;
    Node->nextNode = NULL;
    l->lastNode = Node;
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
void addFirst(list *l, int num){
    nod *Node;
    Node = (nod*)malloc(sizeof(nod));
    Node->nextNode = NULL;
    Node->num = num;
    if(l->firstNode == NULL){
        l->lastNode = Node;
        l->firstNode = Node;
    }
    else{
            Node->nextNode = l->firstNode;
            l->firstNode = Node;
    }
}
void addLast(list *l, int num){
    nod *Node;
    Node = (nod*)malloc(sizeof(nod));
    Node->nextNode = NULL;
    Node->num = num;
    if(l->firstNode == NULL)
    {
        l->firstNode = Node;
        l->lastNode = Node;
    }
    else
    {
        l->lastNode->nextNode = Node;
        l->lastNode = Node;
    }
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
    /*addInt(List, 1);
    addInt(List, 2);
    addInt(List, 3);
    addInt(List, 4);*/
    addFirst(List,1);
    addFirst(List,2);
    addFirst(List,3);
    addFirst(List,4);;
    addInt(List,5);
    addLast(List,6);
    afisareLista(List);
    return 0;
}
