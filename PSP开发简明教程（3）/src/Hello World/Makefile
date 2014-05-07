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