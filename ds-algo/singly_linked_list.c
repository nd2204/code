#include <stdio.h>
#include "utils/defines.h"
#include "utils/dn_memory.h"

typedef enum hanh_kiem {
    HANH_KIEM_UNKNOWN,
    HANH_KIEM_TOT,
    HANH_KIEM_KHA,
    HANH_KIEM_TRUNG_BINH,
    HANH_KIEM_YEU,
    HANH_KIEM_MAXSIZE
} hanh_kiem;

typedef struct sinhvien {
    char* ten;              // 8 bytes char*
    char* lop;              // 8 bytes char*
    i64 masv;               // 4 bytes i32
    hanh_kiem hanh_kiem;    // 4 bytes enum
} node_data;

typedef struct node {
    node_data data;
    struct node *next;
} node;

typedef struct list {
    node *head, *tail;
} list;


b8 list_initialization(list* list) {
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
        return TRUE;
    }
    return FALSE;
}

node* create_node(node_data data) {
    node* p = dn_allocate(sizeof(node), MEMORY_TAG_NODE);
    p->data = data;
    p->next = NULL;
    return p;
}

void insertHead(list* plist, node* pnode) {
    node* prev = plist->head;
    if ( !(plist->head || plist->tail) )
    {
        plist->head = pnode;
        plist->tail = plist->head;
        return;
    }
    plist->head = pnode;
    pnode->next = prev;
}

void insertTail(list* plist, node* pnode) {
    node* prev = plist->tail;
    if ( !(plist->head || plist->tail) )
    {
        insertHead(plist, pnode);
    }
    plist->tail->next = pnode;
    plist->tail = pnode;
}

void insertAfter(list* plist, b8 (*compare)(const node*, const node*), node* pnode)
{
    if (!plist) return;
    node* ptr = plist->head;
    while (ptr) {
        node* next_ptr = ptr->next;
        if(compare(ptr, pnode))
        {
            if (ptr == plist->tail) {
                insertTail(plist, pnode);
            } else {
                ptr->next = pnode;
                pnode->next = next_ptr;
            }
            return;
        }
        ptr = ptr->next;
    }
}

void insertBefore(list* plist, b8 (*compare)(const node*, const node*), node* pnode)
{
    if (!plist) return;
    node* ptr = plist->head;
    while (ptr) {
        node* next_ptr = ptr->next;
        if(compare(next_ptr, pnode))
        {
            if (ptr == plist->head) {
                insertHead(plist, pnode);
            } else {
                ptr->next = pnode;
                pnode->next = next_ptr;
            }
            return;
        }
        ptr = ptr->next;
    }
}

const char* hanhkiem_str[HANH_KIEM_MAXSIZE] = {
    "",
    "TOT",
    "KHA",
    "TRUNG BINH",
    "YEU"
};

void print_node_data(node_data data) {
    printf(
        "%011lld\t%s\t%s\t%s\n",
        data.masv,
        data.ten,
        data.lop,
        hanhkiem_str[data.hanh_kiem]
    );
}

void print_list(list plist) {
    node* ptr = plist.head;
    while(ptr)
    {
        print_node_data(ptr->data);
        ptr = ptr->next;
    }
}

b8 sosanh_masv(const node* target, const node* node) {
    return (target->data.masv < node->data.masv) ? TRUE : FALSE;
}

int main() {
    list L;
    if(!list_initialization(&L)) return -1;

    memory_system_initialize();

    struct sinhvien sv;
    sv.masv = 1;
    sv.ten = "Nguyen van A";
    sv.lop = "D15CNPM4";
    sv.hanh_kiem = HANH_KIEM_TOT;
    node* n1 = create_node(sv);
    insertTail(&L, n1);

    sv.masv = 2;
    sv.ten = "Nguyen van B";
    sv.lop = "D15CNPM5";
    sv.hanh_kiem = HANH_KIEM_KHA;
    node* n2 = create_node(sv);
    insertTail(&L, n2);

    sv.masv = 3;
    sv.ten = "Nguyen van C";
    sv.lop = "D15CNPM3";
    sv.hanh_kiem = HANH_KIEM_TRUNG_BINH;
    node* n3 = create_node(sv);
    insertTail(&L, n3);

    sv.masv = 4;
    sv.ten = "Nguyen van D";
    sv.lop = "D15CNPM4";
    sv.hanh_kiem = HANH_KIEM_TOT;
    node* n4 = create_node(sv);
    insertTail(&L, n4);

    sv.masv = 22810310334;
    sv.ten = "Nguyen van E";
    sv.lop = "D15CNPM5";
    sv.hanh_kiem = HANH_KIEM_YEU;
    node* n5 = create_node(sv);
    insertBefore(&L, sosanh_masv, n5);

    print_list(L);
    dn_free(n1);
    dn_free(n2);
    dn_free(n3);
    dn_free(n4);
    dn_free(n5);
    print_mem_usage();

    memory_system_shutdown();
}
