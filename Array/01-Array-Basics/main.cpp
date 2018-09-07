#include <iostream>
using namespace std;

int main(){
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (int j = 0; j < 10; ++j)
    {
        cout << arr[j] << endl;
    }
    int scores[] = {100, 99, 66};
    for (int k = 0; k < sizeof(scores) / sizeof(int); k++)
    {
        cout << scores[k] << " ";
    }

    cout << endl;

    for (int score : scores)
    {
        cout << score << " ";
    }

    cout << endl;

    scores[0] = 98;
    for (int l = 0; l < sizeof(scores) / sizeof(int); l++)
    {
        cout << scores[l] << " ";
    }


    system("pause");
    return 0;

}