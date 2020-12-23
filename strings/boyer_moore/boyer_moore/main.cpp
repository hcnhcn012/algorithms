//
//  main.cpp
//  boyer_moore
//
//  Created by ChengnanHu on 12/22/20.
//

#include <iostream>

#define HASHTABLE_SIZE 256

using namespace std;

bool issubstr_bm(const char *st, const char *sp, size_t st_len, size_t sp_len);
int bad_char(const char *st, const char *sp, int start, int end, int *sp_index_hash_table);
int good_suffix(const char *st, const char *sp, int start, int end);

int main(int argc, const char * argv[])
{
    
}

/* Pattern strings are longer than text strings */
bool issubstr_bm(const char *st, const char *sp, size_t st_len, size_t sp_len)
{
    int start = 0;
    int end = int(sp_len - 1);
    int hash_table[HASHTABLE_SIZE];
    /* build hash table */
    for (int i=0; i<HASHTABLE_SIZE-1; i++)
        hash_table[i] = -1;
    
    while (end < st_len)
    {
        int move = 0;
        int bad_char_move = bad_char(st, sp, start, end, hash_table);
        int good_suffix_move = good_suffix(st, sp, start, end);
        if (bad_char_move == 0 || good_suffix_move == 0)
        {
            return true;
        }
        bad_char_move > good_suffix_move ? \
            move = bad_char_move : move = good_suffix_move;
        
        start += move;
        end += move;
    }
    return false;
}

int bad_char(const char *st, const char *sp, int start, int end, int *sp_index_hash_table)
{
    char bad_char = '\0';
    /* find bad char */
    int i=end-start;
    for (; i>=0; i--)
    {
        if (sp[i] != st[start+i])
        {
            bad_char = st[start+i];
            break;
        }
    }
    /* get bad char position in pattern string */
    int bad_char_pos = sp_index_hash_table[int(bad_char)];
    /* return shift */
    /* if perfect match, i-bad_char_pos is zero */
    return i-bad_char_pos;
}

int good_suffix(const char *st, const char *sp, int start, int end)
{
    return 0;
}
