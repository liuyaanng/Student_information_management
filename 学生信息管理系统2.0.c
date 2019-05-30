#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE "欢迎使用学生成绩信息管理系统！"
#define MAX 10
#define main_menu_num 8
#define input_menu_num 3
#define search_menu_num 4
#define update_menu_num 3
//定义一个单链表 
typedef struct student
{
	char name[MAX];
	char num[MAX];
	char sex[MAX];
	int chinese;
	int shuxue;
	int english;
	int computer;
	struct student * next;
} stu;


stu * head = NULL;
int get_input();//获取整数输入 
void print_main_menu();//打印主菜单 
void back_main_menu();//回到主菜单 
void print_show_menu();//打印显示菜单 
void print_search_menu();//打印查询菜单 
void print_excel_head();//打印普通表格头部
void print_sum_excel_head();//打印总成绩表格头部 
void print_excel_tail();//打印普通表格尾部 
void print_sum_excel_tail();//打印总成绩尾部 
 

//主要函数
void input_record();//输入学生信息 
void show_record();//显示学生信息
void search_record();//查找学生信息 
void update_record();//修改学生信息 
void delate_record();//删除学生信息 
void calculate_record();//计算学生信息 
void save_as_file();//保存文件 
void exit_system();//退出系统
void save_data();//保存信息 
void clear_record(); 
void search_by_name();//通过名字查找 
void search_by_num();//通过学号查找 
void search_by_sex();//通过性别查找 
void show_data();//显示最近输入的数据 
void show_local_file();//显示本地文件 
void input_data();//输入数据
void print_table(stu * p);//以表格形式打印 学生信息 
stu * get_last_student(stu *p);//获得最后一个学生信息 


//主菜单要显示的内容 
char main_menu[]=
	"\n"
	"| 1、输入学生信息\n"
	"| 2、显示学生信息\n"
	"| 3、查找学生信息\n"
	"| 4、修改（更新）学生信息\n" 
	"| 5、删除学生信息\n"
	"| 6、计算学生信息\n" 
	"| 7、保存文件\n" 
	"| 8、退出系统\n" ;
	

//将主函数存入主菜单函数指针中，用户输入数值对应指针中函数的位置 
void (*main_menu_func[])()=
{
	input_record,
	show_record,
	search_record,
	update_record,
	delate_record,
	calculate_record, 
	save_as_file,
	exit_system,	
};


//输入菜单要显示的内容 
char show_menu[]= 

     "\n"
     "1、显示最近输入的学生信息\n"
     "2、显示本地文件\n"
     "3、返回主菜单\n"
     "\n"   
;


//
void (*input_menu_func[])()=
{
    show_data,
    show_local_file,
    back_main_menu, 

};
   
  
//查询菜单显示内容 
char search_menu[] = 

    "\n"
    "| 1、按姓名查找\n" 
    "| 2、按学号查找\n"
    "| 3、按性别查找\n"
    "| 4、返回主菜单\n"
;


void (*search_menu_func[])()=
{
     search_by_name,
     search_by_num,
     search_by_sex,
     back_main_menu,
}; 


//修改学生信息菜单显示内容
char update_menu[] = {
      "\n"
      "| 1、按姓名查找\n"
      "| 2、按学号查找\n"
      "| 3、返回主菜单\n"
};
      
      
void (*update_menu_func[])() = 
{
     search_by_name,
     search_by_num,
     back_main_menu,
};
      
      
//主函数 
int main ()
{
    print_main_menu();
	system("pause");
    return 0; 
}  


//获取整数输入 
int get_input()
{
     int input;
     char ch;
     while (scanf("%d",&input)!=1)
     {
           while((ch=getchar())!='\n')
               ;
           printf("输入错误，请输入整数:\n");
     }

     return input;
}


