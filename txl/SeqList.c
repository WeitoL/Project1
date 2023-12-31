#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void SLInit(SL * ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps) {
	if (ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//空间不足以再额外插入一个数据
		//扩容
		int newCapcity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapcity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!\n");
			return 1;
		}
		ps->a = tmp;
		ps->capacity = newCapcity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x) {
	//assert(ps != NULL);
	//暴力的方式
	assert(ps);
	//柔和方式
	//if (ps == NULL) {
	//	return;
	//}

	//1)空间足够，直接尾插
	//2）空间不够，扩容
	SLCheckCapacity(ps);
	//直接插入数据
	ps->a[ps->size++] = x;
}
//头插
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	//判断空间是否足够,不够则扩容
	SLCheckCapacity(ps);
	//空间足够，历史数据后移一位
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//尾插
void SLPopBack(SL* ps) {
	//判断顺序表是否为空
	assert(ps);
	assert(!SLIsEmpty(ps));
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(!SLIsEmpty(ps));
	//让后面的数据往前挪动一位
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SLPrint(SL* ps) {
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
bool SLIsEmpty(SL* ps) {
	assert(ps);
	//这样子是不对的，这里只能判断空间是否足够
	//return ps->size == ps->capacity;
	return ps->size == 0;
}

//在指定的位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	//不要忘了对pos加以限制
	assert(pos >= 0 && pos <= ps->size);
	//扩容
	SLCheckCapacity(ps);
	//把pos位置及以后的数据往后挪动一位
	//循环条件里i的初始值是size还是size-1都是可以的，但不同的初始值对应不同的结束条件
	//for (int i = ps->size; i > pos; i--)
	//{
	//	//pos+1
	//	ps->a[i] = ps->a[i - 1];//pos->a[pos+1] = ps->a[pos]
	//}
	for (int i = ps->size - 1; i > pos - 1; i--)
	{
		//最后一次进来的i是pos
		ps->a[i + 1] = ps->a[i];//ps->a[pos+1] = ps->a[pos]
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除指定位置的数据
void SLErase(SL* ps, int pos) {
	assert(ps);
	assert(!SLIsEmpty(ps));
	//pos的范围需要限制
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		//最后一次进来的i的数据ps->size-2
		ps->a[i] = ps->a[i + 1];//ps->a[ps->size-2] = ps->a[ps->size-1]
	}
	ps->size--;
}

bool SLFind(SL* ps, SLDataType x) {
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i].name == 'x') {
			//找到了
			return true;
		}
	}
	return false;
}