#include <bits/stdc++.h>
using namespace std;
int todecimal(string b);

void showqueue(queue <int> gq)
{
    cout <<"the queue is : ";
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << g.front()<< '\t' ;
        g.pop();
    }
    cout << '\n';
}

int main()
{
    string s,bits,txtfilename = "../Name list compression/bits.txt";
    ifstream in;
    in.open(txtfilename);
    if(!in)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }
    while(!in.eof())
    {
        getline(in, s);
        bits += s;
        //lines ++;
    }
    int length =bits.length()/4;

    string most,arr[length];
    int sndarr[length];
    queue <int> numbers;
    int index=0;
    for (int c=0; c<length*4; c=c+4)
    {
        most= bits[c  ];
        most+=bits[c+1];
        most+=bits[c+2];
        most+=bits[c+3];
        arr[index]=most;
        index++;
    }
    for (int i=0; i<length; i++)
    {
        sndarr[i] = todecimal(arr[i]);
    }int temp=0;

    for (int i=0; i<length; i++)
    {
        temp+=sndarr[i];

        if (sndarr[i]==15)
        {
            continue;
        }
        numbers.push( temp);
        temp=0;
    }
    //showqueue(numbers);
    int looper;
    string binstr;
    while (!numbers.empty())
    {
        looper = numbers.front();
        for (int z=0;z<looper;z++)
        {
            binstr += '0';
        }
        numbers.pop();
        binstr += '1';
    }
cout<<binstr;



    return 0;
}

int todecimal(string b)
{
    int d= 0;
    for (int i=0; i<4; i++)
    {
        if(b[i] == '1') d+= pow(2,3-i);
    }
    return d;
}
