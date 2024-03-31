#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// subsets
void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans){
    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums, output, index+1, ans);
    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
}
vector<vector<int>> subsets(vector<int>&nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index =0;
    solve(nums,output,index,ans);
    return ans;
}
//subsequences
void solves(string s, vector<int>output, int index, vector<vector<int>>&ans){
    //base case
    if(index >= s.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solves(s, output, index+1, ans);
    //include
    int element = s[index];
    output.push_back(element);
    solves(s, output, index+1, ans);
}
vector<vector<int>> subsequences(string &s){
    vector<vector<int>> ans;
    vector<int> output;
    int index =0;
    solves(s,output,index,ans);
    return ans;
}
// phone keypad
void combinations(string digits, string output, int index, vector<string>& ans, string mapping[]){
    // base case
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    int number = digits[index]-'0';
    string value = mapping[number];
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        combinations(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}
vector<string> lettercombination(string digits){
    vector<string> ans;
    string output="";
    int index=0;
    string mapping[10]={"","","abc","efg","hij","klm","nop","qrs","tuv","wxyz"};
    combinations(digits, output, index, ans, mapping);
    return ans;
}
// permutation of a string
void permutation(vector<string> p, vector<vector<string>>& ans, int index){
    if(index >= p.size()){
        ans.push_back(p);
        return;
    }
    for(int i=index;i<p.size();i++){
        swap(p[i],p[index]);
        permutation(p,ans,index+1);
        //backtrack
        swap(p[i],p[index]);
    }
}
vector<vector<string>> permute(vector<string>& p){
    vector<vector<string>> ans;
    int index=0;
    permutation(p,ans,index);
    return ans;
}
// rat in maze prblm
bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> &m){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1)){
        return true;
    }
    else{
        return false;
    }
}
void ratmaze(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y,vector<vector<int>> visited,string path){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    //down
    int newx = x+1;
    int newy = y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('D');
        ratmaze(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //left
    newx = x;
    newy = y-1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('L');
        ratmaze(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //right
    newx = x;
    newy = y+1;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('R');
        ratmaze(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    } 
    //up
    newx = x-1;
    newy = y;
    if(issafe(newx,newy,n,visited,m)){
        path.push_back('U');
        ratmaze(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    } 
    visited[x][y]=0;
}
vector<string> findpath(vector<vector<int>> &m, int n){
    vector<string> ans;
    if(m[0][0]==0){
        return ans;
    }
    int srcx=0;
    int srcy=0;
    vector<vector<int>> visited=m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    string path="";
    ratmaze(m,n,ans,srcx,srcy,visited,path);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    // subsets
    vector<int> nums{1,2,3};
    vector<vector<int>> ans;
    ans=subsets(nums);
    for(int i=0;i<ans.size();i++){
        cout<<'{';
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<',';
        }cout<<"},";
    }cout<<endl;
    // subsequences
    string s="abc";
    ans=subsequences(s);
    for(int i=0;i<ans.size();i++){
        cout<<'{';
        for(int j=0;j<ans[i].size();j++){
            cout<<char(ans[i][j])<<',';
        }cout<<"},";
    }cout<<endl;
    //phone keypad
    string st ="34";
    vector<string>result;
    result= lettercombination(st);
    for(int i=0;i<result.size();i++){
        cout<<'{'<<result[i]<<'}'<<',';
    }cout<<endl;
    // permutation of string
    vector<string> p{"a","2","c"};
    vector<vector<string>> res;
    res=permute(p);
    for(int i=0;i<res.size();i++){
        cout<<'{';
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<',';
        }cout<<"},";
    }cout<<endl;
    // rat in maze prblm
    int n=4;
    vector<vector<int>> m;
    m={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> path;
    path=findpath(m,n);
    for(int i=0;i<path.size();i++){
        cout<<'{'<<path[i]<<'}'<<',';
    }cout<<endl;
    return 0;
} 

