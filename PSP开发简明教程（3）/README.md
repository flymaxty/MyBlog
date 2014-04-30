#PSP开发简明教程（3）

##**开头**

上一篇文章说明了如何搭建PSP软件的开发环境，这一篇将大概讲一下关于程序开发的问题。主要会讲到Makefile中各项参数的含义，并说明一下代码的框架。

其实这部分内容我也是看别人的文章学来的（参考文献在文章末尾），并没有研究的太深，所以如果有说的不大明白的地方，还请见谅！

##**Makefile**

之前说过，PSP自制软件使用Makefile进行构建，所以这里对Makefile中的各项做个简单的说明。

下面就给出一个Makefile的示例

	#目标文件
	TARGET = hello_world

	OBJS   = main.o
	
	INCDIR   =
	CFLAGS   = -G0 -Wall -O2
	CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
	ASFLAGS  = $(CFLAGS)
	 
	LIBDIR  =
	LDFLAGS =
	 
	#是否构建PRX
	BUILD_PRX = 1 
	
	#生成文件名（不可改动）
	EXTRA_TARGETS   = EBOOT.PBP

	#软件名称
	PSP_EBOOT_TITLE = Hello World
	#软件图标（144*80）
	PSP_EBOOT_ICON= ICON0.png
	#软件背景（480*272）
	PSP_EBOOT_PIC1= PIC1.png
	#软件背景音乐（AT3格式）
	PSP_EBOOT_SND0= SND0.at3
	
	#PSPSDK路径
	PSPSDK=$(shell psp-config --pspsdk-path)
	include $(PSPSDK)/lib/build.mak

可以看出来Makefile还能够为我们的自制程序添加背景，图标和背景音乐等功能。

需要注意的是，`BUILD_PRX=1`最好不要省略，如果省略的话，会只生成静态可执行文件。按照其它教程的说法，这样做的话，程序的兼容性不大好。

还有一点要注意的就是，PRX其实有两种解释，一种解释是PRX类似于后台程序，金手指就算这种类型的程序。他不能够直接运行，需要依赖系统或者其他可执行程序才可以用。通常被放在记忆棒的seplugins目录下。

另一种就是我们上面说的，有点类似于内部链接库的东西，程序在执行时需要调用它。

##**样例程序**

	#include <pspkernel.h>
	#include <pspdebug.h>
	
	//程序相关的信息,依次是程序名称、运行模式、主版本号，次版本号
	PSP_MODULE_INFO("Hello World", PSP_MODULE_USER, 1, 0);
	
	//定义主线程的属性
	PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER); 
	PSP_HEAP_SIZE_MAX();
	
	//为了使用方便，将pspDebugScreenPrintf定义为printf，用法也和printf一样。
	#define printf	pspDebugScreenPrintf
	
	int done = 0;

	///////////////////////////////////////////////////////////////
	
	/* Exit callback */
	int exit_callback(int arg1, int arg2, void *common)
	{
		done = 1;
		return 0;
	}
	
	/* Callback thread */
	int CallbackThread(SceSize args, void *argp)
	{
		int cbid;
	
		cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
		sceKernelRegisterExitCallback(cbid);
		sceKernelSleepThreadCB();
		return 0;
	}
	
	/* Sets up the callback thread and returns its thread id */
	int SetupCallbacks(void)
	{
		int thid = 0;
	
		thid = sceKernelCreateThread("update_thread", CallbackThread,
					     0x11, 0xFA0, 0, 0);
		if(thid >= 0)
		{
			sceKernelStartThread(thid, 0, 0);
		}
	
		return thid;
	}
	
	///////////////////////////////////////////////////////////////

	int main(void)
	{
		//初始化DebugScreen，这样就可以在屏幕上显示了
		pspDebugScreenInit();
		
		//创建线程监听用户行为，为了能够退出程序
		SetupCallbacks();
	
		//主循环体，用户退出时，done会变为1，循环退出
		while(!done)
		{
			pspDebugScreenSetXY(0, 0);
			printf("Hello World!\n");
			printf("Test by Max");
			sceDisplayWaitVblankStart();
		}
		
		//彻底退出
		sceKernelExitGame();	
		
		return 0;
	}

这里给出一个简单的Hello World程序做代码框架解释。乍看挺乱的，但逻辑上并不复杂。

被斜杠框住的一大堆函数，实现的功能就是我们按下`Home`键的时候，能够退出程序。如果看不懂的话（比如说我=_=)，可以暂时略过。其它的程序里面按照这个写也没有大的问题。

主函数一目了然，先初始化显示，创建线程监听用户操作，然后进入主循环体循环。

整个程序的结构大致就是这样。

大家可以尝试按照上一篇文章所讲的方法，构建出Hello World程序。

