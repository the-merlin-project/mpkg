#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/net.h" 

int exec_pkg_build(const char *filepath) {
  fork();
  execl(filepath, filepath, (char*) NULL);
  return 0;
}

int main() {   
  exec_pkg_build("../../pkgs/vim/build.sh");
}
