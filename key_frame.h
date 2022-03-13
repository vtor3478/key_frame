#ifndef __KEY_FRAME_H__
#define __KEY_FRAME_H__

#include <stdio.h>
#include <malloc.h>

// �ؼ�֡�ṹ�嶨�壬Ŀǰȫ��ʹ��float
typedef struct{
	int index;
	float key;
	float frame;
}T_key_frame;

extern T_key_frame *p_key_frame;
extern float stepping;
extern int frame_cnt;

float kf_get_frame(float key);
void kf_set_frame(float key, float frame);
void kf_set_buff(T_key_frame *pKeyframe);
void kf_print(T_key_frame *pKeyframe);
void kf_insert_sort();

#endif
