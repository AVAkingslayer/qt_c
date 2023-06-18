[1、QT开发概述_哔哩哔哩_bilibilihttps://www.bilibili.com/video/BV1N34y1H7x7?p=1&vd_source=d204d4ea7c273da6d06e696ab2116ac6]()

QT帮助文档路径：D:\software_new\QT5.9.9\5.9.9\mingw53_32\bin

## 0.概述

### ①基本介绍：

c++图形用户界面应用程序开发框架，可以用来开发GUI程序，也可以用来开发非GUI程序，比如控制工具和服务器。QT是面向对象的框架，使用特殊的代码生成扩展，以及一些宏（meta object compiler,moc）。

### ②QT的特点：

1.面向对象(模块化)2.控件间的相互通信（signal和slot的概念）3.友好的联机帮助，HTML，UNIX。4.自定义控件。

http://download.qt.io/archive/qt/

### ③QT的开发工具：

QT_creater+QT_SDK(IDE)

命令行： .\qt-unified-windows-x64-4.5.2-online.exe --mirror https://mirrors.aliyun.com/qt

打开工程：点击cmakelists.txt，直接拖入

mainwindow ：top带有菜单栏的，比如QTcreater的界面。

Qwdget:类似于登录界面，不带菜单栏。

```c++
#include "mainwindow.h"

#include <QApplication>
#include <Qwidget>
#include <QPushButton>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);//创建一个QT应用程序

    QWidget window;//创建一个窗口
    window.resize(500,120);//设置窗口大小 宽200像素 高120像素
    window.setWindowTitle("hello world");//设置窗口标题

    QPushButton button("click me",&window);//创建一个按钮，并将它添加到窗口
    button.setGeometry(10,10,80,30);//设置按钮的位置和大小 左上角位于（10,10），宽80像素，高30像素

    QObject::connect(&button,&QPushButton::clicked,[&](){//将按钮的clicked信号连接到一个lambda表达式上
        QMessageBox::information(&window,"message","Hello World!");//点击按钮时弹出一个对话框
    });

    window.show();//显示窗口
    return app.exec();

}

```

### ④项目结构

包括run.pro工程文件

头文件：widget.h

源文件：main.cpp wiget.cpp

界面文件：widget.ui

```C++
#ifndef WIDGET_H//#ifdef #enddef确保该类只被定义一次
#define WIDGET_H//定义宏，可在整个文件中使用

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }//Ui命名空间
QT_END_NAMESPACE

class Widget : public QWidget//wiget类，继承QWidget类
{
    Q_OBJECT//Q_OBJECT 宏用于启用 Qt 的元对象系统，它提供了在运行时对 Qt 对象进行内省并执行某些类型的动态操作（如信号槽连接）的能力。
//如果一个类中包含信号和槽，那么它必须使用 Q_OBJECT 宏来声明 Qt 元对象系统，以便编译器能够自动生成相关的代码。如果不使用 Q_OBJECT，则会导致编译错误。
public://公共属性，可以在其他类中进行访问
    Widget(QWidget *parent = nullptr);//对象后面加括号进行传参
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```

⑤wiget.ui

![image-20230321140332377](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230321140332377.png)

layouts-控件  button--按钮 item wigets 菜单栏

spacers 空格 combo box下拉框

<img src="C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230321141239911.png" alt="image-20230321141239911" style="zoom:50%;" />

每一个控件为一个对象，并且对应一个类，可以修改对象名，这样方便在程序中知道这个控件是干嘛的。

## 1.信号与槽

按钮发出了一个点击的信号，然后执行一个槽函数。

![image-20230321143832839](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230321143832839.png)

最后执行的效果就是在cmdlineEdit输入一个执行命令，并且点击确定，他就能自己弹出程序。

![image-20230321144029396](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230321144029396.png)

而且槽函数是核心，当我click按钮后，我们会返回这个qstring的字符串对象，最后两行就是运行这个进程，program就是对象。

c-windows-system32中的exe文件基本上都可以执行。

方式①：右键按钮然后直接跳到槽函数进行编写

方式②： [QScrollBar](../qtwidgets/qscrollbar.html) *scrollBar = new [QScrollBar](../qtwidgets/qscrollbar.html); 

（1）Creates a connection of the given *type* from the *signal* in the *sender* object to the *method* in the *receiver* object.

//使用宏进行参数设置：You must use the SIGNAL() and SLOT() macros when specifying the *signal* and the *method*, for example:

```c++
  QObject::connect(scrollBar, SIGNAL(valueChanged(int)),
                   label,  SLOT(setNum(int)));
```

//Note that the signal and slots parameters must not contain any variable names, only the type

在构造函数里面使用connect函数。

![image-20230321150557415](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230321150557415.png)

Qline edit类中的signals有如上的形式，空格的就是

```c++
QMetaObject::Connection QObject::connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
   //sender signal(函数形式) receiver methor  
connect(ui->cmdlineEdit,SIGNAL(returnPressed()),this,SLOT(on_comitButton_clicked()));//this调用的是这个类函数
```

特别的，QT中，slot是一个成员函数，用于响应一个或多个信号的连接。当信号被发射时，连接的槽函数会被调用，可以在槽函数中实现与信号相关的操作。

方式③：地址的形式来写+槽函数

方式④:  地址的方式+内联函数

（2）A signal can also be connected to another signal:

A signal can be connected to many slots and signals. Many signals can be connected to one slot.



```c++
class MyWidget : public QWidget
  {
      Q_OBJECT//信号signal与槽slot 宏声明

  public:
      MyWidget();

  signals:
      void buttonClicked();

  private:
      QPushButton *myButton;
  };

  MyWidget::MyWidget()
  {
      myButton = new QPushButton(this);
      connect(myButton, SIGNAL(clicked()),
              this, SIGNAL(buttonClicked()));
  }
```



### 小example :QT实现计算器

QT中使用STL容器，用栈实现计算器。

## 2.QT与c++基础

### 2.1：C++面向对象的三大特性：==封装、继承、多态==

以下是一些初学者可以尝试的方法来更好地理解类的概念：

1. 学习面向对象编程的基础知识。在学习QT5之前，需要先了解面向对象编程的基础知识，如类、对象、继承、多态等。

2. 查看QT5的类图。QT5提供了类图来展示各个类之间的继承关系和成员函数。可以通过查看类图来了解类之间的关系，以及哪些类是自己需要使用的。

3. 查看QT5的示例代码。QT5提供了很多示例代码，这些代码可以帮助初学者了解类的用法。可以查看代码来了解类的成员函数、信号和槽等。

4. 使用QT Creator创建新的类。QT Creator提供了一个工具来创建新的类。可以通过创建新的类来熟悉类的结构和用法。

5. 多做练习。可以通过多写程序来练习使用类。可以从简单的程序开始，逐步增加复杂度，来提高对类的理解。

   QT中常见的类图

   1. QWidget类图：**QWidget是QT5中最基本的窗口类，所有的窗口部件都是继承自QWidget类。QWidget类图显示了QWidget的成员函数和信号/槽，以及它派生出的子类，例如QMainWindow、QDialog等。**
   2. **QObject类图：QObject是QT5中所有类的基类，它包含了许多非常重要的成员函数和信号/槽。QObject类图显示了QObject的成员函数和信号/槽，以及它派生出的子类，例如QWidget、QThread等。**
   3. QAbstractItemModel类图：QAbstractItemModel是QT5中用于实现模型/视图架构的基类，它提供了许多成员函数用于操作和管理模型数据。QAbstractItemModel类图显示了QAbstractItemModel的成员函数和信号/槽，以及它派生出的子类，例如QStandardItemModel、QTreeModel等。
   4. QNetworkAccessManager类图：QNetworkAccessManager是QT5中用于网络访问的类，它提供了一种简单的方式来进行HTTP请求和响应。QNetworkAccessManager类图显示了QNetworkAccessManager的成员函数和信号/槽。
   5. QGraphicsScene类图：QGraphicsScene是QT5中用于实现2D图形场景的类，它提供了许多成员函数用于管理场景中的图形项。QGraphicsScene类图显示了QGraphicsScene的成员函数和信号/槽，以及它派生出的子类，例如QGraphicsView、QGraphicsItem等。

   这些是一些常见的QT5类图示例，它们可以帮助你了解QT5中的一些重要类的成员函数和继承关系。

   在QT5中，类是一个非常重要的概念。类是一种面向对象编程的基础，它可以用来封装数据和行为，并且可以用来创建对象。在QT5中，很多功能都是通过类实现的，因此熟悉类的概念对于学习和使用QT5非常重要。

### 2.2：封装

- 将==属性（变量）和行为（函数）==作为一个整体，表现生活中的事物

- 将属性和行为加以**权限和控制**

- 类中的属性和行为，统一称为成员；属性，也成为成员属性或成员变量；行为 成员函数或成员方法。

  | 权限            | 权限     | 详细信息                                                     |
  | --------------- | -------- | ------------------------------------------------------------ |
  | public（行为）  | 公共权限 | 成员类内、类外均可访问（类内访问：表示类内的成员函数中可以访问成员属性） |
  | protected       | 保护权限 | 成员类内可以访问，类外不可以访问（类外实例化对象后，不能通过对象访问）     可继承 |
  | private（属性） | 私有权限 | 成员类内可以访问，类外不可以访问（类外实例化对象后，不能通过对象访问）     不可继承 |

  **访问权限**

  C++是`Object-oriented`的语言，也就是所谓的面向对象的语言，其中最重要的时候就是类，C++类里面的成员的访问权限有三种，`public、private、protected`，**这三者在class内部都能相互访问，但是能被对象（类的实例）调用的只有public修饰的成员。**

  ```c++
   class Circle                        //定义一个叫Circle的类
    {
      public:                           //公共权限
          int m_r;                      //属性，半径
          double calculateZC()          //行为，获取周长
          {
             return 2*PI*m_r;
          }
          void set(int r)              //给属性赋值
          {
             m_r = r;   
          }
    }；
    int main()
    {
        Circle c1;             //实例化   通过圆类 创建具体的圆
        c1.m_r = 10;           //给圆对象 的属性进行赋值
        c1.set(10);
        cout << "圆的周长：" << c1.calculateZC() << endl;  //可以调用对象的行为
    }
  ```

### 2.3：class和struct的区别！！！

​	      唯一的区别在于默认的访问权限不同（就不加public、protected、private） ，==struct为公有，class默认为私有private==。

```c++
//example1
struct A {
	int a = 1; // 默认为公共权限
};
class B {//默认为private
    int b = 1; // 默认为private
};
int main() {
    A a;
    a.a = 2; // 可以访问
    B b;
    b.b = 2; // 报错！ 不能访问,变量只能在类内间进行相互访问
    
    system("pause");
    return 0;
}
//example2
class Person{
public:
    //构造函数
    Person(const std::string name,int age)//函数可以在类内访问成员变量
        ：name_(name),age_(age){}
    //成员函数
    void printInfo() const{
        std::cout<<"Name:"<<name_<<"age:"<<age_<<std::endl;
    }
private:
    //成员变量 
    std::string name_;
    int age_;
}
int main(){
    Person person(Alice,20);//创建一个 Person 对象并调用成员函数,可以对变量进行设置
    person.printInfo();//打印
    return 0;
}
//如果在class中'private'关键字下的定义的成员和函数，只能在类的内部被访问，无法从外部进行访问。
//如果需要从类的外部访问'private'成员变量，可以提供'public'成员函数来实现。
//比如 getname(name_(name)); satname(name)
```

### 2.4：对象的初始化和清理

   对象或者变量没有初始化，其使用结果是未知的，使用完一个对象或者变量，未及时清理，会造成一定的安全问题。**构造函数和析构函数会被编译器自动调用**，对象的初始化和清理是**强制**要做的。若我们不提供构造和析构函数，编译器会提供，但提供的是空实现（析构函数的函数体是空的）。

​    构造函数：初始化，创建对象时为对象的成员属性赋值，编译器自动调用；

​    析构函数：清理数据，对象销毁前系统自动调用，执行清理工作。

​           **构造函数语法：** 类名(){}

- ​    没有返回值也不写void；
- ​    函数名称和类名相同！！函数值与类名相同！！
- ​    构造函数可以有参数，可以重载；
- ​    程序在调用对象时会自动调用构造，无需手动调用，只调用一次。

​           **析构函数语法：** ~类名(){} 

- ​    析构函数没有返回值，也不写void

- ​    析构函数不可以有参数，不能发生重载

- ​    程序在对象销毁前自动调用析构函数，只调用一次

  

```c++
//mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow//在QT中，MainWindow是一个类，继承自QMainWindow类，可以用于创建主窗口。
{
    Q_OBJECT//信号与槽 用宏来声明元对象

public:
    MainWindow(QWidget *parent = nullptr); //构造函数
    //在这个构造函数中，QWidget *parent = nullptr 是一个默认参数，用于指定该类的父类，即该类所属的窗口。默认情况下，如果没有传入父类对象，就会将其设置为 nullptr，表示该类没有父类。
    ~MainWindow();//析构函数
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
```

```c++
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
//系统会自动调用这两个函数
MainWindow::MainWindow(QWidget *parent)//构造函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()//析构函数
{
    delete ui;
}


```

```c++
//main.cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//创建对象，此时自动调用 MainWindow(QWidget *parent) 构造函数来初始化对象。同样，当这个 MainWindow 对象被销毁时，就会自动调用析构函数 ~MainWindow() 来释放它占用的内存。
    w.show();//调用对象中的函数
    return a.exec();
}

```

(1)构造函数的分类

​	 分类方式：按参数（有参构造和无参构造（默认构造），按类型（普通构造和拷贝构造），==const Person &p==）

​	 调用方式：括号法、显示法、隐式转换法

​     默认情况下，系统提供函数：默认构造函数（无参）、默认析构函数（无参）、默认拷贝构造函数

   **构造函数的调用规则：**

​    <1>  若用户定义**有参构造函数**，会提供**默认拷贝构造**，但不再提供默认无参构造

​    <2> 若用户定义**拷贝构造函数**，则**不再提供**其他构造函数。需要自己写默认无参构造函数

```c++
#include "iostream"
using namespace std;
class Person
{
	public:
		int m_age;//公共变量
	Person() { cout << "无参构造函数" << endl; }
	Person(int a) { m_age = a; cout << "有参构造函数" << endl; }//有参构造，属性初始化
	Person(const Person &P) { m_age = P.m_age; }//拷贝构造，将已经实例化的对象P的所有属性拷贝到我身上来。以引用的形式拷贝（减小内存空间），同时为了防止改变原对象的属性，加上const
	~Person() { cout << "delete" << endl; }//析构函数
};

int main()
{
	cout << "Hello !" << endl;
	//括号法
	Person p;                         //默认构造函数的调用，注意！！！！不要加（），加了括号会认为是函数的声明，不会认为在创建对象。在一个函数内部声明另一个函数是允许的(void func(int a, int b);)，这里Person 相当于void, p() 相当于func() .
	Person p2(10);                    //有参构造函数的调用
	Person p3(p2);                 //拷贝构造函数的调用
									 //显示法
	Person P1;
	Person P2 = Person(10);          //有参构造，匿名对象Person(10)
	Person P3 = Person(P2);          //拷贝构造
	Person(10);                      //匿名对象，当前行执行结束后，系统立即回收匿名对象
									 // 即紧接着调用有参构造函数和析构函数，调用完了再执行下一行代码
									 //隐式转换法

	Person p4 = 10;                  //相当于Person P4 = Person(10) 有参构造，编译器会自动将隐式转化为显示构造
	Person p5 = p4;                  //相当于拷贝构造
	system("pause");
	return 0;
}
```

​       拷贝构造函数的使用场景：

- **使用一个已经创建完毕的对象来初始化一个新对象**

- 值传递的方式给函数参数传值

- 以值方式返回局部对象

  ```c++
  class Person
  {
  public:
      Person() {cout << "默认构造函数调用" << endl;}
      ~person() {cout << "析构函数调用" << ednl; }
      int m_age;
      Person(int a) {  m_age = a; cout << "有参构造函数" << endl;  }   
      Person(const Person & P){ m_age = p.m_age ; cout << "拷贝构造函数" << endl;  }
  }
  // （一）使用一个已经创建完毕的对象来初始化一个新对象
  void test01()//初始化另一个对象
  {
    Person P1(20);
    Person P2(P1);  
    cout << "P2的年龄为：" << P2.m_age << endl; // 输出20
  }
  // （二）值传递的方式给函数参数传值
  void doWork(Person p){
      xxxxxxx;
  } // 3.dowork()子函数结束之后调用Person析构函数(将拷贝出来的副本释放掉)
  void test02()
  {
     Person P; // 1.调用默认构造函数
     doWork(p); // 2.调用拷贝构造函数，拷贝出一个副本P,在doWork()函数中对副本P的任何操作都不会改变原来test02()中构造出来的P
  } // 4.test02()子函数结束后调用Person析构函数
  
  // （三）以值的方式返回局部对象
  Person doWork2()
  {
     Person P1；
     return P1; //其实之前的P1会被析构掉，然后return相当于新创建了一个P1
  }
  void test03()
  {   Person P = doWork2();}
  ```

深拷贝与浅拷贝！！！

​        浅拷贝：简单的赋值拷贝操作（等号赋值），默认拷贝函数，只是增加了一个指针指向已存在的内存地址。有指针变量，会导致堆区的内存重复释放

​        深拷贝：在堆区重新申请空间，进行拷贝操作。 ==析构函数:==堆区开辟的属性数据（指针）做释放操作.，自己写拷贝构造函数。

```c++
   class person
   {
     public:
         person(){  cout << "默认构造函数调用" << endl ; }
         person(int age,int height) 
         {  
            m_age = age ; 
            m_Height = new int(height); // 将height这个int类型的数据在堆区新开辟一个空间来存放，那么返回的是一个地址，所以此时用一个指针m_Height来接收它。
            cout << "有参构造函数调用" << endl;
         }
         person(const person &p)
         {
           m_age = p.m_age;
           m_Height = new int(*p.m_Height); // 解引用，*p.m_Height表示传入的已经实例化对象P的其中的身高属性的 值，重新开辟了一个堆区空间来存放它，将堆区地址返回给我的m_Height 指针，这样以来，原来已经实例化的对象P存放在堆区的数据和我自己存放在堆区的数据是独立的，两次调用析构函数的时候才不会重复释放同一块堆区地址。
           cout << "拷贝构造函数调用" << endl;
         }
       // 析构函数的主要作用：将堆区开辟的数据进行手动释放！！！！！！！
         ~person()   //有指针，开辟内存之后必须释放
         {
            if(m_Height != NULL) // 如果使用系统默认提供的拷贝构造函数，当出现m_Height为指针的情况，系统会默认拷贝已经实例化对象P的m_Height指针存放的内容即一个地址（如0x0011）到我自己对象的指针中，相当于P的指针和我的指针都指向同一块地址，由于析构函数中需要对堆区数据进行释放，即delete m_Height,但不能重复释放（因为P和我自己的对象都需要执行析构函数）。
            {
              delete m_Height;
              m_Height = NULL; // 防止野指针出现，进行滞空操作？？？？？？
            }
             cout << "有指针析构函数调用" << endl;
         }
         int m_age;
         int *m_Height; // 类的成员属性
   };
   void test01()
   {
     person p1(18 , 160);
     cout << "p1的年龄：" << p1.m_age << "p1的身高：" << *p1.m_Hight << endl;     //输出为年龄18
     person p2(p1);                                                             //拷贝了m_height的地址
     cout << "p2的年龄：" << p2.m_age <<  "p2的身高：" << *p2.m_Hight << endl;        
   }
```

### 2.5：this指针

   每一个非静态成员函数只会诞生一份函数实例，即多个同类型的对象会共用一块代码，那么这个代码是通过什么来区分到底是哪个对象调用的它呢？

**解决办法：**

​		this指针，指向被调用的成员函数所属的对象，这个this指针隐含在每一个**非静态成员函数**内，这样的this 指针系统默认定义好了直接用便可。

​      **this指针的本质，是==指针常量==，指针的指向是不可以修改的**

 **this指针的用途：**

​                 <1>  当形参和成员变量同名时，可用this指针来区分

​                 <2>  在类的**非静态成员函数**中返回对象本身，可用 **return *this** (解引用，得到所属的对象)

```c++
#include "iostream"
using namespace std;
class Person
{
public:
	Person(int age) {//有参构造函数，当形参和变量名同名时，可用this指针替换
		this->age= age;
	}
	void PersonAdddAge(Person &p) {//有参拷贝构造参数
		this->age += p.age;
	}
	Person& PersonAdddAge_2(Person &p) // 若是person返回一个值，则每次都是创建一个新的对象
	{
		this->age += p.age;
		return *this;
	}
	int age;//成员变量
};

int main()
{
	cout << "Hello !" << endl;
	Person p1(18);
	cout << "p1的年龄："<<p1.age << endl;//输出年龄18岁
	Person p2(10);
	Person p3(15);//实例化两个对象
	p3.PersonAdddAge(p2);//this指针指向p3,p3.age+=p2.age
	cout << "p3相加后的年龄："<<p3.age << endl;//输出年龄18岁
	Person p4 = p3.PersonAdddAge_2(p2).PersonAdddAge_2(p1).PersonAdddAge_2(p2);//链式思想，可以一直追加，由于返回的是Person对象的引用，所以可以重新构造
	cout << "p4的年龄：" << p4.age << endl;//输出年龄18岁
	system("pause");
	return 0;
}
```

①在构造函数中访问成员变量

当你在一个类的构造函数中声明了成员变量时，你可以使用`this`指针来访问这些成员变量。例如，如果你有一个`MyClass`类，并在其中声明了一个成员变量`m_value`，你可以使用以下代码在构造函数中初始化它：这里，`this`指针用于引用当前对象，并访问`m_value`成员变量。

```c++
MyClass::MyClass(int value)
{
    this->m_value = value;
}

```

②在成员函数中访问其他成员函数

当你在一个类中有多个成员函数时，你可以使用`this`指针来访问其他成员函数。例如，如果你有一个`MyClass`类，并在其中有两个成员函数`doSomething`和`doSomethingElse`，你可以使用以下代码在`doSomething`函数中调用`doSomethingElse`函数：

```c++
void MyClass::doSomething()
{
    this->doSomethingElse();
}

void MyClass::doSomethingElse()
{
    // do something else
}

```

③在槽函数中访问信号发送者

当你在Qt中使用信号和槽时，你可以使用`this`指针来访问信号的发送者。例如，如果你有一个`MyClass`类，并在其中有一个槽函数`onButtonClicked`，你可以使用以下代码在该槽函数中访问按钮对象：

```c++
void MyClass::onButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(this->sender());
    if (button) {
        // do something with the button
    }
}

```

这里，`this`指针用于引用当前对象，并使用`sender`函数获取信号发送者的指针。

希望这些例子可以帮助你理解在Qt中如何使用`this`指针。

### 2.6 静态变量static！

### 2.7 虚函数 继承 多态

#### 2.7.1继承的基本语法

类与类之间存在的特殊关系，下级成员除了拥有上一级的共性，还有自己的特点。可以减少重复代码。父子类之间的类型可以直接转换。

**语法：**==class 子类 : 继承方式 父类==

  子类也称为派生类，父类也称为基类

**派生类**中的 成员属性包含：1.从基类继承而来（共性）  2.自己新增的成员属性（个性）



```c++
class BasePage  //公共页面属性
{
public:
   void header()  { cout << "首页、登录....公共头部" << endl;}
   void footer()  { cout << "公共底部" << endl;}
   void left()    { cout << "公共分类列表" << endl;}
};
/****************************/
class Java : public BasePage   // 继承Basepage中的公共属性(public)
{
public:
    void content() { cout << "Java学科视频" << endl;}
};
class Python : public BasePage
{
public:
    void content() { cout << "Python学科视频" << endl;}
};
/****************************/
void test01()
{
  cout << "JAVA下载视频的页面如下" << endl;
  Java ja;ja.header();ja.footer();ja.left();ja.content();
  cout << "-------------------------" << emdl;
  Python py;py.header();py.footer();py.left();py.content();
}

/*****************************************************************************************/

```

#### 2.7.2继承方式

 继承方式一共有三种：公共继承、保护继承、私有继承

​     访问权限最高私有、保护、公共；**私有权限，子类永远不可以访问；保护继承，则子类都是保护属性**；公共继承，则子类属性不变，除了不可访问私有

​    先私有继承之后，再进行公共继承，依然不可以访问，因为第一次私有继承之后所有成员属性都变为私有。

 	类外只能访问共有属性的变量/函数；

```c++
class Base1{
public:
	int m_A;
protected:
    int m_B;
private://
    int m_C;
};
class Son1:public Base1//共有继承，子类中除了私有变量访问不到以外，其他的权限都不变
{
 public:
    void func(){
        m_A =10;
        m_B = 20;
    }
};

class Son2:protected Base1//保护继承，子类中除了私有变量访问不到以外，其他的权限都为保护权限
{
 public:
    void func(){
        m_A =10;
        m_B = 20;
    }
};

class Son3:private Base1//私有继承，子类中除了私有变量访问不到以外，其他的权限都为私有权限
{
 public:
    void func(){
        m_A =10;
        m_B = 20;
    }
};

class GrandSon3:public Son3//公有继承，但是变量已经变为私有继承，
{
 public:
    void func(){
        m_A =10;//无法访问，m_A已经变换属性
    }
};
void main(){
    Son1 s1;
    s1.m_A =100;//公有权限可以类外访问，m_B不可以，因为是保护权限，类外不可以访问
    Son2 s2;
    s2.m_A =10;//保护权限内外无法访问
}
```

#### 2.7.3继承中的对象模型

​	**子类继承父类，所有成员（非静态成员）**，都会继承下来。即便是父类的私有成员也是继承下来的，只是说编译器会限制子类的权限，自动隐藏了父类的私有成员。

```c++
 class Base
     {
     public:
        int m_A;
     protected:
        int m_B;
     private:
        int m_C;
     };
     class Son:public Base
     {
     public:
        int m_D;
     };
     void test01()
     {  cout <<  "size of son = " << sizeof(son) << endl;}  // 4*4 = 16， 子类继承父类，所有的成员，都会继承下来
```

#### 2.7.4继承中构造和析构顺序

​	子类继承父类后，当创建子类对象，对创建父类对象（1）先调用父类的构造函数（2）调用son的构造函数（3）son的析构函数 （4）父类的析构函数

​	先进后出 FILO

```c++
class Base{
    public:
    	Base(){cout<<"Base的构造函数"<<endl;}
    	~Base(){cout<<"Base的析构函数"<<endl;}
};
class Son:public Base
{
    public:
    	Son(){cout<<"Son的构造函数"<<endl;}
    	~Son(){cout<<"Son的析构函数"<<endl;}
};
int main(){
    Son son1;
    delete son1;
    system("pause");
	return 0;
}
```

`Base* ptr = new Son();` 和 `Son son1;` 这两种方式创建对象的区别在于它们所使用的内存分配方式不同，以及对象的生命周期和作用域不同。

`Base* ptr = new Son();` 创建了一个指向 `Son` 对象的指针，这个对象是在堆内存上分配的，使用 `new` 运算符进行内存分配。这个对象的生命周期不受限于代码块的作用域，需要手动调用 `delete` 运算符释放内存。通常情况下，这种方式可以用于创建动态对象，即在程序运行期间需要动态地创建和销毁对象的情况。

·`Son son1;` 创建了一个名为 `son1` 的 `Son` 类型的对象，这个对象是在栈内存上分配的，不需要手动释放内存。这个对象的生命周期受限于代码块的作用域，当超出这个作用域时会自动调用析构函数释放资源。通常情况下，这种方式可以用于创建静态对象，即在程序编译期间就确定了对象的个数和生命周期的情况。

需要注意的是，`Base* ptr = new Son();` 创建的对象可以通过基类指针来访问子类对象的成员，可以实现多态。而 `Son son1;` 创建的对象只能访问自身的成员和继承自基类的成员。

####  2.7.6 继承中同名成员的处理

子类和父类出现同名成员，如何通过子类对象，访问子类和父类中同名的数据？

<1> 访问子类同名成员   直接  **.**  访问即可

<2> 访问父类同名成员 需要加作用域  **::**

如果子类中出现和父类同名的成员函数，那么子类的同名成员会隐藏掉所有父类同名的成员函数（包括重载的同名函数），要是想访问父类中被隐藏的同名成员函数，必须加作用域  **::**

```c++
#include "iostream"
using namespace std;

class Base
{
public:
	Base() { m_A = 100; }//构造函数
	void func() { cout << "Base func的函数调用" << endl; }
	void func(int a) { cout << "Base int a 的函数调用" << endl; }
	int m_A;
};

class Son :public Base
{
public:
	Son() { m_A = 200; }//构造函数
	void func() { cout << "Son func的函数调用" << endl; }
	int m_A;
};

void test01()//同名函数属性
{
	Son s;//子类变量定义
	cout << "son m_A=" << s.m_A << endl; //访问子类中的m_A,子类同名成员，直接访问
	cout << "Base m_A=" << s.Base::m_A << endl;//访问父类中的m_A，子类同名成员，加作用域   
};
void test02()
{
	Son s;
	s.func();//直接调用，调的是子类的同名成员函数
	s.Base::func();//父类函数
	s.Base::func(2);//父类重载
	

};

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

那么输出为：

son m_A=200
Base m_A=100
Son func的函数调用
Base func的函数调用
Base int a 的函数调用

#### 2.7.7继承中同名静态成员

​	类的继承中，对于静态的成员属性或者是静态的成员函数的处理，和非静态的基本一致。本身，静态成员的访问方式就有两种：**通过对象，通过类名。**

​	静态成员的优点是它们可以在多个对象之间共享信息，并且在对象不可用时仍然存在。静态成员函数可以在不创建对象的情况下访问静态成员变量和其他静态成员函数，**因此它们通常用于实现全局函数或单例模式等场景。**

​	  静态成员与非静态成员出现同名，处理方式一致，==只不过静态成员的访问方式有：**通过对象和通过类名**==（因为是静态的，在编译的时候分配内存是属于全局数据区，共享一份数据）

​      <1> 访问子类静态同名成员   直接访问即可

​      <2> 访问父类静态同名成员 需要加作用域 ::

​    如果子类中出现和父类同名的静态成员函数，那么子类的同名成员会隐藏掉所有父类同名的成员函数，要是想访问父类中被隐藏的同名成员函数，加作用域::

​	静态变量和非静态变量在访问上存在一定的区别。静态：：，非静态 .



```c++
#include "iostream"
using namespace std;

class Base
{
public:
	static int m_A;//静态成员属性
	static void func() { cout << "base func调用" << endl; }
	
	int value;//非静态成员
	static int count;//静态成员
	static void printCount() {
		cout << "count=" << count << endl;//静态函数只能访问静态成员
	}
	void printVale() {
		cout << "value=" << value << endl;//非静态函数只能访问非静态变量

	}
};
int Base::m_A = 100;//静态成员属性需要在类外初始化
int Base::count = 0;//静态成员初始化

class Son :public Base
{
public:
	static int m_A;//子类与父类同名的成员
	static void func(){ cout << "son func调用" << endl; }
};
int Son::m_A = 200;
void test01() {
	Son s;
	//通过对象访问
	cout << "Son m_A =" << s.m_A << endl;
	cout << "Base m_A=" << s.Base::m_A << endl;
	//通过类名来访问
	cout << "Son m_A=" << Son::m_A << endl;//访问子作用域下的m_A
	cout << "Base m_A=" << Base::m_A << endl;//访问父作用域下的m_A
	
											 //静态成员和非静态成员的对比
	Base obj1;
	obj1.value = 1;//非静态成员
	Base::count = 10;//静态成员
	obj1.printVale();//非静态函数
	Base::printCount();//静态函数
	//Base::printVale();
}
void test02()     //同名静态成员函数
{
	Son s;
	//通过对象访问
	s.func();        //调用son中的func
	s.Base::func();  //调用Base中的func
					 //通过类名访问
	Son::func();
	Son::Base::func();
	Base::func();//与Son::Base::func()作用相同
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```



### 2.8 多态的基本概念

​      多态分为两类：

​                <1>  静态多态：**函数重载 ** 和  **运算符重载**，属于静态多态，复用函数名

​                <2>  动态多态：有继承关系的派生类、子类重写父类中的**虚函数**实现运行时多态

​          （ 重写：函数的返回值类型、函数名、参数列表，完全一致 ）

​      静态多态和动态多态的区别：

​                   静态多态的函数地址早绑定 - 编译阶段确定函数地址

​                   动态多态的函数地址晚绑定 - **运行阶段**确定函数地址

​      动态多态的使用：

​                    **父类的指针**(new哪个对象，就调用哪个对象中重写的函数）**或者引用，指向子类对象**

使用要求：1.首先得有继承关系   2.其次，子类要重写父类的成员函数且父类成员函数要加virtual 成为虚函数。

```c++
// 定义Animal类
class Animal{//父类
    public:
    	//声明虚函数makeSound 动态多态
    	virtual void makeSound(){ 
            cout<<"Animal sound"<<endl;
        }
};
class Dog:public Animal{//子类Dog继承父类Animal，继承的是public属性
    public:
     // 实现makeSound虚函数
    void makeSound(){
        cout<<"Bark!"<<endl;
    }
}
class cat:public Animal{
public:
     // 实现makeSound虚函数
    void makeSound(){
        cout<<"Meow!"<<endl;
    }
};

int main(){
    Animal* animal; // 定义Animal类型的指针animal      Animal* ptr = new Dog();
    Dog dog;// 定义Dog和Cat对象
   	Cat cat;
    animal =&dog;// 将animal指向dog对象
    // 调用animal的makeSound方法，此时由于animal指向的是dog对象，所以会调用Dog类中实现的makeSound方法
    animal->makeSound();//output:"Bark!"
    animal =&cat;
    animal->makeSound();//output:"Meow!"
    return 0;
}

//这里我们定义了一个名为makeSound的虚函数，它输出"Animal sound"。请注意，虚函数可以是纯虚函数，这意味着在基类中没有实现，必须在派生类中实现。纯虚函数用 "=0"标记。例如：
class Animal {
public:
    virtual void makeSound() = 0;
};

//当我们在子类中重写一个虚函数时，我们可以使用override关键字来确保函数名称、参数列表和返回类型与基类中的虚函数相同。这样做可以避免拼写错误或其他错误导致无法正确重写虚函数的情况。

//例如，如果我们想要在Dog类中重写Animal类中的makeSound方法，可以这样做：
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark!" << endl;
    }
};
//虚函数的用途是在运行时动态绑定函数调用。也就是说，当我们将一个父类指针指向子类对象时，调用虚函数时，程序将根据实际对象类型而不是指针类型调用正确的函数。这就是多态性的核心。
```



```c++
#include "iostream"
using namespace std;