//打印主菜单，呈现用户界面 
void print_main_menu()
{  
    int option;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(main_menu);
    printf("--------------------------------------\n");
        
    while (!(option>=1&&option<=main_menu_num)) 
	{
        printf("->请输入你要进行的操作："); 
        option = get_input();        
	 	if(option>=1&&option<=main_menu_num)
		{
	 	 	break;
	 	}
		printf("输入有误(注：请选择1~%d)\n",main_menu_num);
	}  
    main_menu_func[option-1]();
	
}


//打印显示菜单
void print_show_menu()
{
    int option = 0;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(show_menu);
    printf("--------------------------------------\n");

     
    while (!(option>=1&&option<=input_menu_num)) 
	{
        printf(" ->请输入你要进行的操作:");
        option = get_input();
	 	if(option>=1&&option<=input_menu_num)
		{
	 	 	break;
	 	}
		printf("输入有误(注：请选择1~%d)\n",input_menu_num);
	}  
    input_menu_func[option-1]();
}

      
//打印查询菜单
void print_search_menu()          
{
    int option = 0;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(search_menu);
    printf("--------------------------------------\n");
    while (!(option>=1&&option<=search_menu_num)) 
	{	
        printf(" ->请输入你要进行的操作:");
        option = get_input();
	 	if(option>=1&&option<=search_menu_num)
		{
	 	 	break;
	 	}
		printf("输入有误(注：请选择1~%d)\n",search_menu_num);
	} 
    search_menu_func[option-1]();
}  


//打印修改成绩菜单 
void print_update_menu()
{
    int option = 0;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(update_menu);
    printf("--------------------------------------\n");
    while (!(option>=1&&option<=update_menu_num)) 
	{ 	
        printf(" ->请输入你要进行的操作:");
        option = get_input();
	 	if(option>=1&&option<=update_menu_num)
		{
	 	 	break;
	 	}
		printf("输入有误(注：请选择1~%d)\n",update_menu_num);
	} 
    update_menu_func[option-1]();
}    


//
void print_table(stu * p){
	
    printf("|%10s|%10s|%10s|%4d|%4d|%4d|%6d|\n",p->num,p->name,p->sex,p->chinese,p->shuxue,p->english,p->computer);
}


void print_excel_head()
{
    printf("+----------+----------+----------+----+----+----+------+\n");
	printf("|   学号   |   姓名   |   性别   |语文|数学|英语|计算机|\n");
	printf("+----------+----------+----------+----+----+----+------+\n");
}


void print_sum_excel_head()
{
    printf("+----------+----------+----------+----+----+----+------+------+\n");
	printf("|   学号   |   姓名   |   性别   |语文|数学|英语|计算机|总成绩|\n");
	printf("+----------+----------+----------+----+----+----+------+------+\n");
}


void print_excel_tail()
{
     printf("+----------+----------+----------+----+----+----+------+\n");
}


void print_sum_excel_tail()
{
    printf("+----------+----------+----------+----+----+----+------+------+\n");
}
     

//回到主菜单 
void back_main_menu()
{
     print_main_menu();
}


void input_record(){
     char input_judgement = 'N';//输入判断
     stu*pLastStu = NULL;
     
     stu*pNewStu = (stu*)malloc(sizeof(stu));
     pNewStu->next = NULL;
     input_data(pNewStu);
     if (head == NULL)
     {
         head = pNewStu;
     }
     else
     {
         pLastStu = get_last_student(head);
         pLastStu->next = pNewStu;
     }
     printf("继续输入学生信息>(按Y继续，按任意键返回菜单)");
     getchar();
     input_judgement = getchar();
     if(input_judgement == 'Y' || input_judgement == 'y')
     {
         input_record();
     }
     else
     {
         print_main_menu();
        
     }
}            

                                //输入学生信息 
void show_record(){
     print_show_menu();
     
}                   

                        //显示学生信息
void search_record(){
     print_search_menu();
}                    

                       //查找学生信息 
void update_record(){
     print_update_menu();
}                  

                          //修改学生信息 
