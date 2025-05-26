#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char c;

  if (argc < 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("%s can't be opened\n", argv[i]);
    } else {
      while ((c = getc(fp)) != EOF) {
        putchar(c);
      }
    }
    fclose(fp);
  }
  exit(EXIT_SUCCESS);
}
