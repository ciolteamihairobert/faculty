#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int cod;
char ocupatie[351];
}ocupatie;

int numarOcupatii=0;
ocupatie *a,*auxiliar;
void binary_search_function(ocupatie *a,int n,int x)
{    int s=0,d=n;int gasit=0;
      int m;
      while(s <= d) {
          m = (s+d) / 2;
        if(a[m].cod == x){
            gasit=1;
            break;
        }
        else{
            if(a[m].cod>x)
            {
             s=m+1;
            }
            else
            {
                d=m-1;
            }
        }
      }
     if(gasit) {
            printf("output: %s\n",a[m].ocupatie);
            printf("\n");
     }
     else{printf("nu exista\n");}

}
void cautare_liniara(ocupatie *a,int n,char *cuvant){
int i;
for(i=0;i<numarOcupatii;i++)
{
    if (strstr(a[i].ocupatie,cuvant))
    {
        printf("%s \n",a[i].ocupatie);
    }
}

}
void citire()
{FILE *fis=fopen("COR_Descrescator.txt","r");
    if(fis==NULL){
        printf("eroare deschidere");
        exit(EXIT_FAILURE);
    }
    char linie[1000];
    while(!feof(fis))
    {
        fgets(linie,1000,fis);
        linie[strcspn(linie,"\n")]='\0';
        if(strstr(linie,"Cod")==NULL)
        {
            auxiliar=(ocupatie*)realloc(a,sizeof(ocupatie)*(numarOcupatii+1));
            if(auxiliar==NULL)
            {   free(a);
                printf("eroare alocare memorie");
                exit(EXIT_FAILURE);
            }
            a=auxiliar;

            char *pointer_linie;
            pointer_linie=strtok(linie,"\t");
            int numar_cuvinte=0;
            while(pointer_linie)
            {
                if(numar_cuvinte==0)
                {
                    a[numarOcupatii-1].cod=atoi(pointer_linie);
                    numar_cuvinte++;
                }
                else
                {
                    strcpy(a[numarOcupatii-1].ocupatie,pointer_linie);
                    numar_cuvinte++;
                }
                pointer_linie=strtok(NULL,"\t");
            }
            numarOcupatii++;
        }
    }
fclose(fis);
}

int main()
{ citire();
  int i;
  int input;
  printf("input:");
  scanf("%d",&input);
  char cuvant[350];
  scanf("%s",&cuvant);
   binary_search_function(a,numarOcupatii,input);
   cautare_liniara(a,numarOcupatii,cuvant);
    return 0;
}
