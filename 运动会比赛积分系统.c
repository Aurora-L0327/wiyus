#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include <sys/types.h>
#include <sys/stat.h>
#define  N 20
#define NUM 20//学院个数 

int m;//男子项目数
int w; //女子项目数
int n;//学院个数
typedef struct woman
{ 
	int num;  // 编号
    int score;
    int rank;//名次
} woman;
typedef struct man
{ 
	int num;//编号
    int score;
    int rank;//名次
} man;
typedef struct node{
  int schoolnum;
  int score;
  char name[55];
  int manscore;
  int wscore;
  man manItem[N];
  woman woItem[N];
} node;

node stuw[NUM];
  void Write();
  void Read();
  void scan();//输入信息
  void count();//算积分
  void schooltotalsort(); //按学院得分编号排序 
  void itemnum();//以项目编号查询前三名的学校
  void menu();//菜单调用 
  void menu1();//菜单1 
  void menu2();//菜单2 
  void menu3();//菜单3 
int main(int argc, char const *argv[])  
{
	Read();
	menu();
	return 0;
}
void menu(){
	int a,b,c;
	menu1();
	scanf("%d",&a);
	while (a!=4)
	{
		switch(a)
		{
		case 1: 
			scan();
			count();
			getchar();
			system("pause");
			menu1();
			break;
		case 2: 
			menu2();
			scanf("%d",&b);
			while(b!=2)
			{
				switch(b)
				{
				case 1:
					schooltotalsort();
					getchar();
					menu2();
					break;
				case 2:
					getchar();
					menu1();
					break;
				}
				scanf("%d",&b);
			}
			menu1();
			break;
		case 3:
			menu3();
			scanf("%d",&c);
			while(c!=2)
			{
				switch(c)
				{
				case 1:
					itemnum();
					getchar();
					menu3();
					break;
				case 2:
					getchar();
					menu1();
					break;
				}
				scanf("%d",&c);
			}
			menu1();
			break;
		default :
			getchar();
			menu1();
			printf("\n\t\t\t****请输入正确操作***\n");
			break;
		}
	scanf("%d",&a);
	}
} 
void menu1()//菜单
{
	printf(" \t\t\t运动会比赛积分系统\n ") ;
	printf("\n");
	printf("\t\t\t *** 1 输入运动会的相关信息***\n");
	printf("\t\t\t *** 2 运动会排名***\n");
	printf("\t\t\t *** 3 项目分数查询***\n");
	printf("\t\t\t *** 4 退出***\n");
	printf("*******请选择要进行的操作1/2/3/4*******\n");
	printf("注意：在进行其他操作时请先输入运动会信息\n");
}
void menu2()//菜单
{
	printf("***\t\t\t运动会排名***\n");
	printf("\n");
	printf("\t\t\t ***1 学院总分排名***\n");
	printf("\t\t\t ***2 退出***\n");
	printf("*******请选择要进行的操作1/2*******\n");
}
void menu3()//菜单
{
	printf("\t\t\t***运动会查询***\n");
	printf("\n");
	printf("\t\t\t *** 1 项目得分***\n");
	printf("\t\t\t *** 2 退出***\n");
	printf("******* 选择要进行的操作1/2***\n");
}
void scan() //输入信息
 {
	 int i,j,z;
 	 FILE *fp ;
	 printf("请先输入运动会信息\n");
	 printf("输入学校个数:");
	 scanf("%d",&n);
	 getchar();
	 printf("输入男子项目个数:");
	 scanf("%d",&m);
	 getchar();
	 printf("输入女子项目个数:");
	 scanf("%d",&w);
	 getchar();
	 if((fp=fopen("sports.txt","w"))==NULL)
	 {
		 printf("文件打开失败\n");
		 getchar();
		 exit(1);
	 }
	 else
	 {
		 for(i=0;i<n;i++)
		 {
			 printf("\n请输入第%d个学校编号：",i+1);
			 scanf("%d",&stuw[i].schoolnum);//输入学院编号
			 printf("第%d所学校的名字为:",i+1);
			 scanf("%s",&stuw[i].name );
			 printf("\n");
			 for(j=0;j<m;j++)
			 {
				 printf("输入第%d所学校的第%d个男子项目编号",i+1,j+1);
				 scanf("%d",&stuw[i].manItem[j].num );
				 printf("\n");
				 printf("该学校该项目获得第几名？");
				 scanf("%d",&stuw[i].manItem[j].rank   );
				 printf("\n");
			 }
			 for(z=0;z<w;z++)
			 {
				 printf("输入第%d所学校的第%d个女子项目编号",i+1,z+1);
				 scanf("%d",&stuw[i].woItem[z].num  );
				 printf("\n");
				 printf("该学校该项目获得第几名？");
				 scanf("%d",&stuw[i].woItem[z].rank   );
				 printf("\n");
				 printf("\n");
			 }
			 printf("_______________________________\n");
		 }
		 
		 fclose(fp);
		 Write();
	 }
 }
