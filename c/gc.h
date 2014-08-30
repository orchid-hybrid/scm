void gc_init(int set_size);
void gc_pushpointer(scm* ptr);
void gc_poppointer();
unsigned char* gc_alloc(int size);
