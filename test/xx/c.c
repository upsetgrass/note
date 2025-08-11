// #include<stdio.h>
// #include<unistd.h>
// int main() {
//     printf("start\n");
//     int sum = 0;
//     for (int i = 0; i < 10000; i++) {
//         sum += i;
//     }
//     printf("sum = %d\n", sum);
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     printf("a\n");
//     abc:
//     printf("c\n");
//     goto abc;

//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//     int a = 0;
//     printf("a = %d\n", a);
//     int b = 1;
//     int flag = 0;
// abc:
//     printf("c=a+b=%d+%d\n", a, b);
//     if(flag == 1) return 0;
    
//     flag++;
//     b++;
//     goto abc;

//     return 0;
// }

#include <stdio.h>
// #include <setjmp.h>
// #include "b.c"
// jmp_buf env;

// void second() {
//     printf("second: now jumping back\n");
//     siglongjmp(env, 40);  // 相当于 goto 到 setjmp 的地方
// }

// void first() {
//     second();
// }

// int main() {
//     int val = sigsetjmp(env, 1);  // 保存当前执行状态（PC/SP等）
//     printf("val = %d\n", val);
//     printf("xx=%d\n", xx);
//     if (val != 0) {
//         // 这是 longjmp 跳回来后进入的分支
//         printf("main: got jump with val = %d\n", val);
//         return 0;
//     }
//     printf("main: calling first()\n");
//     first();  // 最终调用 second() -> longjmp(...)
    
//     return 0;
// }

// static inline uint64_t pow2ceil(uint64_t value)
// {
//     int n = clz64(value - 1);

//     if (!n) {
//         /*
//          * @value - 1 has no leading zeroes, thus @value - 1 >= 2^63
//          * Therefore, either @value == 0 or @value > 2^63.
//          * If it's 0, return 1, else return 0.
//          */
//         return !value;
//     }
//     return 0x8000000000000000ull >> (n - 1);
// }

// int main()
// {
//     int n = 1 << 15;
//     int ret = pow2ceil(n / 4);
//     printf("ret = %d", ret);

//     return 0;
// }


#include<stdlib.h>
#include <stdio.h>
#include <time.h>
// #include <random>
// #include <ctime>
int hash(int a, int b, int x, int p, int v)
{
    return ((a * x + b) % p) % v;
}

int method1()
{
    srand(time(NULL));
    int p, a, b, v, x;
    int hash_table[1000] = {0};
    int num = 1000;
    for(int i = 0; i < num; i++)
    {
        p = 10007;
        a = rand() % p;
        b = rand() % p;
        v = 1000;
        if(a == 0) continue;
        x = rand() % 10000;
        hash_table[hash(a, b, x, p, v)] += 1;
    }
    for(int i = 0; i < v; i++)
    {
        printf("hash_table[%d]:%d\n",i, hash_table[i]);
    }
    int Collision_cnt = 0;
    for(int i = 0; i < v; i++)
    {
        if (hash_table[i]) Collision_cnt += hash_table[i] - 1;
    }
    printf("hash_Collision_cnt:%d\n", Collision_cnt);
    printf("hash_Collision_rate:%2lf\n", Collision_cnt/(double)num);
    return 0;
}


// #include<stdlib.h>
int hash1(int a, int b, int x, int v)
{
    return (a * x + b) % v;
}

