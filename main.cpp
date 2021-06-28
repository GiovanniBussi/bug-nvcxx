#include <array>
#include <iostream>
#include <cmath>

int main() {
  std::array<std::array<double,3>,3> v;
  v[0][0]=10.0;
  v[0][1]=0.0;
  v[0][2]=10.0;
  v[1][0]=10.0;
  v[1][1]=10.0;
  v[1][2]=0.0;
  v[2][0]=0.0;
  v[2][1]=10.0;
  v[2][2]=10.0;

  int x1min=std::floor(-0.5);
  int x1max=x1min+1;
  int x2min=std::floor(-0.5);
  int x2max=x2min+1;
  bool first=true;
  double mbest,mtrial;
  std::array<double,3> best;
  std::array<double,3> trial;
  best[0]=best[1]=best[2]=0.0;
  trial[0]=trial[1]=trial[2]=0.0;
  for(int x1=x1min; x1<=x1max; x1++) {
    for(int x2=x2min; x2<=x2max; x2++) {
      trial[0]=v[2][0]+x2*v[1][0]+x1*v[0][0];
      trial[1]=v[2][1]+x2*v[1][1]+x1*v[0][1];
      trial[2]=v[2][2]+x2*v[1][2]+x1*v[0][2];
      mtrial=trial[0]*trial[0]+trial[1]*trial[1]+trial[2]*trial[2];
      if(first || mtrial<mbest) {
        mbest=mtrial;
        best[0]=trial[0];
        best[1]=trial[1];
        best[2]=trial[2];
        first=false;
      }
    }
  }
  std::cout<<"0 0 0 would be an error:\n";
  std::cout<<best[0]<<" "<<best[1]<<" "<<best[2]<<"\n";

  return 0;
}

