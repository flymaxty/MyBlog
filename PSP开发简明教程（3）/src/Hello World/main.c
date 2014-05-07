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