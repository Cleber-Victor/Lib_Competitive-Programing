#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

#define N 8
#define MAXINT 2147483648

bool safe (vector<int> &row_elements,int linha, int coluna, int a,int b){

  if ( linha == a){
    if(coluna != b){
      return false;
    }
  }

  for (int i =0; i < linha-1; i++){
    int diff = row_elements[i] - row_elements[linha-1];
    if( diff == 0 || diff == linha -1 -i || -diff ==linha -1 -i ){
      return false;
    }
  }
  int diff = row_elements[a-1] - row_elements[linha-1];
      if( diff == 0 || diff == linha -a || -diff ==linha -a ){
      if (a != linha){
        return false;
      }
      
    }

  return true;

}

void solve (int linha, int a,int b, vector<int> &row_elements,vector<vector<int>>& results ){
  if (linha == 9){
    results.push_back(row_elements);
  }else{
    for (int i =1; i <=N; i++){
      row_elements[linha-1] = i;      
      if(safe(row_elements,linha,i,a,b)){
        solve(linha+1,a,b,row_elements,results);
      }
      row_elements[linha-1] = MAXINT;
    
    }
  }
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int tests; cin >> tests;
  while(tests--){
    cout << "SOLN       COLUMN" <<'\n';
    cout << " #      1 2 3 4 5 6 7 8" <<'\n';
    cout <<'\n';
    int linha,coluna;
    cin >> linha >> coluna;
    int x;
    vector <vector<int>> table(N,vector<int>(N,0));
    vector<int> row_elements(8);
    vector<vector<int>>results;
    vector<int>colum(8);
    for (int i =0; i <N;i++){
      row_elements[i] = MAXINT;
    }
    row_elements[linha-1] = coluna;

    solve(1,linha,coluna,row_elements,results);
    //reverse(results.begin(),results.end());
    vector <vector<int>> saida(results.size(),vector<int>(N,0));
    //ajeitar
    for (int i = 0; i < results.size();i++){
      for(int j = 0; j < results[i].size();j++){
        saida[i][results[i][j]-1] = j+1;
      }
    }
    sort(saida.begin(),saida.end());
    for (int i = 1; i <= saida.size();i++){
      if(10 > i){
        cout << " ";
      }
      cout << i << "      ";
      for(int j =0; j<saida[i-1].size(); j++){
        cout << saida[i-1][j];
        if (j !=saida[i-1].size()-1){
          cout << " ";
        }
      }
      cout <<'\n';
    }
    
  if(tests !=0){
    cout <<'\n';
  }
  

  }


  return 0;
}