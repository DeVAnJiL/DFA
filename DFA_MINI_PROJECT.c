#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>


int no_inputs_symbols;
int fns1, fns2, fns3,fns4;
int check(char,int );   //function declaration
int dfa[10][10];
char alphabet_characters[10], string[10];
int len;


int main()
{

    int no_states_dfa, no_final_state;
    int f[10];
    int i,j,s=0,final=0;
    alphabet_characters[0]='a';
    alphabet_characters[1]='b';
    f[0]=1;

    FILE *fp;
    fp= fopen("data.txt","r");
    if (!fp)
    {
      printf("File doesn't have anything:\n");
      return 1;
    }

    fscanf(fp,"%d%d%d%d%d%d%d",&no_states_dfa ,&no_inputs_symbols,&no_final_state,&fns1,&fns2,&fns3,&fns4);
    fclose(fp);

     dfa[0][0]=fns1;
     dfa[0][1]=fns2;
     dfa[1][0]=fns3;
     dfa[1][1]=fns4;


     do{
     i=0;
     printf("\nEnter a string with 'a' and 'b':\n\nFor Example: ababab, bababa, aaabaa:\n\n |~: ");
     scanf("%s",string);


    while(string[i]!='\0')
        if((s=check(string[i++],s))<0)
        break;
        for(i=0; i<no_final_state ;i++)
        if(f[i] ==s )
        final=1;
           if(final==1)
        {
          printf("\nString is Accepted!\n");
          printf("(q0,%s) |--M)",string );

          len=strlen(string);
          for(i=0; i<len-1; i++)
          {
            string[i]=string[i+1];
          }
          string[len-1] = '\0';
          printf(" (q0,%s)\n",string);


          len=strlen(string);
          for(i=0; i<len-1; i++)
          {
            string[i]=string[i+1];
          }
          string[len-1] = '\0';
          printf("                  (q0,%s)\n",string);


          len=strlen(string);
          for(i=0; i<len-1; i++)
          {
            string[i]=string[i+1];
          }
          string[len-1] = '\0';
          printf("                  (q0,%s)\n",string);


          len=strlen(string);
          for(i=0; i<len-1; i++)
          {
            string[i]=string[i+1];
          }
          string[len-1] = '\0';
          printf("                  (q0,%s)\n",string);


          len=strlen(string);
          for(i=0; i<len-1; i++)
          {
            string[i]=string[i+1];
          }
          string[len-1] = '\0';
          printf("                  (q0,%s)\n",string);
          printf("                  (q0,e)");


        printf("\n\nSince (q0,%s) |--M (q0,e), and so %s is accepted by M.",string, string);
        }
        else
        {
        printf("\nString is Not Accepted!");
        }
       getch();
       printf("\nDo you want to Do again?:(y/n)");
     }
     while (getch()=='y');
     getch();
   }

int check(char b,int d)
{
    int j;
    for(j=0; j<no_inputs_symbols; j++)
    if(b==alphabet_characters[j])
    return(dfa[d][j]);
    return -1;
}
