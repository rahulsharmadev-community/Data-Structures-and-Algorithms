
#include <stdio.h>

void spiralMatrix(int i, int j, int array[i][j]);

int main()
{
    int i=4,j=3;
    int input[4][3] = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}, {7, 6, 5}};
    
    spiralMatrix(i,j,input);
    return 0;
}

void spiralMatrix(int i, int j, int array[i][j]){
    int T=0, D=i-1, L=0, R=j-1;
    
    while(T<=D && L<=R){
      for (int y = L; y <= R; y++) {
         printf("%d, ", array[T][y]);
      }
      T++;
      
      for (int x = T; x <= D; x++) {
         printf("%d, ", array[x][R]);
      }
      R--;
      
      for (int y = R; y >= L; y--) {
         printf("%d, ", array[D][y]);
      }
      D--;
      
      for (int x = D; x >= T; x--) {
         printf("%d, ", array[x][L]);
      }
      L++;
    }
    
}