void Write()
{
  FILE *fp ;
  fp = fopen("sports.txt","wb"); // 打开文件
  fwrite( (char*)stuw,sizeof(node),6,fp); // 写入数据
  fclose(fp);
}
void Read()// 文件数据读取
{
	int i;
	FILE *fp ;
  struct stat buf;
  int rows;
  stat("sports.txt",&buf);
  rows = buf.st_size/sizeof(node);
  fp = fopen("sports.txt","rb");
  fread((char *)stuw,sizeof(node),rows,fp);
  fclose(fp);
  n = NUM;
  m = N;
  w = N;
  for(i = 0; i < NUM; i++){
  	if(stuw[i].schoolnum == 0){
  		n = i;
  		break;
  	}
  }
  for(i = 0; i < N; i++){
  	if(stuw[0].manItem[i].num == 0){
  		m = i;
  		break;
  	}
  }
  for(i = 0; i < N; i++){
  	if(stuw[0].woItem[i].num == 0){
  		w = i;
  		break;
  	}
  }
}
void count()//算积分
 {
	 int i,j;
	 int z;
	 int a=0;
	 int b=0;
	 for(i=0;i<n;i++)  //利用积分制计算分数
	 {
		 printf("学校的编号 %d \n",stuw[i].schoolnum );
		 printf("学校的名字 %s \n",stuw[i].name );
		 for(j=0;j<m;j++)//男子项目
		 {
			 switch(stuw[i].manItem[j].rank      )//根据名次来判断积分的情况
			 {
			 case 1: 
				 stuw[i].manItem[j].score =7; break ;
			 case 2:
				 stuw[i].manItem[j].score =5; break ;
			 case 3:
				 stuw[i].manItem[j].score =3; break ;
			 case 4:
				 stuw[i].manItem[j].score =2; break ;
			 case 5:
				 stuw[i].manItem[j].score =1; break ;
			 default : 
				 stuw[i].manItem[j].score =0; break ;
			 }
		 }
		 for(z=0;z<w;z++) //女子项目
		 {
			 switch(stuw[i].woItem[z].rank  )//根据名次来判断积分的情况
			 {
			 case 1:
				 stuw[i].woItem[z].score=5; break ;
			 case 2: 
				 stuw[i].woItem[z].score=3; break ;
			 case 3:
				 stuw[i].woItem[z].score=2; break ;
			 default:
				 stuw[i].woItem[z].score=0; break ;
			 }
		 }
		 for(j=0;j<m;j++)  //男子项目名次及分数
		 {
			 printf("第%d男子项目的编号为 %d\n",j+1,stuw[i].manItem[j].num   );
			 printf("第%d男子项目的名次为 %d\t",j+1,stuw[i].manItem[j].rank  );
			 printf("男子分数：%d\n",stuw[i].manItem[j].score   );
			 a =a+stuw[i].manItem[j].score;
		 }
		 stuw[i].manscore=a;//男子项目总分
		 for(z=0;z<w;z++)  //女子项目的名次及分数
		 {
			 printf("第%d女子项目的编号为%d\n",z+1,stuw[i].woItem[z].num );
			 printf("第%d女子项目的名次为%d\t",z+1,stuw[i].woItem[z].rank  );
			 printf("女子分数 %d\n",stuw[i].woItem[z].score  );
			 b =b+stuw[i].woItem[z].score ;
		 }
		 stuw[i].wscore=b;//女子项目总分
		 stuw[i].score  =stuw[i].manscore +stuw[i].wscore ;//学院总分
		 printf("男子项目总分数是：%d\t",stuw[i].manscore );
		 printf("女子项目总分数是：%d\n",stuw[i].wscore);
		 printf("分数和：%d\n",stuw[i].score );
		 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		 printf("\n");
		 a=0;
		 b=0;
	 }
	 Write(); 
 }
 void  schooltotalsort()              //按学校总分排序
 {
	 int i,j,k;
	 node t[NUM];
	 for(i=0;i<n-1;i++)//采取交换排序的方法进行学院之间关于总分的排序
	 {
		 for(j=i+1;j<n;j++)
		 {
			 if(stuw[i].score <stuw[j].score  )
			 {
				 t[i]=stuw[i];
				 stuw[i]=stuw[j];
				 stuw[j]=t[i];
			 }
		 }
	 }
	 printf("\t\t运动会学校排名\n\n");
	 printf("\t学校编号\t名称学校\t学校总分数\n");
	 for(i=0;i<n;i++)
	 {
		 printf("\t%d\t\t%s\t\t%d\n",stuw[i].schoolnum ,stuw[i].name ,stuw[i].score );
	 }
	 printf("***\n");
	 Write(); 
 }
