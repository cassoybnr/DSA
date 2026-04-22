#define MAX 10

typedef struct {
    int elem;
    int next;
} Call, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int index);
void insertFirst(VHeap *VH, List *L, int elem);
void deleteFirst(VHeap *VH, List *L);