#include <iostream>
using namespace std;

int main() {
 string text;
 string t[100][100];
 string c[100][100];
 string r[100][100];
 int count[100];
 int col = 0;
 int max = -1;
 for(int i = 0;i < 100;i++){
  for(int j = 0;j < 100;j++){
   t[i][j] = " ";
   c[i][j] = " ";
   r[i][j] = " ";
  }
 }
 //每次先處理一行句子
 while(getline(cin, text)){
  count[col] = text.size();
  if(count[col] > max){
   max = count[col];
  }
  for(int i = 0;i < text.size();i++){
   t[col][i] = text[i];
  }
  col++;
 }
 for(int i = 0;i < col;i++){
  for(int j = 0;j < max;j++){
   c[j][i] = t[i][j];
  }
 }
 for(int j = 0;j < max;j++){
  int cc = col-1;
  for(int i = 0;i < col;i++){
   r[j][cc] = c[j][i];
   cc--;
  }
 }
 
 //輸出陣列r
 for(int j = 0;j < max;j++)
 {
  for(int i = 0;i < col;i++)
  {
   if(i != 0)
   {
    cout << r[j][i];
   }
   else
   {
    cout << r[j][i];
   }
  }
  cout << endl;
 }
 return 0;
}