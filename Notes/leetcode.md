# 数据结构基础

## A.基础知识

### A.1.堆栈：

cpu计算复杂度很高的时候，会把数据暂时存放在内存的栈区（FILO）

内存包括栈区和堆区。

![image-20230423161404830](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423161404830.png)

堆栈的应用：函数调用。

![image-20230423161551291](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423161551291.png)

当函数调用完以后，堆栈里保存的父地址被弹出供cpu返回

为什么非要 用内存中的堆栈区呢？因为函数调用是嵌套的结构，所以要从最里层函数返回外层函数就必须是使用到堆栈。

![image-20230423161819383](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423161819383.png)

### A.2.递归：

自己调用自己，但是要有递归出去的显示数据。（栈溢出错误：栈的大小是有限的）

## 0.时间复杂度

![image-20230423100244433](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423100244433.png)

总结：时间复杂度，常数时间的操作，只取表达式的高阶项。

1.常数操作：int a = arr[i];加减乘除 ，他们与数据量无关，数组取值（值是存在一段连续的区域中）是靠偏移取值。特别的，链表不是常数操作，他是靠遍历来获取值的，如果数据量上去了，那遍历时间，取值时间就要变。

举例：无序数组按照从小到大的顺序进行排序。问时间复杂度是都少？

第一位 0-n-1,第二位1-n-1,第三位2-n-1这样一次排序，

第一位：进行了n眼，n比较，1次swap

![image-20230423101329404](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423101329404.png)

所以时间复杂度是 O(N^2) O最坏的时间

