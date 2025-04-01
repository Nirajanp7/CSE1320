
// Nirajan Pokharel 1002068164

#include <stdio.h>

int main(void)
{   
    int istart, iend, jstart, jend, kstart, kend;
    
    printf("Enter the starting value for i: ");
    scanf("%d", &istart);
    printf("Enter the value for iend: ");
    scanf("%d", &iend);
    
    printf("Enter the starting value for j: ");
    scanf("%d", &jstart);
    printf("Enter the value for jend: ");
    scanf("%d", &jend);
    
    printf("Enter the starting value for k: ");
    scanf("%d", &kstart);
    printf("Enter the value for kend: ");
    scanf("%d", &kend);
    
    
        for(int i=istart; i<iend; i++)
        {
            for(int j=jstart; j<jend; j++)
            {
                for(int k=kstart; k<kend; k++)
                {
                    printf("*");
                }
                
                printf("\n"); 
            } 
            
            printf("\n"); 
        
        }
    
    return 0;
}