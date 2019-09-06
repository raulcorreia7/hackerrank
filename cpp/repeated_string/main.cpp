#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

long repeatedString(string s, long n)
{
    long num_of_char_a = 0;
    long string_size = s.size(); //string size is long max
    auto count_lambda = [](string mystr, long limit) {
        long counter = 0;
        for (long i = 0; i < limit; ++i)
        {
            char c = mystr[i];
            if (c == 'a')
            {
                ++counter;
            }
        }
        return counter;
    };

    long num_repetitions = n / string_size;
    num_of_char_a = num_repetitions * count_lambda(s, string_size);

    if (num_repetitions % n != 0 || num_repetitions == 0)
    {
        long dif = n - (num_repetitions * string_size);
        num_of_char_a += count_lambda(s, dif);
    }
    return num_of_char_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    return 0;
}