笔记：[(89条消息) 剑指2022实习笔记目录_erdngk.top_尔等同学的博客-CSDN博客](https://blog.csdn.net/qq_41852212/article/details/120628784)

我们在决定使用那些算法的时候 ，**不是时间复杂越低的越好，要考虑数据规模**，如果数据规模很小 甚至可以用O(n^2)的算法比 O(n)的更合适。时间复杂度是一个函数，它描述了算法运行时间与输入数据量之间的关系。

- O(1)：常数时间复杂度，表示算法的执行时间与输入数据量无关。例如，访问数组中的元素或执行一次简单的赋值操作。
- O(log n)：log2n对数时间复杂度，表示算法的执行时间随着输入数据量的增加而增加，但增长速度较慢。例如，**二分查找算法**（有序数组）。
- O(n)：线性时间复杂度，表示算法的执行时间与输入数据量成正比。例如，遍历数组中的元素或线性搜索算法。
- O(n log n)：线性对数时间复杂度，表示算法的执行时间随着输入数据量的增加而增加，但增长速度较快。例如，快速排序算法。
- O(n^2)：平方时间复杂度，表示算法的执行时间与输入数据量的平方成正比。例如，嵌套循环的排序算法。
- O(2^n)：指数时间复杂度，表示算法的执行时间随着输入数据量的增加而急剧增加。例如，求解旅行商问题的暴力算法。

### 0.0:O(1)

常数时间复杂度

```c++
#include <iostream>
#include <vector>

int main() {
  std::vector<int> a{1, 2, 3, 4, 5};
  std::cout << a[0] << std::endl; // 访问 vector 中的元素是常数时间复杂度，不随输入数据量的增加而变化
  return 0;
}

```

### 0.1:O(logn):

对数时间复杂度log2n,假设当前查找区间为 [left, right]，那么我们将查找区间缩小至 [mid+1, right] 或者 [left, mid-1]，其中 mid = (left + right) / 2，即将查找区间划分为左右两个子区间，并判断目标数可能在哪个子区间中。然后不断重复这个过程，直到找到目标数或者确定目标数不存在。例如，一次查找区间大小为 n，第二次查找区间大小为 n/2，第三次查找区间大小为 n/4，以此类推，直到查找区间缩小为 1 或者找到目标元素。

```c++
#include<iostream>
#include <vector>
using namespace std;
int binarysearch(vector<int>&nums,int target){
    int left =0,right =nums.size()-1;
    while(left<=right){//序号
        int mid = (left+right)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target){//mid比target大
            right = mid-1;
        }
        else//mid比target小
        {
            left = mid+1;
        }
        return -1
    }
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int index = binarySearch(nums, target);
    if (index == -1) {
        cout << "元素 " << target << " 不存在于数组中" << endl;
    } else {
        cout << "元素 " << target << " 在数组中的下标为 " << index << endl;
    }
    return 0;
}
```

0.2：O(n):线性时间复杂度

```c++
#include <iostream>
#include <vector>

int linear_search(const std::vector<int>& array, int target) {
  for (int i = 0; i < array.size(); ++i) {
    if (array[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << linear_search(a, 6) << std::endl; // 输出：5
  return 0;
}

```

### 0.2：O(n log n)

​	线性对数时间复杂度

​	O(n log n) 的时间复杂度通常出现在一些基于比较的排序算法中，例如快速排序、归并排序等。这些算法都是基于分治法思想，将待排序的序列分成若干个子序列进行排序，然后将已经排序的子序列合并，最终得到完整的排序结果。

#### 0.2.1归并排序：

​	归并排序（Merge Sort）是一种基于分治策略的排序算法，其基本思想是将待排序序列分成两个子序列，分别进行排序，最后将排序好的子序列合并成一个有序序列。

1. 分割（Divide）：将待排序的序列分成两个子序列，每个子序列大约一半大小。这里采用分治策略，通过递归的方式不断地将子序列继续划分，直到子序列的大小为1。
2. 合并（Merge）：将两个已排序的子序列合并成一个有序序列。合并时，需要比较两个子序列的元素大小，将较小的元素先放入新序列中，直到某个子序列全部取完，然后将另一个子序列剩余的元素全部加入新序列中。

```c++
void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        }
        else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

```

#### 0.2.2快速排序：

​	属于分治法（Divide and Conquer）的一种典型应用。它的基本思想是选取一个基准元素（pivot），通过一趟排序将待排序序列分割成独立的两部分，其中一部分的所有元素均小于等于基准元素，另一部分的所有元素均大于基准元素，然后分别对这两部分继续进行排序，直到整个序列有序。

 	可以分为以下几个步骤：

①选择基准元素，通常选择第一个或者最后一个

②分割操作：以基准元素为中心，将数组划分成左右两个子序列，左边子序列中所有元素都小于等于基准元素，右边子序列中所有元素都大于基准元素。可以使用双指针法实现这个操作。

③**递归排序**：对左右两个子序列分别进行递归排序，直到子序列长度为1或0，此时整个序列有序。

④合并操作：由于每次分割后都是将基准元素放在了正确的位置上，因此在递归排序结束后，整个序列已经有序。

```c++
void quicksort(vector<int>& nums,int left,int right){
	if(left>=right)return;//递归的边界条件
    int i =left,j = right,pivot=nums[left];//双指针
    while(i<j)//两指针未相遇
    {
        while(i<j &&arr[j]>=pivot)j--;//如果右边比pivot大，就不移动，只需要再看右边倒数第二个
        arr[i] = arr[j];//如果右边比pivot小，就要把右边换到左边去
        while(i<j && arr[i]<pivot)i++;
        arr[j]=arr[i];
    }
    arr[i]=pivot;//此时i= j，把pivot也放进数组里
    quicksort(arr,left,i-1);//左半部分排序 此时i = j(即mid)
    quicksort(arr,i+1,right);//右半部分排序
}
```

![image-20230423164128594](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230423164128594.png)

​	特别的，在排序的过程中，每个元素都会被比较一次，因此时间复杂度至少是 O(n)。而每次递归调用都会将待排序数组划分成两个大小为 n/2 的子数组，因此递归深度为 O(logn)。因此，快速排序的时间复杂度为 O(nlogn)。

​	需要注意的是，快速排序的时间复杂度不是稳定的。在最坏情况下，每次划分只能减少一个元素，导致递归深度为 n，此时时间复杂度为 O(n^2)。但是，最坏情况的概率很小，可以通过随机化选取基准元素来降低其发生的概率。

。在大规模数据的情况下，快速排序可能是更好的选择，而在小规模数据的情况下，归并排序可能更为适合。

## 	1.栈与队列

​	①队列的特性是 FIFO（先入先出），而栈的特性是 FILO（先入后出）。

​	②双向队列：[deque](https://so.csdn.net/so/search?q=deque&spm=1001.2101.3001.7020)支持push_front、pop_front、push_back、pop_back。

 	 单向队列queue支持push_back、pop_front。

​	③手动用C撸一个栈

1. C++中stack 是容器么？

2. 我们使用的stack是属于那个版本的STL？

3. 我们使用的STL中stack是如何实现的？

4. stack 提供迭代器来遍历stack空间么？

   

###  ==题型① 栈与队列转换:==

### 【232】用栈实现队列(easy)

​	仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

```C++
class MyQueue {
private:
//一个入队栈，一个出队栈，用来模拟队列，把入栈里的元素倒倒出栈里
stack<int> inStack,outStack;
//将入队栈的元素倒转到出堆栈
void in2out(){
    while(!inStack.empty()){//如果入队栈有元素,就进行倒转操作
        outStack.push(inStack.top());//把入队栈里的顶层元素压入出队栈
        inStack.pop();//弹出入队栈的顶层元素
    }
}
public:
MyQueue() {

}
//将元素 x 推到队列的末尾
void push(int x) {//压入栈的方式栈和队列是一样的
    inStack.push(x);
}
//从队列的开头移除并返回元素
int pop() {
    while(outStack.empty()){//如果出队栈空就到出堆栈去取元素，非空就直接用出堆栈
        in2out();
    }
    int x = outStack.top();//得到出队栈的队头
    outStack.pop();//删掉出队栈的队头
    return x;
}
//返回队列开头的元素
int peek() {
    while(outStack.empty()){//如果出队栈空就到出堆栈去取元素，非空就直接用出堆栈
        in2out();
    }
    return outStack.top();
}
//如果队列为空，返回 true 否则，返回false
bool empty() {
    if(inStack.empty()&&outStack.empty()){
        return true;
    }
    else{
        return false;
    }
}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();实现MyQueue类
* obj->push(x);将元素x推到队列末尾
* int param_2 = obj->pop();从队列的开头移除并返回元素
* int param_3 = obj->peek();返回队列开头的元素
* bool param_4 = obj->empty();如果队列为空，返回true，否则返回false
*/
```



### 【225】用队列实现栈(easy)

​	仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

```c++
class MyStack {
private:
    queue<int> q;//两个队列不好解决pop出栈顶的问题，用一个队列先重复push再pop

public:
    MyStack() {
    }
    
    void push(int x) {//将元素 x 压入栈顶
        int size_n = q.size();//计算需要重新入队的元素个数
        q.push(x);//压入新的元素
        for(int i=0;i<size_n;i++){
            q.push(q.front());//压入队头元素
            q.pop();//pop掉队头元素
        }
    }
    
    int pop() {//移除并返回栈顶元素。
        int n= q.front();
        q.pop();
        return n;
    }
    
    int top() {//返回栈顶元素
        return q.front();
    }
    
    bool empty() {//判断栈是否是空的，是空的返回T，否则返回F
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

### 【155】最小栈(easy)

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。

void push(int val) 将元素val推入堆栈。

void pop() 删除堆栈顶部的元素。

int top() 获取堆栈顶部的元素。

int getMin() 获取堆栈中的最小元素。

题解：

bug1:AddressSanitizer:DEADLYSIGNAL ================================================================= ==42==ERROR: AddressSanitizer: stack-overflow on address 0x7ffd692b8ff8 (pc 0x0000003538e6 bp 0x7ffd692b90d0 sp 0x7ffd692b9000 T0) ==42==ABORTING

递归法解决方案的优点是它更容易实现。但是存在一个很大的缺点：如果递归的深度太高，我们将遭受堆栈溢出。

bug2：在第18个样例中超出了时间限制。题目要求在常数时间内获得栈中的最小值，因此不能在 getMin() 的时候再去计算最小值。

```cpp
//错误解法，超过了常数时间，在getmin去比较了大小
class MinStack {//最小栈
private:
    queue<int> q_compare;//比较队列
    queue<int> q_min;//最小值队列
public:
    MinStack() {
    }

    void push(int val) {//用队列实现堆栈
        int size_n=q_compare.size();//测量之前的队列长度
        q_compare.push(val);//推入栈
        for(int i =0;i<size_n;i++){//换入栈顺序
            q_compare.push(q_compare.front());
            q_compare.pop();
        }
        cout<<endl;
    }
    
    void pop() {//删除堆栈顶部的元素
        q_compare.pop();
    }
    
    int top() {// 获取堆栈顶部的元素
        return q_compare.front();
    }
    
    int getMin() {//获取堆栈中的最小元素
        int min =0;
        if(q_min.size()){
             q_min.pop();//清除之前的元素，归零
        }
        q_min.push(q_compare.front());//q_min先放入一队头个元素
        q_compare.push(q_compare.front());//又放到队尾，不破坏元素个数
        q_compare.pop();//弹出队头
        int n = q_compare.size();
        if(n==1){
            min =q_compare.front();
        }
        else{
             for(int i = 0;i<n-1;i++){
                if(q_compare.front() < q_min.front())//如果存储队列头比最小值队列头还小
                {
                    q_min.pop();//最小值队列始终保持一个元素
                    q_min.push(q_compare.front());
                    q_compare.push(q_compare.front());//又放到队尾，不破坏
                    q_compare.pop();//删除比较过的存储队列头
                }
                else{
                    q_compare.push(q_compare.front());//又放到队尾，不破坏
                    q_compare.pop();//删除比较过的存储队列头
                }
            }
        }
           
        min = q_min.front();
        return min;
       
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 栈并不接受遍历,所以直接创建，可能用数组vector
 */
```

解决：

做一个辅助栈专门用来存最小值，栈有多少个，则最小值有多少个。最后对应栈弹出元素后，最小值跟着一起弹出。

INT_MAX：这意味着在几乎所有计算机中，最大整数值为2 ^（31）– 1 = +2147483647。

```c++
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);//这里为什么要push进最大值？
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
```

不用额外的辅助空间：

```php
面试的时候被问到不能用额外空间，就去网上搜了下不用额外空间的做法。思路是栈里保存差值。

class MinStack:
  def __init__(self):
  """
initialize your data structure here.
"""
  self.stack = []
  self.min_value = -1

  def push(self, x: int) -> None:
  if not self.stack:
  self.stack.append(0)
  self.min_value = x
  else:
diff = x-self.min_value
  self.stack.append(diff)
  self.min_value = self.min_value if diff > 0 else x

  def pop(self) -> None:
  if self.stack:
  diff = self.stack.pop()
  if diff < 0:
  top = self.min_value
  self.min_value = top - diff
  else:
  top = self.min_value + diff
  return top

  def top(self) -> int:
  return self.min_value if self.stack[-1] < 0 else self.stack[-1] + self.min_value

  def getMin(self) -> int:
  return self.min_value if self.stack else -1
```

### ==题型② 括号:==

由于栈的结构特殊性，非常适合做对称匹配类的题目。

一般判断括号串是否合法的算法如下：

### 【20】用栈实现括号匹配(easy)

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i =0;i<s.size();i++){
            if(s[i] == '{')stk.push('}');//遇到左括号全部入栈进行存储
            else if (s[i] == '[')stk.push(']');
            else if  (s[i] == '(')stk.push(')');
            //没有匹配到左括号+括号不对称（最后的左括号会最先匹配到对应的右括号）
            else if ((stk.empty())||(s[i] != stk.top()))return false;
            else{//遇到匹配的右括号就弹出
                stk.pop();
                }
        }
        //如果是满足题意的括号就应该为空
        return stk.empty();
    
    }
};

```

【22】括号生成(回溯算法)

数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

### 【739】每日温度

给定一个整数数组 `temperatures` ，表示每天的温度，返回一个数组 `answer` ，其中 `answer[i]` 是指对于第 `i` 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

*？时间/空间复杂度，在用双层循环时，最后提交会超出时间限制*

1.暴力双循环 这样时间会超？为什么

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int grtdy =0;//温度比当前高的日子
        int size_org = temperatures.size();
        vector<int> grtdays;
        for(int j =0;j<size_org;j++)
        {
            for(int i = j+1;i<size_org;i++){
            if(temperatures[i]>temperatures[j]){
                grtdy = i-j;//相差几天
                break;//跳出for循环
                }   
            else{
                continue;
                }
             }
            grtdays.push_back(grtdy);
            grtdy =0;//清零
        }
        return grtdays;
    }
   
};
```

2.单调栈: for,while结构真的很好用

```C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);//返回的间隔天数 ,n为大小
        stack<int> s;//单调栈 温度依次降低（序号）
        for(int i =0;i<n;++i){//高温记录序号差值
            while(!s.empty() && temperatures[i]>temperatures[s.top()]){//单调栈非空+当前遍历温度>栈顶温度
                int previousIndex = s.top();//保存栈顶序号
                ans[previousIndex] = i-previousIndex;//保存序号差值
                s.pop();//弹出栈
            }
            s.push(i);//如果比前面温度低+空栈就入栈
        }
        return ans;
    }
};
```



### 【496】下一个更大的元素

单调栈专门解决Next Greater Number

//暴力搜素：

```C++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m);//初始化返回的数字，长度是nums1的长度
        for(int i =0;i<m;i++){
            int j =0;//进大循环就初始化
            while(j<n &&nums1[i]!=nums2[j]){
                j++;//在nums2没匹配到就一直加
            }
            int k = j+1;//此时在nums2中已经找到了相等的,k的值，开始在nums2的下一个元素中寻找较大值坐标
            while(k<n && nums2[k]<nums2[j]){
                k++;//不大于就一直加
            }
            //遍历完了还不满足就为-1，找到大于的就返回本
            res[i] = k<n ? nums2[k] :-1;
        }

        return res;
        
    }
};
```

//哈希表+单调栈:

1.预处理

①.nums2每个元素右边的第一个更大的值：倒序遍历nums2,并用单调栈维护当前位置右边更大的元素列表，从栈底都栈顶单调减小。

②如何存储①中的子问题的结果：由于nums2是没有重复的元素，我们可以把元素值和对应右边第一个更大的元素值的对应关系存入哈希表。

这是调试过后的 hashmap 结构，可以看到他把nums2先进行处理（单调栈比较大小），再把存储的数据存到hash表中

![image-20230203112908598](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230203112908598.png)

![image-20230203162725873](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230203162725873.png)

理解单调栈，这个问题可以这样抽象思考：把数组的元素想象成并列站立的人，元素大小想象成人的身高。这些人面对你站成一列，如何求元素「2」的 Next Greater Number 呢？很简单，如果能够看到元素「2」，那么他后面可见的第一个人就是「2」的 Next Greater Number，因为比「2」小的元素身高不够，都被「2」挡住了，第一个露出来的就是答案。

//单调栈+哈希表

先处理nums2,对nums2中的每个元素进行查找下一个最大元素的操作、

单调栈：用来比较大小，找到下一个更大的元素：栈里面的元素递减，是为了找到大小介于栈间元素之间的状态

<img src="C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230206094001248.png" alt="image-20230206094001248" style="zoom: 33%;" />

对于3，在这之前就对2，4进行了入栈操作，3是介于2,4之间的。此时将2弹出，并且存入4。3后面最邻近的就是4。

哈希表：通过存储键值对来存储<nums2[i]>下一个更高温度，比如：

![image-20230206095053231](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230206095053231.png)

``

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>hashmap;
        stack<int> st;
        for(int i = nums2.size()-1;i>=0;i--){
            int num = nums2[i];//这里指的是温度值
            while(!st.empty()&&st.top()<=num){
                st.pop();//矮个子起开，栈里面存放的是高个子
            }
            hashmap[num] = st.empty() ? -1 : st.top();//最后一个元素一定为-1
            st.push(num);
        }
        vector<int> res(nums1.size());
        for(int i =0;i< nums1.size();++i){//在nums[1]中 查找hashmap中的元素并且返回
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};
```

