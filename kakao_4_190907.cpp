#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int q_s = queries.size();
	int w_s = words.size();
	int f_count = 0;

	for (int i = 0; i < q_s; i++) {
		f_count = 0;
		for (int j = 0; j < w_s; j++) {

			string word = words[j];
			string query = queries[i];

			int min_t = 100001;
			int max_t = 0;
			int temp;

			string r_q = "";
			//? ½ÃÀÛ ³¡
			for (int k = 0; k < query.length(); k++) {
				if (query[k] == '?') {
					temp = i;

					if (temp > max_t) {
						max_t = temp;
					}
					if (temp < min_t) {
						min_t = temp;
					}
				}
				else {
					r_q += query[k];
				}
			}

			if (word.find(r_q) > min_t && word.find(r_q) < max_t) {

				f_count++;
			}
		}
		answer.push_back(f_count);
	}



	return answer;
}