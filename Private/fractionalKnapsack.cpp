#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct container{
    int  id;
    double volume, cost;
    double ratio;
};

bool compare_asc_ratio(container a, container b){
    return a.ratio < b.ratio;
}


double Mincost(vector<container> items, double W){


    for(int i=0; i<items.size();i++)
        items[i].ratio = items[i].cost/items[i].volume;

    sort(items.begin(), items.end(), compare_asc_ratio);

    double total_cost =0.00;
    double remaining = W;

    for(int i=0; i<items.size();i++){
        if(remaining==0)
            break;

        double take = min(items[i].volume, remaining);
        double fraction = take/items[i].volume;

        total_cost = total_cost + fraction*items[i].cost;
        remaining = remaining - take;



      cout << "Container " << items[i].id
         << ": " << take << " liters\n";
    }
    return total_cost ;
}

int main()
{
   int n;
   double w ;
   cin>> n ;
   cin>> w;
   vector<container>items(n) ;

   for(int i = 0; i < n; i++){
    cin >> items[i].volume >> items[i].cost;
    items[i].id = i + 1;
}

    double result = Mincost(items, w);

    cout << "Minimum Hazard Cost = " << result << endl;
}





