// 1
// int a[], int b[]
for (int i = 0; i < a.size(); i++)
{
    cout << a[i] << " "; // O(1)
}
for (int i = 0; i < b.size(); i++)
{
    cout << b[i] << " "; // O(1)
}

// TC: O(a.size() + b.size())

// 2
// string a[], string b[]
// 1 <= a[i].length() <= m1
// 1 <= b[i].length() <= m2
for (int i = 0; i < a.size(); i++)
{
    cout << a[i] << " "; // O(m1)
}
for (int i = 0; i < b.size(); i++)
{
    cout << b[i] << " "; // O(m2)
}

// TC: O((m1 * a.size()) + (m2 * b.size()))

// 3.
for (int i = 0; i < a.size(); i++)
{
    for (int j = 0; j < b.size(); j++)
    {
        cout << "hello"; // O(1)
    }
}

// TC: O(a.size() * b.size())


// 4.
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        cout << "hello"; // O(1)
    }
}

// TC: O(n*n)
/*
i = 0: j => 1 to n - 1              // n - 1
i = 1: j => 2 to n - 1              // n - 2
...
i = n - 2: j => n - 1 to n - 1      // 1

"hello" gets printed n-1 + n-2 + ... + 1 times = O(n*n) 
*/

// 5.
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < 100; k++)
        {
            cout << "hi";
        }   
    }
}

// TC: O(n*m*100) = O(n*m)

// 6.
We have `n` strings in an array. Each string has a maximum size of `s`.
We first want to sort each string individually and then sort the complete array of strings.

string arr[] = {"bac", "adc", "gfg", "degf"};

string arr[] = {"abc", "acd", "fgg", "defg"}; // Sorted the strings individually

string arr[] = {"abc", "acd", "defg", "fgg"}; // Sorted the complete array


Sorting each string individually: O(n*s * log(s))
Sorting the complete array of strings: O(n*s * log(n))

Overall time complexity: O(n*s(log(s) + log(n)))


// Integer array: O(n*log(n)) 
// Each integer comparison takes O(1) amount of time.
// Therefore, I can say that, while sorting `n` elements, we are doing O(n*log(n)) number of comparsions.

// But for strings, each comparsion will take O(s) amount of time.
// Total number of comparisons: O(n*log(n))
// Soring an array of strings: O(n*log(n) * s) = O(n*s * log(n))

1, 5 => O(1)
"abcd", "abce" => O(s)

// 7.
Fibonacci Numbers: F[0] = 0, F[1] = 1

F[n] = F[n - 1] + F[n - 2] // for n >= 2
0, 1, 1, 2, 3, 5, 8, 13 .. 

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2); // O(1)
}

n = 5
                5                           // 1
        4               3                   // 2
    3       2        2     1                // 4
  2   1   1   0     1  0                    // 8
1  0

Time complexity for recursive functions: O((Number of nodes in the recursive tree) * (time taken by each node in the worst-case))

Number of nodes in the recursive tree = 1 + 2 + 4 + 8 ....  (n-terms)

first-term = 1
number of terms = n
multiplication factor = 2


Number of nodes in the recursive tree = O(2^(n-1)) = O(2^n)
Time taken at each node = O(1)


Overall time complexity = O(2^n * 1) = O(2^n)


Rules for finding the time complexity of recursive functions:
1. Find out an upper bound to the number of nodes in the recursive tree. Say, it is equal to `a`
2. Find out the time taken by each recursive-call ASSUMING THAT making a new recursive call is a O(1) time operation. Say,
   it is equal to `b`.
3. The time complexity will be equal to O(a * b).