class Animal
{
public:
	virtual void speak() { cout << "动物在说话" << endl; }//虚函数，加了virtual
};
class Cat :public Animal
{
public:
	void speak() { cout << "猫在说话" << endl; }//重写，函数返回值类型函数名都一样，也可以加virtual
};
void doSpeak(Animal &animal)
{
	animal.speak;
}

int main() {
	Cat cat;
	doSpeak(cat);
	system("pause");
	return 0;
}
```

#### 2.8.1 多态案例1-计算器

多态的优点：

 		代码组织结构清晰；可读性强；利于前期和后期的扩展以及维护（可以不用修改源码，直接扩展）。

​        在真实的开发中提倡**开闭原则**：对扩展进行开放，对修改进行关闭（如果要增加功能，不需要对父类的函数原码进行修改，而只需要修改或增加子类的功能）。

​	多态（Polymorphism）是面向对象编程中的一个重要概念。多态性是指不同对象对同一消息作出不同的响应的能力。

​	在面向对象编程中，我们通常通过继承来实现多态性。具体来说，我们可以定义一个基类，其中包含一个或多个虚函数，然后从该基类派生出一个或多个子类，并在子类中重写虚函数。当我们使用基类的指针或引用调用该虚函数时，程序将根据指针或引用所指向的对象类型，动态地调用相应的子类函数。

​	这就是多态的本质：不同的对象对同一个消息作出不同的响应。这种行为使得我们能够编写更具有通用性和灵活性的代码，因为我们可以通过使用基类的指针或引用，以一种更抽象的方式来操作对象，并且无需知道对象的具体类型。这使得代码更容易扩展和维护，因为我们可以添加新的子类来扩展程序功能，而不需要修改现有的代码。

## 3.QT常用的函数记录

### ①QWebEngineView 

​	QWebEngineView 有四个槽函数：back () 、forward ()、reload ()、stop () 实现了页面的导航功能，用四个按钮来触发相对应的4个槽函数。

### ②connect

[QMetaObject::Connection](qmetaobject-connection.html) QObject::connect(const [QObject](qobject.html#QObject) **sender*, const char **signal*, const [QObject](qobject.html#QObject) **receiver*, const char **method*, [Qt::ConnectionType](qt.html#ConnectionType-enum) *type* = Qt::AutoConnection)

### ③QKeyEvent Class

r [QEvent::KeyPress](../qtcore/qevent.html#Type-enum) and [QEvent::KeyRelease](../qtcore/qevent.html#Type-enum),键盘按下，键盘弹起

## 4.QT类库概述

### 4.1QT核心特点

​	QT的实质是用标注C++编写的类库，他为开发GUI应用程序和非GUI应用程序提供了各种类。Qt对标准C++进行了扩展，引入了一些新的概念和功能，**例如信号与槽、对象属性等。**Qt的元对象编译器（Meta-Object Compiler，MOC）是一个预处理器，在源程序被编译前先将这些Qt特性的程序转换为标准C++兼容的形式，然后再由标准C++编译器进行编译。这就是为什么在使用信号与槽机制的类里，必须添加一个Q_OBJECT宏的原因，只有添加了这个宏，moc才能对类里的信号与槽的代码进行预处理。  

​	Qt Core模块是Qt类库的核心，所有其他模块都依赖于此模块，如果使用qmake来构建项目，Qt Core模块则是被自动加入的。  Qt为C++语言增加的特性就是在Qt Core模块里实现的，这些扩展特性由Qt的元对象系统实现，包括**信号与槽机制、属性系统、动态类型转换等 **

#### 4.1.1元对象Meta-Object System  

​	1.元对象系统由以下三个基础组成。QObject类是所有使用元对象系统的类的基类。在一个类的private部分声明**Q_OBJECT**宏，使得类可以使用元对象的特性，如动态属性、信号与槽。MOC（元对象编译器）为每个QObject的子类提供必要的代码来实现元对象系统的特性。

​	QT的元对象系统：信号与槽机制、属性系统、动态类型。

   元对象系统（meta-object System）。QObejct类是所有使用元对象的类的基类，在一个类的private部分声明Q_OBJECT宏。MOC为每个Qobject的子类提供必要代码。

​	元对象的作用：（1）MOC工具读取C++源文件，当它发现类的定义里有Q_OBJECT宏时，它就会为这个类生成另外一个包含有元对象支持代码的C++源文件，这个生成的源文件连同类的实现文件一起被编译和连接。  



```c++
QObject *obj = new QPushButton
//Qobject::metaObject返回关联的元对象
QObjct *obj =new QPushButton;
obj->metaOject()->className();//返回“QPushButton”
QTimer *timer = new QTimer;//QTimer是QObect的子类
timer ->inherits("QTimer");//返回ture
timer ->inherits("QObject");//返回true
timer ->inherits("QAbtrctButton");//返回false
```

2.对于Qobject以及其子类，可以使用qobject_cast()函数进行动态投射，

QWidget的子类之一是QMywidget

```c++
QObject *obj = new QMyWidget;
QWidget *widget = qobject_cast<QWidget *>(obj); //Qobj投射到QWidget类(因为obj实际是QMyWidget类，是QWidget的子类)
QMyWidget *myWidget = qobject_cast<QMyWidget *>(obj);//投射为QMyWidget是成功的，因为qobject_cast()并不区分Qt内建的类型和用户自定义类型
QLabel *label = qobject_cast<QLabel *>(obj);//但是如果把他投影到QLabel类就是失败的，返回的label是NULL（QMyWidget不是Labbel的子类）