### 【901】股票价格跨度

我的第一种做法，用for的话会一直卡在一个price这个地方，看来还是要用vector对price进行存储才行。

```C++
class StockSpanner {
private:
    stack<int> st;//初始化单调栈
    int day_last =1;//持续天数,至少都为1
    int count_day=0;//计数，已经过去了多少天
    vector<int> store_stock;//存储股票价格
public:
    StockSpanner() {//初始化类对象 输出null
    }
    //找更小元素 --升序栈   找更大元素 --降序栈
    int next(int price) {//给出今天的股价price，返回该股票当日价格的跨度
        int res =1;//初始化存储价格的数组
        count_day++;//第count_day天
        store_stock.push_back(price);//对每次存进来的股票进行存值
        for(int i =0;i<count_day;i++)
        {   
            while(!st.empty()&&st.top()>store_stock[count_day-1]){//升序栈
                st.pop();
            }
            res= st.empty()?1:day_last+1;
            st.push(store_stock[i]);
            cout<<endl;
        }
        return res;
    }
};
```



## 2.数组与矩阵

```C++
//关于vector的基础题解
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       vector<int> v1;                       //默认构造
        for (int i = 0; i < 10; i++)
        {v1.push_back(i);}
        vector<int> v2(v1.begin(), v1.end());  //区间
        vector<int> v3(5, 1);                 //构造函数将n个elem拷贝给本身
        vector<int> v4(v3);                 //拷贝构造
        v3.assign(v2.begin(),v2.end()); 

        cout << v1.capacity() << endl; //容量
        cout << v1.size() << endl;     //元素的个数
        v1.resize(15,1); //重新指定容器的长度，用1填充，没有写第二个参数则默认为0
        v1.resize(8);       //若容器变短，则末尾超出容器长度的元素被删除

        //vector插入删除 用尾插法建立数组 insert（指定迭代器插入）
        vector<int> v5;
        for (int i = 0; i < 10; i++)
        {v5.push_back(i);}//从尾部插入元素
        v5.pop_back();//从尾部删除一个元素
        v5.insert(v5.begin(), 11);//在第一个元素处，即v5(0)插入11 迭代器指针
        v5.insert(v5.begin()+4, 12);//在第5个元素处插入12
        v5.insert(v5.end(), 3,0);//在数组最后插3个0
        v5.erase(v5.begin());//删除数组一个元素
        v5.erase(v5.begin(), v5.end()-1);//留下最后一个元素

        //vector数据存取
        vector<int> v6;
        for (int i = 0; i < 10; i++){
            v6.push_back(i);
        }
        for(int i = 0;i<v6.size();i++){    //利用成员函数at()以及重载[]访问数据
        cout << v6.at(i) << endl; 
        cout << v6[i]<<endl;
        }
        cout << v6.front() << endl;  // front(); 获取第一个元素
        cout << v6.back() << endl; // back(); 获取最后一个元素


        //vetor互换容器
        vector<int> v;
        for(int i=0;i<100000;i++)
        { v.push_back(i);}
        cout<<"容量"<< v.capacity()<<endl;
        cout << "大小" << v.size() << endl;   //大小是100000,容量会比大小大,130000
        v.resize(3);                         //重新指定大小
        cout<<"容量"<< v.capacity()<<endl;
        cout << "大小" << v.size() << endl;   //大小是3，容量并没有变化,130000
            
        vector<int>(v).swap(v);               //巧用swap收缩内存空间
        cout<<"容量"<< v.capacity()<<endl;
        cout << "大小" << v.size() << endl;   //容量大小都是3
        cout<<endl;
        }
};
```

