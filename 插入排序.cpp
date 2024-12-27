#include<iostream>
#include <vector>
using namespace std;
void sorts(vector<int>& a) {
	for (int low = 1; low < a.size();low++) {
		int t = a[low]; //获取插入值
		int it = low - 1;
		while (it >= 0 && a[it] > t) { //判断某个位置是否 小于 t 那个位置就是插入位置
			a[it + 1] = a[it]; //空出位置 方便插入
			it--;              //向下遍历
		}
		if (it + 1 != low) { //如果插入位置是本身 就不做操作
			a[it + 1] = t; //插入值赋值
		}
	}
}
int main() {
	vector<int> arr = { 9,8,7,6,5,4,3,2,1 };
	sorts(arr);
	for (int i: arr) {
		cout << i << ' ';
	}
	return 0;
}
