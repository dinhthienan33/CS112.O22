#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<math.h>
int count=0;
double roundToTenth(double number) {
    return round(number * 10) / 10;
}
bool dot_product(std::vector<double>& arr, std::vector<double>& res, double x){
    double result=0;
    for(int i=0; i<arr.size();i++){
       result+=arr[i]*res[i];
    }
    if(roundToTenth(result)==x){
        return true;
    }
    return false;
}

void solve(int n, std::vector<double>& arr, std::vector<double>& res, double x, int d=0){
    if(d==n){
         if(dot_product(arr,res,x)){
             for (auto i : res) {
                 std::cout << i << ' ';
            }
             count++;
             std::cout << std::endl;
        }
        else
            return;
        
    }
    else{
       for (double i=.25;i<=10;i+=0.25){
        res[d]=i;
        solve(n,arr,res,x,d+1);
    }
}
}
int main(){
    int n;
    std::cin>>n;
    if(n>=10){
        return 0;
    }
    std::vector<double> arr(n);
    std::vector<double> res(n);
    for(int i=0;i<n;i++){
        double temp;
        std::cin>>temp;
        arr[i]=temp/100;
    }
    double x;
    std::cin>>x;
    solve(n,arr,res,x);
   std::cout<<count;
}