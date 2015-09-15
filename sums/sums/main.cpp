#include <iostream>

using namespace std;


int make_sum(int* mas, char* my_string, int num)
{
    //int length = 0;
    int int_length = 0;
    while(num) //fill new string
    {
        my_string[int_length] = mas[int_length] + 0x30;
        num -= mas[int_length];
        int_length++;
    }
    my_string[int_length] = '\0';
    cout << my_string << endl;
    //cout << endl;
    return int_length;
}

void enum_combs(int mas[], int i, int num, char* my_string)
{
    //int ln = 0;
    int sum = 0;
    while(sum < num)
    {
        make_sum(mas, my_string, num);
        if(i) enum_combs(mas, (i-1), num, my_string);
        mas[i]++;
        for(int j = 0; j <= i; j++)
        {
            sum += mas[j];
        }
    }
    mas[i] = 1;
    //mas[i++]++;

}

void number_parse(const int num)
{
    int mas[num];
    char my_string[num];
    for(int i = 0; i < num; i++)
    {
        mas[i] = 1; //fill with ones
    }
    //int sum = 0;
    enum_combs(mas, num-1, num, my_string);
}





int main()
{
    int number; //number to parse


    cout << "Hello world!" << endl;
    cin >> number;
    number_parse(number);
    return 0;
}
