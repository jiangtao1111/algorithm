//
// Created by 19281 on 2022/11/10.
//

#include"Algorithm.h"
#include<vector>
#include<algorithm>
#include<map>
#include <unordered_map>
#include <stack>

using namespace std;
Algorithm::Algorithm()
{

}
Algorithm::~Algorithm()
{

}

void twoSum()
{
    
}
void Algorithm::SimpleDemo()
{
    cout<<"This is first Algorithm"<<endl;

}
string Algorithm::convert(string s,int numRows)
{
    int n =s.length(), r=numRows;//r是行数
    if(r==1 ||n<=r){
        return s;
    }
    int t= 2*r-2;//一个周期
    int c=(n/t+1)*(r-1);//;列数
    vector<string> mat(r,string(c,0));
    for(int i=0,x=0,y=0;i<n;i++)
    {
        mat[x][y]=s[i];
        if(i%t<r-1)
            x++;
        else
        {x--;
            y++;
        }

    }
    string ans;
    for(auto &row :mat)
        for(char ch:row)
        {
            if(ch){
                ans +=ch;
            }
        }
    return ans;

}
int Algorithm::reverse(int x)
{
    long long int res = 0;
    while(x)
    {
       res *=10;
       res +=x % 10;
       x/10;
       if(res<INT_MIN||res>INT_MAX){
       return 0;
       break;}
    }
    return res;
}
int Algorithm::myAtoi(string s)
{
    int i= 0;
    while(' '==s[i]) i++;
    if(i==s.size()) return 0;
    bool is_minus =false;
    if('-'==s[i]) {
        is_minus = true;
        i++;
    }
    else if ('+'==s[i])
    {
        i++;
    }
//    long long ans = 0;// 题设要求用int存数据，需要修改方式
//    while(s[i]>='0'&&s[i]<='9'&&i<s.size())
//    {
//        ans=ans*10+s[i++]-'0';
//        if(ans>INT_MAX) break;
//    }
//    if(is_minus)ans*=-1;
//    if(ans>=INT_MAX) return INT_MAX;
//    if(ans<=INT_MIN) return INT_MIN;
//    return ans;

    int ans = 0;
    while (s[i]>='0'&&s[i]<='9'&&i<s.size())
     {
        int x= s[i++]-'0';
        if(!is_minus&&ans*10+x>INT_MAX) return INT_MAX;
        if(is_minus&&ans*10+x>-INT_MIN) return INT_MIN;
        if(ans*10+x==-INT_MIN) return INT_MIN;//特判INT_MIN
        ans=ans*10+x;
     }
    if(is_minus)ans*=-1;
     return ans;
}
bool Algorithm::isPalindrome(int x)
{
    if(x<=0)
        return false;
    int sum=0;
    for(int i =x;i;i/=10)
    {
        int temp = i%10;
        sum =sum *10+temp;
    }
    if(sum==x)
        return true;
    else
        return false;
}
int Algorithm::maxArea(vector<int>& height)//暴力解法 消耗内存以及运行时间
{
    int max=0;
    for(int i=0;i<height.size();i++)
    {
        for(int j=i;j<height.size();j++)
        {
            if( height[i]<height[j])
            {
                if(max < height[i]*(j-i)) {
                    max = height[i] * (j - i);
                }
            }
            else
            {
                if( max < height[j]*(j-i)) {
                    max = height[j] * (j - i);
                }
            }
        }

    }
    return max;
}
int Algorithm::maxArea2(vector<int>& height)
{
    int rec =0;
    int i= 0,j=height.size()-1;
    while(i<j)
    {
        if(min(height[i],height[j])*abs(i-j)>rec)
            rec=min(height[i],height[j])*abs(i-j);
        if(height[i]<height[j])
            i++;
        else
            j--;
    }
    return rec;

}
int Algorithm::romanToInt(string s)
{
int value=0;
for(int i =0;i<s.length();i++)
{
if(s[i]=='C'&&s[i+1]=='M')
{value+=900;i++;continue;}
else if(s[i]=='M')
{value+=1000;continue;}
else if(s[i]=='C'&&s[i+1]=='D')
{value+=400;i++;continue;}
else if(s[i]=='D')
{value+=500;continue;}
else if(s[i]=='X'&&s[i+1]=='C')
{value+=90;i++;continue;}
else if(s[i]=='C')
{value+=100;continue;}
else if(s[i]=='X'&&s[i+1]=='L')
{value+=40;i++;continue;}
else if(s[i]=='L')
{value+=50;continue;}
else if(s[i]=='I'&&s[i+1]=='X')
{value+=9;i++;continue;}
else if(s[i]=='X')
{value+=10;continue;}
else if(s[i]=='I'&&s[i+1]=='V')
{value+=4;i++;continue;}
else if(s[i]=='V')
{value+=5;continue;}
else
value +=1;
}
return value;
}
string Algorithm::longestCommonPrefix(vector<std::string> &strs) //利用二分查找法最长公共前缀
{
//    if(!strs.size())
//        rerurn "";
//    //int minLength =min_element()
//    int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
    if(strs.empty()) return string();
    sort(strs.begin(), strs.end());
    string st = strs.front(), en = strs.back();
    int i, num = min(st.size(), en.size());
    for(i = 0; i < num && st[i] == en[i]; i ++);
    return string(st, 0, i);

}
int Algorithm::threeSumClosest(vector<int> &nums, int target) {
//    sort(nums.begin(), nums.end());
//    int n = nums.size();
//    int best = 1e7;
//
//    // 根据差值的绝对值来更新答案
//    auto update = [&](int cur) {
//        if (abs(cur - target) < abs(best - target)) {
//            best = cur;
//        }
//    };
//
//    // 枚举 a
//    for (int i = 0; i < n; ++i) {
//        // 保证和上一次枚举的元素不相等
//        if (i > 0 && nums[i] == nums[i - 1]) {
//            continue;
//        }
//        // 使用双指针枚举 b 和 c
//        int j = i + 1, k = n - 1;
//        while (j < k) {
//            int sum = nums[i] + nums[j] + nums[k];
//            // 如果和为 target 直接返回答案
//            if (sum == target) {
//                return target;
//            }
//            update(sum);
//            if (sum > target) {
//                // 如果和大于 target，移动 c 对应的指针
//                int k0 = k - 1;
//                // 移动到下一个不相等的元素
//                while (j < k0 && nums[k0] == nums[k]) {
//                    --k0;
//                }
//                k = k0;
//            } else {
//                // 如果和小于 target，移动 b 对应的指针
//                int j0 = j + 1;
//                // 移动到下一个不相等的元素
//                while (j0 < k && nums[j0] == nums[j]) {
//                    ++j0;
//                }
//                j = j0;
//            }
//        }
//
//    }
//    return best;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int res=1e7;
    int dis=abs(nums[0]+nums[1]+nums[2]-target);
    for(int i =0;i<n;i++)
    {
        int front =i+1;
        int end=n-1;
        while(front<end)
        {
            if (abs(nums[i]+nums[front]+nums[end]-target)<dis)
            {
                dis=abs(nums[i]+nums[front]+nums[end]-target);
                res=nums[i]+nums[front]+nums[end];
            }
            if (nums[i]+nums[front]+nums[end]==target)
            {
                res=nums[i]+nums[front]+nums[end];
                break;
            }
            else if(nums[i]+nums[front]+nums[end]<target)
            {
                front++;
            }
            else
            {
                end--;
            }

        }

    }
    return res;
}
void backtrack(vector<string>&combinations,const unordered_map<char,string> &phonemap,const string& digits,int index, string& combination)
//这是一个递归函数。需要好好理解
{
    if(index==digits.length())
    {
        combinations.push_back(combination);
    }
    else
    {
        char digit=digits[index];
        const string& litters=phonemap.at(digit);
        for(const char& litter:litters)
        {
            combination.push_back(litter);
            backtrack(combinations,phonemap,digits,index+1,combination);
            combination.pop_back();
        }
    }
}
vector<string> Algorithm::letterCombinations(std::string digits) {
    vector<string> combinations;
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    string combination;
    backtrack(combinations,phoneMap,digits,0,combination);
    return combinations;
}
bool Algorithm::isValid(string s) {
    int n =s.size();
    if(n%2==1)
        return false;


    unordered_map<char,char> match={
            {')','('},
            {'}','{'},
            {']','['}
    };
    stack<char>stk;
    // for(char ch:s)
    // {
    //     if(match.count(ch))
    //     {
    //         if(stk.empty()||stk.top()!=match[ch])
    //         return false;
    //         else
    //         stk.pop();
    //     }
    //     else
    //     stk.push(ch);

    // }
    for(char ch:s)
    {
        // if(stk.empty())
        //     stk.push(ch);
        if(match.count(ch))
        {
            if(stk.empty())
            {
                stk.push(ch);
                continue;
            }

            if(stk.top()==match[ch]  && !stk.empty())
            {
                stk.pop();
            }
            else
               return false;
        }
        else
            stk.push(ch);
    }
    return stk.empty();

}

