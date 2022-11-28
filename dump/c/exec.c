/*
 * inspired by
 * https://percona.community/blog/2021/01/04/fork-exec-wait-and-exit/
 * and the iscsc#dev discord channel
 * https://discord.com/channels/844490231771955212/844491110561611786/1046815865800241313
 *
 * compile as follows:
 * ```bash
 * > clang exec.c -o exec
 * ```
 * or
 * ```bash
 * > gcc exec.c -o exec
 * ```
 * and run as
 * ```bash
 * > ./exec
 * foo: 0
 * foo: 1
 * foo: 2
 * foo: 3
 * ```
 */
#include <unistd.h>  // fork, execl
#include <stdio.h>  // sprintf
#include <sys/wait.h>  // wait
#include <stdlib.h>  // exit


void echo(int i){
  pid_t pid = 0;
  int status;
  char buffer[32];

  switch (pid = fork()) {
    case 0:
      sprintf(buffer, "echo: i: %d", i);
      execl("/usr/bin/echo", "echo", buffer, NULL);
    default:
      pid = wait(&status);
      break;
  }
}


int main(int argc, char** argv) {
  int n = 10;

  for (int i = 0; i < n; i++) {
    echo(i);
  }

  exit(0);
  return 0;
}