### 【283】移动零

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**请注意** ，必须在不复制数组的情况下原地对数组进行操作。

```C++
#错误做法，这样会导致数组长短发生遍历，不能这样用，样例1只是一个巧合
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_size = nums.size();//记录原始数组大小
        int count = 0;//记录0的个数
       
        for(int i =0;i<nums_size;i++){
        if(0==nums[i]){
            nums.erase(nums.begin()+i);//除掉0元素 除掉以后元素也会往上跑 数组会变短
            count++;//统计除掉的0元素个数
        }
        }
        if(count != 0 ){
            for(int i =0;i<count;i++ ){
                nums.push_back(0);
            }
        
        }
    }
};
```

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {//当右指针没有遍历完时
            if (nums[right]) {//如果非零
                swap(nums[left], nums[right]);//交换左右指针
                left++;//非零出现left再移动
            }
            right++;//右指针跑得更快
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s =0;//定义收集不是0的数的指针
        for(int i =0;i<nums.size();i++){
            if(0!=nums[i]){
                nums[s++] = nums[i];
            }
        }
        for (int i = s; i < nums.size(); i++) {
            nums[i]=0;
        }
    }
};
```

### 【556】重塑矩阵

​	在 MATLAB 中，有一个非常有用的函数 `reshape` ，它可以将一个 `m x n` 矩阵重塑为另一个大小不同（`r x c`）的新矩阵，但保留其原始数据。给你一个由二维数组 `mat` 表示的 `m x n` 矩阵，以及两个正整数 `r` 和 `c` ，分别表示想要的重构的矩阵的行数和列数。重构后的矩阵需要将原始矩阵的所有元素以相同的 **行遍历顺序** 填充。如果具有给定参数的 `reshape` 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int m = mat.size();//行数
        int n = mat[0].size();//列数
        if (m * n != r * c) {//如果输入了不对的矩阵就原路返回
            return mat;
        }

        vector<vector<int>> ans(r, vector<int>(c));//创造一个返回矩阵
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = mat[x / n][x % n];//返回新矩阵对应元素 = 
        }
        return ans;
    }
};
```

！创建矩阵：

```c++
//矩阵
vector<vector<int>> A;//最后一个>可以加空格
    				//其实就是容器嵌套容器, 外层容器的元素类型是 						//vector<int> ,内层容器的元素类型是 int型；
m = A.size(); //行数（A中vector的个数）
n = A[0].size();//列数（A中第1个Vector元素的个数）
//插入元素
vector<vector<int> > A;  // 大容器
//A.push_back里必须是vector
vector<int> B;  // 小容器
B.push_back(0);
B.push_back(1);
B.push_back(2);
A.push_back(B); // 小容器放入大容器
B.clear();   // 小容器元素清空
B.push_back(3);
B.push_back(4);
B.push_back(5);
A.push_back(B);
//初始化一个矩阵：
vector<vector<int>> ans(r, vector<int>(c));//r行，c列

```

### 【485】最大连续 1 的个数

max consecutive ones(easy)

给定一个二进制数组 `nums` ， 计算其中最大连续 `1` 的个数。

```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> num1;//存储1个数的数组
     	int count =0;
        int ans =0;//返回值
        for(int i=0;i< nums.size();i++){
            if(1 == nums[i]){
                count++;
            }
            if(0 == nums[i]){
                num1.push_back(count);
                count =0;//清零操作
            }
            if(i == nums.size()-1){//最后一组1
                num1.push_back(count);
            }
        }
        ans = num1[0];
        for(int i =1;i<num1.size();i++){
            if(num1[i]>ans){
                ans = num1[i];
            }
        }
        return ans;
    }
};
```

```c++
public int findMaxConsecutiveOnes(int[] nums) {
    int max = 0, cur = 0;
    for (int x : nums) {
        cur = x == 0 ? 0 : cur + 1;
        max = Math.max(max, cur);
    }
    return max;
}
```

### 【240】搜索二维矩阵

编写一个高效的算法来搜索 `*m* x *n*` 矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。
- <img src="C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230302095114415.png" alt="image-20230302095114415" style="zoom: 67%;" />

```c++
//超出了时间范围
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();//行
        int n = matrix[0].size();//列
        int flag =0;//中间值
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(target == matrix[i][j]){//遍历每行
                    flag =1;
                    return true;
                }
            }
        }
    return false;
    
    }
};
//首先要对矩阵的每行每列进行排序
//其次找到设定的target值
```

```c++
//暴力 const auto&
//当只想读取range中元素时，使用const auto&,如：for(const auto&x:range),它不会进行拷贝，也不会修改range
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto& row:matrix){
            for(int element:row){//在每排的元素，可以确定为int型
                if(element == target){
                    return true;
                }
            }
        }
        return false;
    }
};
```

```c++
//二分查找 lower_bound() 函数用于在指定区域内查找不小于目标值的==第一个元素==;
//使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            //在begin，end之间找到不小于target的元素;
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};
//const auto& row: matrix 遍历每行，就跟行是直接matrix：m = matrix.size();
```

### 【378】有序矩阵的 Kth Element

