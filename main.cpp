#include <iostream>
#include <cstring>

const int screen_width = 120;
const int screen_height = 40;

void print_screen(char screen[screen_height][screen_width])
{
  for (int i=0;i<screen_height;i++)
  {
    for (int j=0;j<screen_width;j++)
    {
      printf("%c", screen[i][j]);
    }
    printf("\n");
  }
}

void show_main_menu()
{
  char screen[screen_height][screen_width];
  // for (int i=0;i<screen_width;i++) for (int j=0;j<screen_height;j++) screen[j][i] = '-';
  strcpy(screen[0], "This is a test");
  print_screen(screen);
}

int main()
{
  // Print Starting Screen.
  show_main_menu();
  // Ask player if they want to start new game, load an old save or view previous game's results.

  // Go through rounds in a loop until game goal is reached.

  // End credits, view game results and/or loop back to the starting Screen.

  return 0;
}
