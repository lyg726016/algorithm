#include <iostream>

using namespace std;

int M;
int N;

#define MAX_CARD 101

int card[MAX_CARD];

int main()
{
    //N장의 카드
    cin >> N;
    //M에 가깝게
    cin >> M;
    
    
    for(int i = 0; i < N; i++){
        cin >> card[i];
    }
    
    //최대 100C3 중 M에 제일 가까운 카드 3개의 합 출력
    int temp = 0;
    int max = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k =j +1; k < N; k++){
                temp = card[i] + card[j] + card[k];
                if(temp >= max && M >= temp){
                    max = temp;
                }
                
                if(max == M){
                    cout << max;
                    return 0;   
                }
            }
        }
    }
    cout << max;
    return 0;
}