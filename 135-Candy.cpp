#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	int rating; // rating值
	int index; // 原始的位置index
};

bool myfunc(Node a, Node b){
	return (a.rating < b.rating);
}

class Solution {
public:
	int candy(vector<int> &ratings) {
		int N = ratings.size();
		vector<int> result(N, 0); // 初始化所有的元素为0
		// 对所有的rating排序
		vector<Node> sorted_ratings(N);
		int i;
		for (i = 0; i < N; ++i){
			sorted_ratings[i].index = i;
			sorted_ratings[i].rating = ratings[i];
		}
		sort(sorted_ratings.begin(), sorted_ratings.end(), myfunc);

		// 处理最小的rating
		int lowest_rating = sorted_ratings[0].rating;
		i = 0;
		while (i<N && sorted_ratings[i].rating == lowest_rating){
			result[sorted_ratings[i].index] = 1;
			++i;
		}
		
		int curr_rating = 0;
		if (i < N){
			curr_rating = sorted_ratings[i].rating;
		}
		else{
			return N; // 只有一个rating值，所以每个都是1个糖果
		}
		// 现在 i 指向的正是第二个不同rating值的位置
		while(true){
			int index = sorted_ratings[i].index;
			if (sorted_ratings[i].rating == curr_rating){
				result[index] = get_candy_num(index, result, ratings);
				++i;
			}
			else{
				curr_rating = sorted_ratings[i].rating; // new rating value
			}

			if (i >= N)
				break;
		}

		int sum = 0;
		for (int i = 0; i < N; ++i){
			sum += result[i];
		}

		return sum;
	}

	int get_candy_num(int pos, vector<int>& result, vector<int>& ratings){
		//check result list and find a larger value of left and right
		int left, right;

		if (pos <= 0)
			left = 1;
		else
		if (ratings[pos] > ratings[pos - 1])
			left = result[pos - 1] + 1;
		else
			left = 1;

		if (pos >= result.size() - 1)
			right = 1;
		else
		if (ratings[pos] > ratings[pos + 1])
			right = result[pos + 1] + 1;
		else
			right = 1;

		// max(left, right) + 1
		int v = left >= right ? left:right;
		return v;
	}
};

int main(){
	Solution s;
	vector<int> ratings({1,2,2});
	cout << s.candy(ratings) << endl;
	return 1;
}
