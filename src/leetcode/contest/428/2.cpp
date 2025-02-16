#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double prod = 1, prodInit = -LONG_MAX, maxC = -LONG_MAX;
    int x[25], visited[25];
    double cost[25][25];

    void tsp(int k, int n) {
        for (int i = 2; i<= n;i++) {
            if (!visited[i] && cost[x[k-1]][i]!=-1) {
                visited[i] = 1;
                x[k] = i;
                prod *= cost[x[k-1]][i];
                if (k == n) {
                    if (cost[i][1] != -1 && prod * cost[i][1] < prodInit)
                        prodInit = prod * cost[i][1];
                }
                else {
                    // Nhanh can:
                    if (prod * (n-k+1)*maxC < prodInit) {
                        tsp(k+1, n);
                    }
                }
                visited[i] = 0;
                prod /= cost[x[k-1]][i];
            }
        }
    }

    double maxAmount2(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string, int> vertice;

        int N = 1;
        vertice[initialCurrency] = N;
        for (auto& pair1 : pairs1){
            string key1 = pair1[0], key2 = pair1[1];
            if (vertice.find(key1) == vertice.end()){
                vertice[key1] = ++N;
            }

            if (vertice.find(key2) == vertice.end()){
                vertice[key2] = ++N;
            }

            cout << key1 << " " << key2 << " " << vertice[key1] << " " << vertice[key2] << endl;
        }

        for (auto& pair2 : pairs2){
            string key1 = pair2[0], key2 = pair2[1];
            if (vertice.find(key1) == vertice.end()){
                vertice[key1] = ++N;
            }

            if (vertice.find(key2) == vertice.end()){
                vertice[key2] = ++N;
            }
            cout << key1 << " " << key2 << " " << vertice[key1] << " " << vertice[key2] << endl;
        }

        for (int i = 0; i < 25; ++i){
            for (int j = 0; j < 25; ++j){
                cost[i][j] = -1;
            }
        }

        for (int i = 0; i < 25; ++i){
            visited[i] = 0;
        }

        for (int i = 0; i < pairs1.size(); ++i){
            string key1 = pairs1[i][0], key2 = pairs1[i][1];
            int k1 = vertice[pairs1[i][0]], k2 = vertice[pairs1[i][1]];
            double c = rates1[i];
            if (cost[k1][k2] != -1){
                cost[k1][k2] = max(cost[k1][k2], c);
                cost[k2][k1] = max(cost[k2][k1], 1. / c);
            }
            else{
                cost[k1][k2] = c;
                cost[k2][k1] = 1./ c;
            }

            maxC = max(maxC, cost[k1][k2]);
            cout << key1 << " " << key2 << " " << vertice[key1] << " " << vertice[key2] << "cost: " << cost[k1][k2] << " " << cost[k2][k1] << endl;
        }

        for (int i = 0; i < pairs2.size(); ++i){
            string key1 = pairs2[i][0], key2 = pairs2[i][1];
            int k1 = vertice[pairs2[i][0]], k2 = vertice[pairs2[i][1]];
            double c = rates2[i];
            if (cost[k1][k2] != -1){
                cost[k1][k2] = max(cost[k1][k2], c);
                cost[k2][k1] = max(cost[k2][k1], 1. / c);
            }
            else{
                cost[k1][k2] = c;
                cost[k2][k1] = 1./ c;
            }
            maxC = max(maxC, cost[k1][k2]);
            cout << key1 << " " << key2 << " " << vertice[key1] << " " << vertice[key2] << "cost: " << cost[k1][k2] << " " << cost[k2][k1] << endl;
        }

        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                cout << cost[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "maxCost = " << maxC << "\n\n";

        tsp(1, N);
        cout << prodInit << "\n";
        return prodInit;

    }

    bool visited[25][25];
    vector<vector<VW>>

    double maxAmount2(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string, int> vertice;

        int N = 1;
        vertice[initialCurrency] = N;
        for (auto& pair1 : pairs1){
            string key1 = pair1[0], key2 = pair1[1];
            if (vertice.find(key1) == vertice.end()){
                vertice[key1] = ++N;
            }

            if (vertice.find(key2) == vertice.end()){
                vertice[key2] = ++N;
            }

            cout << key1 << " " << key2 << " " << vertice[key1] << " " << vertice[key2] << endl;
        }

        for (auto& pair2 : pairs2){
            string key1 = pair2[0], key2 = pair2[1];
            if (vertice.find(key1) == vertice.end()){
                vertice[key1] = ++N;
            }

            if (vertice.find(key2) == vertice.end()){
                vertice[key2] = ++N;
            }
        }

        for (int i = 0; i < pairs1.size(); ++i){
            string key1 = pairs1[i][0], key2 = pairs1[i][1];
            int k1 = vertice[pairs1[i][0]], k2 = vertice[pairs1[i][1]];
            double c = rates1[i];
            if (cost[k1][k2] != -1){
                cost[k1][k2] = max(cost[k1][k2], c);
                cost[k2][k1] = max(cost[k2][k1], 1. / c);
            }
            else{
                cost[k1][k2] = c;
                cost[k2][k1] = 1./ c;
            }
        }

        
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;

    string initialCurrency = "EUR";
    vector<vector<string>> pairs1 = {{"EUR","USD"},{"USD","JPY"}};
    vector<double> rates1 = {2.0, 3.0};
    vector<vector<string>> pairs2 = {{"JPY","USD"},{"USD","CHF"},{"CHF","EUR"}};
    vector<double> rates2 = {4.0,5.0,6.0};



    cout << sol.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2);
}