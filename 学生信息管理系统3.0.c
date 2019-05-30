#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE "��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ��"
#define MAX 10
#define main_menu_num 8
#define input_menu_num 3
#define search_menu_num 4
#define update_menu_num 3
#define pass_mark 60
//����һ�������� 
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
int get_input();//��ȡ�������� 
void print_main_menu();//��ӡ���˵� 
void back_main_menu();//�ص����˵� 
void print_show_menu();//��ӡ��ʾ�˵� 
void print_search_menu();//��ӡ��ѯ�˵�
void print_update_menu();//
void print_delate_menu();//
void print_calculate_menu();//
void print_excel_head();//��ӡ��ͨ���ͷ��
void print_sum_excel_head();//��ӡ�ܳɼ����ͷ�� 
void print_excel_tail();//��ӡ��ͨ���β�� 
void print_sum_excel_tail();//��ӡ�ܳɼ�β�� 
 

//��Ҫ����
void input_record();//����ѧ����Ϣ 
void show_record();//��ʾѧ����Ϣ
void search_record();//����ѧ����Ϣ 
void update_record();//�޸�ѧ����Ϣ 
void delate_record();//ɾ��ѧ����Ϣ 
void calculate_record();//����ѧ����Ϣ 
void save_as_file();//�����ļ� 
void exit_system();//�˳�ϵͳ
void save_data();//������Ϣ 
void clear_record(); 
void search_by_name();//ͨ�����ֲ��� 
void search_by_num();//ͨ��ѧ�Ų��� 
void search_by_sex();//ͨ���Ա���� 
void update_by_name();//ͨ����������
void update_by_num();//ͨ��ѧ�Ÿ��� 
void delate_by_name();//ͨ������ɾ�� 
void delate_by_num();//ͨ��ѧ��ɾ��
void calculate_stu_sum();//����ѧ���ܳɼ� 
void calculate_stu_average();// ����ѧ��ƽ���ɼ� 
void print_stu_fail();//��ӡ������ѧ������ 
void show_data();//��ʾ������������ 
void show_local_file();//��ʾ�����ļ� 
void input_data();//��������
void print_table(stu * p);//�Ա����ʽ��ӡ ѧ����Ϣ 
stu * get_last_student(stu *p);//������һ��ѧ����Ϣ 


//���˵�Ҫ��ʾ������ 
char main_menu[]=
	"\n"
	"| 1������ѧ����Ϣ\n"
	"| 2����ʾѧ����Ϣ\n"
	"| 3������ѧ����Ϣ\n"
	"| 4���޸ģ����£�ѧ����Ϣ\n" 
	"| 5��ɾ��ѧ����Ϣ\n"
	"| 6������ѧ����Ϣ\n" 
	"| 7�������ļ�\n" 
	"| 8���˳�ϵͳ\n" ;
	

//���������������˵�����ָ���У��û�������ֵ��Ӧָ���к�����λ�� 
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


//����˵�Ҫ��ʾ������ 
char show_menu[]= 

     "\n"
     "1����ʾ��������ѧ����Ϣ\n"
     "2����ʾ�����ļ�\n"
     "3���������˵�\n"
     "\n"   
;


//
void (*input_menu_func[])()=
{
    show_data,
    show_local_file,
    back_main_menu, 

};
   
  
//��ѯ�˵���ʾ���� 
char search_menu[] = 

    "\n"
    "| 1��ͨ����������\n" 
    "| 2��ͨ��ѧ�Ų���\n"
    "| 3��ͨ���Ա����\n"
    "| 4���������˵�\n"
;


void (*search_menu_func[])()=
{
     search_by_name,
     search_by_num,
     search_by_sex,
     back_main_menu,
}; 


//�޸�ѧ����Ϣ�˵���ʾ����
char update_menu[] = {
      "\n"
      "| 1��ͨ����������\n"
      "| 2��ͨ��ѧ�Ÿ���\n"
      "| 3���������˵�\n"
};
      
      
void (*update_menu_func[])() = 
{
     update_by_name,
     update_by_num,
     back_main_menu,
};
//ɾ��ѧ����Ϣ�˵���ʾ���� 
char delate_menu[] = 
    "\n"
    "1��ͨ������ɾ����Ϣ\n" 
    "2��ͨ��ѧ��ɾ����Ϣ\n"  
    "3���������˵�\n"
