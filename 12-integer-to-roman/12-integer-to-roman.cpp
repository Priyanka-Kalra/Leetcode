class Solution {
public:
    string intToRoman(int num) {
        
        vector< pair<string,int> > val;
        val.push_back({"I",1});
        val.push_back({"IV",4});
        val.push_back({"V",5});
        val.push_back({"IX",9});
        val.push_back({"X",10});
        val.push_back({"XL",40});
        val.push_back({"L",50});
        val.push_back({"XC",90});
        val.push_back({"C",100});
        val.push_back({"CD",400});
        val.push_back({"D",500});
        val.push_back({"CM",900});
        val.push_back({"M",1000});
        
        
        string ans="";
        int n=val.size()-1;
        while(num>0){
            int c=num/val[n].second;
            while(c>0){
                ans+=val[n].first;
                c--;
            }
            num=num%val[n].second;
            n--;
            
        }
        return ans;
    }
};
