#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buff = NULL;
  size_t size = 0;
  ssize_t n;

  printf("Enter a line of text:\n");

  n = getline(&buff, &size, stdin);
  if (n == -1) {
    perror("Getline Failed");
    exit(EXIT_FAILURE);
  }

  printf("You typed: %s", buff);

  char *saveptr;
  char *token = strtok_r(buff, " ", &saveptr);

  printf("Tokens:\n");

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(buff);
  return 0;
}