不过要注意的是，因为我们在Makefile里面定义了图标，背景等，所以需要在工程文件夹下面放置符合要求的图片和音乐文件，才能保证编译通过。如果实在懒得弄，也可以直接删掉这几行命令。

运行效果（使用CMF截图）：

![小图标][1]

**（小图标）**

![背景图片][2]

**（背景图片）**

![运行效果][3]

**（运行效果）**

对于程序的说明就到这里吧。个人水平实在是有限。

如果想要写一些真正能用的东西，下面这些资料可以做参考。

##**参考文档、论坛**

我找了半天也没找到官方出的开发文档。但是在MINPSPW文件夹下发现了官方的编程参考手册。

>**PSP编程参考手册（由Doxygen生成）**
>
>（MinPSPW安装位置）\doc\pspsdk\index.html

这个手册是SDK作者用Doxygen生成的，是网页版本的。

里面有对函数的说明，和函数参数的格式等等，不过说的不是很细。光看这个我感觉还是不清楚每个模块该如何使用。

但是我在其它地方发现了两个PSP开发的入门教程、wiki，我的文章也参照这两份教程。

>**[PSP Programming（WIKIBOOKS）][4]**
>
>**[linuxgraphics psp专栏（刘鹏）][5]**
>
>第二个博客里面讲的PSP破解史比我说的详细的多，推荐大家看看

这两份教程讲的都比较浅，和我说的差不了多少。

这里有一篇博客文章，是讲程序结构的，说的比我详细些，我的说明也参考了它。

>**[我也玩PSP开发！（2）—— PSPSDK示例 源码分析][6]**

最后是ps2dev论坛，准确的说应该是论坛镜像，因为ps2dev已经不在了。这个镜像里面保存了论坛到2010年的所有帖子。我大概翻过一些，还是有些有意义的东西的。大家如果想深入开发的话，建议多翻翻这里的旧帖子。

**[http://lukasz.dk/mirror/forums.ps2dev.org][7]**

其实在谷歌里还能搜索到其它的PSP教程，不过质量参差不齐。这里就不再多推荐了。

##**关于示例程序**

虽然没有好的教程可供学习，但是官方的示例程序还是有的。在minpspw中有很多示例程序可供参考，种类繁多。从usb、红外（这个2000系列之后没有了）、MP3播放，到wifi，adhoc等网络相关的示例程序都有。

但问题是这些示例程序不少已经不能使用了。因为它们大部分都是在06-08年间写的，都是1.50固件时代的东西。不少程序在最新的6.60版本固件上基本上没法运行，甚至在M33的固件上都不能。

我一共尝试过三个示例，一个是按键检测示例（就是在上篇教程里使用的那个），一个是MP3播放，还有一个就是wlan_scan。这三个程序，第一个可以正常运行，第二个如果MP3文件的ID3信息中不包含中文，则可以运行。至于第三个程序，则完全运行不了，至于原因，有两个可能，一个就是因为它是1.50固件时代的产物，已经无法在新版本固件上使用了；还有一种可就是，我对程序的理解有问题。例程所需的一些文件（比如说PRX）没有提供。我在上面说的那个论坛镜像上找到了两篇关于网络编程的讨论，但是看不大懂。这里我把链接给大家，看博客的人肯定比有我知识经验丰富的，或许可以明白问题究竟出在哪里=。=

>**[wlan "simple" sample for 3.xx (simple_prx)][8]**
>
>**[Wi-Fi in User Mode][9]**

##**总结**

至此，整个PSP开发简明教程就完结了。

我写这个也不是想说，PSP其实还大有可为。虽然PSP的功能很强大，但是个人开发十分的困难，而且没有官方的支持（我真的很佩服当年搞PSP破解和自制软件开发的人）。

加上现在有了手机这种比PSP适用范围更广，更便宜，而且开发还简单的东西，PSP实际上已经可以入住博物馆了……

所以我只是想让大家多了解下它，毕竟PSP的破解很有代表性，研究它或许对我们以后从事类似的工作有一定的帮助。




[1]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%883%EF%BC%89/image/01.jpg
[2]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%883%EF%BC%89/image/02.jpg
[3]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%883%EF%BC%89/image/03.jpg
[4]:http://en.wikibooks.org/wiki/PSP_Programming
[5]:http://www.linuxgraphics.cn/psp/index.html
[6]:http://blog.csdn.net/soulxu/article/details/2053793
[7]:http://lukasz.dk/mirror/forums.ps2dev.org
[8]:http://lukasz.dk/mirror/forums.ps2dev.org/viewtopica9f5.html?t=10372
[9]:http://lukasz.dk/mirror/forums.ps2dev.org/viewtopic55eb.html?t=7032