void backtrack2(vector<string>&ans ,string &cur, int open,int close,int n){

    if(cur.size()==2*n)//边界条件
    {
        ans.push_back(cur);
        return ;
    }
    if(open<n)
    {
        cur+='(';
        backtrack2(ans,cur,open+1,close,n);
        cur.pop_back();
    }
    if(open> close)
    {
        cur+=')';
        backtrack2(ans, cur,open,close+1,n);
        cur.pop_back();
    }
}
vector<string> Algorithm::generateParentthesis(int n) {
//回溯函数 使用上面的backtrack2()函数
vector<string> result;
string current;
    backtrack2(result,current,0,0,n);
    return result;

}
ListNode* mergetTwoLists(ListNode *a,ListNode *b)
{
    if(!(a&&b)) return a? a:b;
    ListNode head, *p=&head,*aPtr=a,*bPtr=b;
    while(aPtr&&bPtr) {
        if (a->val < b->val) {
            p->next = aPtr;
            aPtr = aPtr->next;
        } else {
            p->next = bPtr;
            bPtr = bPtr->next;
        }
        p = p->next;
    }
    p->next=(aPtr? aPtr:bPtr);
    return head.next;
}


ListNode* merge(vector<ListNode*>lists ,int l,int r)
{
    if(l>r)
        return nullptr;
    if(l==r)
        return lists[l];
    int mid=(l+r)>>1;
    mergetTwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
}
ListNode* mergeKlists(vector<ListNode*>lists) {
    return merge(lists,0,lists.size()-1);
}