Kth Smallest Element in a Sorted Matrix ((Medium))

给你一个 `n x n` 矩阵 `matrix` ，其中每行和每列元素均按升序排序，找到矩阵中第 `k` 小的元素。
请注意，它是 **排序后** 的第 `k` 小元素，而不是第 `k` 个 **不同** 的元素。

你必须找到一个内存复杂度优于 `O(n2)` 的解决方案。

时间复杂度：(如何计算的，特别是这种logn的是怎么算出来的)

```c++
//暴力
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> rec;
        for (auto& row : matrix) {
            for (int it : row) {
                rec.push_back(it);//化成一维数组
            }
        }
        sort(rec.begin(), rec.end());//排序
        return rec[k - 1];
    }
};

```

思路非常简单：

![image-20230302220658911](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230302220658911.png)

回答几个问题：

1.mid,num,k,n,count到底代表着什么，check想实现的是什么功能

mid：mid = left + ((right - left) >> 1) 取中位数 

k：排序后第k小的元素

n:矩阵的行数

count：二维矩阵中小于等于mid的元素个数count

check想要判断count是小于k,还是大于k。如果count小于k，那么第K小的元素在矩阵的右半部分，否则在矩阵的左半部分，直到left==right（数值），就可以找到第k小的值。

2.kthSmallest实现的是什么功能

找到第K小的数值

3.left+((right-left)>>2)的意义

n**>>:** [二进制](https://so.csdn.net/so/search?q=二进制&spm=1001.2101.3001.7020)右移
举个例子: 1010 >> 1 == 0101
1010 十[进制](https://so.csdn.net/so/search?q=进制&spm=1001.2101.3001.7020) 10
0101 十进制 5
综上 >> 1 作用相当于除二

所以 **left + ((right -left) >> 1) ==> left + ((right -left)/2)**

```C++
//二分法
//找到排序后第K小的元素
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;//左下角 
        int j = 0;//左上角
        int num = 0;//初始i j [n-1][0]
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {//左半边的矩阵值总是比mid值小的
                num += i + 1;
                j++;//向右
            } else {
                i--;//向上
            }
        }
        return num >= k;//num是否大于K
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

【645】Set Mismatch(east)

集合 `s` 包含从 `1` 到 `n` 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 **丢失了一个数字** 并且 **有一个数字重复** 。给定一个数组 `nums` 代表了集合 `S` 发生错误后的结果。请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

输出的数组[重复数字，丢失数字],按照这个顺序进行输出。

1.方法一：遍历

①寻找重复数字：直接遍历不太行，会有很多特例不符合要求：比如让i从1-n开始遍历时，如果输入[2,2],那么应该输出[2,1]。输入[3,2,2]，输出[2,1].通过样例可以知道，输入的数组不一定是排序数组，所以可以先将数组进行排序，然后比较相邻的元素，找到错误的重复数字。

②寻找丢失的数字：如果丢失的数字大于 1 且小于 n，则一定存在相邻的两个元素的差等于 2，这两个元素之间的值即为丢失的数字；如果丢失的数字是 1 或 n，则需要另外判断。

![image-20230307163845072](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230307163845072.png)

```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {//1.重复 2,缺失
        int n = nums.size();
        vector<int> ans(2);//返回数组, ans[0]返回重复元素 ans[1]返回缺失元素
        sort(nums.begin(), nums.end());//排序
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];//现在的值
            if (curr == prev) {//数组元素是相邻的
                ans[0] = prev;//重复
            } else if (curr - prev > 1) {
                ans[1] = prev + 1;//缺失
            }
            prev = curr;//记录前一个值
        }
        if (nums[n - 1] != n) {//最后一个n缺失
            ans[1] = n;
        }
        return ans;
    }
};
```

### 【287】寻找重复数

给定一个包含 `n + 1` 个整数的数组 `nums` ，其数字都在 `[1, n]` 范围内（包括 `1` 和 `n`），可知至少存在一个重复的整数。假设 `nums` 只有 **一个重复的整数** ，返回 **这个重复的数** 。你设计的解决方案必须 **不修改** 数组 `nums` 且只用常量级 `O(1)` 的额外空间。

- 题目要求查找重复的整数，很容易想到使用「哈希表」，但是题目中要求「只用常量级 O(1) 的额外空间」，该方法不符合题意；（哈希表，晚上学习一下）

  但是题目中还说：「数字都在 1 到 n 之间（包括 1 和 n）」，查找一个有范围的整数，可以使用「二分查找」（这一点很重要，很多「二分查找」的问题就是要我们找一个整数）；

  首先要知道数组中的元素，min =1 max=n 。设 1≤x ≤n，那么就可以知道数组中的数，其中 ≤ x的个数k 是x 或 x+1.所以可以推导，当 k ≤ x 时，重复的数字肯定是 ＞ x的，反之就是 ≤x 的 
  
  如果前3条能够想通，那么后面的二分法就能理解了。 因为从中间找x ，可以快速确定区间

```c++
//返回重复数字
//列表发现cnt仅仅在重复数字后大于该数字
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();//数组大小
        int left = 1, right = n, ans = -1;//范围是1-n,所以n直接为
        while (left <= right) {//当left不等于right
            int mid = (left + right) >> 1;//取中值
            int cnt = 0;//比mid小的进行计数
            for (int i = 0; i < n; ++i) {
                cnt += (nums[i] <= mid);//小于mid都累加
            } 
            if (cnt <= mid) {//没有重复
                left = mid + 1;
            } else {
                right = mid - 1;//在数组的左半部分
                ans = mid;
            }
        }
        return ans;
    }
};
```

疑问：1.mid怎么确定的,为什么一会儿是mid+1,一会儿是mid-1,一会儿是mid。

2.我大概明白这个思路了，我们的目标是找重复数x，前提条件是，在x之前的元素cnt都是<=x,但是包括x在x之后的cnt>x。
根据这个思路，这个又是个确定了区间的数组，我们就可以用二分法（logn）。
假设数组是[1,3,4,2,2]。
第一轮：l=1 r=5 mid =3 此时cnt=4>x=3，那么3可能是重复数，但是还要看看左边元素的cnt是不是也是大于的。所以往左移，r = mid-1=2。
第二轮：l= 1 r =2 mid =1,此时cnt=1<=x=1,1肯定不是重复数，所以我们要往右边找，l = mid+1=2。
第三轮：l=2 r=2 mid=2,此时cnt = 3>x =2,这个时候l=r，那么可以确定2就是重复数。
现在的问题是，为什么
1.最后l=r时不一定是最优值处，比如[3,1,3,4,2],其实他一上来就找到了3，但是不能确定3左边还有没有值，这种不确定的情况下ans=3,先保存着，结果发现后面两种情况下确实都是小于的，不耽误最后的输出。
2.https://zhuanlan.zhihu.com/p/308605122

方法2：hashmap

217.存在重复元素

1.遇到数组没有限制可以先进行排序sort

给你一个整数数组 `nums` 。如果任一值在数组中出现 **至少两次** ，返回 `true` ；如果数组中每个元素互不相同，返回 `false` 。

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        int cur =-1,pre = -1;
        sort(nums.begin(),nums.end());
            for(int i = 0;i<n;i++){
            cur = nums[i];
            if(cur == pre)
            {
                return true;
            }
            pre = cur;
        }
        
        return false;
    }
};
```

