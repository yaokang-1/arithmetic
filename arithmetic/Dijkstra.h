#pragma once
#ifndef Dijkstra
#define Dijkstra

#include <iostream>

#define Size 9				//�ڵ���


using namespace std;

//��ʼ��ͼ
const int Map[Size][Size] = { {0,4,0,0,0,0,0,8,0},
						{4,0,8,0,0,0,0,11,0},
						{0,8,0,7,0,0,0,0,2},
						{0,0,7,0,9,15,0,0,0}, 
						{0,0,0,9,0,10,0,0,0},
						{0,0,4,14,10,0,2,0,0},
						{0,0,0,0,0,2,0,1,6},
						{8,11,0,0,0,0,1,0,7},
						{0,0,2,0,0,0,6,7,0}
						 };
typedef struct Dijkstra_Node
{
	int num;			//�ڵ���
	bool OK;			//���
	int length= 0x3f3f3f3f;			//���������̳���
	int before_num;		//��һ���ڵ���
};

 Dijkstra_Node s[Size];

//��������

//�ڵ��ʼ��
Dijkstra_Node* init(Dijkstra_Node s[Size]);
void Main(const int Map[Size][Size], Dijkstra_Node s[Size]);
void PrintNode(const Dijkstra_Node s[Size]);
//����ʵ��
Dijkstra_Node* init(Dijkstra_Node s[Size])
{
	for (int i = 0; i < Size; i++) {
		s[i].num = i;
		s[i].OK = false;
		
	}
	return s;
}

void PrintNode(const Dijkstra_Node s[Size]) {
	for (int i = 0; i < Size; i++) {
		cout << s[i].num << "," << s[i].length << "," << s[i].before_num << endl;
	}
}
void Main(const int Map[Size][Size], Dijkstra_Node s[Size]) 
{
	s[0].length = 0;
	
	int nb=0;//ѭ��������ÿ��ѭ�����һ���ڵ㣬���нڵ㶼����Ǻ����
	while (nb < Size) {
		int min_num;
		if (s[0].OK == true) {//����ǵ�
			int min = 0x3f3f3f3f;
		//�ҵ�δ��ǵĽڵ����ҳ���������������
			for (int i = 0; i < Size; i++) {
				if (min > s[i].length && s[i].OK == false) {
					min = s[i].length;
					min_num = i;
				}
			}
		}
		else min_num = 0;
		//������Ϊ��ǵ�
		s[min_num].OK = true;

		//����һ���ڵ�ľ�����ϱ�ǽڵ��length��ýڵ����ڵ�length���
		for (int i = 0; i < Size; i++) {
			if (Map[min_num][i] != 0 && s[i].OK == false) {
				if (Map[min_num][i] + s[min_num].length < s[i].length) {
					s[i].length = Map[min_num][i]+s[min_num].length;
					s[i].before_num = min_num;
				}
			}
		}
		nb++;
	}
	PrintNode(s);
}
#endif // !Dijkstra
