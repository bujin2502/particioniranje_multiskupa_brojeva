#include <iostream>
#include <vector>

using namespace std;

int brojacLinija = 1;

void prikazParticija(const vector<int>& multiskup, vector<vector<int>>& ans)
{
    cout << "Particija " << brojacLinija << ": ";
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
    brojacLinija++;
}

void Particija(const vector<int>& multiskup, int index, vector<vector<int>>& ans)
{
    if (index == multiskup.size()) {
        prikazParticija(multiskup, ans);
        return;
    }

    vector<int> noviBlok = { multiskup[index] };
    ans.push_back(noviBlok);
    Particija(multiskup, index + 1, ans);
    ans.pop_back();

    for (int i = 0; i < ans.size(); i++) {
        ans[i].push_back(multiskup[index]);
        Particija(multiskup, index + 1, ans);
        ans[i].pop_back();
    }
}

void sveParticije(const vector<int>& multiskup)
{
    vector<vector<int>> v;
    Particija(multiskup, 0, v);
}

int main()
{
    vector<int> multiskup = {1, 4, 9, 9, 10};
    sveParticije(multiskup);
    return 0;
}