;
void (*delate_menu_func[])() = 
{
     delate_by_name,
     delate_by_num,
     back_main_menu,
};
//����˵���ʾ����
char calculate_menu[] = 
    "\n"
    "1������ѧ���ܳɼ�\n"
    "2������ѧ�����Ƴɼ�ƽ����\n"
    "3����ӡ������ѧ������\n" 
    "4���������˵�\n" ;
void (*calculate_menu_func[])() = 
{
     calculate_stu_sum,
     calculate_stu_average,
     print_stu_fail,
     back_main_menu,
}; 


 
  
//������ 
int main ()
{
    print_main_menu();
	system("pause");
    return 0; 
}  


//��ȡ�������� 
int get_input()
{
     int input;
     char ch;
     while (scanf("%d",&input)!=1)
     {
           while((ch=getchar())!='\n')
               ;
           printf("�����������������:\n");
     }

     return input;
}


//��ӡ���˵��������û����� 
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
        printf("->��������Ҫ���еĲ�����"); 
        option = get_input();        
	 	if(option>=1&&option<=main_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",main_menu_num);
	}  
    main_menu_func[option-1]();
	
}


//��ӡ��ʾ�˵�
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
        printf(" ->��������Ҫ���еĲ���:");
        option = get_input();
	 	if(option>=1&&option<=input_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",input_menu_num);
	}  
    input_menu_func[option-1]();
}

      
//��ӡ��ѯ�˵�
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
        printf(" ->��������Ҫ���еĲ���:");
        option = get_input();
	 	if(option>=1&&option<=search_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",search_menu_num);
	} 
    search_menu_func[option-1]();
}  


//��ӡ�޸ĳɼ��˵� 
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
        printf(" ->��������Ҫ���еĲ���:");
        option = get_input();
	 	if(option>=1&&option<=update_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",update_menu_num);
	} 
    update_menu_func[option-1]();
} 
//��ӡɾ���˵�
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
        printf(" ->��������Ҫ���еĲ���:");
        option = get_input();
	 	if(option>=1&&option<=update_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",update_menu_num);
	} 
    delate_menu_func[option-1]();
} 
//��ӡ����˵�
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
        printf(" ->��������Ҫ���еĲ���:");
        option = get_input();
	 	if(option>=1&&option<=search_menu_num)
		{
	 	 	break;
	 	}
		printf("��������(ע����ѡ��1~%d)\n",search_menu_num);
	} 
    calculate_menu_func[option-1]();

}        


//���������Ϣ�Ա�����ʽ��ӡ���� 
void print_table(stu * p){
	
    printf("|%10s|%10s|%10s|%4d|%4d|%4d|%6d|\n",p->num,p->name,p->sex,p->chinese,p->shuxue,p->english,p->computer);
}


void print_excel_head()
{
    printf("+----------+----------+----------+----+----+----+------+\n");
	printf("|   ѧ��   |   ����   |   �Ա�   |����|��ѧ|Ӣ��|�����|\n");
	printf("+----------+----------+----------+----+----+----+------+\n");
}


void print_sum_excel_head()
{
    printf("+----------+----------+----------+----+----+----+------+------+\n");
	printf("|   ѧ��   |   ����   |   �Ա�   |����|��ѧ|Ӣ��|�����|�ܳɼ�|\n");
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
     

                                                 //�ص����˵� 
void back_main_menu()
{
     print_main_menu();
}


void input_record(){
     char input_judgement = 'N';                     //�����ж�
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
         pLastStu =  get_last_student(head);                //�ж��Ƿ�Ϊ��һ������ ���ݹ������һ�� 
         pLastStu->next = pNewStu;
     }
     printf("��������ѧ����Ϣ>(��Y����������������ز˵�)");
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

                                            //����ѧ����Ϣ 
void show_record(){
     print_show_menu();    
}                   

                                                    //��ʾѧ����Ϣ
void search_record(){   
    print_search_menu();
    
}                    

                       //����ѧ����Ϣ 
void update_record(){
    char continue_input = 'N';
    print_update_menu();
    printf("�Ƿ����������Ϣ��(Y������������������˵�)"); 
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

                          //�޸�ѧ����Ϣ 
void delate_record(){
     print_delate_menu();    
}                 

                          //ɾ��ѧ����Ϣ �����������޸�ѧ����Ϣһ�� 
void calculate_record(){
     print_calculate_menu();
     
     
     }//����ѧ����Ϣ 



void save_as_file(){
	save_data();
	getchar(); 
	print_main_menu();
}                       //�����ļ� 


void save_data(){
     FILE * fp;
     char file[100];
     stu *p = head; 
     printf("�������ļ�����");
     scanf("%s",file);
     fp = fopen(file,"a+");
     
     while(p!=NULL)
     {
           fprintf(fp,"|%10s|%10s|%10s|%4d|%4d|%4d|%6d|\n",p->name,p->num,p->sex,p->chinese,p->shuxue,p->english,p->computer);
           p = p->next;
     }
   
     fclose(fp);
     printf("�����ļ��ɹ���");
     getchar();     
}                                                 //�����ļ� 


//�ݹ�ɾ��student�ṹ����ĺ���
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
		clear_record(p->next);     //�ٴε��ñ�������student�ṹ��nextָ��Ľ����Ϊ����
		free(p);                
		p=NULL;
	}

}


