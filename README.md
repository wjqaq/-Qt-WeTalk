# 俺滴第一个项目写细一点--README by JayWen
## 一、QT环境搭建-Windows
#### 下载
1. 我是下载的qt6.5.3，这个版本能便捷的配置安卓环境(但是弊端也很明显，就是他的APK最低只能用Android-24也就是对应手机的安卓7，这就意味着老手机或者老开发板的安卓系统不适配了,
本人也实验了，一些老开发板部署进去应用后，会出现闪退现象，建议有这方面需求去下载低版本的QT，配置环境就看网上的吧），下面给出下载链接。</br>
[QT6.5.3](https://download.qt.io/archive/qt/6.5/6.5.3/single/ "点击进入下载")<br>
2. 下载完毕后（我这里已经配置完毕了，就是维护界面给展示），先去注册QT账户，然后再登录。
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/37552c45-3839-4304-be8a-a92375f1f155)
3. 登录完毕后选择要下载的组件，大致如下，后续又缺少也可以继续补充下载
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/462651ff-5f51-4feb-bd26-34834896d6bc)
4. 然后就等待下载完毕即可
## 二、搭建安卓环境-windows
#### jdk
1. 下载链接[jdk](https://www.oracle.com/cn/java/technologies/downloads/ "点击进入下载")</br>建议下载版本jdk17
2. 下载安装完毕后，配置，打开QT配置界面
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/d632d157-0bf5-4cb1-83da-5fa82a2fae0a)
3. 然后选择设备，android，浏览下载好后的jdk文件夹
  ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/2d2307f4-1c31-4435-9ed6-6982445e695b)
#### sdk
1. 下载链接[jdk](https://developer.android.google.cn/tools/releases/platform-tools?hl=en "点击进入下载")</br>我的版本是SDK13
2. 下载完后直接连接，还是刚刚那个位置
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/efbae970-cd5b-429a-8cb3-027af4601bd7)
#### ndk
1. ndk这里不需要配置，前两个选完之后，就点击设置SDK，他会帮你下载好你需要的环境，这就是高版本的好处
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/fe4cf7e3-2d82-4746-97f7-4cf01a68b80d)
2. 然后在点击SDK管理器，去下载需要对应版本的安卓平台
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/481b9cfc-61df-44f5-98eb-8202cb083638)
3. 有很多可以选择，但是选择安卓7.0以下的当前版本qt不会识别，选好后点击应用即可
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/818359a5-05ca-44b3-90ae-12c847b4a064)
## 三、QT环境搭建-Linux
#### 编译Linux端的QT
1. 下载链接，这里选择linux即可[QT5.13.2](https://download.qt.io/new_archive/qt/5.13/5.13.2/ "点击进入下载")</br>
2. 跟windows一样的安装流程
#### 接下来才是重点
#### QTE5.7 for Itop4412
1. 下载网盘，这里有准备好的QTE5.7源码下载链接，[QTE5.7](https://pan.baidu.com/s/1JEKipRE42-ZbdP1MAmxFdg?pwd=6666 "提取码：6666")</br>
2. 下载完后，照着官方文档的QTE5.7的搭建进行配置即可[官方文档](https://pan.baidu.com/s/1kKzvoQHZScwnhM7wOuaSOw?pwd=6666 "提取码：6666")</br>
3. 这里做完一半，我们有了交叉编译工具的qt的qmake可以生成在板子上运行的环境，但是板子还缺少相关的运行环境
4. 搭建部署QTE5.7文件系统，这里我提供了镜像文件，[镜像文件](https://pan.baidu.com/s/1dUobFpJrUkjo_7gjLE74xA?pwd=6666 "提取码：6666")</br>
5. 用plantform 烧写工具将该系统进行烧写，具体烧写流程如下，因为以前写过，我就贴图了
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/3327f07a-8929-4c48-88c8-469a4d865d46)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/f4736285-f5e4-4837-b916-de33e92eeeb4)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/b7099825-ad40-480b-bcfa-ceeb4d3ed969)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/9e3293a3-5aa0-4030-bc68-649b73957a74)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/94211ff3-77e0-4727-b93c-09caa49321c8)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/4f8cad6a-a68d-4388-9dd1-eec05098a18a)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/746e8fe6-ed01-4d10-a546-a1b38b5788a4)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/99e63e26-fd66-463b-a20e-50d5b6fbe9b3)
6. 完成后需要进入/etc/init.d/rcS 修改到倒数第3行，将/bin/qt5.7 &加入到那里，这样就可以开机自启动qt5.7了。
7. 烧写好了系统后，就可以通过nfs挂载到开发板了，板子就能运行通过linuxQTE5.7 qmake 编译的可执行程序了。
## 四、代码介绍（后续会更新该点）
#### 客户端介绍
1. 客户端用QT的跨平台的特性，因此基本上都有QT的api进行编写客户端代码，这里的消息传递模式采用的是多线程阻塞IO模型，设计模式采用中介者模式来解耦合。
2. 客户端功能目前包含了，注册，登录，添加好友，聊天等，后续会持续更新。
3. kernel类：kernel类是一个核心处理类，目的是将各种消息的处理逻辑实现，完成后交给中介者类让其转发。
4. inet类：是网络类的父类，用于抽象网络的各个函数，这样方便多态实现不同的子类网络。
5. inettcpmediator类：中介者类的父类，同网络类的父类，对应各个子类网络的中介转发。
6. 各个ui类：实现不同ui，这里就不多赘述，各个ui的事件转发给kernel处理。
7. 资源文件：将所有用得到的资源放入一起，方便管理。
#### 服务端介绍
1. 服务端代码我目前还没有提交。
2. 服务端采用的是主副反应堆模型+线程池，该模型能够处理较大的并发量，主反应堆负责监听连接节点，副反应对负责处理后续的IO事件，主副反应堆采用hash映射来负载均衡，线程池通过生产消费者模型来进行快速处理，生产的任务交给优先队列，消费者通过优先队列去执行任务。
3. 设计模式也是采用中介者模式，将反应堆视为kernel类，负载处理庞大的业务逻辑，网络类和中介者类通过客户端大相径庭。

   
