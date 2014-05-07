#PSP开发简明教程（1）

##**PSP游戏机**

PSP，即PlayStation Portable。是索尼于2004年12月12日发售的掌上型游戏机。

它采用4.3寸16：9比例、背光全透式的夏普ASV超广可视角液晶屏幕，屏幕分辨率达到480*272像素，而且色彩鲜艳亮丽，显示效果一流。同时拥有介于PS1和PS2之间的3D多边形绘图性能。

除此之外，它还可以播放视频和音乐文件。所以PSP不单单是一台掌上游戏机，更像是一部掌上多媒体娱乐终端设备。

![PSP][1]

（PSP掌上游戏机）

##**PSP破解**

因为PSP不支持自制软件，并且游戏售价高昂（400人民币左右），所以就有有人开始研究如何在PSP运行自制软件。（或者免费玩儿游戏？）

高手在民间。

仅在PSP发售的半年后，国外黑客组织就破解了PSP系统，并在一个月后发布了自制的“Hello World”程序（意味着大家可以写自制程序了）。随着日后破解的不断完善，PSP也进入了一个新的时代。（一个破解游戏镜像和自制程序满天飞的时代……）

![Dark_AleX][2]

(PSP破解领域的王者Dark_AleX)

为什么说是新时代呢？因为个人感觉PSP的大热绝对和自制软件的盛行有着很大的关系。（起码在国内是这个样子）

自制软件出现后，人们不光可以用PSP玩游戏，还可以看小说，听音乐（比官方支持的格式更多），看视频（支持字幕和更多的格式），更有甚者把PSP的功能发挥到了极致，比如说利用线控口接收GPS模块的信号（[链接在这里][3]），以取代昂贵的官方GPS模块，或者利用自带的WIFI进行无线入侵等等。

而且还能够免费玩游戏。（这才是重点吧……）

可以说自制软件的出现让PSP从一款掌上多媒体娱乐终端设备一跃成为一部掌上电脑，功能得到了极大地扩充，所以说PSP因此进入新的时代，也不为过吧………^_^

##**PSP软件开发**

其实PSP已经是一个快过时的设备了，这里的PSP特指PSP1000-3000和PSP GO。而最新的PSV（PlayStation Vita）虽然性能更加强大，功能也多了不少（背板触摸，蓝牙等），但因为Sony防破解技术的升级，到目前为止，还没有破解的方法。

![PS Vita][4]

（Sony最新的次时代掌机PS Vita）

有关的资料也少之又少。（SDK已经停止更新，开发论坛也基本上没有人了）

不过我还是想写一篇简明教程。一是在置顶博客中提到的，对自己学到的东西进行总结。另一个就是或许能够给他人打来启发。老设备新用的例子还是有的。最后还有一个原因就是，自己从高一有PSP开始，就非常希望能够自己编写PSP自制软件，高中和大学期间断断续续的研究了好几次，而现在总算是能够凭借自己所学到的知识参透些许东西了，所以想写点东西，给自己的当年的愿望一个交代。

废话多了些貌似……那就下一篇开始正经将PSP开发吧！

**本文MarkDown源文件和提到的示例程序源代码，可以在我的Github上获取。**

>Github地址：[https://github.com/flymaxty/OSChina_Blog](https://github.com/flymaxty/OSChina_Blog)




[1]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%881%EF%BC%89/image/01.jpg
[2]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%881%EF%BC%89/image/02.jpg
[3]:http://www.cnetnews.com.cn/2008/0611/920398.shtml
[4]:https://raw.githubusercontent.com/flymaxty/OSChina_Blog/master/PSP%E5%BC%80%E5%8F%91%E7%AE%80%E6%98%8E%E6%95%99%E7%A8%8B%EF%BC%881%EF%BC%89/image/04.jpg