#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
    string name ;
    int id, start, finish;
};

bool compare_asc_finish(Activity a, Activity b){
    return a.finish<b.finish;
}

vector<Activity> ActivitySelection(vector<Activity> scheduled){

    sort(scheduled.begin(), scheduled.end(),compare_asc_finish);


    vector<Activity> selected;
    selected.push_back(scheduled[0]);
    int last_finish = scheduled[0].finish;


    for(int i=1; i<scheduled.size();i++){
        if(scheduled[i].start>=last_finish){
            selected.push_back(scheduled[i]);
            last_finish = scheduled[i].finish;
        }
    }


    return selected;
}

int main(){

     int n;
    cin >> n;

    vector<Activity> scheduled(n);

    for(int i = 0; i < n; i++){
        cin >> scheduled[i].name >> scheduled[i].start >> scheduled[i].finish;
    }

    vector<Activity> selected = ActivitySelection(scheduled);

    cout << "Maximum Workshops = " << selected.size() << endl;
    cout << "Selected: ";

    for(int i = 0; i < selected.size(); i++){
        cout << selected[i].name;
        if(i != selected.size()-1)
            cout << ", ";
    }
}

