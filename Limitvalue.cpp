#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class Limitvalue {
 private:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																						
 T current_value;
 T min_value;
 T max_value;

 public:
 //初始化列表
 Limitvalue(T a,T b, T c) :current_value(std::clamp(a,b,c)), min_value(b), max_value(c) {}
 //+=
 Limitvalue<T> operator+=(T p)
 { 
  current_value =std::clamp(current_value+p,min_value,max_value);
   return *this;

  }
  //-=
 Limitvalue<T> operator-=(T p)
 {
  current_value = std::clamp(current_value-p,min_value,max_value);
   return *this;
     }
  //=
 Limitvalue<T> operator=(T p)
 {
     current_value = std::clamp(p, min_value, max_value);
     return *this;
 }

 //辅助函数
 T val()
 {
     return current_value;
 }
 };


int main() {
 Limitvalue<int> p(1,2,4);
 
 p-=1;
 cout<<"current_value="<<p.val()<<endl;

 p+=5;
 cout<<"current_value="<<p.val()<<endl;

 p=1;
 cout<<"current_value="<<p.val()<<endl;
 

 system ("pause");
  return  0;

}