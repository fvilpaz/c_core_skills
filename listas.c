#include <stdio.h>
#include <stdlib.h>

// 1. Define la estructura de un nodo
typedef struct s_node
{
    int             number;
    struct s_node   *next;
}   t_node;

// 2. Función para crear un nodo
t_node  *create_node(int num)
{
    
    // - Reserva memoria para un nodo (malloc)
    t_node *result = malloc(sizeof(t_node));
    if(!result)
        return(NULL);
    // - Asigna el número
    result->number =  num;
    // - Pone 'next' a NULL
    result->next = NULL;
    // - Devuelve el puntero al nodo
    return (result);
}

// 3. Función principal
int main(void)
{

    // 4. Crea tres nodos con los números 42, 21 y 10
    t_node *n1 = create_node(42); 
    t_node *n2 = create_node(21); 
    t_node *n3 = create_node(10);

    // 5. Enlázalos manualmente: 42 -> 21 -> 10 -> NULL
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    // 6. Recorre la lista e imprime cada número
    t_node *current = n1;
    while (current != NULL)
    {
        printf("%d -> ", current->number);
        if (current->next != NULL)
            printf("->");
        else
            printf("-> NULL");
        current = current->next;
    }
    printf("\n");

    // 7. ¡EXTRA! Libera la memoria al final
    free(n1);
    free(n2);
    free(n3);

    return (0);
}
