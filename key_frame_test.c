#include "key_frame.h"
// 渐插入排序
void in(int value)
{
	static int arr[10] = { 0 };
}


int  main(void)
{
	int i;
	printf("main\r\n");
	p_key_frame = (T_key_frame *)malloc(sizeof(T_key_frame) * frame_cnt);
	memset(p_key_frame,0,sizeof(T_key_frame) * frame_cnt);
	kf_set_buff(p_key_frame);
	for (i = 0; i <15; i++)
	{
		//kf_set_frame(i - 5, 6);
		kf_set_frame( 1.0f * i/2 +5  ,i/2 + 4);
		kf_print(p_key_frame);
		printf("完成第%d次打印\n",i);
	}
	kf_print(p_key_frame);
	system("pause");
	return 0;
}