void delate_record()
{
    
    stu* p=head;
	stu* pPre=NULL;
	char num[MAX];
	char continue_input='N';
	printf("请输入要删除的学生学号:");
	scanf("%s",num);
	while(p!=NULL)
	{
		if(strcmp(p->num,num)==0)
		{
			break;
		}
		p=p->next;
	}
	if(NULL==p)
	{
		printf("没有学号是[%s]的学生.",num);
	}
	else
	{
		printf("确定要删除学号为[%s]的学生吗?(Y 确定,N 取消)",p->num);
		getchar();
		continue_input=getchar();
		if(continue_input=='y'||continue_input=='Y')
		{
			pPre=head;
			if(pPre==p)
			{
				head=p->next;
				free(p);
			}
			else
			{
				while(pPre!=NULL)
				{
					if(pPre->next==p)
					{
						pPre->next=p->next;
						free(p);
						break;
					}
					pPre=pPre->next;
				}
			}
			printf(">删除成功!\n");
		}
	}
	printf("继续删除吗?(Y 继续,N 返回菜单)");
	getchar();
	continue_input=getchar();
	if(continue_input=='n'||continue_input=='N')
	{
		print_main_menu();
	}
	else
	{
		delete_record();
	}
}
               

                          //删除学生信息 ，主界面与修改学生信息一致 
void calculate_record(){}//计算学生信息 



void save_as_file(){
	save_data();
	getchar(); 
	print_main_menu();
}                       //保存文件 


void save_data(){
     FILE * fp;
     char file[100];
     stu *p = head; 
     printf("请输入文件名：");
     scanf("%s",file);
     fp = fopen(file,"a+");
     
     while(p!=NULL)
     {
           fprintf(fp,"|%10s|%10s|%10s|%4d|%4d|%4d|%6d|\n",p->name,p->num,p->sex,p->chinese,p->shuxue,p->english,p->computer);
           p = p->next;
     }
   
     fclose(fp);
     printf("保存文件成功！");
     getchar();     
}                                                 //保存文件 


//递归删除student结构链表的函数
void clear_record(stu *p)
{
	if(p==NULL)
	{
		return;
	}
	/*如果student结构体的next指针是空则表示没有下一个数据，删除该节点*/
	if(p->next==NULL)
	{
		free(p);
	}
	/*如果student结构体的next指针不为空*/
	else
	{
		clear_record(p->next);//再次调用本函数，student结构体next指向的结点作为参数
		free(p);//删除当前节点
		p=NULL;
	}

}


void exit_system(){
     printf("是否保存文件？(注：按Y保存，按任意键退出)\n");
     char ch;
     getchar();
     ch = getchar();
     if(ch == 'Y' ||ch == 'y')
     {
           save_data();
           printf("\n谢谢您的使用!");
           clear_record(head);
           getchar();
           exit(0);
           
     }
     else
     {
         printf("谢谢您的使用！"); 
         clear_record(head);  //释放整个链表
         getchar();
         exit(0);
     }
}                                    //退出系统


