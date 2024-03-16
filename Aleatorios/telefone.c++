#include <bits/stdc++.h>

using namespace std;


int main(){    	
    string t;
    cin >> t;
    
    for (auto i = 0; i < (int) t.size(); i++)
    {
        if(t[i] == 'A' || t[i] == 'B' || t[i] == 'C') {
            t[i] = '2';
        } 
        else if(t[i] == 'D' || t[i] == 'E' || t[i] == 'F') {
            t[i] = '3';
        } 
        else if(t[i] == 'G' || t[i] == 'H' || t[i] == 'I') {
            t[i] = '4';
        } 
        else if(t[i] == 'J' || t[i] == 'K' || t[i] == 'L') {
            t[i] = '5';
        } 
        else if(t[i] == 'M' || t[i] == 'N' || t[i] == 'O') {
            t[i] = '6';
        } 
        else if(t[i] == 'P' || t[i] == 'Q' || t[i] == 'R' || t[i] == 'S') {
            t[i] = '7';
        } 
        else if(t[i] == 'T' || t[i] == 'U' || t[i] == 'V') {
            t[i] = '8';
        } 
        else if(t[i] == 'W' || t[i] == 'X' || t[i] == 'Y' || t[i] == 'Z') {
            t[i] = '9';
        } 
        
    }

    cout << t;
    
	
    return 0;
}
