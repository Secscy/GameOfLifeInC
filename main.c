
- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


#include stdio.h
#include stdlib.h
#include time.h
#include unistd.h

enum { VIVO = 'O', MORTO = '.' };

int main() {
  
  int i, j;
  int lin, col;
  
  printf(Numero de linhas e colunas  );
  scanf(%d %d, &lin, &col );
  
  char m = malloc( lin  sizeof( char  ) );
  char m2 = malloc( lin  sizeof( char  ) );
  
  i = 0;
  while ( i  lin ) {
    m[i] = malloc( col  sizeof( char ) );
    m2[i] = malloc( col  sizeof( char ) );
    i++;
  }
  
   ====================================
  
  srand( time(NULL) );
  
  for(i=0; i  lin; i++)
    for(j=0; j  col; j++)
      if ( rand() % 20  15 ) m[i][j] = MORTO;
                        else m[i][j] = VIVO;
  
  printf(033[2J);
  while (1) {
   
    printf(033[H);
    
    for(i=0; i  lin; i++) {
      for(j=0; j  col; j++)
        printf(%c, m[i][j]);
      printf(n);
    }
    

        0      1     2...
      -------------------
                      
  0    aaa  bbb   ccc 
                      
      -------------------
            ===       
  1    ddd  l,c   eee 
            ===       
      -------------------
                      
  2    fff  ggg   hhh 
                      
      -------------------    Cria novo tabuleiro em cima de m2

    
     para cada linha de m2 
       para cada coluna de m2 
         conta vizinhos vivos em m
    int l, c;
    for(l = 0; l  lin; l++)
      for(c = 0; c  col; c++) {
        int vivos = 0;
        if ( l  0 && c  0       && m[l-1][c-1] == VIVO ) vivos++;  aaa
        if ( l  0                && m[l-1][c] == VIVO ) vivos++;    bbb
        if ( l  0 && c + 1  col && m[l-1][c+1] == VIVO ) vivos++;  ccc
        
        if ( c  0      && m[l][c-1] == VIVO ) vivos++;  ddd
        if ( c+1  col  && m[l][c+1] == VIVO ) vivos++;  eee
        
        if ( l+1  lin && c  0       && m[l+1][c-1] == VIVO ) vivos++;  fff
        if ( l+1  lin                && m[l+1][c] == VIVO ) vivos++;    ggg
        if ( l+1  lin && c + 1  col && m[l+1][c+1] == VIVO ) vivos++;  hhh
        
        m2[l][c] = m[l][c];
        if ( vivos  2 ) m2[l][c] = MORTO;
        if ( vivos = 4 ) m2[l][c] = MORTO;
        if ( vivos == 3 ) m2[l][c] = VIVO;
      }
          
     Troca m2 com m
    
    char  m3;
    m3 = m;
    m = m2;
    m2 = m3;
   
    usleep( 200000 );
  }
  
   ====================================
   
  i = 0;
  while ( i  lin ) {
    free(m[i]);
    i++;
  }
  free(m);
}