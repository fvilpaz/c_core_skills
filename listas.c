#include <stdio.h>
#include <stdlib.h>

// 1. Define la estructura de un nodo
typedef struct  s_node
{
    int             number;
    struct s_node   *next;
}   t_node;

// 2. Función para crear un nodo
t_node  *create_node(int num)
{
    
    // - Reserva memoria para un nodo (malloc)
    t_node  *result = malloc(sizeof(t_node));
    if(!result)
        return(NULL);
    // - Asigna el número
    result->number =  num;
    // - Pone 'next' a NULL
    result->next = NULL;
    // - Devuelve el puntero al nodo
    return (result);
}

// 3. Función para añadir un nodo al final de la lista
// Recibe: head (doble puntero para poder modificar la cabeza si la lista está vacía)
//          number (el valor del nuevo nodo)
void    add_to_end(t_node **head, int number)
{
    // 1. Crear el nuevo nodo (usando tu función existente)
    t_node  *new_node = create_node(number);
    if (!new_node) // Si malloc falló, salimos
        return;

    // 2. Caso: Lista vacía
    if (*head == NULL)
    {
        *head = new_node;  // La cabeza ahora apunta al nuevo nodo
        return;
    }

    // 3. Caso: Lista NO vacía
    t_node  *current = *head;  // Empezamos desde la cabeza

    // Avanzamos hasta el último nodo (aquel cuyo 'next' es NULL)
    while (current->next != NULL)
    {
        current = current->next;
    }

    // 4. Enlazamos el nuevo nodo al final
    current->next = new_node;
}

// 4. Función principal
int main(void)
{
    t_node  *head = NULL; // Lista vacía
    // Añadimos los nodos
    add_to_end(&head, 42);
    add_to_end(&head, 21);
    add_to_end(&head, 10);

    // Imprimimos la lista
    t_node  *current = head;
    while (current != NULL)
    {
        printf("%d -> ",current->number);
        current = current->next;
    }
    printf("NULL\n");
    // Liberar memoria
    free(head->next->next); // tercer nodo n3
    free(head->next); // segundo nodo n2
    free(head); // primer nodo n1
    head = NULL; // buena practica para evitar punteros colgantes o comportamiento indefinido

    return (0);
}