void search_by_name(){
	char name[MAX];
	char continue_input='N';
	stu *p=head;
	int isfound=0;
	printf(">请输入学生姓名:");
	scanf("%s",name);
	printf("\n>查找[%s]...\n");
	print_excel_head();
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			print_table(p);
			isfound=1;						//姓名可能会重复，所以应该查到最后一个
		}
		p=p->next;
	}
	if(!isfound)
		printf("\n没有找到结果!\n");
	print_excel_tail();
	printf("继续查找?(Y 继续,N 返回)");
	getchar();
	continue_input=getchar();
	if('Y'==continue_input||'y'==continue_input)
	{
		search_by_name();
	}
	else
	{
		search_record();
	}
}                                   //通过名字查找 
                                   
                                   
void search_by_num(){
    char num[MAX];
	char continue_input='N';
	stu*p=head;
	int isfound=0;
	printf(">请输入学生学号:");
	scanf("%s",num);
	printf("\n查找[%s]...\n",num);
	print_excel_head();
	while(p!=NULL)
	{
		if(strcmp(p->num,num)==0)
		{
			print_table(p);
			isfound=1;
			break;					//每个人学号只有一个，所以查到就可以跳出循环
		}
		p=p->next;
	}
	if(!isfound)
		printf("\n没有找到结果!\n");
	print_excel_tail();
	printf("继续查找?(Y 继续,任意键返回)");
	getchar();
	continue_input=getchar();
	if('Y'==continue_input||'y'==continue_input)
	{
		search_by_num();
	}
	else
	{
		search_record();
	}
}                                         //通过学号查找 
	
	
void search_by_sex(){
char sex[MAX];
	char continue_input='N';
	stu *p=head;
	int isfound=0;
	printf(">请输入学生性别:");
	scanf("%s",sex);
	printf("\n>查找[%s]...\n");
	print_excel_head();
	while(p!=NULL)
	{
		if(strcmp(p->sex,sex)==0)
		{
			print_table(p);
			isfound=1;
		}
		p=p->next;
	}
	if(!isfound)
		printf("\n没有找到结果!\n");
	print_excel_tail();
	printf("继续查找?(Y 继续,任意键返回)");
	getchar();
	continue_input=getchar();
	if('Y'==continue_input||'y'==continue_input)
	{
		search_by_sex();
	}
	else
	{
		search_record();
	}
}                        //通过性别查找 


void show_data(){
	 system("cls");
     stu * p = head;
     char i;
     printf("_________________________________________________________\n");
     printf("\n\t\t   学生成绩信息表\n"); 
     print_excel_head();
     while (p!=NULL)
     {
         print_table(p);
		 p = p->next;
	 }
     print_excel_tail();
     printf("\n按任意键返回主菜单\n");
     getchar();
     getchar();
     print_show_menu();
} 


void show_local_file(){
     char input_judgement = 'N'; 
     char ch;
     char name[30];
     FILE *fa,*fp;
     printf("请输入你要打开的文件名：");
     scanf("%s",name);
   
     fa = fopen(name,"r+");
     if (fa==NULL)
     {
         printf("未找到该文件");
         printf("是否创建名为%s的文件？(注：按Y创建，按任意键返回菜单)",name);
         getchar(); 
         input_judgement = getchar();
         if( input_judgement == 'Y' || input_judgement == 'y')
         {
             fp = fopen(name,"a+");
             if (fp ==NULL)
             {
                    printf("打开文件失败！");
             }   
             else
             {
          
                    while ((ch=getc(fp)) != EOF)
                    {
                      putchar(ch);
                    }
             fclose(fp); 
             printf("创建文件成功！\n"); 
             getchar();
             input_record();
             
             }
          }
          else
          {
             print_show_menu();
          }
          }
     else
     {
     	 print_excel_head();
         while ((ch=getc(fa)) != EOF)
         {
             putchar(ch);
         }
         print_excel_tail();
         fclose(fa);
         printf("按任意键返回");
         getchar();
         getchar();
         print_show_menu(); 
     }     
}                                              //导入本地文件 


void input_data(stu * pNewStu){
     printf(">请输入学生信息(注：最大长度是10个字符)\n");
     printf("姓名:");scanf("%s",pNewStu->name); 
     printf("学号:");scanf("%s",pNewStu->num);
     printf("性别:");scanf("%s",pNewStu->sex);
     printf(">请输入%s的成绩(注：0~100)\n",pNewStu->name); 
     printf("语文:");scanf("%d",&(pNewStu->chinese));
     printf("数学:");scanf("%d",&(pNewStu->shuxue));
     printf("英语:");scanf("%d",&(pNewStu->english));
     printf("计算机:");scanf("%d",&(pNewStu->computer));
     
}//


stu* get_last_student(stu*p)
{
	if(p->next==NULL)
	{
		return p;
	}
	else
	{
		return get_last_student(p->next);
	}
}    // 
