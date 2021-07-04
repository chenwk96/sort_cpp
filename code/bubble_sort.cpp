#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& vec);

int main() {
    int n;
    vector<int> vec;
    cout <<  "输入数组的长度：";
    cin >> n;
    cout <<  "输入元素：";
    for(int i = 0, t; i < n; ++i) {
        cin >> t;
        vec.push_back(t);
    }
    bubble_sort(vec);
    cout << "排序后：";
    for (auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

void bubble_sort(vector<int>& vec) {
    int len = vec.size();
    for (int i = 0; i < len; ++i) {
        bool flag = false;
        for (int j = 0; j < len - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}