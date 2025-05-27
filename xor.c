#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]) {
  FILE *fpin, *fpout;
  char orig_char, new_char;

  if (argc != 3) {
    fprintf(stderr, "USAGE: xor input_filename output_filename\n");
    exit(EXIT_FAILURE);
  }

  if ((fpin = fopen(argv[1], "rb")) == NULL) {
    printf("Can't be created: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  } else if ((fpout = fopen(argv[2], "wb")) == NULL) {
    printf("Can't be created: %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  while ((orig_char = getc(fpin)) != EOF) {
    new_char = orig_char ^ KEY;
    putc(new_char, fpout);
  }

  fclose(fpin);
  fclose(fpout);

  exit(EXIT_SUCCESS);
}
