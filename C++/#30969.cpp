#include <cstdio>
#include <cstring>

int main()
{
    int N;
    if (std::scanf("%d", &N) != 1)
    {
        return 0;
    }

    int freq[1001] = {0};   // 1..1000
    long long bigCnt = 0;   // > 1000
    int jinjuCost = -1;

    char dest[32];
    long long cost;

    for (int i = 0; i < N; i++)
    {
        std::scanf("%s %lld", dest, &cost);

        if (std::strcmp(dest, "jinju") == 0)
        {
            jinjuCost = (int)cost;
        }
        else
        {
            if (cost > 1000)
            {
                bigCnt++;
            }
            else
            {
                freq[(int)cost]++;
            }
        }
    }

    long long moreExpensive = bigCnt;
    for (int c = jinjuCost + 1; c <= 1000; c++)
    {
        moreExpensive += freq[c];
    }

    std::printf("%d\n", jinjuCost);
    std::printf("%lld\n", moreExpensive);

    return 0;
}
