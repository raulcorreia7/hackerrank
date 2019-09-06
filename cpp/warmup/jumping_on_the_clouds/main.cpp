#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds_r(int current_cloud, vector<int> c)
{
    if (current_cloud >= c.size())
    {
        return INT_MAX;
    }
    if (current_cloud == c.size() - 1)
    {
        return 0;
    }
    int value = c[current_cloud];
    if (value == 0)
    {
        int first = jumpingOnClouds_r(current_cloud + 1, c);
        int second = jumpingOnClouds_r(current_cloud + 2, c);
        int min_value = min(first, second);
        return 1 + min_value;
    }
    else
    {
        return INT_MAX;
    }
}
int jumpingOnClouds(vector<int> c)
{

    return jumpingOnClouds_r(0, c);
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    
    int n = 100;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp = "0 1 0 0 0 0 0 1 0 1 0 0 0 1 0 0 1 0 1 0 0 0 0 1 0 0 1 0 0 1 0 1 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 0";
    //getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    cout << result << "\n";

    

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
