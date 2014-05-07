#PSP开发简明教程（2）

##**开头**

接着上文，这篇文章将具体说明如何搭建PSP开发环境。因为我是刚开始写教程类文章，加上对这一类型的程序开发不是很了解，所以文章可能有说的不明白，甚至错误的地方。还望大家能够指正。见谅！

##**使用的软件和教程**

为了编写PSP自制程序，我们需要如下软件：

**MinPSPW（Minimalist PSPSDK）**：[链接在这里][1]

**Eclipse IDE for C/C++ Developers**：[链接在这里][2]

其中MinPSPW也可以用DevKitPSP代替（[链接在这里][3]），不过因为现在最新固件（6.60）的破解程序（[PROCFW][4]）是用MinPSPW编译的，为防止出什么稀奇古怪的问题，我就选择了和它一样的环境。

选择MinPSPW的另一个原因是，它有一个比较好的官方教程，名字叫**PSP Development with Eclipse**。教程详细的说明了如何搭建开发环境和编译自制程序，本文也是依据这个写的。所以，如果英语比较好，完全可以看这官方给出的教程，肯定比我写的好。[教程在这里][5]

##**软件的安装**

MinPSPW的安装没什么好说的，在项目网站选择最新的程序，一路默认选项安装就是。安装完成后，它会在系统环境变量中添加自己的运行目录。

![MinPSPW的环境变量][6]

**（MinPSPW的环境变量）**

Eclipse我们选择C/C++ Developers版本，因为软件是绿色版本的，所以也没有安装一说。不过需要注意的是，Eclipse是基于Java编写的，所以需要电脑具有Java运行环境（[没有的可以从这里安装][7]）。

至此安装工作就算完成了。

##**环境配置**

之前说过，MinPSPW会在安装后自动在环境变量中添加运行目录，所以我们只需要检查一下它是否可用就可以。命令提示符中执行`psp-gcc --version`，应该会出现psp-gcc相关的版本信息。

![psp-gcc版本信息][8]

**（psp-gcc版本信息）**

接着说Eclipse，它在第一次执行的时候应该会让你设置工作空间，这里本人建议最好能够新建一个文件夹，比如WorkSpace，来存放所有用Eclpise开发的软件文件夹，因为它会在你指定的目录里面生成一些其它的文件。

![Eclipse弹窗][9]

**（第一次使用Eclipse时的弹窗）**

至此整个环境就基本可用了。

其实官方教程里面还对Eclipse做了其他设置，比如PSP的USB调试功能。这里就不细讲了，如果确实想了解的同学可以翻阅官方文档。

##**工程编译**

PSP的自制程序使用Makfile进行构建。这里我们以一个SDK中自带的例子来说明如何构建程序。

首先，我们在Eclipse中的`Project explorer`中单击右键，选择`Import`，导入工程

![Import][10]

**（导入工程）**

在弹出的`Import`窗口中，选择`C/C++ -> Existing file as Makefile project`，从既有文件导入Makefile工程。

![导入Makefile][11]

**（从既有文件导入Makefile工程）**

进入下一步，在第二个框中填入我们要加入的示例文件的文件夹。这里我们选择PSPSDK中一个关于按键操作的示例进行演示。（位置在：（MinPSPW安装位置）\psp\sdk\samples\controller\basic）

建议将示例程序另复制一份，以免破坏了原有的示例程序。

![目录设置][12]

**（目录设置）**

点击`Finish`，工程导入完成了。在Eclipse的左侧，可以看到我们导入的程序代码（main.c）和Makefile。

![工程目录结构][13]

**（工程目录结构）**

然后我们就可以进行编译了。在Eclipse的菜单栏的Project菜单中，选择`Build Project`

就完成编译了。

![编译][14]

**（编译）**

大家在查看main.c时，可能会发现满篇的红色波浪线，各种头文件无法找到。

![头文件错误][15]

**（头文件错误）**

虽然显得很乱，但其实并不影响程序的构建，因为Makefile中对头文件目录进行了设置。

所以这里会显示头文件无法找到，仅仅只是Eclipse无法找到而已。不信的话，可以把最下侧的对话框切换到`Console`，就可以看出来构	建没有任何问题。

![Console对话框][16]

**（Console对话框）**

如果觉得波浪线碍眼，我们可以在工程设置里面`C/C++ General -> Paths and Symbols`的`Includes`里面，添加目录`（MinPSPW安装位置）\psp\sdk\include`进去，记得勾选`Add to all  languages`。这样，就没有碍眼的错误提示了。

![Include设置][17]

**（Include设置）**

其实这样更重要的是，我们可以直接在编写代码的时候看到每个函数的描述信息。

![函数描述信息][18]

**（函数描述信息）**

以上就是整个PSP软件开发环境的配置过程。

##**自制软件的运行**

在编译之后，我们可以在源文件目录下找到一个叫`EBOOT.PBP`的文件。熟悉PSP自制软件的读者应该知道，这是PSP上类似于Windows下*.exe的东西。我们只要把它拷贝到PSP上面，就可以运行它了。

我们把它拷贝到PSP记忆棒目录下`PSP\GAME\Controler\`文件夹中。完后在PSP上面运行它（就像运行游戏一样）。

Controler basic程序的功能是将所有你按下的按键显示在屏幕上。

*PSP莫名其妙的连不上电脑了。。。等我修好了上这张图（┬＿┬）*

**（Controler运行界面）**

##**总结**

以上就是PSP开发环境配置全过程。

当然官方教程中给出的功能可不止这些，它还说明了如何USB进行自制程序的在线调试。并给出了使用Bullet进行3D游戏开发的配制方法，这里就不一一说明了。有兴趣的可以参照官方教程自行配置使用。

下一篇文章将简单的说明一下Makfile和源代码的结构（网上既有的资料 + 个人比较浅显的理解）。并将自己所做过的些探索一一列出来，使读者们少走些弯路。

这篇文章就写到这里了。

**本文MarkDown源文件和提到的示例程序源代码，可以在我的Github上获取。**

>Github地址：[https://github.com/flymaxty/OSChina_Blog](https://github.com/flymaxty/OSChina_Blog)




[1]:http://sourceforge.net/projects/minpspw/
[2]:https://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/keplersr2
[3]:http://sourceforge.net/projects/devkitpro/files/devkitPSP/
[4]:https://code.google.com/p/procfw/
[5]:http://sourceforge.net/projects/minpspw/files/book/PSP%20Dev%20with%20Eclipse/
[6]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/01.jpg
[7]:http://www.java.com/zh_CN/
[8]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/02.jpg
[9]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/03.jpg
[10]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/04.jpg
[11]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/05.jpg
[12]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/06.jpg
[13]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/07.jpg
[14]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/08.jpg
[15]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/09.jpg
[16]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/10.jpg
[17]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/11.jpg
[18]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/12.jpg
[19]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%882%EF%BC%89/image/13.jpg