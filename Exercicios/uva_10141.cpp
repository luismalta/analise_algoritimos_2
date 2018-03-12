#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, p, req,max,coou=1;
  char ent[100], aux[100],sai[100];
  float preco;

  while(scanf("%d %d", &n, &p) != EOF){
    max = 0;
    if(n != 0){

      pair<string,float> win;
      vector<string>v;
      win = make_pair("",10000000);
      
      for(int i = 0; i < n; i++){
      	//printf("teste");
      	cin >> sai;
      }
      

      for(int i = 0; i < p; i++){

      	scanf("%s", ent);
        scanf("%f %d", &preco, &req);
        
        for(int i = 0; i < req; i++){
        //printf("vai de rewq");
        cin >> sai;
      	}

        if(req > max){
          max = req;
          win = make_pair(ent,preco);
        } else {
          if(req == max){
            if(win.second > preco){
              max = req;
              win = make_pair(ent,preco);
            }
          }
        }
      }

      cout << "RFP #"<< coou++ << endl;
      cout << win.first << endl;
      printf("\n");


    }
  }
}
