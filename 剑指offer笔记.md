# 剑指offer笔记

## c++相关书籍

1. 《Effective C++》
2. 《C++ Primer》
3. 《Inside C++ Object Model》
4. 《The C++ Programming Language》

熟练掌握C++基础语法：运算符函数，常量引用等等

struct是public, class是private
## 题目整理

### **[面试题03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)**

```cpp
//solution 1
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int>st;
        for(int i = 0; i < nums.size(); i++)
        {
            if(st.count(nums[i]))return nums[i];
            st.insert(nums[i]);
        }
        return -1;
    }
};
//solution 2
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int>st;
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != nums[nums[i]])swap(nums[i], nums[nums[i]]);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            //cout<<nums[i]<<endl;
            if(nums[i] != i)return nums[i];
        }
        return -1;
    }
};
```

### **[面试题04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)**

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while(i < m && j >= 0)
        {
            if(matrix[i][j] == target)return true;
            if(matrix[i][j] < target)++i;
            else --j;
        }
        return false;
    }
};
```

### **[面试题05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)**

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(auto a:s)
        {
            if(a != ' ')res += a;
            else res += "%20";
        }
        return res;
    }
};
```

### **[面试题06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head == NULL)return {};
        vector<int>res;
        while(head)
        {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};
```

### **[面试题07. 重建二叉树](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pl = 0, pr = preorder.size() - 1, il = 0, ir = pr;
        return helper(preorder, pl, pr, inorder, il, ir);
    }
    TreeNode* helper(vector<int>& preorder, int pl, int  pr, vector<int>& inorder, int  il,int  ir)
    {
        if(pl > pr || il > ir)return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        int i = il;
        for(; i <= ir; i++)
        {
            if(inorder[i] == preorder[pl])break;
        }
        root->left = helper(preorder, pl + 1, pl + i - il, inorder, il, i-1);
        root->right = helper(preorder, pl+i-il+1, pr, inorder, i+1, ir);
        return root;
    }
};
```

### **[面试题09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)**

```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());st1.pop();
            }
        }
        if(st2.empty())return -1;
        int res = st2.top();st2.pop();
        return res;

    }
    stack<int>st1, st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

### **[面试题10- I. 斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)**

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1)return n;
        int mod = 1e9+7;
        int f0 = 0, f1 = 1, res;
        while(n > 1)
        {
            res = f1%mod + f0%mod;
            f0 = f1;
            f1 = res;
            --n;
        }
        return res%mod;
    }
};
```

### **[面试题10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)**

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n <= 1)return 1;
        int mod = 1e9+7;
        int f0 = 1, f1 = 1, res;
        while(n > 1)
        {
            res = f1%mod + f0%mod;
            f0 = f1;
            f1 = res;
            --n;
        }
        return res%mod;
    }
};
```

### **[面试题11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)**

```cpp
class Solution {
public:
    int minArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right])left = mid+1;
            else if(nums[right] > nums[mid])right = mid;
            else --right;
        }
        return nums[left];
    }
};
```

### **[面试题12. 矩阵中的路径](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)**

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>>v(m, vector<bool>(n, false));
                    if(dfs(i, j, board, word, v, 0))return true;
                }
            }
        }
        return false;
    }
    bool dfs(int i, int j, vector<vector<char>>& board, string& str, vector<vector<bool>>& v, int pos)
    {
        if(pos == str.size())return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || v[i][j] == true || board[i][j] != str[pos])return false;
        v[i][j] = true;
        bool res;
        res = dfs(i+1, j, board, str, v, pos+1)||dfs(i-1, j, board, str, v, pos+1)||dfs(i, j-1, board, str, v, pos+1)||dfs(i, j+1, board, str, v, pos+1);
        v[i][j] = false;
        return res;
    }
};
```

### **[面试题13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)**

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>>v(m, vector<bool>(n, false));
        return dfs(m, n, 0, 0, v, k);
    }
    int dfs(int m, int n, int i, int j, vector<vector<bool>>&v, int k)
    {
        if(i < 0 || j < 0 || i >= m || j >= n || v[i][j] || count(i) + count(j) > k)return 0;
        v[i][j] = true;
        return 1+dfs(m, n, i-1, j, v, k)+dfs(m, n, i+1, j, v, k)+dfs(m, n, i, j-1, v, k)+dfs(m, n, i, j+1, v, k);
    }
    int count(int x)
    {
        int res = 0;
        while(x > 0)
        {
            res += x%10;
            x = x/10;
        }
        return res;
    }
};
```

### **[面试题14- I. 剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)**

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2)return 1;
        if(n == 3)return 2;
        if(n == 4)return 4;
        int res = 1;
        while(n > 4)
        {
            res = res*3;
            n -= 3;
        }
        return res*n;
    }
};
```