int Algorithm::strStr(string haystack, string needle) {
    int n=haystack.size();int m =needle.size();
    if(m>n) return -1;

    int i=0;
    int j=0;//指向needle
    //for( i=0;i<n;i++)
    while (i<n)
    {
        if(haystack[i]==needle[j]){

            if(haystack[i+1]!=needle[j+1]||j+1==m) {
                break;
            }
            j++;

        }
        i++;
        if(j==m)break;
    }
    if(j==m-1) return i-j;
    else return -1;
}
int Algorithm::kmp(string s, string p) {
    int n=p.size();


    //计算next数组
    vector<int>next(n);
    for(int i=1,j=0;i<n;i++)
    {
        while(p[i])
        next[i]=j;
    }
}
int Algorithm::divide(int dividend, int divisor) {
            // 考虑被除数为最小值的情况
            if (dividend == INT_MIN) {
                if (divisor == 1) {
                    return INT_MIN;
                }
                if (divisor == -1) {
                    return INT_MAX;
                }
            }
            // 考虑除数为最小值的情况
            if (divisor == INT_MIN) {
                return dividend == INT_MIN ? 1 : 0;
            }
            // 考虑被除数为 0 的情况
            if (dividend == 0) {
                return 0;
            }

            // 一般情况，使用二分查找
            // 将所有的正数取相反数，这样就只需要考虑一种情况
            bool rev = false;
            if (dividend > 0) {
                dividend = -dividend;
                rev = !rev;
            }
            if (divisor > 0) {
                divisor = -divisor;
                rev = !rev;
            }

            // 快速乘
            auto quickAdd = [](int y, int z, int x) {
                // x 和 y 是负数，z 是正数
                // 需要判断 z * y >= x 是否成立
                int result = 0, add = y;
                while (z) {
                    if (z & 1) {
                        // 需要保证 result + add >= x
                        if (result < x - add) {
                            return false;
                        }
                        result += add;
                    }
                    if (z != 1) {
                        // 需要保证 add + add >= x
                        if (add < x - add) {
                            return false;
                        }
                        add += add;
                    }
                    // 不能使用除法
                    z >>= 1;
                }
                return true;
            };

            int left = 1, right = INT_MAX, ans = 0;
            while (left <= right) {
                // 注意溢出，并且不能使用除法
                int mid = left + ((right - left) >> 1);
                bool check = quickAdd(divisor, mid, dividend);
                if (check) {
                    ans = mid;
                    // 注意溢出
                    if (mid == INT_MAX) {
                        break;
                    }
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return rev ? -ans : ans;
        }


int Algorithm::longestVaildParentheses(std::string s) {//状态转移方程为dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2]

//    vector<int>dp(s.size(),0);
//    int maxVal=0;
//    for(int i=1;i<s.size();i++)
//    {
//        if(s[i]==')')
//        {
//            if(s[i-1]=='(')
//                dp[i] = 2+(i>1?dp[i-2] : 0);
//            else if(i-dp[i-1]>0 && s[i - dp[i - 1] -1]=='(')
//                dp[i] = (i-dp[i-1]> 1 ? 2 + dp[i - 1] + dp[i - dp[i - 1] - 2] : 2 + dp[i - 1]);
//        }
//        maxVal=max(maxVal,dp[i]);
//    }
//
//return maxVal;

/*;利用了栈*/
//int maxval=0;
//stack<int>stk;
//stk.push(-1);//为了保证初始时，栈底也是表示最后一个没有被匹配的右括号的下标
//for(int i=0;i<s.length();i++)
//{
//    if(s[i]=='(')
//    {
//        stk.push(i);
//    }
//    else
//    {
//        stk.pop();
//        if(stk.empty())
//        {
//            stk.push(i);
//        }
//        else
//        {
//            maxval=max(maxval,i - stk.top());
//        }
//        return maxval;
//
//    }
//}
int left=0,right=0,maxval=0;
for(int i=0;i<s.length();i++)
{
    if(s[i]=='(')
        left++;
    else
        right++;
    if(left==right)
         maxval=max(maxval,right+left);
    else if(right>left)
        left=right=0;
}
    left=right=0;
    for(int i=s.length()-1;i>0;i--)
    {
        if(s[i]=='(')
            left++;
        else
            right++;
        if(left==right)
            maxval=max(maxval,right+left);
        else if(right<left)
            left=right=0;
    }

return maxval;
}

vector<int> Algorithm::findSubstring(std::string s, vector<std::string> &words) {
    if(s.length()<words.size()*words[0].length())
        return {};
    unordered_map<string,int> st;
    vector<int> result;
    for(int i=0;i<s.size();i+=words[0].length())
    {
        string str=s.substr(i,words[0].length());



        ++st[str];
    }
//    int i=0,j=0;
//    while(i<words.size()&&j<st.size()) {
//        if(words[i]==st[j]) {
//            i++;
//            j++;
//        }
//        j++;
//    }

//    for(int j=0;j<words.size();j++)//j 是words的索引
//    {
//        int k;
//        for(k=0;k<st.size();k++)//k是s的索引
//        {
//            if(words[j]==st[k])
//            continue;
//        }
//
//        while(k<words.size())
//        {
//            if(st[++k]==words[++j])
//            {
//                result.push_back(k);
//            }
//        }
    return result;

}

int Algorithm::search(vector<int> nums, int target) {
    int n = nums.size();
    if(n==0 || (n==1 &&nums[0]!=target))
        return -1;
    int i=0, r=n-1;
    while(i<=r)
    {
        int mid=(i+r)/2;
        if(nums[mid]==target) return mid;
        if(nums[0]<nums[mid])//[i,mid]是一个有序数组
        {
            if(nums[0]<=target &&target<nums[mid])
                r=mid-1;
            else
                i=mid+1;
        }
        else
        {
            if(nums[mid]<target && target<nums[n-1])
                i=mid+1;
            else
                r=mid-1;
        }
    }
    return -1;

}
string  Algorithm::countAndSay(int n) {
    if(n==1)
        return "1";
    else
    {
        string x="";
        if(n==2)
            return "11";
        string result = countAndSay(n-1);
        int j=0;
        while(j<result.size())
        {
            int k=j;//string 里面的角标
            int i=1;//同一个元素的个数
            while(result[k]==result[k+1])
            {
                k++;
                i++;
            }
            x+= to_string(i);
            x+=result[k];
            j+=i;
        }
        return x;
    }
}

