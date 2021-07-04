#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& vec);

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
    selection_sort(vec);
    cout << "排序后：";
    for (auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

void selection_sort(vector<int>& vec) {
    int len = vec.size();
    int i = 0;
    int j = 0;
    int min = 0;
    for (int i = 0; i < len - 1; ++i) {
        min = i;
        for (j = i + 1; j < len; ++j) {
            if (vec[j] < vec[min]) {
                min = j;
            }
            if (min != i) {
                swap(vec[i], vec[min]);
            }
        }
    }
}