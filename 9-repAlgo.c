/*
9. Design, develop and implement a C/C++/Java program to implement page
replacement algorithms LRU and FIFO. Assume suitable input required to demonstrate
the results.
Output:
Enter the no of empty frames: 3
Enter the length of the string: 5
Enter the string: hello
*********** MENU ***********
1:FIFO
2:LRU
4:EXIT
Enter your choice: 1
PAGE FRAMES FAULTS
H h Page-fault 0
E h e Page-fault 1
L h e l Page-fault 2
L h e l No page-fault
O o e l Page-fault 3
Do u want to continue IF YES PRESS 1
IF NO PRESS 0 : 1
*********** MENU ***********
1:FIFO
2:LRU
4:EXIT
Enter your choice: 2
PAGE FRAMES FAULTS
H h Page-fault 0
E h e Page-fault 1
L h e l Page-fault 2
L h e l No page fault
O e l o Page-fault 3
Do u want to continue IF YES PRESS 1
IF NO PRESS 0 : 1
*********** MENU ***********
1:FIFO
2:LRU
4:EXIT
Enter your choice: 4
*/

#include<stdio.h> 
#include<stdlib.h> 
void FIFO(char [ ],char [ ],int,int); 
void lru(char [ ],char [ ],int,int); 
void opt(char [ ],char [ ],int,int); 
int main() 
{ 
    int ch,YN=1,i,l,f; 
    char F[10],s[25]; 
    printf("\n\n\tEnter the no of empty frames: "); 
    scanf("%d",&f); 
    printf("\n\n\tEnter the length of the string: "); 
    scanf("%d",&l); 
    printf("\n\n\tEnter the string: "); 
    scanf("%s",s); 
    for(i=0;i<f;i++) 
        F[i]=-1; 
    do 
    { 
        printf("\n\n\t*********** MENU ***********"); 
        printf("\n\n\t1:FIFO\n\n\t2:LRU \n\n\t4:EXIT"); 
        printf("\n\n\tEnter your choice: "); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
        case 1: 
            for(i=0;i<f;i++) 
            { 
                F[i]=-1; 
            } 
            FIFO(s,F,l,f); 
            break; 
        case 2: 
            for(i=0;i<f;i++) 
            { 
            F[i]=-1; 
            } 
            lru(s,F,l,f); 
            break; 
        case 4: 
            exit(0); 
        } 
        printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 : "); 
        scanf("%d",&YN); 
    }while(YN==1);return(0); 
} 
//FIFO 
void FIFO(char s[],char F[],int l,int f) 
{ 
    int i,j=0,k,flag=0,cnt=0; 
    printf("\n\tPAGE\t FRAMES\t FAULTS"); 
    for(i=0;i<l;i++) 
    { 
        for(k=0;k<f;k++) 
        { 
            if(F[k]==s[i]) 
            flag=1; 
        } 
        if(flag==0) 
        { 
            printf("\n\t%c\t",s[i]); 
            F[j]=s[i];
            j++; 
            for(k=0;k<f;k++) 
            { 
            printf(" %c",F[k]); 
            } 
            printf("\tPage-fault%d",cnt); 
            cnt++; 
        } 
        else 
        { 
            flag=0; 
            printf("\n\t%c\t",s[i]); 
            for(k=0;k<f;k++) 
            { 
            printf(" %c",F[k]); 
            } 
            printf("\tNo page-fault"); 
        } 
        if(j==f) 
            j=0; 
    } 
} 


//LRU 
void lru(char s[],char F[],int l,int f) 
{ 
    int i,j=0,k,m,flag=0,cnt=0,top=0; 
    printf("\n\tPAGE\t FRAMES\t FAULTS"); 
    for(i=0;i<l;i++) 
    { 
        for(k=0;k<f;k++) 
        { 
            if(F[k]==s[i]) 
            { 
                flag=1; 
                break; 
            } 
        } 
        printf("\n\t%c\t",s[i]); 
        if(j!=f && flag!=1) 
        { 
            F[top]=s[i]; 
            j++; 
            if(j!=f) 
                top++;
        } 
        else 
        { 
            if(flag!=1) 
            { 
                for(k=0;k<top;k++) 
                { 
                    F[k]=F[k+1]; 
                } 
                F[top]=s[i]; 
            } 
            if(flag==1) 
            { 
                for(m=k;m<top;m++) 
                { 
                    F[m]=F[m+1]; 
                } 
                F[top]=s[i]; 
            } 
        } 
        for(k=0;k<f;k++) 
        { 
            printf(" %c",F[k]); 
        } 
        if(flag==0) 
        { 
            printf("\tPage-fault%d",cnt); 
            cnt++; 
        } 
        else 
            printf("\tNo page fault"); 
        flag=0; 
    
    } 
}