### **[面试题14- II. 剪绳子 II](https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/)**

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        int mod = 1e9+7;
        if(n == 2)return 1;
        if(n == 3)return 2;
        if(n == 4)return 4;
        long res = 1;
        while(n > 4)
        {
            res = res*3%mod;
            n -= 3;
        }
        return res*n%mod;
    }
};
```

### **[面试题15. 二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)**

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n > 0)
        {
            res += 1;
            n &= n-1;
        }
        return res;
    }
};
```

### **[面试题16. 数值的整数次方](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)**

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int cnt = abs(n);
        res = helper(x, cnt);
        return n < 0?1/res:res;
    }
    double helper(double x, int n)//快速幂
    {
        if(n == 0)return 1;
        if(n == 1)return x;
        double temp = helper(x, n/2);
        return (n%2 == 0?1:x)*temp*temp; 
    }
};
```

### **[面试题17. 打印从1到最大的n位数](https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)**

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int>res;
        int cnt = pow(10, n)-1;
        for(int i = 1; i <= cnt; i++)res.push_back(i);
        return res;
    }
};
```

### **[面试题18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dumm = new ListNode(-1), *pre = dumm;
        dumm->next = head;
        while(pre->next)
        {
            if(pre->next->val == val)break;
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        if(cur->next == NULL)
        {
            pre->next = NULL;
            return dumm->next;
        }
        pre->next = cur->next;
        return dumm->next;
    }
};
```

### **[面试题19. 正则表达式匹配](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)**

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(),  n = p.size();
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i < n; i++)
        {
            if(p[i] == '*')dp[0][i+1] = dp[0][i-1];
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    if(j > 1 && s[i-1] != p[j-2] && p[j-2] != '.')
                    {
                        dp[i][j] = dp[i][j-2];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                    }
                    
                }
            }
        }
        return dp[m][n];
    }
};
```

### **[面试题20. 表示数值的字符串](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)**

```cpp

```

### **[面试题21. 调整数组顺序使奇数位于偶数前面](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/)**

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]%2 == 1)swap(nums[i], nums[j++]);
        }
        return nums;
    }
};
```

### **[面试题22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dumm = new ListNode(-1), *pre = dumm, *cur = dumm;
        dumm->next = head;
        for(int i = 0; i < k; i++)
        {
            pre = pre->next;
        }
        while(pre)
        {
            cur = cur->next;
            pre = pre->next;
        }
        return cur;
    }
};
```

### **[面试题24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = p;
            p = head;
            head = temp;
        }
        return p;
    }
};
```

### **[面试题25. 合并两个排序的链表](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dumm = new ListNode(-1), *pre = dumm;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = l1?l1:l2;
        return dumm->next;
    }
};
```

### **[面试题26. 树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* s, TreeNode* t) {
        if(!s || !t)return false;
        if(iss(s, t))return true;
        return isSubStructure(s->left, t) || isSubStructure(s->right, t);
    }
    bool iss(TreeNode* s, TreeNode* t)
    {
        if(!t)return true;
        if(!s)return false;
        return s->val == t->val && iss(s->left, t->left) && iss(s->right, t->right);
    }
};
```

### **[面试题27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* node = new TreeNode(root->val);
        node->left = mirrorTree(root->right);
        node->right = mirrorTree(root->left);
        return node;
    }
};
```

### **[面试题28. 对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)return true;
        if(!root1 || !root2)return false;
        return root1->val == root2->val && (helper(root1->left, root2->right)) && helper(root1->right, root2->left);
    }
};
```

### **[面试题29. 顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)**

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())return {};
        vector<int>res;
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = n-1, up = 0, down = m-1;
        while(true)
        {
            for(int j = left; j <= right; j++)
            {
                res.push_back(matrix[up][j]);
            }
            if(++up > down)break;
            for(int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if(--right < left)break;
            for(int j = right; j >= left; --j)
            {
                res.push_back(matrix[down][j]);
            }
            if(--down < up)break;
            for(int i = down; i >= up; --i)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left > right)break;
        }
        return res;
    }
};
```

### **[面试题30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)**

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st1.push(x);
        if(!st2.empty())
        {
            st2.push(x < st2.top()?x:st2.top());
        }
        else
        {
            st2.push(x);
        }
    }
    
    void pop() {
        st1.pop();
        st2.pop();

    }
    
    int top() {
        return st1.top();

    }
    
    int min() {
        return st2.top();

    }
    stack<int>st1, st2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```

### **[面试题31. 栈的压入、弹出序列](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)**

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int>st;
        for(auto a:pushed)
        {
            st.push(a);
            while(!st.empty() && st.top() == popped[i])
            {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};
```

