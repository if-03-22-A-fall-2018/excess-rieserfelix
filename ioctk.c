
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
  struct winsize ws;

  if (ioctl(0,TIOCGWINSZ,&ws)!=0)
  {
    fprintf(stderr,"TIOCGWINSZ:%s\n",strerror(errno));
    exit(-1);
  }
  printf("row=%d, col=%d, xpixel=%d, ypixel=%d\n",
  ws.ws_row,ws.ws_col,ws.ws_xpixel,ws.ws_ypixel);

  FILE* fd = fopen("file.txt", "r");
  char choice = 'a';
  char digit;
  int count = 0;
  digit = fgetc(fd);
  do
  {
  count = 0;
  for (size_t j = 0; j < ws.ws_row; j++)
  {
    for (size_t i = 0; i < ws.ws_col && digit != '\0' && digit != '\n'; i++)
    {
      printf("%c", digit);
      count++;
      digit = fgetc(fd);
    }
    count++;
    printf("%c", digit);
    digit = fgetc(fd);
}

  choice=getchar();

  if (choice == 'b')
  {
    fseek(fd, -count*2, SEEK_CUR);
  }

  }while(choice != 'c');

  }
