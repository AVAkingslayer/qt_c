## Qt模块移植

### 一、实现功能

​		新建项目，按要求实现需要替换功能。

#### 1、编译器选择

​		Qt_5_9_9_MinGW_32bit。

#### 2、实现要求

​		1)需要将**功能代码**和**测试代码**分文件实现。方便后续将**功能实现文件**加入到**动态库**。

​		2)**功能代码**的“.h”文件不能引用qt系统文件。只声明功能实现函数。	

​	什么是功能代码，什么是测试代码？测试代码是指我完整测试的一个demo，但是功能代码是指我引入动态库dll的代码。功能代码的h文件只能声明实现函数。

我们实验室仓库的网址：

http://dso_user2017:pxw$7463290@192.168.2.2/dso_demo.git

文档：

http://ppa2020_doc:pdfyid8Ljf@192.168.2.2/ppa2020_doc.git

如果冲突了，但是不想上传自己的代码，可以点第二个地方然后revert一下

### 二、添加到动态库（qtwinmigrate）

#### 1、工程复制

​		将新实现的QT工程项目复制到“dso_demo\qtwinmigrate\examples\qtdll”文件夹下面。

#### 2、将功能代码文件添加到动态库

1)打开qt工程“qtwinmigrate”。

2)右键点击“qtdll”,选择添加现有文件。

![](.\图片\qtdll_功能文件添加.png)

3）选择**功能文件**进行添加。

#### 3、动态库编译

1）选择“Qt_5_9_9_MinGW_32bit”编译器。

2）对**功能代码**的“.h”文件的函数声明添加前缀“extern "C" __declspec(dllexport)”。把需要的函数都囊括在里面

​	注意：如果“.h”中有中文注释，需要将**utf-8**转码为**GB2312**编码格式，因为vc6可能不能识别**utf-8**的中文编码。

3）编译工程“qtwinmigrate”，将“\dso_demo\build-qtwinmigrate-Desktop_Qt_5_9_9_MinGW_32bit-Debug\examples\qtdll\debug”文件夹下的“qtdialog.dll”，“libqtdialog.a”复制到"\dso_demo\DSO6932\libs"文件夹下面。

#### 4、调用动态库，替换功能函数

1)调用动态库

​		在需要调用动态库的".cpp"文件中引用**"QtWinMigrate.h"**，**功能代码的”.h“**文件。

2)调用功能函数。

​		注意：不能删除原实现，将原实现条件编译，改为调用动态库中的功能函数。

3）编译项目工程，验证功能是否移植成功。

#### 5、删除之前的新建项目

​		删除之前的新建项目，并提交至服务器。

#### 6、图示例子

![image-20230516095251190](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095251190.png)

![image-20230516095301521](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095301521.png)

![image-20230516095317343](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095317343.png)

![image-20230516095327719](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095327719.png)

全部改成QtFactoryDlg的类属性：

![image-20230516095739296](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095739296.png)

![image-20230516095336979](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095336979.png)

![image-20230516095349385](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516095349385.png)

### 三、实际操作

1.首先将工程文件qthelpwindow复制到qtwinmigrate里面的qtll文件里面

![image-20230516101019321](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516101019321.png)

2.可以发现这个时候还没有把文件添加到工程中

右键qtdll选择添加现有文件，可以发现这里的文件夹又多了一层，所以我们不需要把整个工程文件都添加进来，只需要添加.cpp和.h就好了

![image-20230516101359138](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516101359138.png)

现在就返回修改我想要移植的.cpp,.h类名，文件名，然后把我想添加的cpp,.h文件添加进去。

![image-20230516102136216](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516102136216.png)

![image-20230516102423805](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516102423805.png)

![image-20230516104147169](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516104147169.png)

改完以后，这是我第二次修改了，注意先renamecpp,h,ui的名称，再进ui修改的变量名称，宏声明的名称。

2.现在就移植.cpp,.h，但是我产生了一个疑问，就是ui是不需要移植的么？

 ![image-20230516104804030](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516104804030.png)

就像这样，把文件添加到.h，然后把所有.h中声明的函数前面添加![image-20230516110336302](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516110336302.png)

```c++
extern "C" __declspec(dllexport)
```

注意，这是在类外添加。

![image-20230516110714335](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516110714335.png)

但是这里构造函数，析构函数也需要重新说明么？不用声明



由于整个工程已经迁移，我们还是先pull工程，在新工程上面改

git did not exit cleanly (exit code 1) (750 ms @ 2023/5/16 11:24:37)

![image-20230516113157974](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516113157974.png)

如果显示git did not exit cleanly (exit code 1)，即有冲突的情况，那么我们首先进行压栈stack save再pull以后commit掉有问题的代码fever，再弹栈stack pop的操作，最后再push，如果还有冲突的文件，右键选中后进行revert的操作。（还需要下面了解下git原理）

2.再把整个工程复制到工程文件下，有这么一个问题，最开始我是按下Qpushbutton以后，然后再弹出的页面。

![image-20230516144041711](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516144041711.png)

找不到槽函数报错，是槽函数声明那里还要添加。

3.下面就是修改总文件里面的相关代码

①添加枚举类型

![image-20230516151144636](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516151144636.png)

![image-20230516151344547](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516151344547.png)

②添加控件（暂时先搁置）

③修改类名:

![image-20230516151812080](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516151812080.png)

④在qtfactorydlg.cpp里面添加helpwindow的路径

![image-20230516152021012](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516152021012.png)

改变这里，发现命名不是很贵方

![image-20230516152717118](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516152717118.png)

![image-20230516153128882](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230516153128882.png)

### 四、功率分析仪软件设计

ES2448型功率分析仪

数据测量、分析处理以及显示、记录

整个系统的软件主要包括三个模块：UI模块、采集处理模块、时钟模块。UI模块分别在三大模块中的三个线程中运行。

![image-20230530103521446](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230530103521446.png)

UI模块:单独出来的用户帮助界面。

采集处理模块:读取功率分析仪数据，数据采集，数据处理，数据分析等。 时钟线程负责定时（每30毫秒）刷新显示波形。

时钟模块：更新波形显示。

​	除了以上三个一直存在的线程外，在使用功率分析仪某些特定功能时，还需创建其它的辅助线程。

​	系统初始化之后进行预触发深度的设置，并根据时基情况设置系统采样率，进入数据采集过程，当FIFO满后停止采集，一次数据采集过程结束。

![image-20230530104327417](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230530104327417.png)