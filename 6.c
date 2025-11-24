#include<stdio.h>
#include<limits.h>

void print_alloc(int n,int alloc[]){
 printf("process->block\n");
  for(int i=0;i<n;i++){
   if(alloc[i]==-1)printf("p%d->not allocated\n",i+1);
    else printf("p%d->block%d\n",i+1,alloc[i]+1);
    }
    }

    void first_fit(int holes[],int m,int procs[],int n){
    int alloc[50];for(int i=0;i<n;i++)alloc[i]=-1;
    int rem[m];for(int i=0;i<m;i++)rem[i]=holes[i];

     for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
      if(rem[j]>=procs[i]){
      alloc[i]=j;
      rem[j]-=procs[i];
      break;
      }
      }
      }
       printf("\nfirst fit:\n");
       print_alloc(n,alloc);
       }
        void best_fit(int holes[],int m,int procs[],int n){
         int alloc[50];for(int i=0;i<n;i++)alloc[i]==-1;
         int rem[m];for(int i=0;i<m;i++)rem[i]=holes[i];

          for(int i=0;i<n;i++){
           int best_idx=-1,best_diff=INT_MAX;


           for(int j=0;j<m;j++){
           if(rem[j]>=procs[i]&&rem[j]-procs[i]<best_diff){
           best_diff=rem[j]-procs[i];
           best_idx=j;
           }
           }
           if(best_idx!=-1){
           alloc[i]=best_idx;
           rem[best_idx]-=procs[i];
           }
           }
           printf("\nbest fit:\n");
           print_alloc(n,alloc);
           }

           void worst_fit(int holes[],int m,int procs[],int n){
            int alloc[50];for(int i=0;j<n;i++)alloc[i]=-1;
            int rem[m];for(int i=0;i<n;i++)rem[i]=holes[i];

            for(int i=0;i<n;i++){
            int worst_id=-1,worst_diff=-1;
            for(int j=0;j<m;j++){
            if(rem[j]>=procs[i]&&rem[j]-procs[i]>worst_diff){
              worst_diff=rem[j]-procs[i];
              worst_id=j;
              }
              }
              if(worst_idx!=-1){
              alloc[i]=worst_idx;
              rem[worst_idx]-=procs[i];
              }
              }
              printf("\nWorst fit:\n");
              print_alloc(n,alloc);
           }
              int main(){
               int holes[]={100,500,200,300,600};
               int m=sizeof(holes[0]);
               int procs[]={212,417,112,426};
               int n=sizeof(procs)/sizeof(procs[0]);

               first_fit(holes,m,procs,n);
               best_fit(holes,m,procs,n);
               worst_fit(holes,m,procs,n);

               return 0;
               }
