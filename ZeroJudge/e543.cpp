#include<stdio.h>
#include<string.h>

char s[30] , map[256];

signed main(){
    map['A'] = 'A';
    map['E'] = '3';
    map['H'] = 'H';
    map['I'] = 'I';
    map['L'] = 'J';
    map['J'] = 'L';
    map['M'] = 'M';
    map['O'] = 'O';
    map['S'] = '2';
    map['T'] = 'T';
    map['U'] = 'U';
    map['V'] = 'V';
    map['W'] = 'W';
    map['X'] = 'X';
    map['Y'] = 'Y';
    map['Z'] = '5';
    map['0'] = '0';
    map['1'] = '1';
    map['2'] = '2';
    map['2'] = 'S';
    map['3'] = 'E';
    map['5'] = 'Z';
    map['8'] = '8';
    while(scanf("%s" , s) != EOF){
        int l=0 , r = strlen(s)-1;
        bool is_palindrome = true;
        bool is_mirrored = true;
        while(l <= r){
            if(s[l] != s[r]) is_palindrome = false;
            if(s[l] != map[s[r]]) is_mirrored = false;
            l++,r--;
        }
        if(is_mirrored && is_palindrome) printf("%s -- is a mirrored palindrome.\n",s);
        else if(is_mirrored) printf("%s -- is a mirrored string.\n" , s);
        else if(is_palindrome) printf("%s -- is a regular palindrome.\n" , s);
        else printf("%s -- is not a palindrome.\n",s);

        puts("");
    }
    
}