### **[面试题32 - I. 从上到下打印二叉树](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        queue<TreeNode*>q{{root}};
        while(!q.empty())
        {
            for(int k = q.size(); k > 0; --k)
            {
                auto t = q.front();q.pop();
                res.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return res;
    }
};
```

### **[面试题32 - II. 从上到下打印二叉树 II](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q{{root}};
        while(!q.empty())
        {
            vector<int>out;
            for(int k = q.size(); k > 0; --k)
            {
                auto t = q.front();q.pop();
                out.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(out);
        }
        return res;
    }
};
```

### **[面试题32 - III. 从上到下打印二叉树 III](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q{{root}};
        int cnt = 0;
        while(!q.empty())
        {
            ++cnt;
            vector<int>out;
            for(int k = q.size(); k > 0; --k)
            {
                auto t = q.front();q.pop();
                out.push_back(t->val);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(cnt%2 == 0)reverse(out.begin(), out.end());
            res.push_back(out);
        }
        return res;
    }
};
```

### **[面试题33. 二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)**

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())return true;
        return helper(postorder, 0, postorder.size() - 1);
    }
    bool helper(vector<int>& nums, int left, int right)
    {
        if(left >= right)return true;
        int k = left;
        for(; k < right; k++)
        {
            if(nums[k] > nums[right])break;
        }
        for(int i = k; i < right; i++)
        {
            if(nums[i] < nums[right])return false;
            
        }
        return helper(nums, left, k - 1) && helper(nums, k, right - 1);
    }
};
```

### **[面试题34. 二叉树中和为某一值的路径](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>out;
        helper(root, sum, res, out);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& out)
    {
        if(!root)return ;
        out.push_back(root->val);
        if(root && !root->left && !root->right && root->val == sum)
        {
            res.push_back(out);
        }
        helper(root->left, sum - root->val, res, out);
        helper(root->right, sum - root->val, res, out);
        out.pop_back();
    }
};
```

### **[面试题35. 复杂链表的复制](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/)**

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        unordered_map<Node*, Node*>m;
        Node* root = new Node(head->val, NULL, NULL), *cur = head->next, *res = root;
        m[head] = root;
        while(cur)
        {
            Node* t = new Node(cur->val, NULL, NULL);
            res->next = t;
            m[cur] = t;
            cur = cur->next;
            res = res->next;
        }
        cur = head, res = root;
        while(cur)
        {
            res->random = m[cur->random];
            cur = cur->next;
            res = res->next;
        }
        return root;
    }
};
```

### **[面试题36. 二叉搜索树与双向链表](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/)**

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)return root;
        Node* head = NULL, *pre = NULL;
        stack<Node*>st;
        while(!st.empty() || root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();st.pop();
            if(!head)head = root;
            if(pre)
            {
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
};
```

### **[面试题37. 序列化二叉树](https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root)return res;
        queue<TreeNode*>q{{root}};
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            if(t)
            {
                res += to_string(t->val) + " ";
                q.push(t->left);
                q.push(t->right);
            }
            else
            {
                res += "# ";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        if(str.empty())return NULL;
        istringstream in(str);
        string val;
        in>>val;
        TreeNode* root = new TreeNode(stoi(val)), *cur = root;
        queue<TreeNode*>q{{root}};
        while(!q.empty())
        {
            auto t = q.front(); q.pop();
            if(!(in>>val))break;
            if(val != "#")
            {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->left = cur;
                
            }
            if(!(in>>val))break;
            if(val != "#")
            {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->right = cur;
                
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

### **[面试题38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)**

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        set<string>res;
        helper(res, s, 0);
        return vector<string>(res.begin(), res.end());
    }
    void helper(set<string>& res, string& s, int start)
    {
        if(start >= s.size())
        {
            res.insert(s);
            return;
        }
        for(int i = start; i < s.size(); i++)
        {
            if(i != start && s[i] == s[start])continue;
            swap(s[i],s[start]);
            helper(res, s, start+1);
            swap(s[i],s[start]);
        }
    }
};
```

### **[面试题39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/)**

```cpp
//solution1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
//solution2摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, res = 0;
        for(auto a:nums)
        {
            if(res == 0)x = a;
            res += x==a?1:-1;
        }
        return x;
    }
};
```

### **[面试题40. 最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/)**

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int>q;
        for(int i = 0; i < arr.size(); i++)
        {
            q.push(arr[i]);
            if(q.size() > k)q.pop();
        }
        vector<int>res;
        while(!q.empty())
        {
            res.push_back(q.top());q.pop();
        }
        return res;
    }
};
```

### **[面试题41. 数据流中的中位数](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)**

```cpp
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(small.size() != big.size())
        {
            small.push(num);
            big.push(small.top());small.pop();
        }
        else
        {
            big.push(num);
            small.push(big.top());big.pop();
        }
    }
    
    double findMedian() {
        return small.size() > big.size()?small.top():(small.top() + big.top())*0.5;
    }
    priority_queue<int, vector<int>, greater<int>>small;
    priority_queue<int>big;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

