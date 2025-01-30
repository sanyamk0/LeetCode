class Solution {
public:
    string reorganizeString(string s) {
      int n=s.length() ;
      unordered_map<char,int>mp;
      int mfreq=0;
      char mchar;
      for(char c:s){
        mp[c]++;
        if(mp[c]>mfreq){
            mfreq=mp[c];
            mchar=c;
        }
      }
      if(mfreq>(s.length()+1)/2)
        return "";
      string res(s.length(),'\0');
      int i=0;
      while(mp[mchar]-- > 0){
        res[i]=mchar;
        i+=2;
      }
      for( auto it:mp){
        while(it.second-- > 0){
            if(i>=res.length())i=1;
            res[i]=it.first;
            i+=2;
        }
      }
      return res;

    //   for(auto )
    }
};