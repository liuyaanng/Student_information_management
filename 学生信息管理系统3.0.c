#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE "欢迎使用学生成绩信息管理系统！"
#define MAX 10
#define main_menu_num 8
#define input_menu_num 3
#define search_menu_num 4
#define update_menu_num 3
#define pass_mark 60
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
void print_update_menu();//
void print_delate_menu();//
void print_calculate_menu();//
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
void update_by_name();//通过姓名更新
void update_by_num();//通过学号更新 
void delate_by_name();//通过姓名删除 
void delate_by_num();//通过学号删除
void calculate_stu_sum();//计算学生总成绩 
void calculate_stu_average();// 计算学生平均成绩 
void print_stu_fail();//打印不及格学生名单 
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
    "| 1、通过姓名查找\n" 
    "| 2、通过学号查找\n"
    "| 3、通过性别查找\n"
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
      "| 1、通过姓名更新\n"
      "| 2、通过学号更新\n"
      "| 3、返回主菜单\n"
};
      
      
void (*update_menu_func[])() = 
{
     update_by_name,
     update_by_num,
     back_main_menu,
};
//删除学生信息菜单显示内容 
char delate_menu[] = 
    "\n"
    "1、通过姓名删除信息\n" 
    "2、通过学号删除信息\n"  
    "3、返回主菜单\n"
;
void (*delate_menu_func[])() = 
{
     delate_by_name,
     delate_by_num,
     back_main_menu,
};
//计算菜单显示内容
char calculate_menu[] = 
    "\n"
    "1、计算学生总成绩\n"
    "2、计算学生各科成绩平均分\n"
    "3、打印不及格学生名单\n" 
    "4、返回主菜单\n" ;
void (*calculate_menu_func[])() = 
{
     calculate_stu_sum,
     calculate_stu_average,
     print_stu_fail,
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
//打印删除菜单
void print_delate_menu()
{
    int option = 0;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(delate_menu);
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
    delate_menu_func[option-1]();
} 
//打印计算菜单
 void print_calculate_menu(){
    int option = 0;
    system("cls");
    printf("======================================\n");
    printf(TITLE);
    printf("\n--------------------------------------\n");
    printf(calculate_menu);
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
    calculate_menu_func[option-1]();

}        


//将输入的信息以表格的形式打印出来 
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
     char input_judgement = 'N';                     //输入判断
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
         pLastStu =  get_last_student(head);                //判断是否为第一次输入 ，递归获得最后一个 
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
    char continue_input = 'N';
    print_update_menu();
    printf("是否继续更新信息？(Y继续，任意键返回主菜单)"); 
    continue_input=getchar();
	if('Y'==continue_input||'y'==continue_input)
	{
		print_update_menu();
	}
	else
	{
		back_main_menu();
	}
    
}                  

                          //修改学生信息 
void delate_record(){
     print_delate_menu();    
}                 

                          //删除学生信息 ，主界面与修改学生信息一致 
