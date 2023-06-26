#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 250


typedef struct {
    char *name;   // variable name
     char *type;   // variable type
    int var_size; // variable size
} RECORD;

RECORD symtab[TABLE_SIZE];

void init_hash_table(){
    int i;
    for( i =0;i<TABLE_SIZE;i++)
    {
        symtab->name=NULL;
        symtab->type=NULL;
        
    }
}
int hash(char name[]){
    int length = strlen(name);
    int hash_value = 0;
    int i;
    for( i=0;i<length;i++)
    {
        hash_value+=name[i];
        hash_value=(hash_value*name[i])% TABLE_SIZE;
    }
    return hash_value;
}

void hash_insert (char name[],char type[])
{       
             
        int j = hash(name);
        if (symtab[j].name==NULL);
            symtab[j].name=name;
            symtab[j].type=type; 
          
}

int hash_search(char str[] ){
        int index;
        index = hash(str);
        
        if(symtab[index].name==str)
            return 0;
        else
            return -1;
}

void free_hash_table()
{   
    int i;
    for( i =0;i<TABLE_SIZE;i++)
    {
    free(symtab[i].name);
    free(symtab[i].type);
    }
}

// void printh()
//  {
//      for(int i = 0 ;i<TABLE_SIZE;i++)
//  {
   
//     {
//      printf("\t%s\t%s\n",symtab[i].name,symtab[i].type);

//      }
//  }
//  }




int main(int argc, char **argv)
{
    
    init_hash_table();
   
   hash_insert("num1", "INTEGER");
    hash_insert("num2", "INTEGER");
    hash_insert("num3", "INTEGER");
    hash_insert("num4", "REAL");
    //  printh();
    printf("Insert Done ...\n");
    char *str1 = "num1";
    char *str2 = "num3";
    char *str3 = "Num1";

    if (hash_search(str1) != -1)
        printf("Element %s found\n",str1);
    else
        printf("Element %s not found\n",str1);

   if (hash_search(str2) != -1)
        printf("Element %s found\n",str2);
    else
        printf("Element %s not found\n",str2);

    if (hash_search(str3) != -1)
        printf("Element %s found\n",str3);
    else
        printf("Element %s not found\n",str3);

    free_hash_table();
   

    return 0;
}