```

说白了，就是C++中一个继承问题，子类可以投射到父类。

#### 4.1.2属性系统

​	1.Qt提供一个Q_PROPERTY()宏可以定义属性，它也是基于元对象系统实现的。  

READ指定一个读取属性值的函数，没有MEMBER关键字时必须设置READ。

QWidget类定义属性的一些例子如下：  

```c++
Q_PROPERTY(type name READ name WRITE setname NOTIFY nameChanged)
Q_PROPERTY(bool focus READ hasFocus)
Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
Q_PROPERTY(QCursor cursor READ cursor WRITE setCursor RESET unsetCursor)
```

2.属性的使用:不管是否用READ和WRITE定义了接口函数，只要知道属性名称，就可以通过QObject::property()读取属性值，并通过QObject::setProperty()设置属性值。  

```c++
QPushButton *button = new QPushButton;//定义一个新的button指针指向QPushButton
QObject *object = button;//把object指向button，这样相当于object只用了QPushButton中的一小步分空间
object->setProperty("flat", true);//设置属性值
bool isFlat= object->property("flat");//读取属性值
//setProperty可以在运行时定义一个新的类型(动态属性)。
```



#### 4.1.3 动态属性

QObject::setProperty()  定义新的属性  QObject::property()  对属性进行查询

例如，在数据表编辑界面上，一些字段是必填字段，就可以在初始化界面时为这些字段的关联显示组件定义一个新的required属性，并设置值为“true”，如  

```c++
editName->setProperty("required", "true");
comboSex-> setProperty("required", "true");
checkAgree-> setProperty("required", "true");

