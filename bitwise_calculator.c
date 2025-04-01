//Nirajan Pokharel - 1002068164

#include <stdio.h>
#define BITS 8

void ConvertDecimalToBinary();


void ConvertDecimalToBinary(int num, char array[])
{
    int binary[BITS];
    
    
    for (int i = 0; i < BITS; i++)
    {
        binary[i]=num;
    
    
        if((binary[i]&1)==0)
        {
            binary[i] = 0;
        }
        else
        {
            binary[i] = 1;
        }
    
        num = num >> 1;
    
    }

    for (int i = BITS-1; i >= 0; i--)
    {
        array[i] = binary[BITS-1-i] + '0';
    }
}

int main()
{
    printf("Bitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result and the binary result.  The format is\n\n ");
    printf("FirstNumber BitwiseOperator SecondNumber \n\n");
    printf("For example, enter the expression\n\n2 & 3 \n\nThis calculator can used with &, |, ^, << and >> \n\n ");
    printf("Please note that the spaces between numbers and operator is essential and the two entered values must be between 0 and 255\n\n");
    int firstNum; 
    int secondNum;
    char inputOperator[3];
    char array[BITS];
    
    printf("Enter the expression: ");
    
    do 
    {
        scanf("%d%s%d", &firstNum, &inputOperator[0], &secondNum);
    } 
    while( firstNum< 0 || firstNum > 255 || secondNum < 0 || secondNum > 255  );
    
    if (inputOperator[0] == '&') 
    {
        printf("In base 10...\n%d %s %d = %d \n", firstNum, inputOperator, secondNum, firstNum&secondNum);
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(firstNum, array);
        printf("%11s", array);
        printf("\n");
        printf("%s\n",inputOperator);
        ConvertDecimalToBinary(secondNum, array);
        printf("%11s", array);
        printf("\n");
        printf("   ========\n");
        
        ConvertDecimalToBinary(firstNum & secondNum, array);
        printf("%11s", array);
        
    }
    else if (inputOperator[0] == '|') 
    {
        printf("In base 10...\n%d %s %d = %d \n", firstNum, inputOperator, secondNum, firstNum|secondNum);
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(firstNum, array);
        printf("%11s", array);
        printf("\n");
        printf("%s\n",inputOperator);
        ConvertDecimalToBinary(secondNum, array);
        printf("%11s", array);
        printf("\n");
        printf("   =============\n");
        ConvertDecimalToBinary(firstNum | secondNum, array);
        printf("%11s", array);
        
    } 
    else if (inputOperator[0] == '^') 
    {
        printf("In base 10...\n%d %s %d = %d \n", firstNum, inputOperator, secondNum, firstNum^secondNum);
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(firstNum, array);
        printf("%11s", array);
        printf("\n");
        printf("%s\n",inputOperator);
        ConvertDecimalToBinary(secondNum, array);
        printf("%11s", array);
        printf("\n");
        printf("   ========\n");
        ConvertDecimalToBinary(firstNum ^ secondNum, array);
        printf("%11s", array);
    } 
    else if (inputOperator[0] == '>') 
    {
        printf("In base 10...\n%d %s %d = %d \n", firstNum, inputOperator, secondNum, firstNum>>secondNum);
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(firstNum, array);
        printf("%s", array);
        printf(" %s %d",inputOperator, secondNum);
        ConvertDecimalToBinary(secondNum, array);
        printf("\n");
        ConvertDecimalToBinary(firstNum >> secondNum, array);
        printf("%s", array);
    } 
    else if (inputOperator[0] == '<') 
    {
        printf("In base 10...\n%d %s %d = %d \n", firstNum, inputOperator, secondNum, firstNum<<secondNum);
        printf("In 8-bit base 2...\n");
        ConvertDecimalToBinary(firstNum, array);
        printf("%s", array);
        printf(" %s %d",inputOperator, secondNum);
        
        printf("\n");
        ConvertDecimalToBinary(firstNum << secondNum, array);
        
        printf("%s", array);
    } 
    else 
    {
        printf("This %s is not supported by this calculator.", inputOperator);
    }    
    
       
}



