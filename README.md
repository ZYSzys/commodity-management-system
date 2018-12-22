# CMS

[![Travis CI](https://travis-ci.org/ZYSzys/commodity-management-system.svg?branch=master)](https://travis-ci.org/ZYSzys/commodity-management-system) 
[![license](https://img.shields.io/github/license/ZYSzys/commodity-management-system.svg)](https://github.com/ZYSzys/commodity-management-system/blob/master/LICENSE)

A simple commodity management system......create by Qt Creator  


## 运行环境
* Qt

## 下载运行
在终端输入以下命令下载：
```bash
git clone git@github.com:ZYSzys/commodity-management-system.git
```
#### 方法一：  
进入当前文件夹，进入CMS，选择.pro文件右击通过Qt Creator打开  
点击运行即可。

#### 方法二：
在终端编译运行，输入以下命令：
```bash
cd commodity-management-system/CMS
qmake -project
qmake
echo >> CMS.pro 'QT += widgets'
echo >> CMS.pro 'QT += sql'  
make
open CMS.app
```

