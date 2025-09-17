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
    // a. Crear el nuevo nodo (usando tu función existente)
    t_node  *new_node = create_node(n);
    if (!new_node) // Si malloc falló, salimos
        return;

    // b. Caso: Lista vacía
    if (*head == NULL)
    {
        *head = new_node;  // La cabeza ahora apunta al nuevo nodo
        return ;
    }

    // c. Caso: Lista NO vacía
    t_node  *current = *head;  // Empezamos desde la cabeza

    // Avanzamos hasta el último nodo (aquel cuyo 'next' es NULL)
    while (current->next != NULL)
    {
        current = current->next;
    }

    // d. Enlazamos el nuevo nodo al final
    current->next = new_node;
}

/* 4. función para añadir nodo al principio,lo mismo, doble puntero 
para modificar head y le pasmos el entero del nodo que vamos a crear*/
void	add_to_start(t_node **head, int n)
{
	t_node *new_node = create_node(n);
	if (!new_node) // si falla salimos y devuelve el head que habia
		return ;
	new_node->next = *head; // lo que le siga al nodo apunt a head
	*head = new_node; // ahora head apunta al nuevo nodo
}

// 5. función para intercambiar los dos primeros nodos
// Usamos doble puntero a head porque solo habra modificacion en head
void	swap_first_two(t_node **head)
{
	// si el nodo esta vacio o si solo hay un nodo, salimos
	if (*head == NULL || (*head)->next == NULL)
		return ;
	t_node *first = *head; // el primer nodo apunta a la cabeza
	t_node *second = first->next; // el 2° nodo es el que sigue al 1°

	first->next = second->next; // cambiamos y ahora el 1° nodo apunta al lo que apuntaba el 2°
	second->next = first; // el segundo apuntaba a lo mismo que el primero con el cambio, ahora apunta al primero
	*head = second; // ahora head apunta al 2 nodo (que seria el primero)
}

// 6. función para imprimir la lista
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

// 7. función para liberar nodos
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

// 8. Función para mover el primer nodo de src a dst
void	push_to_list(t_node **dest, t_node **src)
{
	// si no hay nada en la lista, salimos
	if (*src == NULL)
		return ;
	t_node *node_to_move = *src; // nodo a mover
	*src = (*src)->next; // src apunta al siuient nodo
	
	node_to_move->next = *dest; // lo movemos al frente
	*dest = node_to_move;
}


// Función principal
int main(void)
{
    t_node  *head = NULL; // Lista vacía
	t_node *list_1 = NULL;// Nueva lista para push
    
	// Lista principal 
    add_to_end(&head, 42);
    add_to_end(&head, 21);
    add_to_end(&head, 10);
	add_to_start(&head, 1);

    // Imprimimos la lista 
    t_node  *current = head;
	printf("Head_Then: ");
	print_list(head);
	printf("\nSWAPING...\n");
	swap_first_two(&head);
	printf("Head_Now: ");
	print_list(head);
    
	// Push: movere el primer nodo de head a list_1
	push_to_list(&list_1, &head);
	printf("\nPUSHING THE FIRST NODE TO A NEW LIST...:\n");
	printf("Head_now: ");
	print_list(head);
	printf("New_list: ");
	print_list(list_1);

    // Liberar memoria de ambas listas
	free_list(head);
	free_list(list_1);
    head = NULL;
	list_1 = NULL;	
	// buena practica para evitar punteros colgantes o comportamiento indefinido

    return (0);
}