*[required="true"] {background-color: lime}
```

#### 4.1.4类的附加信息

 属性系统有一个宏定义Q_CLASSINFO() ，可以为类的元对象定义“名称——值”信息，如：  

```c++
class QMyClass : public QObject
{
Q_OBJECT
Q_CLASSINFO("author", "Wang")//classinfo(0)
Q_CLASSINFO("company", "UPC")//classinfo(1)
Q_CLASSINFO("version ", "3.0.1")
QMyWidget *myWidget =new QMyWidget;
Qdebug()<<myWidget->metaOnjct()->classinfo(0).name();
...
};
```

用Q_CLASSINFO()宏定义附加类信息后，可以通过元对象的一些函数获取类的附加信息，如  

#### 4.1.5 信号与槽

​	1.两种connect的用法

```c++
//信号与槽的2种用法
//方式1：
connect(sender,SIGNAL(signal()),recevier,SLOT(slot()));
//如果信号和槽函数带有参数，需要注明参数的类型
connect(spinNum,SIGNAL(valueChanged(int)),this,SLOT(updateStatus(int)));

//方式2：
connect(lineEdit, &QLineEdit::textChanged,this,&widget::on_textChanged);
//LineEdit只有一个信号textChanged(QString),在自定义窗体类widget里定义一个槽函数
//on_textChanged(QString)，就可以用上面的语句将此信号与槽关联起来，无需出现函数参数，不需要参数类型

//总结：
//对于不同参数的同名信号就不能采用函数指针的方式进行信号与槽的关联，比如QSpinBox有两个valueChanged()信号，分别是：
void QSpinBox::valueChanged(int i)
void QSpinBox::valueChanged(const QString &text)
//即使在自定义窗体widget里定义了一个槽函数，
void onValueChanged(int i)
//使用下面语句进行关联时，编译还是会报错
connect(spinNum, &QSpinBox::valueChanged ,this,&widget::onValueChanged);
```

判断一个函数是不是槽函数：

1. 是一个成员函数
2. 声明在QObject或其子类中，并且使用Q_OBJECT宏进行声明
3. 函数名以**on_开头**（也可以通过connect函数显式连接信号和槽）
4. 返回值为void
5. **只有一个参数**，该参数是由connect函数自动传递的信号值，可以是任何Qt支持的数据类型。

```c++
void QmyWidget::on_btnBoyInc_clicked()
{//"boy长大一岁"按钮
    boy->incAge();
}

```

在这个例子中，Widget类中的on_BtnBotincr_clicked函数满足上述条件，因此可以被认为是一个槽函数。它是一个成员函数，声明在QObject的子类Widget中，使用了Q_OBJECT宏进行声明，函数名以on_开头，返回值为void，只有一个参数。

并且这里调用的是QT自动连接 信号槽的机制，所以不需要手动再去connect信号与槽。

2.使用sender（）获得信号发射者

在槽函数里，使用QObject::sender()可以获取信号发射者的指针。如果知道信号发射者的类型，可以将指针投射为确定的类型，然后使用这个确定类的接口函数.  

```c++
QspinBox *spinBox =qobject_cast<QSpinBox *>(sender());
```

这种编写代码的方式一般用于为多个**同类型组件的同一信号编写一个槽函数**，在槽函数里区分信号来源分别做处理，避免为每个组件分别编写槽函数形成的代码冗余  

同类型组件：都是spinbox

同一信号：都是agechanged信号

同一个槽函数：都反应到on_spin_valueChanged(int argl)槽函数

#### 4.1.6 元对象特性测试实例

![image-20230406193122515](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230406193122515.png)

创建一个基于Qwidget的应用程序：①点击按钮，会在文本框输出相应操作结果的文本信息。②使用了Q_CLASSINFO③使用了Q_PROPERTY④使用了信号与槽机制。

①UI设计：

display widgets（显示窗口）:label（标签设置）

![image-20230406195331394](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230406195331394.png)

plainedit是文本框，文本的显示框

gridLayout栅格布局，最后点大的界面也能实现大小的控制

②添加一个Qperson类（新建c++文件，然后选择Qobject类）

qperson.h

```c++
#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>
//继承于Qobject的QPerson类
class QPerson : public QObject
{
    Q_OBJECT
    //CLASSINFO附加信息
    Q_CLASSINFO("Author","ava");//设置作者
    Q_CLASSINFO("Company","UESTC");//设置公司
    Q_CLASSINFO("Version","1.1.0");//版本信息
    //属性信息(3个属性+1信号)
    Q_PROPERTY(type age READ age WRITE setAge NOTIFY ageChanged)//年龄 设置可读函数age 可写函数setAge NOTIFY是可选的，用于设置一个信号，当属性值变化时发射此信号ageChanged。
    Q_PROPERTY(Qstring name MEMBER m_name)//姓名访问 MEMBER指定一个成员变量与属性关联，成为可读可写的属性，无需再设置READ和WRITE。
    Q_PROPERTY(int score MEMBER m_score)

private:
    unsigned m_age =10;//年龄
    Qstring m_name;//姓名
    int m_score=79;//分数


public:
    explicit QPerson(QObject *parent = nullptr);

