#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a subset of `numbers` sums up to `target`
bool subsetSum(vector<int>& numbers, int target, int index, int sum, vector<int>& subset) {
    if (sum == target) {
        return true;
    }
    if (index == numbers.size() || sum > target) {
        return false;
    }
    subset.push_back(numbers[index]);
    bool include = subsetSum(numbers, target, index+1, sum+numbers[index], subset);
    if (include) {
        return true;
    }
    subset.pop_back();
    return subsetSum(numbers, target, index+1, sum, subset);
}

// Helper function to check if the `numbers` can be partitioned into two subsets with equal sum
bool canPartition(vector<int>& numbers, vector<int>& subset1, vector<int>& subset2) {
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    if (sum % 2 != 0) {
        return false;
    }
    bool found = subsetSum(numbers, sum/2, 0, 0, subset1);
    if (found) {
        for (int num : numbers) {
            if (find(subset1.begin(), subset1.end(), num) == subset1.end()) {
                subset2.push_back(num);
            }
        }
        return true;
    }
    return false;
}

int main() {
    vector<int> numbers = {1, 5, 11, 5};
    vector<int> subset1, subset2;
    if (canPartition(numbers, subset1, subset2)) {
        cout << "The numbers can be partitioned into two subsets with equal sum.\n";
        cout << "Subset 1: ";
        for (int num : subset1) {
            cout << num << " ";
        }
        cout << "\nSubset 2: ";
        for (int num : subset2) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "The numbers cannot be partitioned into two subsets with equal sum.\n";
    }
    return 0;
}