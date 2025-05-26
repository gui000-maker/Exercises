#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char c;

  if (argc < 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rw")) == NULL) {
    printf("Can't open %s\n", argv[1]);
  } else
    while ((c = getc(fp)) != EOF) {
      if (isalpha(c)) {
        putchar(toupper(c));
      } else
        putchar(c);
    }

  fclose(fp);

  exit(EXIT_SUCCESS);
}
