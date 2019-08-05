#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input_c;
int input_result_c;
int input_temp;

vector <int> input_v;
vector <pair<int, int>> input_v_count;

int go(vector<pair<int, int>> &vv, int num, int l, int r) {
	int ret = 0;
	int mid = (l + r) / 2;

	if (l > r) return 0;
	if (vv[mid].first == num) return vv[mid].second;

	if (num < vv[mid].first) ret = go(vv, num, l, mid - 1);
	else if (num > vv[mid].first) ret = go(vv, num, mid + 1, r);

	return ret;
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> input_c;
	for (int i = 0; i < input_c; i++){
		cin >> input_temp;
		input_v.push_back(input_temp);
	}

	sort(input_v.begin(), input_v.end());

	int temp = input_v[0];
	int index = 0;
	input_v_count.push_back(make_pair(temp, 1));

	//input count
	for (int i = 1; i < input_c; i++){
		temp = input_v[i - 1];
		if (input_v[i] == temp){
			input_v_count[index].second++;
		}
		else{
			input_v_count.push_back(make_pair(input_v[i], 1));
			index++;
		}
	}

	//find each number's count
	cin >> input_result_c;
	for (int i = 0; i < input_result_c; i++){
		cin >> input_temp;
		cout << go(input_v_count, input_temp, 0, input_v_count.size() - 1) << " ";
	}

	return 0;
}