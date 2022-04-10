/* ========Disclaimer======== 
 This is not GNU yes but rather 
  a poorly constructed clone */


/* yes - output a string repeatedly until killed

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Keegan Powers <john.doe@example.com> */

#include <stdio.h>
#include <string.h>

#ifndef VERSION
  #define VERSION "1.1"
#endif

int catc(char argp[], char optp[]) { // can argp be completed to optp
  int optLen = strlen(optp);

  for (int i = 0; argp[i] != NULL; i++) {
    if (argp[i] != optp[i] || i > optLen) return 0;
  } 

  return 1;
}

void printHelp() { // hlep
  printf("\
Usage: yes(.exe) [STRING]...\n\
  or:  yes(.exe) OPTION\n\
Repeatedly output a line with all specified STRING(s), or 'y'.\n\n\
      --help     display this help and exit\n\
      --version  output version information and exit\n");
}

void printVersion() { // vresion
  printf("\
yes (GUN coreutils) %s\n\
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n\
\n\
Written by Keegan Powers.\n", VERSION);
}

void printUA(int argi, char *argv[]) { // unkown arggg
  printf("\
yes(.exe): unrecognized option '%s'\n\
Try 'yes(.exe) --help' for more information.\n", argv[argi]);
}

int main(int argc, char **argv) { // mane
  if (argc == 1) {
    for (;;) printf("y\n");
  }
  
  for (int i = 0; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (catc(argv[i], "--help")) {printHelp(); return 0;} else
        if (catc(argv[i], "--version")) {printVersion(); return 0;}
      }
      printUA(i, argv); return 1;
    }
  }

  for (;;) {
    for (int i = 1; i < argc - 1; i++) {
      printf("%s ", argv[i]);
    }
    
    printf("%s\n", argv[argc - 1]);
  }

  return 0;
}