void itemnum()//以项目编号查询学校排名 
{
	int a,b,c;
	int i,j,k;
	int flag=0,sign;
	node t[NUM];
	printf("\n");
	printf("\t\t\t ***1 *** 查询***\n");
	printf("\t\t\t ***0 ***返回上一单元\n");
	printf("*******您要进行的操作1/0.....***\n");
	scanf("%d",&a);
	if(a==0)
	{
		printf("\t\t\t按任意键返回上一单元\n");
		return;
	}
	printf("\n输入需要查询项目编号\n");
	scanf("%d",&b);
	if(a==1)
	{
		for(j=0;j<m;j++)
			if(b==stuw[0].manItem[j].num)
			{
				flag=1;sign=1;c=j;
			} 
			for(j=0;j<m;j++)
				if(b==stuw[0].woItem[j].num)
				{	
					flag=2;sign=2;c=j;
				}
				if(flag==1)
					for(i=0;i<n;i++)
						for(j=0;j<n-i;j++)
							if(stuw[j].manItem[c].score<stuw[j+1].manItem[c].score ||(stuw[j].manItem[c].score == stuw[j+1].manItem[c].score && stuw[j].manItem[c].rank > stuw[j+1].manItem[c].rank && stuw[j].manItem[c].rank != 0 && stuw[j+1].manItem[c].rank != 0))
							{
								t[0]=stuw[j];
								stuw[j]=stuw[j+1];
								stuw[j+1]=t[0];
							}
							if(flag==2)
								for(i=0;i<n;i++)
									for(j=0;j<n-i;j++)
										if(stuw[j].woItem[c].score<stuw[j+1].woItem[c].score || (stuw[j].woItem[c].score == stuw[j+1].woItem[c].score && stuw[j].woItem[c].rank > stuw[j+1].woItem[c].rank && stuw[j].woItem[c].rank != 0 && stuw[j+1].woItem[c].rank != 0))
										{
											t[0]=stuw[j];
											stuw[j]=stuw[j+1];
											stuw[j+1]=t[0];
										}
										if(flag!=0)
										{
											printf("\t学校编号\t学校名字\t项目编号\t项目名次\t项目分数\n");
											if(sign==1)
												for(i=0;i<n;i++)
													printf("\t%d\t\t%s\t\t%d\t\t%d\t\t%d\n",stuw[i].schoolnum,stuw[i].name,stuw[i].manItem[c].num,stuw[i].manItem[c].rank,stuw[i].manItem[c].score);
												printf("\n\n");
												if(sign==2)
													for(i=0;i<n;i++)
														printf("\t%d\t\t%s\t\t%d\t\t%d\t\t%d\n",stuw[i].schoolnum,stuw[i].name,stuw[i].woItem[c].num,stuw[i].woItem[c].rank,stuw[i].woItem[c].score); 
													printf("\n\n");
										}
										if(flag==0)
											printf("查无此项目.\n");
	}
	if(a<0||a>1)
	{
		printf("输入错误.\n");
		printf("按任意键返回\n");
		return;
	}
}

