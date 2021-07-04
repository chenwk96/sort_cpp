# sort_cpp:smile:
几个常见的排序算法的CPP实现：

1. 冒泡排序
2. 插入排序
3. 选择排序





## 如何分析一个”排序算法“？

* **算法的执行效率**
  1. 最好情况、最差情况、平均情况时间的复杂度；
  2. 时间复杂度的系数、常数、阶数；
  3. 比较次数和交换（或移动）次数。
* **算法的内存消耗**：是否为原地排序，即有无消耗额外的空间
* **算法的稳定性**：待排序的序列中值相等的元素在排序后的相对位置是否会发生变化



## 冒泡排序（Bubble Sort）

每次冒泡操作都会对相邻的两个元素进行比较，看是否满足大小关系要求。如果不满足就让它俩互换。一次冒泡会让至少一个元素移动到它应该在的位置，重复 n 次，就完成了 n 个数据的排序工作：

- 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
- 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
- 针对所有的元素重复以上的步骤，除了最后一个；
- 重复步骤1~3，直到排序完成。

```C++
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
        // 当某次冒泡操作已经没有数据交换时，说明已经达到完全有序，
        // 不用再继续执行后续的冒泡操作
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

/*************************************
PS E:\sort_cpp\code> .\bubble_sort.exe
输入数组的长度：5
输入元素：45
43
32
65
45
排序后：32 43 45 45 65 
**************************************/
```

原地排序、稳定（相邻的两个元素大小相等的时候，我们不做交换）、最好$O(n)$、最差$O(n^2)$、平均$O(n^2)$



## 插入排序（Insertion Sort）

插入排序通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

- 从第一个元素开始，该元素可以认为已经被排序；
- 取出下一个元素，在已经排序的元素序列中从后向前扫描；
- 如果该元素（已排序）大于新元素，将该元素移到下一位置；
- 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
- 将新元素插入到该位置后；
- 重复步骤2~5。

```C++
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

/******************************************
PS E:\sort_cpp\code> .\insertion_sort.exe
输入数组的长度：5
输入元素：45
43
32
65
45
排序后：32 43 45 45 65 
*******************************************/
```

原地排序、稳定（相邻的两个元素大小相等的时候，我们不做交换）、最好$O(n)$、最差$O(n^2)$、平均$O(n^2)$



## 选择排序（Selection Sort）

选择排序算法的实现思路有点类似插入排序，也分已排序区间和未排序区间。但是选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾。

```C++
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

/******************************************
PS E:\sort_cpp\code> .\insertion_sort.exe
输入数组的长度：5
输入元素：32
23
45
67
1
排序后：1 23 32 45 67 
*******************************************/
```

原地排序、**不稳定**、最好$O(n^2)$、最差$O(n^2)$、平均$O(n^2)$

比如说：6，8，5，6，2 这样一组数据，第一次找到最小元素 2，与第一个 6交换位置，那第一个 6 和中间的 6 顺序就变了，所以就不稳定了。相对于冒泡排序和插入排序，选择排序就稍微逊色了。













































