#include <iostream>


inline uintptr_t AlignAddress(uintptr_t addr, size_t align) {
    const size_t mask = align - 1;
    if ((align & mask) != 0) {
        printf("Uh oh..");
    }
    return (addr + mask) & ~mask;
}

template<typename T>
inline T* AlignPointer(T* ptr, size_t align) {
    const uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    return reinterpret_cast<T*>(AlignAddress(addr, align));
}

void* alloc_aligned(size_t bytes, size_t align) {
    size_t worstCaseByte = bytes + align - 1;
    unsigned char *pRawMem = new unsigned char[worstCaseByte];
    return AlignPointer(pRawMem, align);
}
 
int main(void)
{
    void *p;
    for (int i = 0; i < 1000; ++i) {
        p = malloc(213);
        printf("%p\n", p);
    }
}