int method2()
{
    srand(time(NULL));
    int a, b, v, x;
    int hash_table[1000] = {0};
    int num = 1000;
    for(int i = 0; i < num; i++)
    {
        // p = 1009;
        a = rand();
        b = rand();
        v = 1000;
        if(a == 0) continue;
        x = rand() % 10000;
        hash_table[hash1(a, b, x, v)]++;
    }
    for(int i = 0; i < v; i++)
    {
        printf("hash_table[%d]:%d\n",i, hash_table[i]);
    }
    int Collision_cnt = 0;
    for(int i = 0; i < v; i++)
    {
        if (hash_table[i]) Collision_cnt += hash_table[i] - 1;
    }
    printf("hash_Collision_cnt:%d\n", Collision_cnt);
    printf("hash_Collision_rate:%2lf\n", Collision_cnt/(double)num);
    return 0;
}
// 1000 - 362 638
void test()
{
    srand(time(NULL));
    int hash[1000] = {0};
    for(int i = 0; i < 1000; i ++)
    {
        int x = rand() % 1000;
        hash[x] ++;
    }
    int ret = 0;
    int ret1 = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(hash[i])
        {
            printf("hash[%d]:%d\n", i, hash[i]);
            ret += hash[i] - 1;
        }
        else 
        {
            ret1++;
        }
    }
    
    printf("bed_situation:%d\n", ret);
    printf("dont:%d\n", ret1);
}






#include<stdint.h>
#define TARGET_PAGE_BITS 12
#define TB_JMP_CACHE_BITS 12
#define TB_JMP_CACHE_SIZE (1 << TB_JMP_CACHE_BITS)
typedef uintptr_t vaddr;
#define TB_JMP_PAGE_BITS (TB_JMP_CACHE_BITS / 2)
#define TB_JMP_PAGE_SIZE (1 << TB_JMP_PAGE_BITS)
#define TB_JMP_ADDR_MASK (TB_JMP_PAGE_SIZE - 1)
#define TB_JMP_PAGE_MASK (TB_JMP_CACHE_SIZE - TB_JMP_PAGE_SIZE)

static inline unsigned int tb_jmp_cache_hash_page(vaddr pc)
{
    vaddr tmp;
    tmp = pc ^ (pc >> (TARGET_PAGE_BITS - TB_JMP_PAGE_BITS));
    return (tmp >> (TARGET_PAGE_BITS - TB_JMP_PAGE_BITS)) & TB_JMP_PAGE_MASK;
}
static inline unsigned int tb_jmp_cache_hash_func1(vaddr pc)
{
    vaddr tmp;
    tmp = pc ^ (pc >> (TARGET_PAGE_BITS - TB_JMP_PAGE_BITS));
    return (((tmp >> (TARGET_PAGE_BITS - TB_JMP_PAGE_BITS)) & TB_JMP_PAGE_MASK)
           | (tmp & TB_JMP_ADDR_MASK)); // TB_JMP_ADDR_MASK-0x3F
}
static inline unsigned int tb_jmp_cache_hash_func2(vaddr pc)
{
    return (pc ^ (pc >> TB_JMP_CACHE_BITS)) & (TB_JMP_CACHE_SIZE - 1);
}

void qemu_qhash()
{
    uintptr_t BASE = 0x4000000;
    uintptr_t RANGE = 0x1000000;
    uintptr_t STEP = 4;          // 每个指令 4 字节对齐
    int hash1[4096] = {0};
    int hash2[4096] = {0};
    for (uintptr_t pc = BASE; pc < BASE + RANGE; pc += STEP) {
        int page_hash = tb_jmp_cache_hash_page(pc);
        int value_hash1 = tb_jmp_cache_hash_func1(pc);
        int value_hash2 = tb_jmp_cache_hash_func2(pc);
        // hash[tb_jmp_cache_hash_page(pc)]++;
        // hash[tb_jmp_cache_hash_func(pc)]++;
        // hash[value_hash]++;
        hash1[value_hash1]++;
        hash2[value_hash2]++;
        printf("pc == %lu, page_hash:%d, value_hash1:%d, value_hash2:%d\n", 
            pc, page_hash, value_hash1, value_hash2);
        // if(value_hash1-page_hash < 0 || value_hash2-page_hash < 0)
        if(value_hash1-page_hash >= 0 && value_hash1-page_hash < 64)
        {
            printf("value_hash1-page_hash1=%d, value_hash2-page_hash2:%d\n",
                value_hash1-page_hash, value_hash2-page_hash);
            // return;
        }
        else {
            return;
        }
    }
    printf("finish\n");
}

int main()
{
    // method1();
    // method2();
    // test();
    // qemu_qhash();
}