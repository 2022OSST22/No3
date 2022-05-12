#include "dessert.h"

int selectOption(){
    int menu;
    printf("\n=== ����Ʈ �ֹ� ���Ǳ� ===\n");
    printf("1. �޴� ��ȸ\t6. ���� ��������\n");
    printf("2. �޴� �߰�\t7. �ֹ� �����ϱ�\n");
    printf("3. �޴� ����\t8. ��ǰ�� �˻�\n");
    printf("4. �޴� ����\t9. �������� �˻�\n");
    printf("5. �޴� ����\t10. �޴������� �˻�\n");
    printf("0. ����\n\n");
    printf("> ���ϴ� �ɼ��� �������ּ���. ");
    scanf("%d", &menu);
    return menu;
}

void readMenu(Menu* p){
  if(p->price!=-1)
    printf("%s %dg %d�� %s\n",p->name,p->weight,p->price,p->kind);

}//�ϳ��� ��ǰ�� ����ϴ� �Լ�

void loadMenu( Menu* p[], int count){
    printf("\n��ǰ��  �߷�    ����    ����\n-----------------------\n");
    for(int i=0; i<count; i++){
        if(p[i]->price!=-1)printf("[%d]",i+1);
        readMenu(p[i]);
    }
}//��� ��ǰ�� ����ϴ� �Լ�

int getMenu( Menu *p){
    
    printf("�̸���?");
    scanf("%s",p->name);
    printf("�߷���?");
    scanf("%d",&p->weight);
    printf("������?");
    scanf("%d",&p->price);
    printf("������?");
    scanf("%s",p->kind);
    return 1;
}//��ǰ�� �߰��ϴ� �Լ�


int changeMenu(Menu* p[], int count){
    int updatenum;
    printf("�����ϰ���� ��ǰ�� ��ȣ�� �Է����ּ���: ");
    scanf("%d",&updatenum);
    if(updatenum< count) return 0;

    printf("�̸���?");
    scanf("%s",p[updatenum-1]->name);
    printf("�߷���?");
    scanf("%d",&p[updatenum-1]->weight);
    printf("������?");
    scanf("%d",&p[updatenum-1]->price);
    printf("������?");
    scanf("%s",p[updatenum-1]->kind);
    printf("�����Ǿ����ϴ�\n");
    return 1;
}// �޴��� �����ϴ� �Լ�

int deleteMenu( Menu *p){
    int n;
    printf("���� �����Ͻðڽ��ϱ�?(Ȯ��:0/�ƴϿ�:1) ");
    scanf("%d",&n);
    if(n==0){
        p->price = -1;
        return 0;
    }
    return -1;
}//�ֹ����� ���� ��ǰ�� �����ϴ� ��� �ֹ����� ���� �� (return -1)

void selectMenu(Menu *p[], int count){
    int num,a,b;
    FILE* fp;
    fp = fopen("order.txt","wt");
    while(1){
        loadMenu(p,count);
        printf("������ �޴��� ��ȣ�� �Է� �ϼ���: ");
        scanf("%d",&num);
        printf("������ �Է��ϼ���: ");
        scanf("%d",&a);
        if(p[num-1]->price != -1 && num <count) {
            fprintf(fp, "%s %dg %d %s %d��\n",p[num-1]->name, p[num-1]->weight, p[num-1]->price, p[num-1]->kind, a);
        }
        printf(" �� �ֹ��Ͻðڽ��ϱ�? (��:0/�ƴϿ�:1) ");
        scanf("%d",&b);
        if(b==1) break;
    }
    fclose(fp);
    printf("=>�ֹ��� �����Ǿ����ϴ�.\n\n");
} //�ֹ��� �޴��� �����ϴ� �Լ�

void searchName( Menu *p[], int count){
    char search[20];
    printf("�˻��� ��ǰ�� �̸��� �Է��ϼ���: ");
    scanf("%s",search);
    for(int i=0;i<count;i++){
        if(strstr(p[i]->name,search)){
            readMenu(p[i]);
        }
    }
}//��ǰ���� ���� �˻��ϴ� �Լ�

void searchPrice( Menu* p[], int count){
    int search;
    printf("�˻��� ��ǰ�� ������ �Է��ϼ���: ");
    scanf("%d",&search);
    for(int i=0;i<count;i++){
        if(p[i]->price==search){
            readMenu(p[i]);
        }
    }
}//������ ���� �˻��ϴ� �Լ�

void searchKind( Menu* p[], int count){
    char search[20];
    printf("�˻��� ��ǰ�� ������ �Է��ϼ���: ");
    scanf("%s",search);
    for(int i=0;i<count;i++){
        if(strstr(p[i]->kind,search)){
            readMenu(p[i]);
        }
    }
} //�޴��� ������ ���� �˻��ϴ� �Լ�

void saveMenu( Menu *p[], int count){
    FILE *fp;
    fp = fopen("menu.txt","wt");
    for(int i=0; i<count;i++){
        if(p[i]->price != -1) {
            fprintf(fp, "%s %d %d %s \n",p[i]->name, p[i]->weight, p[i]->price, p[i]->kind);
        }
    }
    fclose(fp);
    printf("=>�޴��� ����Ǿ����ϴ�.\n");
}


int bringMenu( Menu* p[]){
    FILE *fp;
    fp = fopen("menu.txt","rt");
    int temp, count = 0;
    while(!feof(fp)){
        p[count] = (Menu*) malloc(sizeof(Menu));
        temp = fscanf(fp,"%s %d %d %s",p[count]->name, &p[count]->weight, &p[count]->price, p[count]->kind);
        if(temp<1) break;
        count ++;
    }
    return count;
}// ������ �޴��� �ٽ� �������� �Լ