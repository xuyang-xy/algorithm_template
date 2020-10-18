int h[MAXN];
void Init()
{
    memset(h, 0, sizeof(h));
    for(int i = 2; i <= MAXN; i++)
        if(!h[i])
            for(int j = i + i; j <= MAXN; j += i)
                h[j] = 1;
}
