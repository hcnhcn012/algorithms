/*
 * lru_cache.c
 * lru cache implementation by single linked list(sll)
 * @author Chengnan Hu
 * 2020-09-01
 */

#include <stdio.h>
#include <string.h>
#define MAX_LEN 5
int len = 0;


/* Node struct */
typedef struct lru_cache_s
{
    int data;
    void *next;
}lru_cache_t;

/* Single Linked List struct */
typedef struct lru_sll_s
{
    lru_cache_t *head;
    lru_cache_t *tail;
    int len;
}lru_sll_t;

void init_lru_sll(lru_sll_t *sll);

lru_cache_t* sll_find_data(lru_sll_t *sll, int data);
void sll_linsert(lru_sll_t *sll, lru_cache_t *pos, lru_cache_t *cache);
void sll_rinsert(lru_sll_t *sll, lru_cache_t *pos, lru_cache_t *cache);
void sll_remove(lru_sll_t *sll, lru_cache_t *pos);

void show_sll(lru_sll_t *sll);
int lru(lru_sll_t *sll, lru_cache_t *cache);


void init_lru_sll(lru_sll_t *sll)
{
    sll->head = NULL;
    sll->tail = NULL;
    sll->len = 0;
    return;
}

lru_cache_t* sll_find_data(lru_sll_t *sll, int data)
{
    lru_cache_t *pos;
    pos = sll->head;
    while (pos != NULL && pos->data != data)
        pos = pos->next;
    return pos;
}

lru_cache_t* find_prev_pos(lru_sll_t *sll, lru_cache_t *pos)
{
    lru_cache_t *ptr;
    ptr = sll->head;
    /* 
     * Consider if pos is head 
     * if pos is head
     * return head
     */
    if(ptr != pos)
        for (;ptr->next!=pos&&ptr!=NULL;ptr=ptr->next);
    return ptr;
}

void show_sll(lru_sll_t *sll)
{
    printf("lru cache ssl, length: %d\n", sll->len);
    lru_cache_t *pos;
    pos = sll->head;
    for (;pos!=NULL;pos=pos->next)
    {
        fflush(stdout);
        printf("%d -> ", sll->head->data);
    }
    printf("NULL\n");
}

void sll_linsert(lru_sll_t *sll, lru_cache_t *pos, lru_cache_t *cache)
{
    /* 
     * Insert to the left
     * position of given pos
     */
    lru_cache_t *ptr;
    lru_cache_t *prev_pos;
    ptr = sll->head;
    for (;ptr!=NULL&&ptr!=pos;ptr=ptr->next);
    /* if pos in sll */
    if (ptr != NULL)
    {
        prev_pos = find_prev_pos(sll, ptr);
        /* if pos is head */
        if (prev_pos == ptr)
        {
            sll->head = cache;
            cache->next = ptr;
        }
        /* if pos isn't head */
        else
        {
            prev_pos->next = cache;
            cache->next = ptr;
        }
        sll->len++;
    }
    else
    {
        printf("Can't insert: Given position not found.\n");
    }
    
}

void sll_rinsert(lru_sll_t *sll, lru_cache_t *pos, lru_cache_t *cache)
{
    /* 
     * Insert to the right 
     * position of given pos
     */
    lru_cache_t *ptr;
    ptr = sll->head;
    for (;ptr!=NULL&&ptr!=pos;ptr=ptr->next);
    /* if pos in sll */
    if (ptr != NULL)
    {
        cache->next = ptr->next;
        ptr->next = cache;
        sll->len++;
    }
    else
    {
        printf("Can't insert: Given position not found.\n");
    }
    
}

void sll_remove(lru_sll_t *sll, lru_cache_t *pos)
{
    lru_cache_t *ptr;
    lru_cache_t *prev_pos;
    lru_cache_t *ptr_to_remove;
    ptr = sll->head;
    for (;ptr!=NULL&&ptr!=pos;ptr=ptr->next);
    /* if pos is in sll */
    if (ptr != NULL)
    {
        prev_pos = find_prev_pos(sll, ptr);
        /* if pos is head */
        if (prev_pos == ptr)
        {
            ptr_to_remove = sll->head;
            sll->head = ptr->next;
        }
        else
        {
            ptr_to_remove = ptr;
            prev_pos->next = ptr->next;
        }
        free(ptr_to_remove);
        sll->len--;
    }
    else
    {
        printf("Can't insert: Given position not found.\n");
    }
    
}


int lru(lru_sll_t *sll, lru_cache_t *cache)
{
    int data = cache->data;
    int res;
    res = sll_find_data(sll, data);
    /* if not found */
    if (res == NULL)
    {
        /* 
         * if length isn't exceeded
         * add a new node as SSL head 
         */
        if (sll->len < MAX_LEN)
            sll_linsert(sll, sll->head, cache);
        /*
         * else sll_remove tail node, then add as a new head
         */
        else
        {
            sll_remove(sll, sll->tail);
            sll_linsert(sll, sll->head, cache);
        }
    }
    /* if found */
    else
    {
        /* First sll_remove cache*/
        sll_remove(sll, cache);
        /* Then add to header */
        sll_linsert(sll, sll->head, cache);
    }
    return 0;
}

int main()
{
    lru_sll_t sll;

    init_lru_sll(&sll);
    printf("Now sll is: \n");
    show_sll(&sll);

    printf("Now find 5 in sll: \n");
    lru_cache_t cache;
    cache.data = 5;
    lru(&sll, &cache);
    printf("After find %d, Now sll is \n", cache.data);
    show_sll(&sll);

    lru_cache_t cache2;
    cache2.data = 9;
    lru(&sll, &cache2);
    printf("After find %d, Now sll is \n", cache2.data);
    show_sll(&sll);

    lru_cache_t cache3;
    cache3.data = 7;
    lru(&sll, &cache3);
    printf("After find %d, Now sll is \n", cache3.data);
    show_sll(&sll);

    lru_cache_t cache4;
    cache4.data = 4;
    lru(&sll, &cache4);
    printf("After find %d, Now sll is \n", cache4.data);
    show_sll(&sll);

    lru_cache_t cache5;
    cache5.data = 9;
    lru(&sll, &cache5);
    printf("After find %d, Now sll is \n", cache5.data);
    show_sll(&sll);

    lru_cache_t cache6;
    cache6.data = 18;
    lru(&sll, &cache6);
    printf("After find %d, Now sll is \n", cache6.data);
    show_sll(&sll);

    lru_cache_t cache7;
    cache7.data = 23;
    lru(&sll, &cache7);
    printf("After find %d, Now sll is \n", cache7.data);
    show_sll(&sll);

    return 0;
}