void calculate_record(){
     print_calculate_menu();
     
     
     }//计算学生信息 



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
	if(p->next==NULL)
	{
		free(p);
	}
	
	else
	{
		clear_record(p->next);     //再次调用本函数，student结构体next指向的结点作为参数
		free(p);                
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
	char continue_input = 'N';
	char name[MAX];
	stu *p=head;
	int isfound=0;
	printf(">请输入学生姓名:");
	scanf("%s",name);
	printf("\n>查找[%s]...\n",name);
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
	printf("继续查找?(Y 继续,任意键返回)");
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
	
}                                       //通过名字查找 
                                   
                                   
void search_by_num(){
    char num[MAX];
	char continue_input = 'N';
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
		search_by_name();
	}
	else
	{
		search_record();
	}
	
}                                         //通过学号查找 
	
	
void search_by_sex(){
    char continue_input = 'N';
    char sex[MAX];
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
		search_by_name();
	}
	else
	{
		search_record();
	}
	
}                        //通过性别查找 
void update_by_name()
{
     char name[MAX];
     char continue_input = 'N';
     stu * p = head;
     
     printf("请输入要更新信息学生的姓名：");
     scanf("%s",name);
     print_excel_head();
     while(p!=NULL)
     {
           if(strcmp(p->name,name)==0)
           {
               print_table(p);
               break;
              
           } 
           p = p->next;
     }
     if (p == NULL){
         printf("没有姓名为%s的学生",name);
         print_excel_tail();
     }
     else
     {
         print_excel_tail();
         input_data(p);
         printf("\n更新成功!"); 
     }
     getchar();
} 
void update_by_num()
{
     stu *p = head;
     char num[MAX];
     printf("请输入要更新的学生的学号：");
     scanf("%s",num);
     print_excel_head();
     while(p!=NULL)
     {
           if(strcmp(p->num,num)==0)
           {
                  print_table(p);break;
           }
           p = p->next;
     }
     if(p==NULL)
     {
         printf("没有学号为%s的学生",num);
         print_excel_tail();
     }
     else
     {
         print_excel_tail();
         input_data(p);
         printf("更新成功！\n");
     }
     getchar();
}        
void delate_by_name(){
     char continue_input = 'N';
     char name[MAX];
     stu *p=head;
     stu *q=NULL;
     printf("请输入你要删除的学生的姓名：");
     scanf("%s",name);
     print_excel_head();
     while(p!=NULL)
     {
           if(strcmp(p->name,name)==0)
           {
                 print_table(p);
                 break;
           }
           p = p->next;
     }
     if(p==NULL)
     {
         printf("没有姓名为%s的学生\n",name);
         print_excel_tail();
         printf("按任意键返回菜单"); 
         getchar();
         getchar(); 
         print_delate_menu();
     }
     else
     { 
         printf("确定要删除姓名为%s学号为%s的学生吗？(Y删除，任意键返回菜单)",p->name,p->num);
         getchar();
         continue_input = getchar();
         if(continue_input=='Y'||continue_input=='y')
         {
             q = head;
             if(q==p)
             {
                 head = p->next;
                 free(p);
             }
             else
             {
                 while(q!=NULL)
                 {
                      if(p==q->next)
                      {
                             q->next = p->next;
                             free(p);
                             break;
                      }
                      q = q->next;
                      
                 }   
             }
             printf("删除成功！\n");
             printf("是否继续删除？(注：按Y删除，任意键返回菜单)");
             getchar();
             continue_input = getchar(); 
             if(continue_input=='Y'||continue_input=='y')
             {
                     delate_by_name();
             }
             else
             {
                     print_delate_menu();
             }
                                              
         }
         else 
         {
              print_delate_menu();  
         }
    
     }
}                                            
void delate_by_num()
{
     char continue_input = 'N';
     char num[MAX];
     stu *p=head;
     stu *q=NULL;
     printf("请输入你要删除的学生的学号：");
     scanf("%s",num);
     print_excel_head();
     while(p!=NULL)
     {
           if(strcmp(p->num,num)==0)
           {
                 print_table(p);
                 break;
           }
           p = p->next;
     }
     if(p==NULL)
     {
         printf("没有学号为%s的学生\n",num);
         print_excel_tail();
         printf("按任意键返回菜单"); 
         getchar();
         getchar(); 
         print_delate_menu();
     }
     else
     { 
         printf("确定要删除姓名为%s学号为%s的学生吗？(Y删除，任意键返回菜单)",p->name,p->num);
         getchar();
         continue_input = getchar();
         if(continue_input=='Y'||continue_input=='y')
         {
             q = head;
             if(q==p)
             {
                 head = p->next;
                 free(p);
             }
             else
             {
                 while(q!=NULL)
                 {
                      if(p==q->next)
                      {
                             q->next = p->next;
                             free(p);
                             break;
                      }
                      q = q->next;
                      
                 }     
             }
             printf("删除成功！\n");
             printf("是否继续删除？(注：按Y继续删除，任意键返回菜单)");
             getchar();
             continue_input = getchar(); 
             if(continue_input=='Y'||continue_input=='y')
             {
                     delate_by_num();
             }
             else
             {
                     print_delate_menu();
             }
                                                   
         }
         else 
         {
              print_delate_menu();
         }
 
     } 
}                                            
void calculate_stu_sum()
{
     int t;
     stu *p = head;
     if(p==NULL)
     {
         printf("你还没有输入任何信息！(按任意键返回主菜单)");
         getchar();
         getchar();
         back_main_menu();
     }
     else
     {   
         print_sum_excel_head();
         while(p!=NULL)
         {
             t = p->chinese + p->shuxue + p->english + p->computer;
             printf("|%10s|%10s|%10s|%4d|%4d|%4d|%6d|%6d|\n",p->num,p->name,p->sex,p->chinese,p->shuxue,p->english,p->computer,t);
             p = p->next;
         }
         print_sum_excel_tail();
         printf("按任意键返回");
         getchar();
         getchar(); 
         print_calculate_menu();
     }
} 
 
void calculate_stu_average()
{
     stu * p = head;
     int ave1=0;
     int ave2=0;
     int ave3=0;
     int ave4=0;
     int count = 0;
     system("cls");
     printf("_________________________________________________________\n");
     printf("\n\t\t   学生成绩信息表\n"); 
     print_excel_head();
     while (p!=NULL)
     {
         print_table(p);
         ave1 += p->chinese;
         ave2 += p->shuxue;
         ave3 += p->english;
         ave4 += p->computer;
         p = p->next;
         count=count+1;
	 }

     print_excel_tail();
     printf("\n各科平均成绩为：\n"); 
     printf("语文:%5.2f  数学:%5.2f  英语:%5.2f  计算机:%5.2f",(float)ave1/count,(float)ave2/count,(float)ave3/count,(float)ave4/count);
     printf("\n按任意键返回");
     getchar();
     getchar();
     print_calculate_menu();   
}  
                                                                                //
void print_stu_fail(){
	stu *p=head;
	int count1 = 0;
	int count2 = 0;
	system("cls");
    printf("_________________________________________________________\n");
    printf("\n\t\t   学生成绩信息表\n"); 
    print_excel_head();
    while (p!=NULL)
    {
    	if(p->chinese<=pass_mark||p->shuxue<=pass_mark||p->english<=pass_mark||p->computer<=pass_mark)
    	{
    		print_table(p);
    		count1++;
		}
		p = p->next;
		count2++;
	}
	print_excel_tail();
	printf("\n不及格人数为：%d",count1);
	printf("\t及格率为：%4.2f%%",((float)(count2-count1)/count2)*100);
	printf("\n按任意键返回菜单");
	getchar();
    getchar();
    print_calculate_menu();	
}
void show_data(){
	 system("cls");
     stu * p = head;
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
             printf("该文件为空，是否立刻输入学生信息？(注:按Y继续，任意键返回菜单)");
			 input_judgement = getchar();
			 if( input_judgement == 'Y' || input_judgement == 'y')
			     input_record();
			 else 
                 print_show_menu();
             
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
