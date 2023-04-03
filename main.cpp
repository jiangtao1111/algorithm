#include <iostream>
using namespace std;
#include"speechManager.h"
#include"Algorithm.h"



ListNode* createListNode(std::vector<int> vals);
void freeListNode(ListNode* head);
void printListNode(ListNode* head);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
string longestPalindrome(string  s);

#include<stdio.h>
struct S1
{
    int i:8;
    char j:4;
    int a:4;
    double b;
};
struct S2
{
    int i:8;
    char j:4;
    double b;
    int a:4;
};

struct S3
{
    int i;
    char j;
    int a;
    double b;
};



int main() {
    cout << "Hello, World!" <<endl;
    Algorithm Am;
    Am.SimpleDemo();
    /*两数相加
    auto l1 = createListNode({1, 2, 3});
    auto l2 = createListNode({9, 8, 7, 6});
    printListNode(l1);
    printListNode(l2);
    Solution s;
    auto sum = s.addTwoNumbers(l1, l2);
    printListNode(sum);
    freeListNode(l1);
    freeListNode(l2);
    freeListNode(sum);*/
    /*vector<int> v1{1,3};
    vector<int> v2{2};
    double result=findMedianSortedArrays(v1,v2);
    cout<<result;*/
//    string s ="PAYPALISHIRING";
//    string re = Am.convert(s,3);
//    string s1="42";
//    int re1=Am.myAtoi((s1));
//
//    int x=121;
//    bool re2 =Am.isPalindrome(x);
    //vector<int> height1{1,8,6,2,5,4,8,3,7};
    //int a[]=[1,8,6,2,5,4,8,3,7];
//    int re3 = Am.maxArea(height1);
//    int re4 = Am.maxArea2(height1);
//    string s="MCMXCIV";
//    int value=Am.romanToInt(s);
//    vector<string> str1={"leets","leatcode","leet","leetsfcsdfs"};
//    string res_str=Am.longestCommonPrefix(str1);
//    printf("%d\n",sizeof(S1)); // 输出8
//    printf("%d\n",sizeof(S2));// 输出12
//    printf("%d\n",sizeof(S3)); // 输出8
//    printf("%d\n",sizeof(int)); // 输出8
//    printf("%d\n",sizeof(double));
//    printf("%d\n",sizeof(char));
    //vector<int>nums={4,0,5,-5,3,3,0,-4,-5};
//    vector<int>nums={-1,2,1,-4};
//    int res=Am.threeSumClosest(nums,1);
//    cout<<"res = "<<res<<endl;
    string digits="23";
    Am.letterCombinations(digits);
    string s2="(]";
    bool T=Am.isValid(s2);
    //int a=Am.strStr("leetcode","leeto");
    //int a=Am.strStr("sadbutsad","sad");
    int a=Am.strStr("a","a");
    int diviend =10; int divisor =3;
    int re=Am.divide(diviend,divisor);
    string s="barfoothefoobarman";
    vector<string>words={"foo","bar"};
    vector<int>re2 = Am.findSubstring(s,words);
    int r=Am.longestVaildParentheses(s);
    vector<int> nums={4,5,6,7,0,1};
    int target =0;
    int re3=Am.search(nums,target);
    return 0;



}
//链表创建
ListNode* createListNode(std::vector<int> vals)
{
    //c11新特性， nullptr空指针类型的关键字
    ListNode *res = nullptr;
    ListNode *last = nullptr;
    for(auto val : vals) {
        if(last) {
            last->next = new ListNode(val);
            last = last->next;
        }
        else {
            res = new ListNode(val);
            last = res;
        }
    }
    return res;
}

//链表输出
void printListNode(ListNode* head)
{
    ListNode* node = head;
    while(node) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}

//释放内存
void freeListNode(ListNode* head)
{
    ListNode* node = head;
    while(node) {
        auto temp = node->next;
        delete node;
        node = temp;
    }
}
//string convert(string s,int numRows)
//{
//    int n =s.length(), r=numRows;//r是行数
//    if(n==1 ||n<=r){
//        return s;
//    }
//    int t= 2*r-2;//一个周期
//    int c=(n/t+1)*(r-1);//;列数
//    vector<string> mat(r,string(c,0));
//    for(int i=0,x=0,y=0;i<n;i++)
//    {
//        mat[x][y]=s[i];
//        if(i%t<r-1)
//            x++;
//        else
//        {x--;
//            y++;
//        }
//
//    }
//    string ans;
//    for(auto &row :mat)
//        for(char ch:row)
//        {
//            if(ch){
//                ans +=ch;
//            }
//        }
//        return ans;
//
//}