#include <stdio.h>
#include <stdlib.h>


int G[5][5] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main(){
    int n=5;

    int selected[n];

    for(int i=0; i<n; i++){
        selected[i]=0;
    }
    selected[0]=1;
int x=0;
    while(x<n-1){

        int min= 9999;
        int u=0, v=0;

        for(int i=0; i<n; i++){
            if(selected[i]){
                for(int j=0; j<n; j++){
                    if(selected[j]==0&&G[i][j]){
                        if(min>G[i][j]){
                            min= G[i][j];
                            u=i;
                            v=j;

                        }
                    }
                }
            }
        }

        printf("%d %d: %d\n", u,v,min);
        selected[v]=1;
        x++;
    }

return 0;
}
