//
// Created by 19281 on 2022/11/10.
//

#ifndef CLIONPROJECTS_ALGORITHM_H
#define CLIONPROJECTS_ALGORITHM_H
#include<iostream>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    //ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}

};


//两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //创建虚拟表头指针，默认为-1；
        ListNode *res = new ListNode(-1);
        //指向链表表头的指针，用于返回值
        ListNode *cur = res;
        ListNode *del = cur;
        int carry = 0;
        while (l1 || l2 )
        {
            //l1和l2当前位是否为空,不存在用0补上
            int l1val = l1 ? l1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int sum = l1val + l2val + carry;
            carry = sum / 10;
            // cur->next保存各位的数值
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        //最高位有进位，在最前面补1
        if (carry) cur->next = new ListNode(1);
        return res->next;
        free (del);
    }
};

class Algorithm
{
public:
    Algorithm ();
    void SimpleDemo();
    string convert(string s,int numRows);
    int reverse(int x);
    int myAtoi(string s);
    bool isPalindrome(int x);
    int maxArea(vector<int> &height);
    int maxArea2(vector<int>& height);
    int romanToInt(string s);
    string longestCommonPrefix(vector<string>& strs);
    int threeSumClosest(vector<int>& nums, int target);
    vector<string>letterCombinations(string digits);
    bool isValid(string s);
    vector<string>generateParentthesis(int n);
    int strStr(string haystack, string needle);
    int kmp(string s,string p);
    int divide(int dividend, int divisor);
    int longestVaildParentheses(string s);
    vector<int>findSubstring(string s ,vector<string>&words);
    int search(vector<int>nums,int target);
    string countAndSay(int n);


    ~Algorithm();
};
#endif //CLIONPROJECTS_ALGORITHM_H
