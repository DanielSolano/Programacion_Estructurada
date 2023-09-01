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

    if(exam1<exam2)
    {
        menor=exam1;
    }
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
    printf("%d",menor);
    if(menor==exam1)
    {
        printf("Promedio= %d",(exam2+exam3+exam4+exam5)/4);
    }
    else
    {
        if (menor==exam2)
        {
        printf("Promedio= %f",(exam1+exam3+exam4+exam5)/4);
        }
        else
        {
            if(menor==exam3)
            {
                printf("Promedio= %f",(exam2+exam1+exam4+exam5)/4);
            }
            else
            {
                if(menor==exam4)
                {
                    printf("Promedio= %f",(exam2+exam3+exam1+exam5)/4);
                }
                else
                {
                    printf("Promedio= %f",(exam1+exam2+exam3+exam4)/4);
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