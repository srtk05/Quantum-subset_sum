

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> set_elements;
int target_sum = 0;
int n = 0;  // Number of elements

// Function to find all subsets with sum = target

void findSubsetSum(int index, vector<int>& current_subset, int current_sum) {
    
    // BASE CASE 1: When current sum equals target, we found a valid subset
    if (current_sum == target_sum) {
        cout << "Valid Subset: { ";
        for (int num : current_subset) {
            cout << num << " ";
        }
        cout << "} -> Sum = " << current_sum << endl;
        return;  // Continue searching for other solutions
    }
    
    // BASE CASE 2: If no more elements to process, return
    if (index == n) {
        return;
    }
    
    // PRUNING: If current sum exceeds target, stop (important optimization)
    if (current_sum > target_sum) {
        return;
    }
    
    // BACKTRACKING CHOICE 1: INCLUDE current element
    current_subset.push_back(set_elements[index]);
    findSubsetSum(index + 1, current_subset, current_sum + set_elements[index]);
    current_subset.pop_back();  // Backtrack - remove the element
    
    // BACKTRACKING CHOICE 2: EXCLUDE current element
    findSubsetSum(index + 1, current_subset, current_sum);
}

// Wrapper function with timing and statistics

void solveSubsetSum(vector<int> input_set, int target) {
    
    set_elements = input_set;
    target_sum = target;
    n = input_set.size();
    
    cout << "\n========== SUBSET SUM SOLVER (CLASSICAL) ==========" << endl;
    cout << "Set: { ";
    for (int num : input_set) {
        cout << num << " ";
    }
    cout << "}" << endl;
    cout << "Target Sum: " << target << endl;
    cout << "Number of elements (n): " << n << endl;
    cout << "Theoretical max subsets: 2^" << n << " = " << (1 << n) << endl;
    cout << "=================================================" << endl;
    
    // Start timer
    clock_t start = clock();
    
    vector<int> subset;
    findSubsetSum(0, subset, 0);
    
    // End timer
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    
    cout << "=================================================" << endl;
    cout << "Execution Time: " << time_taken << " seconds" << endl;
    cout << "Time Complexity: O(2^n) where n = " << n << endl;
    cout << "=================================================" << endl;
}
// Main function with test cases


int main() {
    
    // TEST CASE 1: Small example
    
    cout << "\n>>> TEST CASE 1: Small Set <<<\n" << endl;
    vector<int> set1 = {5, 10, 12, 13, 15, 18};
    solveSubsetSum(set1, 30);
    
    // TEST CASE 2: Medium example with more subsets
    
    cout << "\n\n>>> TEST CASE 2: Different Target <<<\n" << endl;
    vector<int> set2 = {3, 5, 7, 8, 12};
    solveSubsetSum(set2, 15);
    
    
    // TEST CASE 3: Simple example for understanding
    
    
    cout << "\n\n>>> TEST CASE 3: Minimal Example <<<\n" << endl;
    vector<int> set3 = {2, 3, 5, 8};
    solveSubsetSum(set3, 10);
    
    
    // PERFORMANCE ANALYSIS
    
    
    cout << "\n\n========== COMPLEXITY ANALYSIS ==========" << endl;
    cout << "n=6   -> Operations = 2^6 = 64" << endl;
    cout << "n=10  -> Operations = 2^10 = 1,024" << endl;
    cout << "n=20  -> Operations = 2^20 = 1,048,576" << endl;
    cout << "n=30  -> Operations = 2^30 ≈ 1,000,000,000 (1 BILLION!)" << endl;
    cout << "n=50  -> Operations = 2^50 ≈ 1 QUADRILLION (infeasible)" << endl;
    cout << "========================================" << endl;
    
    cout << "\n[INSIGHT] This is why quantum computing matters!" << endl;
    cout << "Quantum can theoretically reduce this to O(2^(n/2)) !" << endl;
    
    return 0;
}