void exit_system(){
     printf("�Ƿ񱣴��ļ���(ע����Y���棬��������˳�)\n");
     char ch;
     getchar();
     ch = getchar();
     if(ch == 'Y' ||ch == 'y')
     {
           save_data();
           printf("\nлл����ʹ��!");
           clear_record(head);
           getchar();
           exit(0);
           
     }
     else
     {
         printf("лл����ʹ�ã�"); 
         clear_record(head);  //�ͷ���������
         getchar();
         exit(0);
     }
}                                    //�˳�ϵͳ


void search_by_name(){
	char continue_input = 'N';
	char name[MAX];
	stu *p=head;
	int isfound=0;
	printf(">������ѧ������:");
	scanf("%s",name);
	printf("\n>����[%s]...\n",name);
	print_excel_head();
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			print_table(p);
			isfound=1;						//�������ܻ��ظ�������Ӧ�ò鵽���һ��
		}
		p=p->next;
	}
	if(!isfound)
		printf("\nû���ҵ����!\n");
	print_excel_tail();
	printf("��������?(Y ����,���������)");
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
	
}                                       //ͨ�����ֲ��� 
                                   
                                   
void search_by_num(){
    char num[MAX];
	char continue_input = 'N';
	stu*p=head;
	int isfound=0;
	printf(">������ѧ��ѧ��:");
	scanf("%s",num);
	printf("\n����[%s]...\n",num);
	print_excel_head();
	while(p!=NULL)
	{
		if(strcmp(p->num,num)==0)
		{
			print_table(p);
			isfound=1;
			break;					//ÿ����ѧ��ֻ��һ�������Բ鵽�Ϳ�������ѭ��
		}
		p=p->next;
	}
	if(!isfound)
		printf("\nû���ҵ����!\n");
	print_excel_tail();
	printf("��������?(Y ����,���������)");
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
	
}                                         //ͨ��ѧ�Ų��� 
	
	
void search_by_sex(){
    char continue_input = 'N';
    char sex[MAX];
	stu *p=head;
	int isfound=0;
	printf(">������ѧ���Ա�:");
	scanf("%s",sex);
	printf("\n>����[%s]...\n");
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
		printf("\nû���ҵ����!\n");
	print_excel_tail();
	printf("��������?(Y ����,���������)");
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
	
}                        //ͨ���Ա���� 
void update_by_name()
{
     char name[MAX];
     char continue_input = 'N';
     stu * p = head;
     
     printf("������Ҫ������Ϣѧ����������");
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
         printf("û������Ϊ%s��ѧ��",name);
         print_excel_tail();
     }
     else
     {
         print_excel_tail();
         input_data(p);
         printf("\n���³ɹ�!"); 
     }
     getchar();
} 
void update_by_num()
{
     stu *p = head;
     char num[MAX];
     printf("������Ҫ���µ�ѧ����ѧ�ţ�");
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
         printf("û��ѧ��Ϊ%s��ѧ��",num);
         print_excel_tail();
     }
     else
     {
         print_excel_tail();
         input_data(p);
         printf("���³ɹ���\n");
     }
     getchar();
}        
void delate_by_name(){
     char continue_input = 'N';
     char name[MAX];
     stu *p=head;
     stu *q=NULL;
     printf("��������Ҫɾ����ѧ����������");
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
         printf("û������Ϊ%s��ѧ��\n",name);
         print_excel_tail();
         printf("����������ز˵�"); 
         getchar();
         getchar(); 
         print_delate_menu();
     }
     else
     { 
         printf("ȷ��Ҫɾ������Ϊ%sѧ��Ϊ%s��ѧ����(Yɾ������������ز˵�)",p->name,p->num);
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
             printf("ɾ���ɹ���\n");
             printf("�Ƿ����ɾ����(ע����Yɾ������������ز˵�)");
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
     printf("��������Ҫɾ����ѧ����ѧ�ţ�");
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
         printf("û��ѧ��Ϊ%s��ѧ��\n",num);
         print_excel_tail();
         printf("����������ز˵�"); 
         getchar();
         getchar(); 
         print_delate_menu();
     }
     else
     { 
         printf("ȷ��Ҫɾ������Ϊ%sѧ��Ϊ%s��ѧ����(Yɾ������������ز˵�)",p->name,p->num);
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
             printf("ɾ���ɹ���\n");
             printf("�Ƿ����ɾ����(ע����Y����ɾ������������ز˵�)");
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
         printf("�㻹û�������κ���Ϣ��(��������������˵�)");
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
         printf("�����������");
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
     printf("\n\t\t   ѧ���ɼ���Ϣ��\n"); 
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
     printf("\n����ƽ���ɼ�Ϊ��\n"); 
     printf("����:%5.2f  ��ѧ:%5.2f  Ӣ��:%5.2f  �����:%5.2f",(float)ave1/count,(float)ave2/count,(float)ave3/count,(float)ave4/count);
     printf("\n�����������");
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
    printf("\n\t\t   ѧ���ɼ���Ϣ��\n"); 
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
	printf("\n����������Ϊ��%d",count1);
	printf("\t������Ϊ��%4.2f%%",((float)(count2-count1)/count2)*100);
	printf("\n����������ز˵�");
	getchar();
    getchar();
    print_calculate_menu();	
}
void show_data(){
	 system("cls");
     stu * p = head;
     printf("_________________________________________________________\n");
     printf("\n\t\t   ѧ���ɼ���Ϣ��\n"); 
     print_excel_head();
     while (p!=NULL)
     {
         print_table(p);
		 p = p->next;
	 }
     print_excel_tail();
     printf("\n��������������˵�\n");
     getchar();
     getchar();
     print_show_menu();
} 


