#include <unistd.h>
#define TL (47);
#define TR (92);
#define BL (92);
#define BR (47);
#define ROWS (42);
#define BLANK (32);

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void print_board(int row, int col, int board[][row])
{
  int i;
  int j;
  
  i = 0;
  while (i < col)
  {
    j = 0;
    while (j < row)
    {
      ft_putchar(board[i][j]);
      if (j == row - 1)
        ft_putchar('\n');
      j++;  
    }
    i++;
  }
}

void  modify_board(int row, int col, int board[][row])
{
  int i;
  int j;

  i = 0;
  while (i < col)
  {
    j = 0;
    while (j < row)
    {
      if (i == 0 && j == 0)
        board[i][j] = TL;
      if (i == 0 && j == row - 1 && j != 0)
        board[i][j] = TR;
      if (i == col - 1 && j == 0 && col > 1)
        board[i][j] = BL;
      if (i == col - 1 && j == row - 1 && row > 1 && col > 1)
        board[i][j] = BR;
      j++;
    }
    i++;
  }
  print_board(row, col, board); 
}

void  create_board(int row, int col)
{
  int board[col][row];
  int i;
  int j;
  
  i = 0;
  while (i < col)
  {
    j = 0;
    while (j < row)
    {
      if (i == 0 || i == col - 1)
      {
        board[i][j] = ROWS;
      }
      else if (j == 0 || j == row - 1)
      {
        board[i][j] = ROWS;
      }
      else
        board[i][j] = BLANK;
      j++;
    }
    i++;
  }
  modify_board(row, col, board);   
}

void    rush(int num1, int num2)
{
  create_board(num1, num2);
}

int main() {
  
  rush(123, 42);
  ft_putchar('\n');
  rush(5, 1);
  ft_putchar('\n');
  rush(1, 5);
  ft_putchar('\n');
  rush(1, 1);
  ft_putchar('\n');
  rush(5,3);
  return 0;
}