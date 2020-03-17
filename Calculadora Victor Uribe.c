#include <stdio.h>
#include <stdlib.h>

float suma(float x, float y)
{
    return x + y;
}
float resta(float x, float y)
{
    return x - y;
}
float multi(float x, float y)
{
    return x * y;
}
float division(float x, float y)
{
    return x / y;
}

int main(int argc, char**argv)
{
    float x= atof(argv[1]);
    char *operador = argv[2];
    float y= atof(argv[3]);
    switch(*operador){
        case 'x': printf("Your multiplication is: %.2f\n", multi(x,y));
        break;
        case '+': printf("Your addition is: %.2f\n", suma(x,y));
        break;
        case '/': printf("Your division is: %.2f\n", division(x,y));
        break;
        case '-': printf("Your substraction is: %.2f\n", resta(x,y));
        break;
        default: printf("Check your symbol\n");
        break;
    }
}