void show_local_file(){
     char input_judgement = 'N'; 
     char ch;
     char name[30];
     FILE *fa,*fp;
     printf("��������Ҫ�򿪵��ļ�����");
     scanf("%s",name);
   
     fa = fopen(name,"r+");
     if (fa==NULL)
     {
         printf("δ�ҵ����ļ�");
         printf("�Ƿ񴴽���Ϊ%s���ļ���(ע����Y����������������ز˵�)",name);
         getchar(); 
         input_judgement = getchar();
         if( input_judgement == 'Y' || input_judgement == 'y')
         {
             fp = fopen(name,"a+");
             if (fp ==NULL)
             {
                    printf("���ļ�ʧ�ܣ�");
             }   
             else
             {
          
                    while ((ch=getc(fp)) != EOF)
                    {
                      putchar(ch);
                    }
             fclose(fp); 
             printf("�����ļ��ɹ���\n"); 
             getchar();
             printf("���ļ�Ϊ�գ��Ƿ���������ѧ����Ϣ��(ע:��Y��������������ز˵�)");
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
         printf("�����������");
         getchar();
         getchar();
         print_show_menu(); 
     }     
}                                              //���뱾���ļ� 


void input_data(stu * pNewStu){
     printf(">������ѧ����Ϣ(ע����󳤶���10���ַ�)\n");
     printf("����:");scanf("%s",pNewStu->name); 
     printf("ѧ��:");scanf("%s",pNewStu->num);
     printf("�Ա�:");scanf("%s",pNewStu->sex);
     printf(">������%s�ĳɼ�(ע��0~100)\n",pNewStu->name); 
     printf("����:");scanf("%d",&(pNewStu->chinese));
     printf("��ѧ:");scanf("%d",&(pNewStu->shuxue));
     printf("Ӣ��:");scanf("%d",&(pNewStu->english));
     printf("�����:");scanf("%d",&(pNewStu->computer));
     
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
