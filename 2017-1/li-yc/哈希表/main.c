#include "Hashtable.h"

int main() {
	Hashtable H;
	int arr[ArrayLenth][2];
	int i;

	srand(time(0));

	//������ϣ��
	H = CreatHash(HashLength);
	CreatArray(arr);

	//��ʼ����ϣ��
	for (i = 0; i < ArrayLenth; ++i) {
		Insert(H, arr[i][0], arr[i][1]);
	}
	printf("��ϣ�������\n");
	TraverseHash(H);
	
	//�ؼ��ֲ���
	for (i = 0; i < HashLength / 2; ++i) {
		Find(H, arr[rand() % ArrayLenth][0]);
	}
	for (i = 0; i < HashLength / 2; ++i) {
		Find(H, rand() % 100 + 1);
	}

	//�ؽ���ϣ��
	RebulidHash(&H);
	TraverseHash(H);

	return 0;
}