    int age();//和Q_PROPERTY关联的公共函数
    void setAge(int value);
    void incAge();//增加年龄 按refator生成函数，按F4回来

signals:
    void ageChanged(int value);//信号
};

#endif // QPERSON_H

```

通常情况下，**`ageChanged`信号会被连接到一个槽函数**，这个槽函数会根据新的年龄值来执行一些操作，例如更新用户界面中显示的年龄值。例如：

```c++
// 定义一个槽函数
void MyWidget::onAgeChanged(int age)
{
    ui->ageLabel->setText(QString::number(age));
}

// 连接信号和槽
QPerson *person = new QPerson;
MyWidget *widget = new MyWidget;
connect(person, &QPerson::ageChanged, widget, &MyWidget::onAgeChanged);

// 修改年龄值
person->setAge(30); // 会自动调用onAgeChanged函数更新界面

```

这样，当`person`对象的年龄值发生改变时，它会发射`ageChanged`信号，然后`widget`对象就会自动调用`onAgeChanged`函数来更新界面中的年龄值。

现在就开始定义槽函数，注意的是，槽函数可以直接在ui界面设定，也可以转到具体的cpp文件中定义/声明:

！！**搞懂connect的信号，槽函数，理清楚从哪里到哪里去**

1。首先在qperson.h里声明了Qperso类是继承于public QObject的，

定义了属性信息：CLASSINFO附加信息 定义了属性信息Q_PROPERTY  （新建CPP文件基于object类）。

声明了信号 void ageChanged(int value); 使用的时候就是&QPerson::ageChanged或者SIGNAL(ageChanged(int))

声明了三个Qperson类成员函数,用于修改Qperson对象的状态

2。其次在qperson.cpp里定义了类的成员函数，用于修改‘QPerson’的状态

```c++
QPerson::QPerson(QString fName,QObject *parent) : QObject(parent)//构造函数
int QPerson::age()
void QPerson::setAge(int value)//设置年龄
void QPerson::incAge()//增加年龄
```

3.widget.h

自定义了类间才能使用的私有变量QPerson指针类boy，girl。

自定义了槽函数：

```c++
 void on_ageChanged(int value);//年龄的变化
 void on_spin_valueChanged(int argl);//spinbox
```

四个用ui直接转成的槽函数（clear的button功能太简单了，可以直接在ui上面写）

```c++
void on_BtnBotincr_clicked();//boy增长一岁
void on_BtnGirlincr_clicked();//girl增长一岁
void on_Btnclinfo_clicked();//元信息的查看
 void on_btnGirlInc_clicked();//清理信息
```

定义了两个私有变量

```c++
QPerson *boy;
QPerson *girl;
```

3.自定义信号以及使用

 自己设计的类中可以自定义信号，**信号就是类定义里面声明的一个函数**，这个函数无需实现，只需要**emit**.

```c++
//例如，在下面的自定义类QPerson的signals部分定义一个信号ageChanged(int )。
class QPerson:public QObject
{
	Q_OBJECT
private:
	int m_age =10;
public:
	void incAge();
signals:
	void ageChanged(int value);//自定义信号函数
}
```

信号函数必须是无返回值的函数，但是可以有输入参数。信号函数无需实现，只需在某些条件下发射信号。例如，在incAge()函数中发射信号。

```c++
void QmyWidget::on_btnBoyInc_clicked()//qt信号槽机制（不用写connect函数）
{//"boy长大一岁"按钮
    boy->incAge();
}

void incAge()//公共函数
{
    m_age++;
    emit ageChanged(m_age);//发射信号
}

//这里的 ageChanged信号与on_ageChanged槽函数进行连接
boy=new QPerson("王小明");
    boy->setProperty("score",95);
    boy->setProperty("age",10);
    boy->setProperty("sex","Boy");//动态属性
//    connect(boy,SIGNAL(ageChanged(int)),this,SLOT(on_ageChanged(int)));
    connect(boy,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);//所有agechanged的信号都转到这个槽函数，包括 boy->incAge();


```

 特别的，在incAge()函数里，当私有变量m_age变化后，发射信号ageChanged(int)，表示年龄发生了变化。至于是否有与此信号相关联的槽函数，信号发射者并不管。  

​	如果在使用QPerson类对象的程序中为此信号关联了槽函数，在incAge()函数里发射此信号时，就会执行相关联的槽函数。  与connect()函数设置信号与槽关联时设置的连接类型以及信号与槽是否在同一个线程有关。

```C++
QmyWidget::QmyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QmyWidget)
{//构造函数
    ui->setupUi(this);

    boy=new QPerson("王小明");
    boy->setProperty("score",95);
    boy->setProperty("age",10);
    boy->setProperty("sex","Boy");//动态属性
//    connect(boy,SIGNAL(ageChanged(int)),this,SLOT(on_ageChanged(int)));
    connect(boy,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);//所有agechanged的信号都转到这个槽函数，包括 boy->incAge();

    girl=new QPerson("张小丽");
    girl->setProperty("score",81);
    girl->setProperty("age",20);
    girl->setProperty("sex","Girl");//动态属性
    connect(girl,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);

    ui->spinBoy->setProperty("isBoy",true); //动态属性
    ui->spinGirl->setProperty("isBoy",false);

//  不能使用此形式，因为QSpinBox有两种参数形式的valueChanged()信号
//    connect(ui->spinGirl,&QSpinBox::valueChanged,
//            this,&QmyWidget::on_spinBoy_valueChanged);
    connect(ui->spinGirl,SIGNAL(valueChanged(int)),
            this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoy,SIGNAL(valueChanged(int)),
            this,SLOT(on_spin_valueChanged(int)));
}
```

  

​	 emit ageChanged(m_age);发射信号是将信号发送给所有连接到该信号的槽函数。而ageChanged信号又会和on_ageChanged槽函数进行连接：

```c++
void QmyWidget::on_ageChanged( int value)//ageChanged()信号的槽函数
{//响应QPerson的ageChanged()信号
    Q_UNUSED(value);//避免编译器因未使用参数而发出警告信息 
    QPerson *aPerson = qobject_cast<QPerson *>(sender()); //类型投射
    QString hisName=aPerson->property("name").toString(); //姓名
//    QString hisName=aPerson->name(); //获取姓名，错误。返回的类型将是QVariant类型。QVariant是一个通用值容器类，可以存储各种类型的数据，我们需要根据具体的情况将其转换为对应的类型。
    QString hisSex=aPerson->property("sex").toString(); //动态属性
    int hisAge=aPerson->age();//通过接口函数获取年龄
//    int hisAge=aPerson->property("age").toInt();//通过属性获得年龄

    ui->textEdit->appendPlainText(hisName+","+hisSex+QString::asprintf(",年龄=%d",hisAge));
}

