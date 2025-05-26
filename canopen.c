#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  bool canopen = false;

  if (argc < 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("%s can't be opened\n", argv[1]);
      canopen = true;
    } else {
      printf("%s can be opened\n", argv[i]);
      fclose(fp);
    }
  }

  if (canopen == true) {
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
