#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include <sys/types.h>
#include <sys/stat.h>
#define  N 20
#define NUM 20//ѧԺ���� 

int m;//������Ŀ��
int w; //Ů����Ŀ��
int n;//ѧԺ����
typedef struct woman
{ 
	int num;  // ���
    int score;
    int rank;//����
} woman;
typedef struct man
{ 
	int num;//���
    int score;
    int rank;//����
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
  void scan();//������Ϣ
  void count();//�����
  void schooltotalsort(); //��ѧԺ�÷ֱ������ 
  void itemnum();//����Ŀ��Ų�ѯǰ������ѧУ
  void menu();//�˵����� 
  void menu1();//�˵�1 
  void menu2();//�˵�2 
  void menu3();//�˵�3 
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
			printf("\n\t\t\t****��������ȷ����***\n");
			break;
		}
	scanf("%d",&a);
	}
} 
void menu1()//�˵�
{
	printf(" \t\t\t�˶����������ϵͳ\n ") ;
	printf("\n");
	printf("\t\t\t *** 1 �����˶���������Ϣ***\n");
	printf("\t\t\t *** 2 �˶�������***\n");
	printf("\t\t\t *** 3 ��Ŀ������ѯ***\n");
	printf("\t\t\t *** 4 �˳�***\n");
	printf("*******��ѡ��Ҫ���еĲ���1/2/3/4*******\n");
	printf("ע�⣺�ڽ�����������ʱ���������˶�����Ϣ\n");
}
void menu2()//�˵�
{
	printf("***\t\t\t�˶�������***\n");
	printf("\n");
	printf("\t\t\t ***1 ѧԺ�ܷ�����***\n");
	printf("\t\t\t ***2 �˳�***\n");
	printf("*******��ѡ��Ҫ���еĲ���1/2*******\n");
}
void menu3()//�˵�
{
	printf("\t\t\t***�˶����ѯ***\n");
	printf("\n");
	printf("\t\t\t *** 1 ��Ŀ�÷�***\n");
	printf("\t\t\t *** 2 �˳�***\n");
	printf("******* ѡ��Ҫ���еĲ���1/2***\n");
}
void scan() //������Ϣ
 {
	 int i,j,z;
 	 FILE *fp ;
	 printf("���������˶�����Ϣ\n");
	 printf("����ѧУ����:");
	 scanf("%d",&n);
	 getchar();
	 printf("����������Ŀ����:");
	 scanf("%d",&m);
	 getchar();
	 printf("����Ů����Ŀ����:");
	 scanf("%d",&w);
	 getchar();
	 if((fp=fopen("sports.txt","w"))==NULL)
	 {
		 printf("�ļ���ʧ��\n");
		 getchar();
		 exit(1);
	 }
	 else
	 {
		 for(i=0;i<n;i++)
		 {
			 printf("\n�������%d��ѧУ��ţ�",i+1);
			 scanf("%d",&stuw[i].schoolnum);//����ѧԺ���
			 printf("��%d��ѧУ������Ϊ:",i+1);
			 scanf("%s",&stuw[i].name );
			 printf("\n");
			 for(j=0;j<m;j++)
			 {
				 printf("�����%d��ѧУ�ĵ�%d��������Ŀ���",i+1,j+1);
				 scanf("%d",&stuw[i].manItem[j].num );
				 printf("\n");
				 printf("��ѧУ����Ŀ��õڼ�����");
				 scanf("%d",&stuw[i].manItem[j].rank   );
				 printf("\n");
			 }
			 for(z=0;z<w;z++)
			 {
				 printf("�����%d��ѧУ�ĵ�%d��Ů����Ŀ���",i+1,z+1);
				 scanf("%d",&stuw[i].woItem[z].num  );
				 printf("\n");
				 printf("��ѧУ����Ŀ��õڼ�����");
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
  fp = fopen("sports.txt","wb"); // ���ļ�
  fwrite( (char*)stuw,sizeof(node),6,fp); // д������
  fclose(fp);
}
void Read()// �ļ����ݶ�ȡ
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
void count()//�����
 {
	 int i,j;
	 int z;
	 int a=0;
	 int b=0;
	 for(i=0;i<n;i++)  //���û����Ƽ������
	 {
		 printf("ѧУ�ı�� %d \n",stuw[i].schoolnum );
		 printf("ѧУ������ %s \n",stuw[i].name );
		 for(j=0;j<m;j++)//������Ŀ
		 {
			 switch(stuw[i].manItem[j].rank      )//�����������жϻ��ֵ����
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
		 for(z=0;z<w;z++) //Ů����Ŀ
		 {
			 switch(stuw[i].woItem[z].rank  )//�����������жϻ��ֵ����
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
		 for(j=0;j<m;j++)  //������Ŀ���μ�����
		 {
			 printf("��%d������Ŀ�ı��Ϊ %d\n",j+1,stuw[i].manItem[j].num   );
			 printf("��%d������Ŀ������Ϊ %d\t",j+1,stuw[i].manItem[j].rank  );
			 printf("���ӷ�����%d\n",stuw[i].manItem[j].score   );
			 a =a+stuw[i].manItem[j].score;
		 }
		 stuw[i].manscore=a;//������Ŀ�ܷ�
		 for(z=0;z<w;z++)  //Ů����Ŀ�����μ�����
		 {
			 printf("��%dŮ����Ŀ�ı��Ϊ%d\n",z+1,stuw[i].woItem[z].num );
			 printf("��%dŮ����Ŀ������Ϊ%d\t",z+1,stuw[i].woItem[z].rank  );
			 printf("Ů�ӷ��� %d\n",stuw[i].woItem[z].score  );
			 b =b+stuw[i].woItem[z].score ;
		 }
		 stuw[i].wscore=b;//Ů����Ŀ�ܷ�
		 stuw[i].score  =stuw[i].manscore +stuw[i].wscore ;//ѧԺ�ܷ�
		 printf("������Ŀ�ܷ����ǣ�%d\t",stuw[i].manscore );
		 printf("Ů����Ŀ�ܷ����ǣ�%d\n",stuw[i].wscore);
		 printf("�����ͣ�%d\n",stuw[i].score );
		 printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		 printf("\n");
		 a=0;
		 b=0;
	 }
	 Write(); 
 }
 void  schooltotalsort()              //��ѧУ�ܷ�����
 {
	 int i,j,k;
	 node t[NUM];
	 for(i=0;i<n-1;i++)//��ȡ��������ķ�������ѧԺ֮������ֵܷ�����
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
	 printf("\t\t�˶���ѧУ����\n\n");
	 printf("\tѧУ���\t����ѧУ\tѧУ�ܷ���\n");
	 for(i=0;i<n;i++)
	 {
		 printf("\t%d\t\t%s\t\t%d\n",stuw[i].schoolnum ,stuw[i].name ,stuw[i].score );
	 }
	 printf("***\n");
	 Write(); 
 }
void itemnum()//����Ŀ��Ų�ѯѧУ���� 
{
	int a,b,c;
	int i,j,k;
	int flag=0,sign;
	node t[NUM];
	printf("\n");
	printf("\t\t\t ***1 *** ��ѯ***\n");
	printf("\t\t\t ***0 ***������һ��Ԫ\n");
	printf("*******��Ҫ���еĲ���1/0.....***\n");
	scanf("%d",&a);
	if(a==0)
	{
		printf("\t\t\t�������������һ��Ԫ\n");
		return;
	}
	printf("\n������Ҫ��ѯ��Ŀ���\n");
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
											printf("\tѧУ���\tѧУ����\t��Ŀ���\t��Ŀ����\t��Ŀ����\n");
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
											printf("���޴���Ŀ.\n");
	}
	if(a<0||a>1)
	{
		printf("�������.\n");
		printf("�����������\n");
		return;
	}
}

