#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<fstream>

using namespace std;



struct state{
  state(int i){
    id=i;
  }
  int id;
  map<char,vector<int> > next;
};

void getClosure(state* current,vector<state*> states , vector<int> &res){
      res.push_back(current->id);

      for(auto itr: current->next){
          if(itr.first == 'E'){
            for(auto id : itr.second)
              getClosure(states[id],states,res);
          }

      }
}
int main(){
  ifstream infile("input.txt");


  int N,from,to;
  char usingSymbol;
  infile>>N;
  vector<state *> states(N) ;

  for(int i=0;i<N;i++){
    states[i] = new state(i);

  }

  while(infile){
        infile>>from;
        infile>>usingSymbol;
        infile>>to;
        states[from]->next[usingSymbol].push_back(to);
  }
  for(int i=0;i<N;i++){
    vector<int> res;
    getClosure(states[i],states,res);
    cout<<endl<<"Epsilon Closure"<<endl;
    for(auto itr : res)
        cout<<itr<<" ";
  }

}