```

这个槽函数的核心就是在text上显示姓名(string)，性别（string）,年龄(int)。

`qobject_cast`是Qt中一个模板函数，可以进行类型转换并返回**转换后的对象指针**，若转换失败则返回`nullptr`。

在信号槽机制中，`sender()`返回发送信号的对象的指针，但是它的类型通常是`QObject*`，如果我们想要调用该对象特定的函数，我们需要将其转换为该Qperson *类型。[QObject](qobject.html#QObject) *QObject::sender() const

​	这个例子中，sender()返回一个指向QPerson的对象的指针，但是在on_ageChanged槽函数中我们需要使用QPerson对象，所以需要通过qobject_cast进行转换。

```c++
void QmyWidget::on_spin_valueChanged(int arg1)//
{//响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if (spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}
```

同理on_spin_valueChanged槽函数。spinbox的信号在帮助文档中可以查看这个控件有两个参数不同的信号：

<img src="C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230410105824042.png" alt="image-20230410105824042" style="zoom:67%;" />

```c++
void QmyWidget::on_spin_valueChanged(int arg1)
{//响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if (spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

```

```c++
void QmyWidget::on_btnClassInfo_clicked()
{//"类的元对象信息"按钮
//    const QMetaObject *meta=boy->metaObject();
    const QMetaObject *meta=girl->metaObject();
//    const QMetaObject *meta=ui->spinBoy->metaObject();
    ui->textEdit->clear();

    ui->textEdit->appendPlainText("==元对象信息==\n");
    ui->textEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));

    ui->textEdit->appendPlainText("property");
    for (int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        const char* propName=meta->property(i).name();
        ui->textEdit->appendPlainText(
           QString("属性名称=%1，属性值=%2").arg(propName).arg(boy->property(propName).toString()));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");
    for (int i=meta->classInfoOffset();i<meta->classInfoCount();++i)
    {
       QMetaClassInfo classInfo=meta->classInfo(i);
        ui->textEdit->appendPlainText(
           QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }

}
```

### 4.2Qt全局定义

#### 	4.2.1 数据类型定义

| Qt数据类型 | 等效定义     | 字节数 |
| ---------- | ------------ | ------ |
| qint8      | signed char  | 1      |
| qint16     | signed short | 2      |
| qint32     | signed int   | 4      |



| Qt数据类型 | 等效定义       | 字节数 |
| ---------- | -------------- | ------ |
| qint64     | long long int  | 8      |
| qlonglong  | long long int  | 8      |
| quint8     | unsigned char  | 1      |
| quint16    | unsigned short | 2      |
| quint32    | unsigned int   | 4      |
| qreal      | double         | 8      |

#### 4.2.2 函数

​	< QtGlobal >头文件包含一些常用函数的定义，这些函数多以模板类型作为参数，返回相应的模板类型，模板类型可以用任何其他类型替换。  

​	还有一些基础的数学运算函数在<QtMath>头文件中定义，比如三角运算函数、弧度与角度之间的转换函数等。  比如qreal  qAcos(qreal v)。

typedef qreal：Typedef for double unless Qt is configured with the -qreal float option.

| T qAbs(const T &value) | 返回变量value的绝对值 |
| ---------------------- | --------------------- |
|                        |                       |

#### 4.2.3 宏定义

**Q_DECL_OVERRIDE**  ：在类定义中，用于重载一个虚函数，例如在某个类中重载虚函数paintEvent()，可以定义如下：  

```c++
void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;
```

**Q_DECL_FINAL**  :这个宏将一个虚函数定义为最终级别，不能再被重载，或定义一个类不能再被继承，示例如下：  

```c++
class QRect Q_DECL_FINAL { // QRect不能再被继承
// ...
};
```

**Q_UNUSED(name):  **这个宏用于在函数中定义不在函数体里使用的参数，示例如下：

```c++
void MainWindow::on_imageSaved(int id, const
QString &fileName)
{
Q_UNUSED(id);
LabInfo->setText("图片保存为： "+fileName);
}
```

在这个函数里，id参数没有使用。如果不用Q_UNUSED(id)定义，编译器会出现参数未使用的警告。

**foreach(variable, container)  :**

foreach用于容器类的遍历，例如  

```c++
foreach(const QString &codeName,recorder->supportedAudioCodecs())
    ui->comboCodec->addItem(codecName);
```

**qDebug(const char *message, ...)**：

  类似的宏还有qWarning、qCritical、qFatal、qInfo等，也是用于在debugger窗体显示信息。  

### 4.3容器类

#### 	4.3.1 容器类概述  

​		Qt提供了多个基于模板的容器类，这些容器类可以用于存储指定类型的数据项，例如常用的字符串列表类QStringList就是从容器类 QList<QString>继承的，实现对字符串列表的添加、存储、删除等操作。  	

​		比如定义了一个QList容器类的变量aList,他的数据项是QString,所以aList可以用于处理字符串表，例如：

```c++
aList.append("Monday");
aList.append("Tuesday");
aList.append("Wednesday");
QString str=aList[0];
```

​		Qt的容器类分为顺序容器（sequential containers）和关联容器（associative containers）   有Java类型的迭代类和STL类型的迭代类。Java类型的迭代类易于使用，提供高级功能，而STL类型的迭代类效率更高一些。  

#### 4.3.2 顺序容器类  

​	Qt的顺序容器类有**QList、QLinkedList、QVector、QStack和QQueue。**  

①QList	

QList是最常用的容器类，虽然它是以数组列表（array-list）的形式实现的，但是在其前或后添加数据非常快，QList以下标索引的方式对数据项进行访问  

​	QList用于添加、插入、替换、移动、删除数据项的函数有：insert()、replace()、removeAt()、move()、swap()、append()、prepend()、removeFirst()和removeLast()等。  

​	QList提供下标索引方式访问数据项，如同数组一样，也提供at()函数，例如  

```c++
QList<QString> list;
list << "one" << "two" << "three";
QString str1=list[1]; //str1=="two"
QString str0=list.at(0); //str0=="one"
```

②QLinkedList  

除了不提供下标索引的数据项访问外，QLinkedList其他接口函数与QList相同。

③Qvector

QVector<T>提供动态数组的功能，以下标索引访问数据。QVector的函数接口与QList几乎完全相同， QVector<T>的性能比QList<T>更高，因为QVector<T>的数据项是连续存储的。

④QStack<T>是提供类似于堆栈的后入先出（LIFO）操作的容器类，push()和pop()是主要的接口函数。例如：  

```c++
QStack<int> stack;
stack.push(10);
stack.push(20);
stack.push(30);
while (!stack.isEmpty())
cout << stack.pop() << endl;
```

程序会依次输出30，20，10 。

⑤QQueue  

  QQueue<T>是提供类似于队列先入先出（FIFO）操作的容器类。enqueue()和dequeue()是主要操作函数。例如：

```c++
QQueue<int> queue;
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
while (!queue.isEmpty())
cout << queue.dequeue() << endl;
//会输出10，20，30
```

  4.3.3 关联容器类

​	Qt还提供关联容器类QMap、QMultiMap、QHash、QMultiHash和QSet。 QMultiMap和QMultiHash支持一个键关联多个值， QHash和QMultiHash类使用散列（Hash）函数进行查找，查找速度更快。1．QSet

 2.QMap

### 4.4 容器类的迭代    

Qt有两种迭代器类：Java类型的迭代器和STL类型的迭代器。  

### 4.5 Qt基本模块

Qt基本模块：

| 模块                 | 描述                             |
| -------------------- | -------------------------------- |
| Qt Core              | 其他模块都用到的核心非图形类     |
| Qt GUI               | 设计GUI界面的基础类，包括OpenGL  |
| Qt Multimedia        | 音频、视频、摄像头和广播功能的类 |
| Qt MultimediaWidgets | 实现多媒体功能的界面组件类       |

| 模块              | 描述                                             |
| ----------------- | ------------------------------------------------ |
| Qt Network        | 使网络编程更简单和轻便的类                       |
| Qt QML            | 用于QML和JavaScript语言的类                      |
| Qt Quick          | 用于构建具有定制用户界面的动态应用程序的声明框架 |
| Qt Quick Controls | 创建桌面样式用户界面，基于Qt Quick的用户界面控件 |
| Qt Quick Dialogs  | 用于Qt Quick的系统对话框类型                     |
| Qt Quick Layouts  | 用于Qt Quick 2界面元素的布局项                   |
| Qt SQL            | 使用SQL用于数据库操作的类                        |
| Qt Test           | 用于应用程序和库进行单元测试的类                 |
| Qt Widgets        | 用于构建GUI界面的C++图形组件类                   |

QT Core和QT Gui模块是自动被加入的，其他的模块可以在.pro文件里面自行添加。

## 5.常用界面设计组件

Qt类库为应用程序设计提供了大量的类，本章主要介绍设计GUI应用程序常用的各种界面组件的使用，这些是设计GUI应用程序的基础。

## 6.常用界面设计组件

### 6.1标准对话框

Qt为应用程序设计提供了 一些常用的标准对话框，如打开文件对话框、选择颜色对话框、信息提示和确认选择对话框、标准输入对话框等，用户无需再自己设计这些常用的对话框，这样可以减少程序设计工作量。 Qt预定义的各标准对话框的类，及其主要静态函数的功能见表6-1。（截取部分）

| QInputDialog输入对话框     | QString getText()          | 输入单行文字 |
| -------------------------- | -------------------------- | ------------ |
| int getInt()               | 输入整数                   |              |
| double getDouble()         | 输入浮点数                 |              |
| QString getItem()          | 从一个下拉列表框中选择输入 |              |
| QString getMultiLineText() | 输入多行字符串             |              |

| 对话框                    | 常用静态函数名称             | 函数功能       |
| ------------------------- | ---------------------------- | -------------- |
| QMessageBox消息框         | StandardButton information() | 信息提示对话框 |
| StandardButton question() | 询问并获取是否确认的对话框   |                |
| StandardButton warning()  | 警告信息提示对话框           |                |
| StandardButton critical() | 错误信息提示对话框           |                |
| void about()              | 设置自定义信息的关于对话框   |                |
| void aboutQt()            | 关于Qt的对话框               |                |

### 6.2自定义对话框以及调用



### 6.3多窗体 应用程序设计

#### 6.3.1主要的窗体类以及用途

​	常用的窗体基类：QWidget、QDialog和QMainWindow 。QWidget直接继承于QObject。 Qobject---QWidget(QDialog,QMainWindow,QSplashScreen,QMdiSubWindow,QDesktopWidget)、QWindow

其中，QWindow通过底层的窗口系统表示一个窗口的类，一般作为一个父容器的嵌入式窗体，不作为独立的窗体。

![image-20230410181858462](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230410181858462.png)

#### 6.3.2 窗体类重要特性的设置

窗体的运行特性可以通过QWidget的一些函数进行设置，像6.2节介绍对话框的创建和使用时，有如下的代码。  

```c++
dlgLocate = new QWDialogLocate(this);
dlgLocate->setAttribute(QT::WA_DeleteOnClose);//设置窗体的显示属性
QT::WindowFlags flags = dlgLocate->windowFlags();
dlgLocate->setWindowFlags(flags|QT::WindowStaysOnTopHint);//设置窗体的运行属性

//函数原型 在QwebEngine里面
void QWebEngineSettings::setAttribute(WebAttribute attribute, bool on)
//在QWidget里面
void QWidget::setAttribute(Qt::WidgetAttribute attribute, bool on = true)
//Sets the attribute attribute on this widget if on is true; otherwise clears the attribute.ture是设置属性，false是清除属性

```

##### ①Qt::WidgetAttribute

特别的，枚举类型Qt::WidgetAttribute定义了窗体的一些属性，可以打开或者关闭这些属性

| 常量                     | 意义                              |
| ------------------------ | --------------------------------- |
| Qt::WA_AcceptDrops       | 允许窗体接收拖放来的组件          |
| Qt::WA_DeleteOnClose     | 窗体关闭时删除自己，释放内存      |
| Qt::WA_Hover             | 鼠标进入或移出窗体时产生paint事件 |
| Qt::WA_AcceptTouchEvents | 窗体是否接受触屏事件              |

##### ②setWindowFlags()函数  

setWindowFlags()函数用于设置窗体标记，其函数原型是：  

```c++
void setWindowFlags(Qt::WindowFlags type)//用于同时设置多个标记
void QWidget::setWindowFlag(Qt::WindowType flag, bool on = true)//用于一次设置一个标记
```

枚举类型Qt::WindowType常用的常量值

| 常量               | 意义                                                         |
| ------------------ | ------------------------------------------------------------ |
| 表示窗体类型的常量 |                                                              |
| Qt::Widget         | 这是QWidget类的缺省类型。这种类型的窗体，如果它有父窗体，就作为父窗体的子窗体；否则就作为一个独立的窗口 |
| Qt::Window         | 表明这个窗体是一个窗口，通常具有窗口的边框、标题栏，而不管它是否有父窗体 |
| Qt::Dialog         | 表明这个窗体是一个窗口，并且要显示为对话框（例如在标题栏没有最小化、最大化按钮）。这是QDialog类的缺省类型 |
| Qt::Popup          | 表明这个窗体是用作弹出式菜单的窗体                           |
| Qt::Tool           | 表明这个窗体是工具窗体，具有更小的标题栏和关闭按钮，通常作为工具栏的窗体 |

| 常量                                           | 意义                                                        |
| ---------------------------------------------- | ----------------------------------------------------------- |
| Qt::ToolTip                                    | 表明这是用于Tooltip消息提示的窗体                           |
| Qt::SplashScreen                               | 表明窗体是splash屏幕，是QSplashScreen类的缺省类型           |
| Qt::Desktop                                    | 表明窗体是桌面，这是QDesktopWidget类的类型                  |
| Qt::SubWindow                                  | 表明窗体是子窗体，例如QMdiSubWindow就是这种类型             |
| 控制窗体显示效果的常量                         |                                                             |
| Qt::MSWindowsFixedSizeDialogHint               | 在Windows平台上，使窗口具有更窄的边框，用于固定大小的对话框 |
| Qt::FramelessWindowHint                        | 创建无边框窗口                                              |
| 定制窗体外观的常量，要定义窗体外观，需要先设置 |                                                             |
| Qt::CustomizeWindowHint                        |                                                             |
| Qt::CustomizeWindowHint                        | 关闭缺省的窗口标题栏                                        |
| Qt::WindowTitleHint                            | 窗口有标题栏                                                |
| Qt::WindowSystemMenuHint                       | 有窗口系统菜单                                              |

| 常量                            | 意义                       |
| ------------------------------- | -------------------------- |
| Qt::WindowMinimizeButtonHint    | 有最小化按钮               |
| Qt::WindowMaximizeButtonHint    | 有最大化按钮               |
| Qt::WindowMinMaxButtonsHint     | 有最小化、最大化按钮       |
| Qt::WindowCloseButtonHint       | 有关闭按钮                 |
| Qt::WindowContextHelpButtonHint | 有上下文帮助按钮           |
| **Qt::WindowStaysOnTopHint**    | 窗口总是处于最上层         |
| Qt::WindowStaysOnBottomHint     | 窗口总是处于最下层         |
| Qt::WindowTransparentForInput   | 窗口只作为输出，不接受输入 |

##### ③setWindowState()函数  

setWindowState()函数使窗口处于最小化、最大化等状态，其函数原型是  

```c++
void QWidget::setWindowState(Qt::WindowStates windowState)
```

| 常量                 | 意义                                 |
| -------------------- | ------------------------------------ |
| Qt::WindowNoState    | 正常状态                             |
| Qt::WindowMinimized  | 窗口最小化                           |
| Qt::WindowMaximized  | 窗口最大化                           |
| Qt::WindowFullScreen | 窗口填充整个屏幕，而且没有边框       |
| Qt::WindowActive     | 变为活动的窗口，例如可以接收键盘输入 |

##### ④setWindowModality()函数 

 setWindowModality()函数用于设置窗口的模态，只对窗口类型有用。 

 表6-5 枚举类型Qt:: WindowModality的常量

| 常量                 | 意义                                           |
| -------------------- | ---------------------------------------------- |
| Qt::NonModal         | 无模态，不会阻止其他窗口的输入                 |
| Qt::WindowModal      | 窗口对于其父窗口、所有的上级父窗口都是模态的   |
| Qt::ApplicationModal | 窗口对整个应用程序是模态的，阻止所有窗口的输入 |

##### ⑤setWindowOpacity()函数  

```c++
void QWidget::setWindowOpacity(qreal level)  
```

参数level是1.0（完全不透明）至0.0（完全透明）之间的数。窗口透明度缺省值是1.0，即完全不透明。  

### 6.4时间日期与定时器

#### 6.4.1.QT时间日期类

QTime  ，QDate，QDateTime  （时间-日期-日期时间）

设置一个定时器的定时周期为1000ms，那么1000ms就会发射定时器的timeout()信号

QT中的定时器类是QTimer,他是直接从QObject类中继承而来的，不是界面组件类

#### 6.4.2.日期时间数据与字符串之间的转换

#### 6.4.3.QCalendarWidget日历组件

#### 6.4.4.定时器的使用

![image-20230523160427046](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230523160427046.png)

还有什么时候在多线程中使用Qtimer？

QT的定时器类是Qtimer，QTimer主要的属性是interval，是定时中断的周期，单位毫秒。QTimer主要的信号是timeout()，在定时中断时发射此信号，要想在定时中断里做出响应，这就需要编写timeout()信号的槽函数 。

关于Qtimer的定义，调用：

a)构造函数里面创建定时器，定于中断时间，每1s中断一次，转到槽函数on_timer_timeout（）

```c++
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    fTimer=new QTimer(this);  //创建定时器
    fTimer->stop();
    fTimer->setInterval(1000);//设置定时周期,单位：毫秒（这里想当于1s）
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout())); //关联定时器的信号与槽 每1s以后发送timeout()信号
}
```

b）on_timer_timeout()槽函数

```c++
void Dialog::on_timer_timeout()
{ //定时器中断响应槽函数
    QTime curTime=QTime::currentTime(); //获取当前时间

    ui->LCDHour->display(curTime.hour()); //显示  小时

    ui->LCDMin->display(curTime.minute());//显示  分钟

    ui->LCDSec->display(curTime.second());//显示  秒

    int va=ui->progressBar->value(); //读取progressBar的数值
    va++;
    if (va>100)//100S
        va=0;
    ui->progressBar->setValue(va); //设置progressBar的数值 刷新progressBar的进程
}
```

c)定时器/计数器启动/关闭

```c++
//在.h文件里面定义
private:
    QTimer *fTimer;  //定时器

    QTime   fTimeCounter;//计时器


