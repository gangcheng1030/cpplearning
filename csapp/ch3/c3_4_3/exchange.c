//
// Created by gang cheng on 2021/7/5.
//

long exchange(long *xp, long y)
{
    long x = *xp;
    *xp = y;
    return x;
}