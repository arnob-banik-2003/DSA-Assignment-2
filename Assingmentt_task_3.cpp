
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ChocolatePacket{
int id;
int chocolate;


};
bool compare_asc_finish(ChocolatePacket a,ChocolatePacket b){
    return a.chocolate<b.chocolate;
}

int Distrubution(vector<ChocolatePacket>item,int n,int m){
         sort(item.begin(),item.end(),compare_asc_finish) ;

         int min=item[m-1].chocolate-item[0].chocolate;

         for(int i=1;i<n-m;i++){
         int diff=item[i+m-1].chocolate-item[i].chocolate;

         if(diff<min)
            min=diff;

         }


return min;

}

int main(){
int n,m;
cin>>n>>m;

vector<ChocolatePacket>item(n);

for(int i=0;i<n;i++){
    cin>>item[i].chocolate;
    item[i].id=i+1;
}

int result=Distrubution(item,n,m);
cout<<result<<endl;
return 0;



}
