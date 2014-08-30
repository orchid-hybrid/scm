#include "scm.h"

// 4MB = 1024*1024*4

int space_size;
unsigned char *ptr;
unsigned char *space1;
unsigned char *space2;

int rootsize;
int rootlength;
scm **root_pointers;

void gc_init(int set_size) {
  puts("GC INITIALIZTING");
  
  space_size = set_size;
  
  space1 = malloc(space_size);
  space2 = malloc(space_size);
  ptr = space1;
  
  rootsize = 1;
  rootlength = 0;
  root_pointers = malloc(sizeof(scm*)*rootsize);
}

void gc_pushpointer(scm* ptr) {
  // TODO: double when it needs to be bigger
  root_pointers[rootlength] = ptr;
  rootlength++;
}

void gc_poppointer() {
  rootlength--;
}

unsigned char* gc_alloc(int size) {
  unsigned char* p = ptr;
  ptr += size;
  
  if(ptr >= space1+space_size) {
    puts("GC: RUN OUT OF GC MEMORY");
    exit(0);
  }
  else {
    fprintf(stderr,"DID NOT RUN OUT OF MEMORY (%d%%)\n", (int)(100*(ptr-space1)/(double)space_size));
  }
  
  return p;
}