### 【667】优美排列2

给你两个整数 `n` 和 `k` ，请你构造一个答案列表 `answer` ，该列表应当包含从 `1` 到 `n` 的 `n` 个不同正整数，并同时满足下述条件：

- 假设该列表是 `answer = [a1, a2, a3, ... , an]` ，那么列表 `[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|]` 中应该有且仅有 `k` 个不同整数。

返回列表 `answer` 。如果存在多种答案，只需返回其中 **任意一种** 。

![image-20230309162553619](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230309162553619.png)

```c++
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for(int i = 1;i<n-k;++i){
            ans.push_back(i);//1-n-k,前面的都是1个不同的数
        }
        for(int i = n-k,j = n;i<=j;++i,--j){
            ans.push_back(i);//n-k
            if(i!=j){
                ans.push_back(j);//n
            }
        }
        return ans;
    }
};
```

### 【697】数组的度

​	给定一个非空且只包含非负数的整数数组 `nums`，数组的 **度** 的定义是指数组里任一元素出现频数的最大值。你的任务是在 `nums` 中找到与 `nums` 拥有相同大小的度的最短连续子数组，返回其长度。

1.map和set的区别:

2.哈希表

a.hashmap的遍历：

```c++
//第一种
unordered_map<int, int> Hashmap;
for (auto p : Hashmap) {
	int front = p.first;   //key
    int end = p.second;   //value
}

//第二种
unordered_map<int, int> Hashmap;
for(auto it=Hashmap.begin();it!=Hashmap.end();it++)
{
    int front = it->first;   //key
    int end = it->second;   //value
}

//第三种
unordered_map<int,int> hash;
unordered_map<int,int>::iterator it;
it = hash.begin();
while(it != hash.end())
{
	int front= it->first;   //key
	int end = it->second;   //value
	it++;
}

```

b.map容器排序

本来map就是按照顺序大小进行排序的?

```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();//数组的个数
        int pre =-1,cur =-1,cnt =0;
        map<int, int> Hashmap;
        sort(nums.begin(),nums.end());//排序 不能改变顺序，最后是要进行输出的
        for(int i =0;i<n;i++){//得到带有
            cur = nums[i];
            if(cur == pre){
                cnt++;
            }
            else{
                Hashmap[pre] = cnt+1;//分别存入（元素值，频数）,hashmap是按降序排列的
                cnt=0;//清零操作
            }
            if(i == n-1){//nums最后一组数
                Hashmap[nums[n-1]] = cnt+1;
            }
            pre = cur;
        }
        //找出最大的频数
        
    return cnt;

    }
};
```

4. 怎么避免想要一个有序的map这个时候可以使用LinkedHashMap

LinkedHashMap在我使用的时候是有序的,毕竟其包含链表么, 链表就是,数据之间会有顺序,无论是单向链表还是双向链表,都包含,所指向的下一个节点,这次踩坑就到此为止了,下次在用Map在出现这种顺序问题,我就自己起锅炖了自己



```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;//创建一个无序的哈希表
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {//map里面存入了这个键值
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};//1次 i,i是什么意思
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto& [_, vec] : mp) {
            if (maxNum < vec[0]) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if (maxNum == vec[0]) {
                if (minLen > vec[2] - vec[1] + 1) {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};
```

①.count(),find

==使用count==，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。
==使用find==，返回的是被查找元素的位置，没有则返回map.end()。

总结1.对map进行赋值，mp[key] =value,其中key是不可以重复的，重复了就直接覆盖了，比如我之前把频数设为键值，就存不进去。

2. for (auto& [_, vec] : mp) 循环体 （对value值进行查找最大值）

### 【697】对角元素相等的矩阵 托普利茨矩阵

```c++
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();//行
        int n = matrix[0].size();//列
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][j]!=matrix[i-1][j-1]){//不能写成matrix[i+1][j+1],会越界
                    return false;
                }
            }
        }
        return true;
    }
};
```

### 【565】嵌套数组

### 【769】分隔数组

​		给定一个长度为 `n` 的整数数组 `arr` ，它表示在 `[0, n - 1]` 范围内的整数的排列。我们将 `arr` 分割成若干 **块** (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。返回数组能分成的最多块数量。

​		如数组[2,0,1,3,4]可以最佳划分出[2,0,1][3][4]这3个小数组，划分出的每个小数组在其内部重新排序后，得到[0,1,2][3][4]，拼接回数组即[0,1,2,3,4]，和题目要求符合，故返回值3

贪心？？

```c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int sum = 0; // sum记录当前区间的元素值之和
        int total = 0; // total记录当前区间的下标和
        for(int i = 0; i < arr.size(); ++i){
            sum += arr[i];
            total += i;
            // 当sum==total时，说明当前区间中所有元素和所有下标存在一一对应关系，
            // 则当前区间就可以当作一个块
            if(sum == total){
                ++ans;
                // sum = 0, total = 0;
            }
        }
        return ans;
    }
};
```

## 3.哈希表

​	哈希表使用 O(N) 空间复杂度存储数据，并且以 O(1) 时间复杂度求解问题。

### 【1】两数之和

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){//i与j要保持一致
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};
```

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


```

对于mp.find和mp.count的总结：

​     **find(key);**            //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，则返回map.end();

​      **count(key);**         //统计key的元素个数,只能是0或者1（map中不允许有重复的的数）

find最后返回的是该键的迭代器，比如一个mp={[1] =10,[2]=20,[3]=30,[4]=40}

那么pos = mp.find(3) pos：{first = 2,second = 30},最后访问元素是：pos->first pos->second

```c++
//find的用法
void test01(){
    map<int,int> m;//创建一个map
    m[1]=10;m[2]=20;m[4]=40;m[3]=30;
    map<int,int>::iterator pos = m.find(3);
    if(pos!=m.end){
        cout<<"key:"<<pos->first<<"value:"<<pos->second<<endl;
    }
    else{
        cout<<"没有找到"<<endl;
    }
}
```

```c++
//map查找与统计 定义一个结构体在，在构造的时候就比较大小，但是调试不出来..
class Solution {
public:
    class MyCompare{
    public:
    bool operator()(const int&v1,const int &v2){
        return v1>v2;}
    };
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> m;//正常顺序从小到大
     m[1]=10;m[2]=20;m[4]=40;m[3]=30;
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key:"<<it->first<<"value:"<<it->second<<endl;//正常的排序顺序
    }
    
    map<int,int,MyCompare> m2;//从大到小
    m2[1]=10;m2[2]=20;m2[4]=40;m2[3]=30;
    for(map<int,int,MyCompare>::iterator it = m2.begin();it!=m2.end();it++){
       cout<<"key:"<<it->first<<"value:"<<it->second<<endl;//正常的排序顺序
    }
    
    return {};
    }
};
```



### 【594】最长和谐子序列

```c++
class Solution{
public:
    int findLHS(vetor<int>&nums){
        unordered_map<int,int> cnt;
        int res =0;
        for(int num:nums){
            cnt[nums]++;//[元素值]=频数
        }
        for(auto [key,value]:cnt){//这种遍历方式666
            if(cnt.count(key+1)){//遍历key值，且差值为1
                res=max(res,val+cnt[key+1]);//当前值+之后的值
            }
        }
        return res;
    }
};
```

