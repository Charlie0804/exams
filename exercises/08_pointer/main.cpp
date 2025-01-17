﻿#include "../exercise.h"

// READ: 数组向指针退化 <https://zh.cppreference.com/w/cpp/language/array#%E6%95%B0%E7%BB%84%E5%88%B0%E6%8C%87%E9%92%88%E7%9A%84%E9%80%80%E5%8C%96>
bool is_fibonacci(int *ptr, int len, int stride) {
    ASSERT(len >= 3, "`len` should be at least 3");
    // TODO: 编写代码判断从 ptr 开始，每 stride 个元素取 1 个元素，组成长度为 n 的数列是否满足
    // arr[i + 2] = arr[i] + arr[i + 1]
    // 处理stride为0的情况，若stride为0无法按规则取元素进行判断，直接返回false
    if (stride == 0) {
        return false;
    }
    // 计算实际可用于判断的元素个数，考虑从ptr开始以及stride间隔情况
    int actualLen = (len - 2 * stride) / stride;
    // 至少需要3个元素才能进行斐波那契数列特性判断，若不足则返回false

    for (int i = 0; i < actualLen - 2; ++i) {
        // 根据stride计算当前、下一个、下下个元素对应的指针位置
        int *curPtr = ptr + i * stride;
        int *nextPtr = ptr + (i + 1) * stride;
        int *nextNextPtr = ptr + (i + 2) * stride;

        // 判断是否满足斐波那契数列的递推关系，不满足则返回false
        if (*nextNextPtr!= *nextPtr + *curPtr) {
            return false;
        }
    }
    return true;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    int arr0[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55},
        arr1[]{0, 1, 2, 3, 4, 5, 6},
        arr2[]{99, 98, 4, 1, 7, 2, 11, 3, 18, 5, 29, 8, 47, 13, 76, 21, 123, 34, 199, 55, 322, 0, 0};
    // clang-format off
    ASSERT( is_fibonacci(arr0    , sizeof(arr0) / sizeof(*arr0)    , 1),         "arr0 is Fibonacci"    );
    ASSERT( is_fibonacci(arr0 + 2, sizeof(arr0) / sizeof(*arr0) - 4, 1), "part of arr0 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr1    , sizeof(arr1) / sizeof(*arr1)    , 1),         "arr1 is not Fibonacci");
    ASSERT( is_fibonacci(arr1 + 1,  3                              , 1), "part of arr1 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr2    , sizeof(arr2) / sizeof(*arr2)    , 1),         "arr2 is not Fibonacci");
    ASSERT( is_fibonacci(arr2 + 2, 10                              , 2), "part of arr2 is Fibonacci"    );
    ASSERT( is_fibonacci(arr2 + 3,  9                              , 2), "part of arr2 is Fibonacci"    );
    ASSERT( is_fibonacci(arr2 + 3, 10                              , 2), "guard check"                  );
    ASSERT(!is_fibonacci(arr2 + 1, 10                              , 2), "guard check"                  );
    // clang-format on
    return 0;
}
