# 俺滴第一个项目写细一点--README by JayWen
## 一、QT环境搭建-Windows
#### 下载
1. 我是下载的qt6.5.3，这个版本能便捷的配置安卓环境(但是弊端也很明显，就是他的APK最低只能用Android-24也就是对应手机的安卓7，这就意味着老手机或者老开发板的安卓系统不适配了,
本人也实验了，一些老开发板部署进去应用后，会出现闪退现象，建议有这方面需求去下载低版本的QT，配置环境就看网上的吧），下面给出下载链接。</br>
[QT6.5.3](https://download.qt.io/archive/qt/6.5/6.5.3/single/ "点击进入下载")<br>
2. 下载完毕后（我这里已经配置完毕了，就是维护界面给展示），先去注册QT账户，然后再登录。
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/37552c45-3839-4304-be8a-a92375f1f155)</br>
3. 登录完毕后选择要下载的组件，大致如下，后续又缺少也可以继续补充下载
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/462651ff-5f51-4feb-bd26-34834896d6bc)</br>
4. 然后就等待下载完毕即可
## 二、搭建安卓环境-windows
#### jdk
1. 下载链接[jdk](https://www.oracle.com/cn/java/technologies/downloads/ "点击进入下载")</br>建议下载版本jdk17
2. 下载安装完毕后，配置，打开QT配置界面
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/d632d157-0bf5-4cb1-83da-5fa82a2fae0a)</br>
3. 然后选择设备，android，浏览下载好后的jdk文件夹
  ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/2d2307f4-1c31-4435-9ed6-6982445e695b)</br>
#### sdk
1. 下载链接[jdk](https://developer.android.google.cn/tools/releases/platform-tools?hl=en "点击进入下载")</br>我的版本是SDK13
2. 下载完后直接连接，还是刚刚那个位置
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/efbae970-cd5b-429a-8cb3-027af4601bd7)</br>
#### ndk
1. ndk这里不需要配置，前两个选完之后，就点击设置SDK，他会帮你下载好你需要的环境，这就是高版本的好处
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/fe4cf7e3-2d82-4746-97f7-4cf01a68b80d)</br>
2. 然后在点击SDK管理器，去下载需要对应版本的安卓平台
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/481b9cfc-61df-44f5-98eb-8202cb083638)</br>
3. 有很多可以选择，但是选择安卓7.0以下的当前版本qt不会识别，选好后点击应用即可
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/818359a5-05ca-44b3-90ae-12c847b4a064)</br>
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
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/3327f07a-8929-4c48-88c8-469a4d865d46)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/f4736285-f5e4-4837-b916-de33e92eeeb4)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/b7099825-ad40-480b-bcfa-ceeb4d3ed969)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/9e3293a3-5aa0-4030-bc68-649b73957a74)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/94211ff3-77e0-4727-b93c-09caa49321c8)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/4f8cad6a-a68d-4388-9dd1-eec05098a18a)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/746e8fe6-ed01-4d10-a546-a1b38b5788a4)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/99e63e26-fd66-463b-a20e-50d5b6fbe9b3)</br>
6. 完成后需要进入/etc/init.d/rcS 修改到倒数第3行，将/bin/qt5.7 &加入到那里，这样就可以开机自启动qt5.7了。
7. 烧写好了系统后，就可以通过nfs挂载到开发板了，板子就能运行通过linuxQTE5.7 qmake 编译的可执行程序了。
## 四、结果演示（后续增添新功能后会更新）
#### 服务端运行，将服务端运行在Ubuntu上，并且将虚拟机调整为桥接模式，并搭配好IP地址
1. 服务器目录架构
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/83ddbdf5-d302-430b-8cc0-f0bc6f6e6977)</br>
2. 服务器ip地址
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/b08217f3-eca0-470c-8183-7f7e82f5f6de)</br>
3. 虚拟机设置为桥接
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/22794c45-7183-4134-ab0e-518f288f660e)</br>
4. 配置好IP，目的是配对开发版的IP
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/cc1df1b2-2070-4db3-9e68-55dc05130225)</br>
5. 运行服务端（这里我没有将服务器的代码提交）
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/9cfb0b9c-1b9b-4408-9d03-c5db85ba7ab7)</br>
#### window端结果
1. 将项目装配好后，选择桌面类型编译即可
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/22d9d38b-b4c8-40fa-9f35-e2cc58c9d3ca)</br>
2. 登录界面
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/6f9bb016-b793-435f-a4bf-0214c4040a83)</br>
4. 注册界面
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/ac18f6ca-ba33-48e5-82d3-7382120a25ca)</br>
   账号重复
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/fd4d44eb-08f4-4862-8000-67a91403380c)</br>
   账号不为空
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/22501e8e-b322-499c-9972-f28a46d1038d)</br>
   昵称不为空
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/fd056bf7-5449-492b-be2a-7e553e4a199c)</br>
   还有密码的一些限制，如正则匹配密码必须为大小写字母数字+.组成，其他还有的客户端判断，在服务端也为有设计这里就不多演示了
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/b93e4f7a-409e-40ad-8b2d-58e3458fd215)</br>
5. 用户列表界面，这里目前实现功能有添加好友以及好友列表
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/fbdc0b54-3a93-4e55-b6ae-f1c20f6e7cb7)</br>
6. 添加好友
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/7ece0eb6-e48d-454d-a1b7-860a9fb0afdd)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/67338208-eda5-4a60-bf18-0c4a05ebb494)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/077d637a-f4ff-433b-ba79-027f52cb93f6)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/49837683-7e37-4b73-ba5c-af9f68b854b4)</br>
7. 聊天界面
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/afe69ebb-2f61-4fc5-a61b-bfae65af9500)</br>
#### Linux端结果
1. 各个界面已展示，下面展示windows端同linux端通讯
2. 双端通讯Linux-Windows
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/e8201ce8-8de4-4ed7-82d0-3a4607ec04b2)</br>
#### 开发版端结果
1. 在linux移植完后，来到项目目录通过/opt/qt5.7.0/bin/qmake 编译该目录生成makefile文件，在make生成arm架构的可执行文件
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/5e52e350-0d71-4486-83cd-b7e38256ed15)</br>
2. 开发板各个信息展示
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/1af47bc0-acf3-4066-89bd-570f27f8fe4a)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/15e7f0da-0794-437d-a4b8-b08f32af075d)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/d5e4a1eb-9ada-4014-8668-9c91eda9a3b9)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/20d9e52b-3ed6-4846-babe-83b039e2ac15)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/41276b8d-ab3b-47ff-8f78-165026a5da2b)</br>
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/949c1d9b-c72c-4deb-9e33-84e22c2d9009)</br>

#### 安卓端结果
1. 首先是将windows端的配置调整为手机架构版本，这里我是米13，因此我用这个以下架构和APK
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/3d3812e3-01e1-446f-bbd7-bf6126ac1dab)
2. 手机记得调整为开发者模式，打开usb调试功能，然后直接部署即可
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/4a6f7daf-de77-42d9-9895-111b34b61f8b)
   ![image](https://github.com/wjqaq/-Qt-WeTalk/assets/101192481/22f5147c-e498-49ab-9e92-f0f38b99349f)

## 五、代码介绍（后续会更新该点）
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

   
