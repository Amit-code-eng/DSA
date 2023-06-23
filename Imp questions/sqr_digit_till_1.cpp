#include <bits/stdc++.h>
using namespace std;

int f(int n)
{

    int x = 0;
    while (n)
    {

        int y = n % 10;
        x += y * y;
        n /= 10;
    }
    return x;
}
bool Old_isHappy(int n)
{

    unordered_set<int> st;
    st.insert(n);

    while (1)
    {
        n = f(n);
        if (n == 1)
            return 1;
        else if (st.find(n) != st.end())
            return 0;
        else
            st.insert(n);
    }


    //// we see repeatation always think of cycle {floyd detection}
}

int solve(int n)
{
    return f(n);
}

bool isHappy(int n)
{

    int fast = n, slow = n;

    do
    {
        slow = solve(slow);
        fast = solve(solve(fast));
    } while (slow != fast);/// 1==1 or some value

    /// if it give one in slow then definatly in fast also
    /// if over value repeate then it cant be one
    return slow == 1;
}

int main()
{

    return 0;
}