由于map的key值不能重复，所以可以记录元素的时候同时记录频数。然后善于用max函数。最后c++，for遍历的写法也很重要。

### 【c++ for循环】

补充：c++11标准之前，（C++ 98/03 标准）

```c++
//C++ 98/03 标准
for(表达式 1; 表达式 2; 表达式 3){
    //循环体
}
vector<char>myvector(arc,arc+23);
vector<char>::iterator iter;
  //for循环遍历 vector 容器
for (iter = myvector.begin(); iter != myvector.end(); ++iter) {
   cout << *iter;
}
```

- declaration：表示此处要定义一个变量，==该变量的类型为要遍历序列中存储元素的类型==。需要注意的是，C++ 11 标准中，declaration参数处定义的变量类型可以用 auto 关键字表示，该关键字可以使编译器自行推导该变量的数据类型。

- expression：表示要遍历的序列，常见的可以为事先定义好的普通数组或者容器，还可以是用 {} 大括号初始化的序列。

  ```c++
  //c++11为for添加了全新的语法格式
  for(declaration:expression){
      //循环体
  }
  
  int main(){
      char arc[]="hello!";
      for(char ch:arc){
          cout<<ch;
      }
      vector<char>myvector(arc,arc+3);//hel
      for (auto ch:myvector){
          cout<<ch;
      }
      return 0;
      
      char arc[] = "abcde";
      vector<char>myvector(arc,arc+5);//把字符转换为向量
      for(auto &ch:myvector){
          ch++;//所有字符都+1，最后输出bcdef
      }
      
  }
  ```

  ​	使用新语法格式的for遍历某个序列时，如果需要遍历的同时修改序列中元素的值，实现的方法是在declaration参数定义引用形式的变量。

  ​	*如果需要在遍历序列的过程中修改器内部元素的值，就必须定义引用形式的变量；反之，建议定义`const &`（常引用）形式的变量（避免了底层复制变量的过程，效率更高），也可以定义普通变量。

  

  ##### 【128】最长连续数列

  ​	给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

  ​	请你设计并实现时间复杂度为 `O(n)` 的算法解决此问。
  
  ```c++
  class Solution {
  public:
      int longestConsecutive(vector<int>& nums) {
          map<int,int> map;//定义map,存储数组 有重复数组
          int count =1;
          vector<int> max_count;
          int n = nums.size();
          for(int i=0;i<n;i++){
              map[nums[i]]=i;
          }
          if(!n){
              return 0;
          }
          else{
              for(auto [key,value]:map){
              if(map.count(key+1)){
                  count++;
              }
              else{
                  max_count.push_back(count);
                  count =1;//清零方便下次遇到连续值进行计算
              }
          }
          }
          int ans =max_count[0];
          for(int it:max_count){//要找到最大的连续数组
              if(it>=ans)
              {
                  ans =it;
              }    
          }
          return ans;
      }
  };
  ```
  
  总结：有两个重点，第一个是遍历的方法for(auto [key,value]:map){},c++11for这样遍历真的很好用。其次是map.count(key+1)，指的是找到key+1键值，返回0或者1.
  
  ```C++
  class Solution {//用set来做，进行去重
  public:
      int longestConsecutive(vector<int>& nums) {
          unordered_set<int> num_set;
          for (const int& num : nums) {
              num_set.insert(num);
          }
  
          int longestStreak = 0;
  
          for (const int& num : num_set) {
              if (!num_set.count(num - 1)) {
                  int currentNum = num;
                  int currentStreak = 1;
  
                  while (num_set.count(currentNum + 1)) {
                      currentNum += 1;
                      currentStreak += 1;
                  }
  
                  longestStreak = max(longestStreak, currentStreak);
              }
          }
  
          return longestStreak;           
      }
  };
  
  
  ```
  
  那么怎么判断是否跳过呢？由于我们要枚举的数 xxx 一定是在数组中不存在前驱数 x−1x-1x−1 的，不然按照上面的分析我们会从 x−1x-1x−1 开始尝试匹配，因此我们每次在哈希表中检查是否存在 x−1x-1x−1 即能判断是否需要跳过了。
  

## 4.字符串

### 【242】有效的字母异位词

给定两个字符串 `s` 和 `t` ，编写一个函数来判断 `*t*` 是否是 `*s*` 的字母异位词。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同，则称 `*s*` 和 `*t*` 互为字母异位词。

例子：可以看到s被统计了7次，会在字母对应数字处记录频数。

![image-20230320095808537](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230320095808537.png)

```c++
//判断t是否是s的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> table(26,0);//初始化table{0,0,0...0}包括26个0
        for(auto &ch:s){
            table[ch-'a']++;//ch-'a'：ch的asii值
        }
        for(auto &ch:t){
            table[ch-'a']--;
            if(table[ch-'a']<0){
            return false;
        }
        }
        return true;
    }
};
```

​	由于本题的字符串只包含 26 个小写字符，因此可以使用长度为 26 的整型数组对字符串出现的字符进行统计，不再使用 HashMap。

### 【409】最长回文串

```c++
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;//不管是奇数还是偶数，这样可以直接做
            if (v % 2 == 1 and ans % 2 == 0)//只放一个奇数在中间 当放进去ans就变成了偶数了了
                ++ans;
        }
        return ans;
    }
};

```



