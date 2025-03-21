#include "push_swap.h"

// Función para verificar si un carácter es un espacio en blanco
int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

// Función para procesar un argumento que puede contener múltiples números
int process_single_argument(char *arg, t_stack *stack)
{
    int i;
    int start;

    i = 0;
    while (arg[i])
    {
        // Saltar espacios en blanco
        while (arg[i] && is_space(arg[i]))
            i++;
        
        // Si llegamos al final del string, salir
        if (!arg[i])
            break;
        
        // Marcar el inicio del número
        start = i;
        
        // Avanzar hasta el final del número
        while (arg[i] && !is_space(arg[i]))
            i++;
        
        // Temporalmente poner un null para formar un substring
        char temp = '\0';
        if (arg[i])
        {
            temp = arg[i];
            arg[i] = '\0';
        }
        
        // Añadir el número al stack
        if (!add_number(stack, &arg[start]))
        {
            // Restaurar el carácter original si fue modificado
            if (arg[i] == '\0')
                arg[i] = temp;
            return (0);
        }
        
        // Restaurar el carácter original si fue modificado
        if (arg[i] == '\0')
            arg[i] = temp;
    }
    return (1);
}