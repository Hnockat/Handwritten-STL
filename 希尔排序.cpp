#include<iostream>
#include <vector>
using namespace std;
void sorts(vector<int>& a) {
	//希尔排序不是稳定的排序算法，因为它在排序过程中可能会改变相等元素的相对顺序。
	//希尔排序相对于插入排序 ->
	// 1.分组插入排序
	// 2.减少比较次数
	// 3.减少移动次数
	for (int get = a.size() / 2; get >= 1; get /= 2) { //间隔逐渐减少
		for (int low = get; low < a.size(); low+=get) {
			int t = a[low]; //获取插入值
			int it = low - get;
			while (it >= 0 && a[it] > t) { //判断某个位置是否 小于 t 那个位置就是插入位置
				a[it + get] = a[it]; //空出位置 方便插入
				it-=get;              //向下遍历
			}
			if (it + get != low) { //如果插入位置是本身 就不做操作
				a[it + get] = t; //插入值赋值
			}
		}
	}
	
}
int main() {
	vector<int> arr = { 99,55,43,346,243,45,221,55 };
	sorts(arr);
	for (int i: arr) {
		cout << i << ' ';
	}
	return 0;
}
