#include "key_frame.h"

// 传入指针，分段数由外部进行决定
T_key_frame *p_key_frame = NULL;
// 外部设置步进精度，默认为1
float stepping = 0.5f;
// 外部设置总共有多少个等级，默认为10
int frame_cnt = 10;
// 当前存储了多少个index，默认为0
T_key_frame key_frame_temp;


void kf_print(T_key_frame *pKeyframe)
{
	int i = 0;
	if (pKeyframe == NULL)
	{
		return;
	}
	for (	;i <frame_cnt; i++)
	{
		//if (pKeyframe[i].key < -1e-6 || 1e-6 < pKeyframe[i].key)
		{
			printf("[%d]:[%.2f]=%.2f\r\n", pKeyframe[i].index, pKeyframe[i].key, pKeyframe[i].frame);
		}
	}
}

void kf_set_buff(T_key_frame *pKeyframe)
{
	p_key_frame = pKeyframe;
}

float kf_get_frame(float key)
{

	return 1.0f;
}


void kf_set_frame(float key, float frame)
{
	// 赋值给临时变量，
	key_frame_temp.key = key;
	key_frame_temp.frame = frame;
	kf_insert_sort();
}

// 使用插入排序
void kf_insert_sort()
{
	int i = 0;
	int j = frame_cnt - 1;
	float step = 0.0f;
	// 找到要插入的位置，
	// 条件1：原有值刚好大于此值
	// 条件2：或者原有值为0
	while (1)
	{
		if( p_key_frame[i].key == 0)
		{
			break;
		}
		else if (key_frame_temp.key < p_key_frame[i].key)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	// 计算2帧之间的差别，如果比较小，就直接进行替换
	step = p_key_frame[i].key - key_frame_temp.key;
	//printf("[%d],%f,,%f\n",i, p_key_frame[i].key , key_frame_temp.key);
	if (-stepping < step && step < stepping)
	{
		//printf("will replace [%d]=%f->%f\n", i, p_key_frame[i].frame,key_frame_temp.frame);
		// 直接执行替换操作
		p_key_frame[i].frame = key_frame_temp.frame;
	}
	else // 间隔满足插入条件，执行插入，并排序
	{
		//printf("will insert %d\n", i);
		// 将已排好的数据往后挤
		while (j > i)
		{
			p_key_frame[j].key = p_key_frame[j - 1].key;
			p_key_frame[j].frame = p_key_frame[j - 1].frame;
			j--;
		}
		p_key_frame[j].key = key_frame_temp.key;
		p_key_frame[j].frame = key_frame_temp.frame;
	}
}

