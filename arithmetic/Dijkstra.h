#pragma once
#ifndef Dijkstra
#define Dijkstra

#include <iostream>

#define Size 9				//节点数


using namespace std;

//初始化图
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
	int num;			//节点编号
	bool OK;			//标记
	int length= 0x3f3f3f3f;			//距离起点最短长度
	int before_num;		//上一个节点编号
};

 Dijkstra_Node s[Size];

//函数声明

//节点初始化
Dijkstra_Node* init(Dijkstra_Node s[Size]);
void Main(const int Map[Size][Size], Dijkstra_Node s[Size]);
void PrintNode(const Dijkstra_Node s[Size]);
//函数实现
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
	
	int nb=0;//循环次数，每次循环标记一个节点，所有节点都被标记后结束
	while (nb < Size) {
		int min_num;
		if (s[0].OK == true) {//待标记点
			int min = 0x3f3f3f3f;
		//找到未标记的节点中找出距离出发点最近的
			for (int i = 0; i < Size; i++) {
				if (min > s[i].length && s[i].OK == false) {
					min = s[i].length;
					min_num = i;
				}
			}
		}
		else min_num = 0;
		//把它作为标记点
		s[min_num].OK = true;

		//与下一个节点的距离加上标记节点的length与该节点现在的length相比
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
