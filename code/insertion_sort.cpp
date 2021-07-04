#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& vec);

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
    insertion_sort(vec);
    cout << "排序后：";
    for (auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

void insertion_sort(vector<int>& vec) {
    int len = vec.size();
    if (len <= 1) return;
    for (int i = 1; i < len; ++i) {
        int val = vec[i];
        // 已排序区间[0, j - 1]，未排序区间[j, len - 1]
        int j = i - 1;    
        for (; j >= 0; --j) {
            if (vec[j] > val) {
                vec[j + 1] = vec[j];
            } else {
                break;
            }
        }
        vec[j + 1] = val; // 插入数据
    }
}