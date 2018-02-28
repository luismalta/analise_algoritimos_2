#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, p, req,max;
  string ent, aux;
  float preco;

  while(scanf("%d %d", &n, &p) != EOF){
    max = 0;
    while(p--){

      pair<string,float> win;
      vector<string>v;
      win = make_pair("",10000000);
      /*
      for(int i = 0; i < n; i++){
        scanf("%s", ent);
        v.push_back(ent);
      }
      */

      for(int i = 0; i < n; i++){
        scanf("%s", &ent);
        scanf("%f %d", &preco, &req);

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

      printf("%s", win.first);


    }
  }
}
