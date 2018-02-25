#include <bits/stdc++.h>
using namespace std;
string toBinary(int n);
int main()
{
    ofstream bits;
    bits.open("bits.txt");
    bits.clear();
    string s, txtfilename = "list.txt";
    int lines=0,cnt = 0;
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
        lines ++;
    }
    //in.clear();
    in.seekg(0, ios::beg);
    string myArray[lines];
    while(!in.eof())
    {
        getline(in, s);
        myArray[cnt] = s;
        cnt++;
    }
    in.close(); // I finished dealing with it
    string name = "",binstr = "";
    int total_length = 0;
    for(int x = 0; x < lines; ++x)
    {
        name = myArray[x];
        total_length += name.size();
        for (std::size_t i = 0; i < name.size(); ++i)
        {
            bitset<8>c(name[i]);
            binstr += c.to_string();
        }
    }
    //binstr = "01000000000000000000000000000000000000000011";
    int zeros =0, ones = 0,most=0,length = binstr.length(),bits_length = 0;
    char les;
    for (int k=0; k< length; ++k)
    {
        if (binstr[k] =='1') ones++;
        else zeros ++;
    }
    if (zeros > ones ) les = '1';
    else les = '0';
    cout<<"less repeated number is "<<les<<endl;
    for (int k=0; k<length; ++k)
    {
        if (binstr[k] == les)
        {
            while (most > 15)
            {
                bits<<toBinary(15);
                bits_length +=4;
                most -=15;
            }
            if (most > 0)
            {
                bits<<toBinary(most);
                bits_length +=4;
            }
            else
            {
                bits<<toBinary(0);
                bits_length +=4;
            }
            most = 0;
        }
        else most++;
    }
    while (most > 15)
    {
        bits<<toBinary(15);
        bits_length +=4;
        most -=15;
    }
    if (most > 0)
    {
        bits<<toBinary(most);
        bits_length +=4;
    }
    else
    {
        bits<<toBinary(0);
        bits_length +=4;
    }
    cout<<endl;
    cout <<binstr.length()<<endl;
    cout << bits_length <<endl;
    cout << 1.0 * bits_length/binstr.length();
    bits.close();
    return 0;
}

string toBinary(int n)
{
    string r;
    while(n!=0)
    {
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    while (r.length() < 4)
        r = "0"+r;
    return r;
}
