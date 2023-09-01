#include <stdio.h>
int main()
{
    int exam1,exam2,exam3,exam4,exam5,menor;
    printf("Examen 1: ");
    scanf("%d",&exam1);
    printf("Examen 2: ");
    scanf("%d",&exam2);
    printf("Examen 3: ");
    scanf("%d",&exam3);
    printf("Examen 4: ");
    scanf("%d",&exam4);
    printf("Examen 5: ");
    scanf("%d",&exam5);

    menor=exam1;
    
    if(exam2<menor)
    {
        menor=exam2;
    }
    if(exam3<menor)
    {
        menor=exam3;
    }
    if(exam4<menor)
    {
        menor=exam4;
    }
    if(exam5<menor)
    {
        menor=exam5;
    }

    if(menor==exam1)
    {
        printf("Promedio= %.2f",((exam2+.0)+(exam3+.0)+(exam4+.0)+(exam5+.0))/4);
    }
    else
    {
        if (menor==exam2)
        {
        printf("Promedio= %.2f",((exam1+.0)+(exam3+.0)+(exam4+.0)+(exam5+.0))/4);
        }
        else
        {
            if(menor==exam3)
            {
                printf("Promedio= %.2f",((exam2+.0)+(exam1+.0)+(exam4+.0)+(exam5+.0))/4);
            }
            else
            {
                if(menor==exam4)
                {
                    printf("Promedio= %.2f",((exam2+.0)+(exam3+.0)+(exam1+.0)+(exam5+.0))/4);
                }
                else
                {
                    printf("Promedio= %.2f",((exam1+.0)+(exam2+.0)+(exam3+.0)+(exam4+.0))/4);
                }
            }
        }
        
    }
    return 0;
}
/*
    if(exam1<exam2)
    {
        menor=exam1;
        if(exam3<menor)
        {
            exam3=menor;
            if(exam4<menor)
            {
                menor=exam4;
                if(exam5<menor)
                {
                    menor=exam5;
                }
            }
            else
            {
                if(exam5<menor)
                {
                    menor=exam5;
                }
            }

        }
        else
        {
            if(exam4<menor)
            {
                menor=exam4;
                if(exam5<menor)
                {
                    menor=exam5;
                }
            }
            else
            {
                if(exam5<menor)
                {
                    menor=exam5;
                }
            }
        }
    }
    else
    {
        menor=exam2;
        if(exam3<menor)
        {
            menor=exam3;
            if(exam4<menor)
            {
                menor=exam4;
                if(exam5<menor)
                {
                    menor=exam5
                }
            }
            else
            {
                if(exam5<menor)
                {
                    menor=exam5;
                }
            }
        }
    }
*/