### **[面试题42. 连续子数组的最大和](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)**

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            cur = max(nums[i], cur + nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};
```

### **[面试题43. 1～n整数中1出现的次数](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)**

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        long res = 0, digit = 1, high = n/10, low = 0, cur = n%10;
        while(cur || high)
        {
            if(cur == 0)res += high*digit;
            else if(cur == 1)res += high*digit + low + 1;
            else res += (high+1)*digit;
            low += cur*digit;
            cur = high%10;
            high = high/10;
            digit *= 10;
        }
        return res;
    }
};
```

### **[面试题44. 数字序列中某一位的数字](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/)**

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while(n > len*cnt)
        {
            n -= len*cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1)/len;
        string str = to_string(start);
        return str[(n-1)%len] - '0';
    }
};
```

### **[面试题45. 把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)**

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>str;
        for(auto a:nums)
        {
            str.push_back(to_string(a));
        }
        sort(str.begin(), str.end(), [](string& a, string b)
             {
                 return a+b < b+a;
             });
        string res = "";
        for(auto a:str)res += a;
        return res;
    }
};
```

### **[面试题46. 把数字翻译成字符串](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/)**

```cpp
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i-1];
            if(i > 1 && (str[i-2] == '1' || (str[i-2] == '2' && str[i-1] <= '5')))
            {
                dp[i] += dp[i-2];
            }
        }
        return dp.back();
    }
};
```

### **[面试题47. 礼物的最大价值](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/)**

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())return 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i < m; i++)grid[i][0] += grid[i-1][0];
        for(int j = 1; j < n; j++)grid[0][j] += grid[0][j-1];
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
```

### **[面试题48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)**

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = -1;
        unordered_map<char, int>m;
        for(int i = 0; i < s.size(); i++)
        {
            if(m.count(s[i]) && m[s[i]] > start)
                start = m[s[i]];
            res = max(res, i - start);
            m[s[i]] = i;
            
        }
        return res;
    }
};
```

### **[面试题49. 丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)**

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        long a = 0, b = 0, c = 0, aa = 2, bb = 3, cc = 5;
        vector<long>res;
        res.push_back(1);
        while(n > 1)
        {
            long a1 = res[a]*aa;
            long b1 = res[b]*bb;
            long c1 = res[c]*cc;
            long temp = min({a1, b1, c1});
            if(temp == a1)++a;
            if(temp == b1)++b;
            if(temp == c1)++c;
            res.push_back(temp);
            --n;
        }
        return res.back();
    }
};
```

### **[面试题50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)**

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> t;
        for(char c: s) t[c]++;
        for(char c: s)
            if(t[c]== 1) return c;
        return ' ';
    }
};
```

### **[面试题51. 数组中的逆序对](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)**

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return count(nums, 0, nums.size());
    }
    int count(vector<int>& nums, int start, int end)
    {
        if(start + 1 >= end)return 0;
        int mid = start + (end - start)/2;
        int res = count(nums, start, mid) + count(nums, mid, end);
        for(int i = start, j = mid; i < mid; i++)
        {
            while(j < end && nums[i] > nums[j])++j;
            res += j - mid;
        }
        inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);
        return res;
    }
};
```



### **[面试题52. 两个链表的第一个公共节点](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA, *B = headB;
        while(A != B)
        {
            A = A?A->next:headB;
            B = B?B->next:headA;
        }
        return A;
    }
};
```

### **[面试题53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)**

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] < target)left = mid+1;
            else right = mid;
        }
        
        if(right == nums.size() || nums[right] != target)return 0;
        int cnt = right;
        right = nums.size();
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] <= target)left = mid+1;
            else right = mid;
        }
        return right - cnt;
    }
};
```

### **[面试题53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/)**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)return i;
        }
        return nums.size();
    }
};
```

