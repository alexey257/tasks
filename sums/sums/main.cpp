#include <iostream>

using namespace std;


int make_sum(int* mas, int max_idx, char* my_string, int num)
{
    int int_length = 0;

    while(num) //fill new string
    {
        my_string[int_length] = mas[max_idx] + 0x30;
        num -= mas[max_idx];
        max_idx--;
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
    while(sum <= num)
    {
        sum = 0;
        if(i) enum_combs(mas, (i-1), num, my_string);
        mas[i]++;
        int j = 0;
        while(sum < num)
        {
            sum += mas[j];
            j++;
        }
        //}
        if((sum <= num)&&(mas[i] < num)) make_sum(mas, (j-1), my_string, num);
        //sum = 0;
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
    make_sum(mas, num-1, my_string, num);
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
