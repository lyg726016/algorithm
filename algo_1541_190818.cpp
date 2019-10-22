#include <iostream>
#include <string>

using namespace std;

int front_sum = 0;
int back_sum = 0;
string input_s;
string s_temp;
int i_temp;
bool is_first_minus = true;
bool is_first_plus = true;

int main(){

	cin >> input_s;

	for (int i = 0; i < input_s.length(); i++){
		//���� ���
		if (input_s[i] >= '0' && input_s[i] <= '9'){
			s_temp += input_s[i];
		}
		//��ȣ�� ���� ��, �ڿ� ����
		else if (input_s[i] == '-'){
			if (is_first_minus){
				is_first_minus = false;
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
		//��ȣ�� ���� ��, �ڿ� ����
		else{
			if (is_first_minus){
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
		//������ ���� -> ��ȣ�� ���� ��, �ڿ� ����
		if (i == input_s.length() - 1){
			if (is_first_minus){
				front_sum += stoi(s_temp);
				s_temp = "";
			}
			else{
				back_sum += stoi(s_temp);
				s_temp = "";
			}
		}
	}

	cout << front_sum - back_sum << '\n';

	return 0;
}