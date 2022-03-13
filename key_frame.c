#include "key_frame.h"

// ����ָ�룬�ֶ������ⲿ���о���
T_key_frame *p_key_frame = NULL;
// �ⲿ���ò������ȣ�Ĭ��Ϊ1
float stepping = 0.5f;
// �ⲿ�����ܹ��ж��ٸ��ȼ���Ĭ��Ϊ10
int frame_cnt = 10;
// ��ǰ�洢�˶��ٸ�index��Ĭ��Ϊ0
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
	// ��ֵ����ʱ������
	key_frame_temp.key = key;
	key_frame_temp.frame = frame;
	kf_insert_sort();
}

// ʹ�ò�������
void kf_insert_sort()
{
	int i = 0;
	int j = frame_cnt - 1;
	float step = 0.0f;
	// �ҵ�Ҫ�����λ�ã�
	// ����1��ԭ��ֵ�պô��ڴ�ֵ
	// ����2������ԭ��ֵΪ0
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
	// ����2֮֡��Ĳ������Ƚ�С����ֱ�ӽ����滻
	step = p_key_frame[i].key - key_frame_temp.key;
	//printf("[%d],%f,,%f\n",i, p_key_frame[i].key , key_frame_temp.key);
	if (-stepping < step && step < stepping)
	{
		//printf("will replace [%d]=%f->%f\n", i, p_key_frame[i].frame,key_frame_temp.frame);
		// ֱ��ִ���滻����
		p_key_frame[i].frame = key_frame_temp.frame;
	}
	else // ����������������ִ�в��룬������
	{
		//printf("will insert %d\n", i);
		// �����źõ���������
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

