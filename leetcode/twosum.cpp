#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;

    int len = nums.size();

    sort(nums.begin(), nums.end());
    // procuro a soma, ou o numero mais proximo dela.
    auto it = lower_bound(nums.begin(), nums.end(), target);
    int j = it - nums.begin();
    for (j = j; j >= 0; j--)
    {
        for (int i = 0; i < len; i++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if ((nums[i] + nums[j]) > target)
            {
                break;
            }
        }
    }
}

int main()
{

// Test case input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Chama a função twoSum
    vector<int> result = twoSum(nums, target);

    // Imprime o resultado
    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "Nenhum par encontrado que soma o target." << endl;
    }

}