void Dialog::on_btnStart_clicked()
{
fTimer->start();//定时器开始工作
fTimeCounter.start();//计时器开始工作
ui->btnStart->setEnabled(false);
ui->btnStop->setEnabled(true);
ui->btnSetIntv->setEnabled(false);
}

void Dialog::on_btnStop_clicked()
{
fTimer->stop(); //定时器停止
int tmMsec=fTimeCounter.elapsed();//毫秒数
int ms=tmMsec%1000;
int sec=tmMsec/1000;
QString str=QString::asprintf("流逝时间：%d 秒，
%d 毫秒",sec,ms);
ui->LabElapsTime->setText(str);
ui->btnStart->setEnabled(true);
ui->btnStop->setEnabled(false);
ui->btnSetIntv->setEnabled(true);
}

```





## 7.实例

### 7.1QT实现按下esc键关掉网页

```c++
Contents
Properties
Public Functions
Reimplemented Public Functions
Public Slots
Signals
Protected Functions
Reimplemented Protected Functions
Detailed Description
```

this指针指向的是子类？还是类？

### 7.2混合方式UI设计

如某些组件无法可视化地添加到界面上，比如在工具栏上无法可视化添加ComboBox组件，而用代码就可以。  混合UI方式设计可以提高设计UI的效率。

同时用这个实例讲解如何使用资源文件、如何使用Actions，如何设计主窗口里的菜单、工具栏和状态栏  。

![image-20230328101403390](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230328101403390.png)

先将所有在UI设计器里可设计的静态UI元素都用可视化的方式实现，不能在UI设计器里可视化设计的再用代码实现 

![image-20230328113244566](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230328113244566.png) 

注意事项：

在mainwidow.ui中最下面有acttioneditor以及 signa_slotseditor，一个是图形化界面，一个对应的信号和槽函数。

action是非常有用的类，可以创建菜单栏、工具栏按钮

![image-20230328141707362](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230328141707362.png)

(1)statusBar()

在Qt中，默认情况下，状态栏位于MainWindow的底部，通常是在窗口左下角。状态栏可以用来显示一些与应用程序状态相关的信息，例如当前时间、进度条、提示信息等。

在MainWindow中，可以使用QStatusBar类来创建和管理状态栏。QStatusBar类提供了一系列的函数来操作状态栏，例如addWidget()函数可以将一个QWidget对象添加到状态栏中，showMessage()函数可以在状态栏中显示一条消息，clearMessage()函数可以清除状态栏中的消息等等。

状态栏通常是通过调用MainWindow的setStatusbar()函数来设置的，例如：

```c++
cppCopy codeQLabel *label = new QLabel("Ready", this);
statusBar()->addWidget(label);
```

Action的enabled和checked属性的更新  

快捷键：F4 同名ch文件来回切换

​				F2 跟踪光标下的符号 函数体申明和函数实体

### 7.3多窗体类以及用途

#### 7.3.1搭建UI

建立resource，引入图标

![image-20230411142002607](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230411142002607.png)

![img](https://img-blog.csdnimg.cn/20201124191319449.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzE2NTA0MTYz,size_16,color_FFFFFF,t_70)

右键能够添加menubar,action可以直接从其他项目那里复制，这样的话可以简化不少步骤

![image-20230411143806692](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230411143806692.png)

![image-20230411143956150](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230411143956150.png)

toolbar这里把文字显示出来

```c++
setCentralWidget(ui->plainTextEdit);
```

!QT遇到显示图标不完整的时候可以用到左侧的项目，然后点击取掉勾选[Shadow](https://so.csdn.net/so/search?q=Shadow&spm=1001.2101.3001.7020) build，然后对项目进行重新构建。

qt生成可执行文件.exe，参考文章[(83条消息) qt如何生成exe文件并运行_qt生成exe文件_何朴尧 的博客-CSDN博客](https://blog.csdn.net/qq_39054069/article/details/96481902)

tabwiget，嵌入式网页

tabcloseable::默认是可以关闭的网页

![image-20230411151209410](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230411151209410.png)

最后完成主窗口的设计

#### 7.3.2子窗口的设计

实例除了主窗口外，还有两个窗口和两个对话框

**QFromDoc**:继承于Qwidget可视化窗口 "嵌入式Widget"“独立widget窗口”

QFromTable:继承MainWindow可视化窗体 “嵌入式mainwindow”"独立MainWindow"表格

![image-20230411154353556](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230411154353556.png)

生成子窗体需要创建的文件

#### 7.3.3QTabWidget类

**FromDoc**:继承于Qwidget可视化窗口 "嵌入式Widget"“独立widget窗口”，这个类是我自己定义的。在这里面我可以设置子界面的内容

在mainwindow里面创建了一个FormDoc对象，并将主窗口指针作为父对象传递给他。

同时可以通过tabwiget设置子页面状态栏不同的状态。

enum QTabWidget::TabPosition

This enum type defines where [QTabWidget](qtabwidget.html) draws the tab row:

方向键盘控制

| Constant          | Value | Description                                   |
| ----------------- | ----- | --------------------------------------------- |
| QTabWidget::North | 0     | The tabs are drawn above the pages.           |
| QTabWidget::South | 1     | The tabs are drawn below the pages.           |
| QTabWidget::West  | 2     | The tabs are drawn to the left of the pages.  |
| QTabWidget::East  | 3     | The tabs are drawn to the right of the pages. |

#### 7.3.4QTextCursor类

Public Types
Public Functions
Detailed Description

 [QTextCursor](qtextcursor.html) 提供了API了修改QTextDocuments

```c++
int QTextCursor::positionInBlock() const//当前状态
void QTextCursor::removeSelectedText()
void QTextCursor::select(SelectionType selection)
```

```c++
QTextBrowser* textBrowser = new QTextBrowser(this);
textBrowser->setCursorWidth(2); // 设置光标宽度
textBrowser->setTextCursor(QTextCursor()); // 隐藏光标
QPalette p = textBrowser->palette();
p.setColor(QPalette::TextCursor, Qt::black); // 设置光标颜色
textBrowser->setPalette(p);

```

```c++
void FormDoc::keyPressEvent(QKeyEvent *event)
{
    QTextCursor cursor = textBrowser->textCursor();
    switch (event->key()) {
        case Qt::Key_Left:
            cursor.movePosition(QTextCursor::Left);
            break;
        case Qt::Key_Right:
            cursor.movePosition(QTextCursor::Right);
            break;
        case Qt::Key_Up:
            cursor.movePosition(QTextCursor::Up);
            break;
        case Qt::Key_Down:
            cursor.movePosition(QTextCursor::Down);
            break;
        case Qt::Key_Return: // 处理回车键
            if (cursor.charFormat().isAnchor()) {
                QTextAnchor* anchor = cursor.charFormat().anchor();
                if (anchor) {
                    QString link = anchor->data().toString();
                    QDesktopServices::openUrl(QUrl(link)); // 打开链接
                    return;
                }
            }
            break;
        default:
            QWidget::keyPressEvent(event);
            break;
    }
    textBrowser->setTextCursor(cursor);
}

```

关于为什么声明变量时，QTextCursor不用指针类型，但是QTextEdit派生类要用指针类型

​	QTextCursor是一个类，而不是一个指针类型。与指针不同，您可以直接创建QTextCursor对象，而无需使用new操作符来分配内存。例如，以下代码创建一个QTextCursor对象并将其分配给名为cursor的变量：

```c++
cppCopy code
QTextCursor cursor;
```

​	QTextEdit是一个QWidget派生类，因此它是一个QObject的子类，可以通过new操作符来创建并返回指向其实例的指针。例如，以下代码创建一个QTextEdit对象并将其分配给名为textEdit的变量：

```c++
cppCopy code
QTextEdit *textEdit = new QTextEdit();
```

​	这里使用指针是因为QWidget派生类需要在堆上分配内存，并通过指针进行访问。与QTextCursor不同，它们的生命周期可以通过delete运算符来管理，以确保在不再需要它们时释放内存。

​	派生类不一定需要使用指针类型，但通常情况下，我们会使用指针来引用它们的实例，因为派生类往往比较大且具有动态分配的资源，如QWidget派生类。因此，将其作为指针分配到堆上并通过指针来访问是比较常见的做法。

​	另一方面，对于值类型的类，如QTextCursor，它们通常较小且不需要动态分配内存，因此通常会将它们作为变量或成员对象直接创建。这样做可以避免使用指针和动态内存分配，减少代码的复杂度和内存分配的成本。

​	总之，选择使用指针还是值类型取决于类的大小、生命周期和使用场景等因素。在开发应用程序时，需要根据具体情况来选择合适的方式。

​	因为要用锚点，所以必须要查看htm的代码。但是CTRL+u以后改不了。因为加载不出来htm的代码，于是就想着还是打开html代码，但是发现用textstream的方式只能打开文字，不能打开图片，表格，所以现在需要第三份库 libmttnl来提取MHTML文件中的HTML代码、图片、样式表、脚本和其他资源。



#### 7.3.5光标、锚点、enter功能实现

​	在html文本中的目录，一般使用的是锚点实现。

锚点是HTML中的超链接，可以在当前界面中跳转到指定的位置。

现在还剩鼠标光标点击的问题，以及点击以后的enter键进入的问题。

文件打开的demo

多线程的demo

​	如果您想在Qt应用程序中查看文档时显示光标，您可以使用QTextCursor类。这个类提供了一种在文档中移动和编辑文本的方式。

### 7.4Qt焦点事件

设置焦点：打开带有百度主页或者其他带有编辑框的页面时，不需要使用鼠标点击编辑框就可以直接输入文字等信息

无需点击，因为搜索框设置了焦点.

一个空间要先设置他的焦点事件的模式，及窗口是如何接受焦点事件的（通过鼠标单击、tab键、不接受焦点事件）

```c++
focusPolicy : Qt::FocusPolicy
This property(属性) holds the way the widget accepts keyboard focus
The policy is Qt::TabFocus if the widget accepts keyboard focus by tabbing, Qt::ClickFocus if the widget accepts focus by clicking, Qt::StrongFocus if it accepts both, and Qt::NoFocus (the default) if it does not accept focus at all.
You must enable keyboard focus for a widget if it processes keyboard events. This is normally done from the widget's constructor. For instance, the QLineEdit constructor calls setFocusPolicy(Qt::StrongFocus).
If the widget has a focus proxy, then the focus policy will be propagated to it.
Access functions:

Qt::FocusPolicy 
focusPolicy() const
void 
setFocusPolicy(Qt::FocusPolicy policy)

See also focusInEvent(), focusOutEvent(), keyPressEvent(), keyReleaseEvent(), and enabled.
```

设置获得焦点的方式

Constant	Value	Description
Qt::TabFocus	0x1	通过Tab键获得焦点
Qt::ClickFocus	0x2	通过被单击获得焦点
Qt::StrongFocus	TabFocus | ClickFocus | 0x8	可通过上面两种方式获得焦点
Qt::WheelFocus	StrongFocus | 0x4	类似Qt::StrongFocus只不过再加上鼠标滑轮
Qt::NoFocus	0	不能通过上两种方式获得焦点(默认值),setFocus仍可使其获得焦点.

当前有焦点的时间的窗口只能有一个，一个窗口获取焦点事件或失去焦点事件时，可能需要相应的操作，或者如何判断一个子窗口有没有焦点事件。Qt中亦有相应的函数。

```c++
[virtual protected] void QWidget::focusInEvent(QFocusEvent *event)//获得焦点事件
 [virtual protected] void QWidget::focusOutEvent(QFocusEvent *event)//失去焦点事件，需要我们重写
 
bool hasFocus() const//判断一个窗口是否有焦点，返回bool值
See also setFocus(), clearFocus(), setFocusPolicy(), and QApplication::focusWidget().
    
void QWidget::setFocus ( Qt::FocusReason reason )
void QWidget::clearFocus ()
//这两个函数就是设置或清除焦点事件的。
```

!!注：QT焦点方向键控制光标移动，改变选中的控件。

### 7.5QT改mainwindow的名字为helpWindow

不是所有的mainwindow都要改，父类的不能改,所以必须一个一个手动改构造函数的类名。

1.把.c,.h,.ui中的名字全部换成help_window，rename一个文件以后，QT会自动问你需不需要把其他的文件也替换了，直接让它帮你换了就好（renames）。记得把ui_helpWindow.h也改了。

2..进入ui界面，把mainwindow的标题（属性栏）换成help_window。

main.cpp

```c++
#include "helpWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    helpWindow w;
    w.show();
    return a.exec();
}

