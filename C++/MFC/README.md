# Learning/C++/MFC
MFC(Microsoft Foundation Classes, 微软基础类库)

这是一门古老的技术，有许多历史遗留问题，微软几乎要放弃它了

为什么还学它呢？仅仅只是对其封装的API进行学习，进而构造Windows的编程模型，并不深入学习

# 基本配置
计算机：32位计算机

操作系统：Microsoft Windows 7

IDE：Visual Studio 2010

第三方软件：VPSD虚拟串口、Commix

注意事项：
1.该项目在Visual Studio 2010里头编译通过。

2.创建MFC项目时需要设置Unicode字符集编码才可使用中文输出，并编译通过。

3.项目使用静态MFC库。

4.链接器的清单文件的输出需要改为否，才可编译运行。

（或删除VS文件夹中bin文件夹里头的cvtres.exe，原因可能是VS2010编译器与.NET FrameWork最新版本不兼容）

5.添加ActiveX控件：Microsoft Communications Control Version 6.0

6.使用模拟数据采集卡需要引入三个文件：MyDLL.dll、MyDLL.h、MyDLL.lib

# 项目设置

## les00
MFC源程序的基本结构

## les01
简单的使用windows.h头文件，创建基本界面

## les02
使用MFC创建基本界面

## les03
画刷的简单使用

## les04
正弦曲线的绘制

## les05
消息接收与绘图

## les06
键盘消息接收与响应

## les07
矩形与椭圆的绘制，但没有考虑刷新

## les08
考虑刷新后的矩形与椭圆的绘制，有BUG，刷新后图像变形

## les09
MFC控件编程，简易的绘图软件制作，绘图区域刷新需要优化

## les10
MSComm串口编程，未完成

## les11
简易版MSComm串口编程

## les12
简易版数据采集程序（数据随机模拟版本）