### **[面试题54. 二叉搜索树的第k大节点](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*>st;
        TreeNode* q = root;
        while(!st.empty() || q)
        {
            if(q)
            {
                st.push(q);
                q = q->right;
                
            }
            else
            {
                q = st.top();st.pop();++cnt;
                if(cnt == k)return q->val;
                q = q->left;
            }
            
        }
        return 0;
    }
};
```

### **[面试题55 - I. 二叉树的深度](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

### **[面试题55 - II. 平衡二叉树](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(abs(maxd(root->left) - maxd(root->right))> 1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int maxd(TreeNode* root) {
        if(!root)return 0;
        return 1 + max(maxd(root->left), maxd(root->right));
    }
};
```

### **[面试题56 - I. 数组中数字出现的次数](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)**

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for(auto a:nums)
        {
            res ^= a;
        }
        int div = 1;
        while((div&res) == 0)
        {
            div <<= 1;
        }
        int a = 0, b = 0;
        for(auto n:nums)
        {
            if(n&div)
            {
                a^=n;
            }
            else
            {
                b^=n;
            }
        }
        return {a, b};
    }
};
```

### **[面试题56 - II. 数组中数字出现的次数 II](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/)**

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>m;
        for(auto a:nums)++m[a];
        for(auto a:nums)
        {
            if(m[a] == 1)return a;
        }
        return -1;
    }
};
```

### [面试题57. 和为s的两个数字](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/)

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum == target)return {nums[left], nums[right]};
            else if(sum < target)++left;
            else --right;
        } 
        return {};
    }
};
```












### **[面试题57 - II. 和为s的连续正数序列](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)**

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 1, sum = 0;
        vector<vector<int>>res;
        while(i <= target/2)
        {
            if(sum < target)
            {
                sum += j;
                j++;
            }
            else if(sum > target)
            {
                sum -= i;
                ++i;
            }
            else
            {
                vector<int>out;
                for(int k = i; k < j; k++)
                {
                    out.push_back(k);
                }
                res.push_back(out);
                sum -= i;
                ++i;
            }
        }
        return res;
    }
};
```

### **[面试题58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)**

```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);
        string res = "", t = "";
        while(in>>t)
        {
            string str = t;
            //reverse(str.begin(), str.end());
            res = str + " " + res;
        }
        //cout<<res<<endl;
        if(!res.empty())res.pop_back();
        return res;
    }
};
```

### **[面试题58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)**

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        n = n%len;
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
        
    }
};
```

### **[面试题59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)**

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!dq.empty() && dq.front() == i - k)dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1)res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
```

### **[面试题59 - II. 队列的最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/)**

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(dq.empty())return -1;
        int res = dq.front();
        return res;
    }
    
    void push_back(int val) {
        q1.push(val);
        while(!dq.empty() && dq.back() < val)
        {
            dq.pop_back();
            
        }
        dq.push_back(val);

    }
    
    int pop_front() {
        if(q1.empty())return -1;
        int res = q1.front();q1.pop();
        if(res == dq.front())dq.pop_front();
        return res;

    }
    queue<int>q1;
    deque<int>dq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```

### **[面试题60. n个骰子的点数](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/)**



### **[面试题61. 扑克牌中的顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)**

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == 0)++cnt;
            else if(nums[i] == nums[i+1])return false;
        }
        return nums.back() - nums[cnt] < 5;
    }
};
```

### **[面试题62. 圆圈中最后剩下的数字](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/)**

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for(int i = 2; i != n+1; i++)
        {
            f = (f+m)%i;
        }
        return f;
    }
};
```

### **[面试题63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)**

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int mn = prices[0], res = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            mn = min(prices[i], mn);
            res = max(res, prices[i] - mn);
        }
        return res;
    }
};
```

### **[面试题64. 求1+2+…+n](https://leetcode-cn.com/problems/qiu-12n-lcof/)**

```cpp
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n; 
    }
};
```

### **[面试题65. 不用加减乘除做加法](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/)**

```cpp
class Solution {
public:
    int add(int a, int b) {
        while(b!=0){
            int tmp=a^b;
            b=((unsigned int)(a&b)<<1);
            a=tmp;
        }
        return a;
    }
};
```

### **[面试题66. 构建乘积数组](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/)**

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int>left(a.size(), 1), right(a.size(), 1);
        for(int i = 1; i < a.size(); i++)
        {
            left[i] = left[i-1]*a[i-1];
        }
        for(int i = a.size() - 2; i >= 0; --i)
        {
            right[i] = right[i+1]*a[i+1];
        }
        vector<int>res;
        for(int i = 0; i < a.size(); i++)
        {
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};
```

### **[面试题67. 把字符串转换成整数](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/)**

### **[面试题68 - I. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)return root;
        return left?left:right;
    }
};
```

### **[面试题68 - II. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right)return root;
        return left?left:right;
    }
};
```

