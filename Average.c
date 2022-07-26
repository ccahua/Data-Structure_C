#include<stdio.h>

int main(){
	//求两个数的平均数
	int a,b;
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b);
	double c = (a+b)/2.0;
	printf("%d和%d的平均数为：%f\n",a,b,c);
	return 0;
}
