#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s)
{

    int level = 0;
    int valleys = 0;
    for (int i = 0; i < n; ++i)
    {
        char c = s[i];
        int direction = (c == 'D') ? -1 : 1;
        if (level == 0)
        {
            if (direction < 0)
            {
                ++valleys;
            }
        }
        level += direction;
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
