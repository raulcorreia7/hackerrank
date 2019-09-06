#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
    int height = 0;
    int half_height = arr.size() / 2;
    int max_sum = INT_MIN;
    for (int curr_height = 0; curr_height <= half_height; ++curr_height)
    {
        for (int curr_width = 0; curr_width <= half_height; ++curr_width)
        {
            int first = curr_width, second = curr_width + 1, third = curr_width + 2;
            int current_sum =
                arr[curr_height][first] + arr[curr_height][second] + arr[curr_height][third] 
                + arr[curr_height + 1][second] 
                + arr[curr_height + 2][first] + arr[curr_height + 2][second] + arr[curr_height+ 2][third];
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    arr[0] = {-9, -9, -9, 1, 1, 1};
    arr[1] = {0, -9, 0, 4, 3, 2};
    arr[2] = {-9, -9, -9, 1, 2, 3};
    arr[3] = {0, 0, 8, 6, 6, 0};
    arr[4] = {0, 0, 0, -2, 0, 0};
    arr[5] = {0, 0, 1, 2, 4, 0};
    // for (int i = 0; i < 6; i++)
    // {
    //     arr[i].resize(6);

    //     for (int j = 0; j < 6; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }

    int result = hourglassSum(arr);

    //fout << result << "\n";
    cout << result << "\n";
    //fout.close();

    return 0;
}
