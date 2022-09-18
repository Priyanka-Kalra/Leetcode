//https://www.youtube.com/watch?v=z_Hy9exZIWU
#include<bits/stdc++.h>
class Solution {
    
    
    int get_days(string s){
        
        int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        string dd="";
        string mm="";
        dd+=s[3];
        dd+=s[4];
        mm+=s[0];
        mm+=s[1];
        
        int days_till_date=0,d,m;
        d=stoi(dd);
        m=stoi(mm);
        for(int i=0;i<m-1;i++)days_till_date+=days[i];
        
        days_till_date+=d;
        return days_till_date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int a1=get_days(arriveAlice);
        int a2=get_days(arriveBob);
        int l1=get_days(leaveAlice);
        int l2=get_days(leaveBob);
        
        int ans=min(l2,l1)-max(a1,a2);
        
        if(ans<0)return 0;
        return ans+1;
        
    }
};