#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int g(int x) {
  return x+3;
}

int f(int x) {
  return g(x);
}

void main(void) {
  // unsigned int i = 0x00646c72; // chr(0x72) = r chr(0x6c) = l chr(0x64) = d
	// printf("H%x Wo%s", 57616, &i);  // hex(57616) = 0xE110
  printf("%d %d\n", f(8)+1, 13);
  // printf("x=%d y=%d", 3);
  exit(0);
}
