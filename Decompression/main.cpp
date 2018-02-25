#include <bits/stdc++.h>
using namespace std;
int todecimal(string b,int length);

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

char convert(string letter)
{
    string data = letter;
    stringstream sstream(data);
    char output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
    return output;
}

void showqueuestring(queue <string> gq)
{
    cout <<"the queue is : ";
    queue <string> g = gq;
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

    string reno,arr[length];
    int sndarr[length];
    queue <int> numbers;
    int index=0;
    for (int c=0; c<length*4; c=c+4)
    {
        reno= bits[c  ];
        reno+=bits[c+1];
        reno+=bits[c+2];
        reno+=bits[c+3];
        arr[index]=reno;
        index++;
    }
    for (int i=0; i<length; i++)
    {
        sndarr[i] = todecimal(arr[i],4);
    }
    int temp=0;

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
    char les='1', most='0';
    while (!numbers.empty())
    {
        looper = numbers.front();
        for (int z=0; z<looper; z++)
            binstr += most;
        binstr += les;
        numbers.pop();
    }
    binstr.pop_back();
    //cout<<binstr;
    string letter;
    char chart;
    queue <string> letters;
    for (int i=0; i<binstr.length(); i+=8)
    {
        letter="";
        for(int j=0; j<8;j++)
        {
            letter+=binstr[i+j];
        }
        letters.push(letter);
    }
    queue <char> chars;
    showqueuestring (letters);
    while (!letters.empty())
    {
        chars.push(convert(letters.front()));
        letters.pop();
    }
    queue <string> words;
    string word;
    char c;
    while (!chars.empty())
    {
        word=chars.front();
        c = chars.front();
        if (isupper(c))
        words.push(word);
        else
        word+=chars.front();
        chars.pop();
    }
    showqueuestring (words);
    cout <<"finished"<<endl;
    return 0;
}

int todecimal(string b,int length)
{
    int d= 0;
    for (int i=0; i<length; i++)
    {
        if(b[i] == '1') d+= pow(2,length-1-i);
    }
    return d;
}
