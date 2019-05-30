#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TITLE "��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ��"
#define MAX 10
#define main_menu_num 8
#define input_menu_num 3
#define search_menu_num 4
#define update_menu_num 3
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
    "| 1������������\n" 
    "| 2����ѧ�Ų���\n"
    "| 3�����Ա����\n"
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
      "| 1������������\n"
      "| 2����ѧ�Ų���\n"
      "| 3���������˵�\n"
};
      
      
void (*update_menu_func[])() = 
{
     search_by_name,
     search_by_num,
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


//
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
     char input_judgement = 'N';//�����ж�
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
     print_update_menu();
}                  

                          //�޸�ѧ����Ϣ 
void delate_record()
{
    
    stu* p=head;
	stu* pPre=NULL;
	char num[MAX];
	char continue_input='N';
	printf("������Ҫɾ����ѧ��ѧ��:");
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
		printf("û��ѧ����[%s]��ѧ��.",num);
	}
	else
	{
		printf("ȷ��Ҫɾ��ѧ��Ϊ[%s]��ѧ����?(Y ȷ��,N ȡ��)",p->num);
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
			printf(">ɾ���ɹ�!\n");
		}
	}
	printf("����ɾ����?(Y ����,N ���ز˵�)");
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
               

                          //ɾ��ѧ����Ϣ �����������޸�ѧ����Ϣһ�� 
void calculate_record(){}//����ѧ����Ϣ 



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
	/*���student�ṹ���nextָ���ǿ����ʾû����һ�����ݣ�ɾ���ýڵ�*/
	if(p->next==NULL)
	{
		free(p);
	}
	/*���student�ṹ���nextָ�벻Ϊ��*/
	else
	{
		clear_record(p->next);//�ٴε��ñ�������student�ṹ��nextָ��Ľ����Ϊ����
		free(p);//ɾ����ǰ�ڵ�
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
	char name[MAX];
	char continue_input='N';
	stu *p=head;
	int isfound=0;
	printf(">������ѧ������:");
	scanf("%s",name);
	printf("\n>����[%s]...\n");
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
	printf("��������?(Y ����,N ����)");
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
}                                   //ͨ�����ֲ��� 
                                   
                                   
void search_by_num(){
    char num[MAX];
	char continue_input='N';
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
		search_by_num();
	}
	else
	{
		search_record();
	}
}                                         //ͨ��ѧ�Ų��� 
	
	
void search_by_sex(){
char sex[MAX];
	char continue_input='N';
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
		search_by_sex();
	}
	else
	{
		search_record();
	}
}                        //ͨ���Ա���� 


void show_data(){
	 system("cls");
     stu * p = head;
     char i;
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
