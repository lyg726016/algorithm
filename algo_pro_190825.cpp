#include <string>
#include <vector>

using namespace std;

int i;
int count_possible = 0;
string currunet_st;
int current_kill_number = 0;
string s_skill;
int currnet_n;
bool is_ok = true;

bool is_pissilbe(char current_c){
	if (s_skill.at(currnet_n) == current_c)
	{
		currnet_n++;
		return true;
	}
	else{
		if (currnet_n >= s_skill.length()){
			return true;
		}
		else{
			for (int i = currnet_n + 1; i < s_skill.length(); i++){
				if (s_skill.at(i) == current_c){
					return false;
				}
			}
		}
		return true;
	}
}


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	s_skill = skill;
	for (int i = 0; i < skill_trees.size(); i++){
		currnet_n = 0;
		is_ok = true;
		currunet_st = skill_trees[i];
		for (int k = 0; k < currunet_st.length(); k++){
			if (!is_pissilbe(currunet_st.at(k))){
				is_ok = false;
				break;
			}
		}
		if (is_ok){
			answer++;
		}
	}
	return answer;
}

int main(){
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");
	cout << solution("CDE", skill_trees);

	return 0;
}