647. Palindromic Substrings (Medium

     

     9.Palindrome Number (Easy)

696. Count Binary Substrings (Easy)

### 【205】同构字符串

​		给定两个字符串  `s` 和 `t` ，判断它们是否是同构的。如果 `s` 中的字符可以按某种映射关系替换得到 `t` ，那么这两个字符串是同构的。每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

 s2t.count(x) //统计key的元素个数,只能是0或者1（map中不允许有重复的的数）



```c++
class Solution{
public:
     bool isIsomorphic(string s, string t) {
         unordered_map<char,char> s2t;
         unordered_map<char,char> t2s;
         int len =s.length();
         for(int i =0;i<len;i++){ 
             char x = s[i],y = t[i];//分别遍历s,t中的字符
             if((s2t.count(x)&&s2t[x]!=y)||t2s.count(y)&&t2s[y]!=x){//有重复字母，但是又不相互映射，这种情况下返回错误。
                 return false;
             }
             s2t[x] =y;
             t2s[y] =x;
         }
         return true;
     }
}
```

再总结下，这里的s2t.count相当于是在说如果哈希表中已经存在了当前的key值,那么他们的value值如果不一样的话，说明就不是映射关系。

### 【647】回文子串

给你一个字符串 `s` ，请你统计并返回这个字符串中 **回文子串** 的数目。

**回文字符串** 是正着读和倒过来读一样的字符串。

**子字符串** 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

*这道题还需要再理解一下思路*

```c++
class Solution {
  public int countSubstrings(String s) {
    int n = s.length();
    int ans = 0;
    for (int center = 0; center < n; center++) {
      ans += expand(s, center, center) + expand(s, center, center + 1);//偶数 + 奇数
    }
    return ans;
  }

  private int expand(String s, int left, int right) {
    int cnt = 0;//回文字符串频次
    while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {//边界限制   左边的字符==右边的字符
      cnt++;//频次++
      left--;//向左右扩展
      right++;
    }
    return ans;
  }
}
```

### 【9】判断一个整数是否是回文数

给你一个整数 `x` ，如果 `x` 是一个回文整数，返回 `true` ；否则，返回 `false` 。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

```c++
输入：x = 121
输出：true

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

 class Solution {
public:
    bool isPalindrome(int x) {
    if (x == 0) {
        return true;
    }
    if (x < 0 || x % 10 == 0) {//x是负数一定不是回文数 
        return false;
    }
    int right = 0;
    while (x > right) {
        right = right * 10 + x % 10;
        x /= 10;
    }
    return x == right || x == right / 10;
    }
};
```

### 【696].计数二进制子串

给定一个字符串 `s`，统计并返回*具有相同数量 `0` 和 `1` 的非空（连续）*子字符串的数量，并且这些子字符串中的所有 `0` 和所有 `1` 都是成组连续的。重复出现（不同位置）的子串也要统计它们出现的次数。

```c++
public int countBinarySubstrings(String s) {
    int preLen = 0, curLen = 1, count = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s.charAt(i) == s.charAt(i - 1)) {
            curLen++;
        } else {
            preLen = curLen;
            curLen = 1;
        }

        if (preLen >= curLen) {
            count++;
        }
    }
    return count;
}
```

## 5.链表

## 6.二叉树

二叉树是一种常见的数据结构，由节点组成，每个节点最多有两个子节点，左子节点和右子节点。二叉树可以用来表示许多实际问题，如计算机程序中的表达式、组织结构等。以下是一些二叉树的概念：

1. 二叉树的深度：从根节点到叶子节点的最长路径的长度称为二叉树的深度，也称为高度。
2. 二叉树的度：一个节点拥有的子节点数量称为该节点的度。二叉树的度为2，即每个节点最多只有两个子节点。
3. 二叉树的遍历：二叉树的遍历是指按照一定顺序访问树中的所有节点。常用的遍历方式有前序遍历、中序遍历和后序遍历。
4. 二叉查找树：二叉查找树是一种特殊的二叉树，它的左子树中所有节点的值都小于根节点的值，而右子树中所有节点的值都大于根节点的值。

二叉树的定义可以使用如下的 C++ 代码表示：

```c++
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

```

在学习二叉树的过程中，你可能需要掌握以下几个方面：

1. 二叉树的基本操作：包括二叉树的创建、遍历、搜索等。
2. 二叉查找树的实现及应用：包括二叉查找树的创建、插入、删除、查找等操作。
3. 平衡二叉树：为了解决二叉查找树在某些情况下退化为链表的问题，出现了平衡二叉树，如 AVL 树和红黑树等。
4. 线段树：线段树是一种特殊的二叉树，用于解决区间查询的问题，如区间最大值、区间和等。
5. 树状数组：树状数组也是一种特殊的二叉树，用于解决前缀和、区间和等问题。

### 6.1基础

#### 1.二叉树的建立：子树是不相交的！

![image-20230523093958412](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523093958412.png)

#### 2.基础的术语

结点的度：结点的字数个数，比如二叉树的度为2（一个节点最多有2个字数个数）

树的度：数的所有结点中最大的度数

叶结点：度为0的结点

父结点，子结点，兄弟结点（具有同一个父结点的各结点）

路径和路径的长度：从结点n1到nk,路径所包含的边的个数为路径的长度。

祖先结点，子孙结点

结点的层次：规定根结点在1层，然后后面的结点层次都依次加一

树的深度：树中国所有结点的最大层次是这棵树的深度

#### 3.树的建立

用儿子-兄弟的表示法，可以让树的每一个结点的结构都一致

![image-20230523095726650](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523095726650.png)

再旋转45°，有点类似于二叉树的结构，那么，所有的树都是可以由二叉树这种方式进行表示的。二叉树的度为2。

![image-20230523095942947](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523095942947.png)

#### 4.二叉树的定义

二叉树T：一个有穷的结点集合，二叉树的子树有**左右顺序之分**

![image-20230523100424431](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523100424431.png)

特殊的二叉树：斜二叉树，满二叉树，完全二叉树（连续结点）

![image-20230523100642545](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523100642545.png)

![image-20230523101337870](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523101337870.png)

等式两边都是树的边的个数，所有边的总是等于结点的和-1;而n0结点能够贡献0条边，n1结点能够贡献1条边，n2结点能够贡献2条边。

即n0+n1+n2-1 =n1+2n2  推得 n0 = n2+1

![image-20230523101828865](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523101828865.png)

#### 5.二叉树的存储结构

①顺序存储结构

![image-20230523103313219](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523103313219.png)

一般的二叉树也可以采用这种结构（数组存储），但是会造成空间的浪费。

②链表存储

![image-20230523103633236](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523103633236.png)

#### 6.二叉树的遍历

travelsal :先序遍历，中序遍历，后续遍历，层次遍历。

##### （1）先序遍历：

递归，链表。

![image-20230523104149370](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523104149370.png)

##### （2）中序遍历

左（叶），根，右（叶）

DBEF(左叶E是要优于跟F的，但是根B是要优于右叶F的)

![image-20230523104402600](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523104402600.png)

##### （3）后序遍历

左，右，根（先从叶节点出发）

![image-20230523104736963](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523104736963.png)

![image-20230523151449021](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523151449021.png)

每个结点都有三次被碰到的机会，但是先打印的就是先序，第二次碰到的就是中序，第三次碰到的就是后序。

（5）二叉树的非递归遍历

中序遍历非递归遍历算法。

![image-20230523152517500](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523152517500.png)

先序遍历的非递归算法：把printf往前面提

#### 7.层序遍历

二叉树遍历的核心问题：二维结构的线性化

现实是访问左结点一定要先访问父结点，如果访问了做结点，应该如何去访问右结点。

需要一个存储结构保存暂时不访问的**结点**，存储结构：堆栈、队列。

![image-20230529160200988](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230529160200988.png)

用队列实现层序遍历：遍历从根节点开始，首先要根节点入队，然后开始执行循环：**结点出队，访问该结点，其 左右儿子入队。**

​                                 层序遍历  队列

A抛出，BC入队              A         BC

B抛出 DF入队               AB        CDF

​                                    ABC      DFGI

​									ABCD    FGIE

```c++
//层序基本的过程：先从根节点入队，然后
//1)从队列中取出一个元素；2.访问元素所指的结点；3.左右孩子的指针顺序入队（非空）
void LevelOrderTraversal(BinTree BT)
{
    Queue Q;BinTree T;
    if（！BT）return;//如果是空树就直接返回
    Q = CreatQueue(MaxSize);//创建并初始化队列Q
    AddQ(Q,BT);
    while(!IsEmptyQ(Q)){
        T = DelteQueue(Q);//从队列里面抛出元素
        printf("%d\n",T->Data);//访问取出队列的结点
        if(T->Left) AddQ(Q,T->Left);
         if(T->Right)AddQ(Q,T->Right);
    }
}
```

![image-20230529165634149](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230529165634149.png)

求二叉树中的叶子结点（前序遍历）

![image-20230529165841114](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230529165841114.png)

求树的高度

![image-20230529171954280](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230529171954280.png)
