//mini projet :gestion des notes des etudiants.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void remplir(float*t,int n){
int i ;
for(i=0;i<n;i++){
  printf("saisir la note de etudiant t[%d]:" ,i);
  scanf("%f",t+i);
}}
float moyenne (float*t , int n){
    int s=0;
    int i;
    float m;
  for(i=0;i<n;i++) {
        s=s+*(t+i);
    }

    m=(float)s/n;

return m;}



float maximum(float *t ,int n){
float max;
int i;
max=*t;
for(i=0;i<n;i++){
    if(max<*(t+i))
        max=*(t+i);}
return max;}



float minimum(float *t ,int n){
float min;
int i;
min=*t;
for(i=0;i<n;i++){
    if(min>*(t+i))
        min=*(t+i);}
return min;}





int main(){
int s ,n,i,a;
float max,min ,m;
char rep;
printf("saisir la taille de tableau : ");
scanf("%d",&n);
float*t=calloc(n,sizeof(float));
if(t==NULL){
    printf("Erreur d'allocation !");
    return 1;
}
remplir(t,n);
m=moyenne(t,n);
printf("La moyenne est : %.2f\n",m);
max=maximum(t,n);
min=minimum(t,n);
printf("le  maximum est : %.2f" ,max);
printf("le minimum est : %.2f" ,min);


do {
    printf("Tu peux ajouter d'autres elements (O/N) : ");
    scanf(" %c",&rep);

} while(rep!='O' && rep!='N');

if(rep=='N')
    exit(0);
else if(rep=='O'){
    printf("saisir le nouveau taille de tableau : ");
    scanf("%d",&a);
    n=n+a;
    float *temp=realloc(t,n*sizeof(float));
    if(temp==NULL){
    printf("Erreur !");
    free(t);
    return 1;
}
 for(i=n-a;i<n;i++){
    printf("saisir lelement t[%d]:" ,i);
  scanf("%d",t+i);}
  m=moyenne(t,n);
printf("La nouvelle moyenne est : %.2f\n",m);
max=maximum(t,n);
min=minimum(t,n);
printf("le nouveau maximum est : %.2f" ,max);
printf("le nouveau minimum est : %.2f" ,min);}
free(t);
return 0;}
