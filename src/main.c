#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  size_t size;
  char *data;
  size_t line_count;
} PkgFile;

PkgFile pkg_load(const char *filepath) {
  PkgFile loaded_file = {};

  FILE *fp = fopen(filepath, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Couldn't find package path.\n");
  }

  fseek(fp, 0, SEEK_END);
  loaded_file.size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  loaded_file.data = (char *)malloc(loaded_file.size + 1);

  if(!loaded_file.data) {
    fprintf(stderr, "Malloc failed.\n");
  }

  fread(loaded_file.data, 1, loaded_file.size, fp);
  loaded_file.data[loaded_file.size] = '\0';

  fclose(fp);
  return(loaded_file);
}

void pkg_free(PkgFile *doc) 
{
  if (doc) {
    free(doc->data);
  }
}

// SIDE EFFECT: Changes the PkgFile "line_count"
void get_pkg_lines(PkgFile *doc)
{
  unsigned int i = 0;
  for(i = 0; i < doc->size; i++) {
    if(doc->data[i] == '\n') {
      doc->line_count++;
    }
  }
}

int get_line(PkgFile doc) {
  unsigned int f = 0;
  unsigned int i = 0;
  unsigned int n = 0;
  char *buffer[256][512];
  get_pkg_lines(&doc);

  if (doc.line_count = 0) {
    return 1;
  }

  for (i = 0; i < doc.size; i++) {
    f++;
    printf("%c", doc.data[i]);
    if (doc.data[i] == '\n') {
      n++;
      for (int x = i - f; x < i; x++) {
      }
    }
  }
  return 0;
}

int main() {   
  PkgFile Package = pkg_load("../tests/test.txt");
  get_line(Package);
  pkg_free(&Package);    
}
