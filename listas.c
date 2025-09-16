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
    // - Pon 'next' a NULL
    result->next = NULL;
    // - Devuelve el puntero al nodo
    return (result);
}

// 3. Función para añadir un nodo al final de la lista
// Recibe: head (doble puntero para poder modificar la cabeza si la lista está vacía)
//          number (el valor del nuevo nodo)
void    add_to_end(t_node **head, int n)
{
    // 1. Crear el nuevo nodo (usando tu función existente)
    t_node  *new_node = create_node(n);
    if (!new_node) // Si malloc falló, salimos
        return;

    // 2. Caso: Lista vacía
    if (*head == NULL)
    {
        *head = new_node;  // La cabeza ahora apunta al nuevo nodo
        return ;
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

/* función para añadir nodo al principio, igual que antes, doble puntero 
para modificar head y le pasmos el entero del nodo que vamos a crear*/
void	add_to_start(t_node **head, int n)
{
	t_node *new_node = create_node(n);
	if (!new_node) // si falla new_node salimos y devuelve el head que habia
		return ;
	new_node->next = *head; // lo que le siga al nodo apunt a head
	*head = new_node; // ahora head apunta al nuevo nodo
}

// función para intercambiar los dos primeros nodos
// Esta vez sol usamos doble puntero a head porque solo habra modificacion en head
void	swap_first_two(t_node **head)
{
	// si el nodo esta vacio o si solo hay un nodo, salimos
	if (*head == NULL || (*head)->next == NULL)
		return ;
	t_node *first = *head; // el primer nodo apunta a la cabeza
	t_node *second = first->next; // el segundo nodo es el que le sigue al primero

	first->next = second->next; // cambiamos y ahora el primer nodo apunta al lo que apuntaba el 2
	second->next = first; // el segundo apuntaba a lo mismo que el primero con el cambio, ahora apunta al primero
	*head = second; // ahora head apunta al 2 nodo (que seria el primero)
}

// función para imprimir la lista
void	print_list(t_node *head)
{
	t_node *current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->number);
		current = current->next;
	}
	printf("NULL\n");
}

// función para liberar nodos
void	free_list(t_node *head)
{
	t_node *current = head;
	t_node *tmp;
	while (current != NULL)
	{
		tmp = current; // guardamos current en tmp
		current = current->next;	// avanzamos la posicion
		free(tmp); // liberamos la memoria
	}
}
// 4. Función principal
int main(void)
{
    t_node  *head = NULL; // Lista vacía
    // Añadimos los nodos
    add_to_end(&head, 42);
    add_to_end(&head, 21);
    add_to_end(&head, 10);
	add_to_start(&head, 1);

    // Imprimimos la lista
    t_node  *current = head;
	printf("Lista antes de swap: ");
	print_list(head);

	swap_first_two(&head);
	printf("Lista después del swap: ");
	print_list(head);
    
    // Liberar memoria
	free_list(head);
    head = NULL; // buena practica para evitar punteros colgantes o comportamiento indefinido

    return (0);
}