```

helpWindow.cpp

```c++
#include "helpWindow.h"
#include "ui_helpWindow.h"

helpWindow::helpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

helpWindow::~helpWindow()
{
    delete ui;
}

```

helpWindow.h

```c++
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class helpWindow : public QMainWindow
{
    Q_OBJECT

public://构造函数，析构函数要改名字
    helpWindow(QWidget *parent = nullptr);
    ~helpWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

```

### 7.6 IM_WT5000

### 7.7串口

要实现串口通信，需要知道串口通信需要的信息

主要参数有：波特率、校验位、数据位、停止位、控制流

主要操作有：串口的打开和关闭、刷新设备串口、接发数据、开关显示灯等。

```c++
private slots://按键的槽函数
	void on_open_button_clicked();//打开该串口 获取波特率,数据位,奇偶校验，停止位
    void on_getport_button_clicked();//获取串口 获取串口号com1\com2...
    void Read_data();//读数据
	void on_send_button_clicked();//发数据
	void on_clear_recieve_button_clicked();//清理接收到的数据
	void on_r_hex_stateChanged(int arg1)//传入状态发生变化
public://公共函数
    qtSerialport(QWidget *parent = nullptr);
    ~qtSerialport();
    QList<QSerialPortInfo> Get_Serial_Port();//获取端口可用号
     void refresh_text(QTextEdit *text,QByteArray temp);//更新串口
```

```c++
QByteArray是qt中的字节数组，是一类，等待书写
```

接收存在乱码的情况。![image-20230528164029133](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230528164029133.png)

[1000行代码打造的QT5串口调试助手 (rymcu.com)](https://rymcu.com/article/152)

### 7.8多线程

#### 7.8.1基础

首先进程包含线程。进程是资源分配的最小单位，线程是程序执行的最小单位。

如果遇到比较消耗时间的计算或者操作，在一个线程中不能及时运行，可以创建一个单独的线程来执行比较消耗时间的操作，并与主线程之间处理好同步与数据机交互。

QThread是线程类，**线程之间的同步是其交互的主要问题，Qt提供了QMutex、QMutexLocker、QReadWriteLock、QwaitCondition、QSemaphore等多种类用于实现线程之间的同步。  **Qt还有Qt Concurrent模块  ，提供高级的API实现多线程编程无需使用以上的基础操作

一般从QThread继承一个自定义类，并且重定义虚函数run(),在run（）中实现线程需要完成的任务。

​	主线程 ---工作线程（start()----run()进入工作线程的事件循环----exit()--quit()）或者在主线程中国调用terminate()

​	thread线程有5种状态，创建-就绪-运行-阻塞-死亡这五种，用[Thread类](https://so.csdn.net/so/search?q=Thread类&spm=1001.2101.3001.7020)的start()方法来启动一个线程，这时此线程处于就绪（可运行）状态，并没有运行，等到cpu空闲时，才会执行线程里面的run方法，run方法运行完毕，此线程结束。

**多线程的声明周期**：
新建：从新建一个线程对象到start之前的状态，都是新建状态
就绪：线程调用start之后，就处于就绪状态，等待线程调度器的调度
运行：就绪状态下的线程在获取CPU资源后就可以执行run（），此时的线程就处于运行状态，运行的线程可变为就绪、阻塞及死亡三种状态
等待/阻塞/睡眠：在一个线程执行了sleep（睡眠）、suspend（挂起）等方法，从而进入阻塞状态，在睡眠结束后方可进入就绪状态
终止：run（）方法完成后或发生其它终止条件时就会切换到终止状态

**线程**是操作系统能够进行运算调度的最小单位。它被包含在进程之中，是进程中的实际运作单位。一条线程指的是进程中一个单一顺序的控制流，**一个进程中可以并发多个线程**，每条线程并行执行不同的任务。

#### 7.8.2qt中的线程

qt线程的第一种使用方式：

1.继承QThread,重写run(),在run()中进行费时操作

它的优点是便于理解，缺点是操作繁琐而且需要自己处理线程安全。下面是一个简单的示例。

遇到的问题：

①：Q_DECL_OVERRIDE也就是c++的override，放在虚函数后面，作用是防止写错虚函数。

②：qrand和qsrand是一对，qsrand用于初始化随机数，rand用于产生随机数种子

```C++
#include <QTime>       //使用了QTime函数
#include <QtGlobal>    //qsrand和qrand这两个函数在这里面
 
void Widget::on_pushButton_clicked()
{
    //在这个示例里，每次点击按钮就在标签显示一个随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));          //设置随机数种子
    int rand = qrand() % 10;                                    //产生十以内的随机数(0-9)
    ui->label->setText(tr("产生的随机数：%1").arg(rand));
 
}

```

③ ui->label->setText(tr("产生的随机数：%1").arg(rand));

arg的使用类似于C中的printf中使用的格式输出符”和“C++中string的append方法。    

再看看qmake和qsra 

④导致错误信息的原因是：子类没有实现父类的[纯虚函数](https://so.csdn.net/so/search?q=纯虚函数&spm=1001.2101.3001.7020)；
在Qt中，首先要想到的是在一个类中添加了新的继承[QObject](https://so.csdn.net/so/search?q=QObject&spm=1001.2101.3001.7020)，并添加了 Q_OBJECT 宏，然后执行构造或重新构造，都会造成这个错误。
根本原因是，只执行构造或重新构造，都不会编译新添加的宏[Q_OBJECT](https://so.csdn.net/so/search?q=Q_OBJECT&spm=1001.2101.3001.7020)。因此在这之前要执行qmake，让moc编译器去预编译Q_OBJECT，然后再执行构造，就不再报错了。                                    

## 8.TCP客户端/TCP服务端

## 9.github仓库管理

```c++
http:
https://github.com/AVAkingslayer/ava_c_demo.git
ssh:
git@github.com:AVAkingslayer/ava_c_demo.git
    
    
git remote add origin https://github.com/AVAkingslayer/ava_c_demo.git
```

未更新凭据或缓存：如果你之前在另一台电脑上使用了 Git 凭据存储或缓存密码的功能，但密码已经更改，那么推送时可能会使用过期的密码。在这种情况下，你需要更新凭据或清除缓存，并提供正确的密码。

- 对于 Windows 操作系统，你可以打开控制面板，找到凭据管理器，并查找与 GitHub 相关的凭据。然后更新或删除存储的凭据。

## 10.实验室服务器上传代码

### ①基本步骤

首先在服务器里面下载所需要的git软件：

Z:\Sharing Material\Installation Files\Software\git

![](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413152720645.png)

64位的git

![image-20230413152756756](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413152756756.png)

②然后在想要的文件夹里面创建仓库，右键然后Git create repository here

然后就出现了一个空的git文件夹![image-20230413153222765](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413153222765.png)

③右键以后点击git synchronization

然后输入地址

```c++
http://dso_user2017:pxw$7463290@192.168.2.2/dso_demo.git
```



![image-20230413153300829](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413153300829.png)

每次上传代码的时候要点一下pull，更新文件夹，把文件复制到该仓库问价夹上

![image-20230413153640791](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413153640791.png)

然后点commit，输入版本信息

![image-20230413153810823](C:\Users\AVA\AppData\Roaming\Typora\typora-user-images\image-20230413153810823.png)

最后点push,代码就上传完成啦

### ②命名规范

驼峰命名法

## 11.动态库

### 1.基础讲解

为了代码重用，动态库：dll 静态库：lib





