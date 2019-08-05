#include <iostream>
#include <queue>

using namespace std;

queue <int> card_deck;
int input_n;
int temp;
int count_n = 1;

int main(){
	cin >> input_n;

	for (int i = 1; i <= input_n; i++){
		card_deck.push(i);
	}

	while (card_deck.size() != 1){
		if (count_n % 2 == 1)
		{
			card_deck.pop();
			count_n++;
		}
		else {
			temp = card_deck.front();
			card_deck.pop();
			card_deck.push(temp);
			count_n++;
		}
	}

	cout << card_deck.front();

	return 0;
}