#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int trapWater(vector<int>& tinggi) 
{
    int n = tinggi.size();
    if (n <= 2) return 0;
    int trappedWater = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && tinggi[i] > tinggi[st.top()]) 
        {
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int jarak = i - st.top() - 1;
            int batastinggi = min(tinggi[i], tinggi[st.top()]) - tinggi[top];
            trappedWater += jarak * batastinggi;
        }
        st.push(i);
    }
    return trappedWater;
}
int main() {
    int n;
    cin >> n;
    vector<int>elevasi(n);
    for (int i = 0; i < n; i++) {
        cin >> elevasi[i];
    }
    int hasil = trapWater(elevasi);
    cout << hasil << endl;
    return 0;
}