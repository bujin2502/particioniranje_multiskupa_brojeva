#include <iostream>
#include <vector>

using namespace std;

int lineCounter = 1;

void printPartition(const vector<int>& multiset, vector<vector<int>>& ans)
{
    cout << "Particija " << lineCounter << ": ";
    cout << "(";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << "{ ";
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j];
            if (j < ans[i].size() - 1) {
                cout << ",";
            }
        }
        cout << " }";
        if (i < ans.size() - 1) {
            cout << "; ";
        }
    }
    cout << ")" << endl;
    lineCounter++;
}

void Partition(const vector<int>& multiset, int index, vector<vector<int>>& ans)
{
    if (index == multiset.size()) {
        printPartition(multiset, ans);
        return;
    }

    vector<int> newBlock = { multiset[index] };
    ans.push_back(newBlock);
    Partition(multiset, index + 1, ans);
    ans.pop_back();

    for (int i = 0; i < ans.size(); i++) {
        ans[i].push_back(multiset[index]);
        Partition(multiset, index + 1, ans);
        ans[i].pop_back();
    }
}

void allPartitions(const vector<int>& multiset)
{
    vector<vector<int>> v;
    Partition(multiset, 0, v);
}

int main()
{
    vector<int> multiset = {1, 4, 9, 9, 10};
    allPartitions(multiset);
    return 0;
}
