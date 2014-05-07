#如何使用Python3读取配置文件（ini）

##**ini文件简介**

ini是我们常见到的配置文件格式之一。

>ini是微软Windows操作系统中的文件扩展名（也常用在其他系统）。

>INI是英文“初始化（Initial）”的缩写。正如该术语所表示的，INI文件被用来对操作系统或特定程序初始化或进行参数设置。
>
>[百度百科](http://baike.baidu.com/view/1296365.htm)

通过它，可以将经常需要改变的参数保存起来（而且还可读），使程序更加的灵活。

我先给出一个ini文件的示例。

	[School]
	ip = 10.15.40.123
	mask = 255.255.255.0
	gateway = 10.15.40.1
	dns = 211.82.96.1
	
	[Match]
	ip = 172.17.29.120
	mask = 255.255.255.0
	gateway = 172.17.29.1
	dns = 0.0.0.0


这个配置文件中保存的是不同场合下的IP设置参数。

下面将以生成和读取这个配置文件为例，进行讲解。

##**Python（v3）读取方法**

首先，Python读取ini配置需要用到`ConfigParser`包，所以要先加载它。

	import configparser

之后我们需要载入配置文件。

	config=configparser.ConfigParser()

	#IpConfig.ini可以是一个不存在的文件，意味着准备新建配置文件。
	config.read("IpConfig.ini")

接下来，我们可以使用`configparser.add_section()`向配置文件中添加一个`Section`。

	#添加节School
	config.add_section("School")
*注意：如果文件中已经存在相应的项目，则不能再增加同名的节。*

然后可以使用`configparser.set()`在节`School`中增加新的**参数**。

	#添加新的IP地址参数
    config.set("School","IP","192.168.1.120")
    config.set("School","Mask","255.255.255.0")
    config.set("School","Gateway","192.168.1.1")
    config.set("School","DNS","211.82.96.1")

你可以以同样的方式增加其它几项。

	#由于ini文件中可能有同名项，所以做了异常处理
	try:
	    config.add_section("Match")
	    config.set("Match","IP","172.17.29.120")
	    config.set("Match","Mask","255.255.255.0")
	    config.set("Match","Gateway","172.17.29.1")
	    config.set("Match","DNS","0.0.0.0")
	except configparser.DuplicateSectionError:
    	print("Section 'Match' already exists")

增加完所有需要的项目后，要记得使用`configparser.write()`进行写入操作。
	
	config.write(open("IpConfig.ini", "w"))

以上就是写入配置文件的过程。

接下来我们使用`configparser.get()`读取刚才写入配置文件中的参数。读取之前要记得读取ini文件。

	ip=config.get("School","IP")
	mask=config.get("School","mask")
	gateway=config.get("School","Gateway")
	dns=config.get("School","DNS")
	
	print((ip,mask+"\n"+gateway,dns))

##**完整示例**

下面是一个完整的示例程序，他将生成一个`IpConfig.ini`的配置文件，再读取文件中的数据，输出到屏幕上。

	# -*- coding: utf-8 -*-
	
	import configparser
	
	#读取配置文件
	config=configparser.ConfigParser()
	config.read("IpConfig.ini")
	
	#写入宿舍配置文件
	try:
		config.add_section("School")
		config.set("School","IP","10.15.40.123")
		config.set("School","Mask","255.255.255.0")
		config.set("School","Gateway","10.15.40.1")
		config.set("School","DNS","211.82.96.1")
	except configparser.DuplicateSectionError:
		print("Section 'School' already exists")
	
	#写入比赛配置文件
	try:
		config.add_section("Match")
		config.set("Match","IP","172.17.29.120")
		config.set("Match","Mask","255.255.255.0")
		config.set("Match","Gateway","172.17.29.1")
		config.set("Match","DNS","0.0.0.0")
	except configparser.DuplicateSectionError:
		print("Section 'Match' already exists")
	
	#写入配置文件
	config.write(open("IpConfig.ini", "w"))
	
	ip=config.get("School","IP")
	mask=config.get("School","mask")
	gateway=config.get("School","Gateway")
	dns=config.get("School","DNS")
	
	print((ip,mask+"\n"+gateway,dns))

##**总结**

Python读取ini文件还是十分简单的，这里我给出的只是一些简单的使用方法，如果想用更高级的功能，比如和注释有关的功能。可以参考Pyhton官方文档

>Python3官方参考文档
>
>[14.2. configparser — Configuration file parser](https://docs.python.org/3/library/configparser.html)

**本文MarkDown源文件和提到的示例程序源代码，可以在我的Github上获取。**

>Github地址：[https://github.com/flymaxty/OSChina_Blog](https://github.com/flymaxty/OSChina_Blog)