#include "dessert.h"
#include <stdio.h>
#include <string.h>

int main(void){
    Menu* p [50];
    int menu;
    int count=0,index=0;

    while(1){
        menu = selectOption();
        
        if(menu==1){
            if(count>0)
            loadMenu(p,index);   
        }//�޴� ��ȸ

        else if(menu==2){
            p[index] = (Menu*) malloc(sizeof(Menu));
            count=count+getMenu(p[index++]);

        }//�޴� �߰�

        else if(menu==3){
            int n3 = changeMenu(p,index);
            if(n3 !=1) printf("=>�߸��� ��ȣ�Դϴ�.\n");
        }//�޴� ����

        else if(menu==4){
            int num, n4;
            printf("������ ��ǰ ��ȣ�� �Է����ּ��� >");
            scanf("%d",&num);
            if(num<=count){
                n4 = deleteMenu(p[num-1]);
            } else{
                printf("=>�������� �ʴ� ��ǰ ��ȣ�Դϴ�!!");
            }
            if(n4==0) printf("�����Ǿ����ϴ�.\n");
        }//�޴� ����

        else if(menu==5){
            
        }//�޴� ����

        else if(menu==6){
            
        }//���� ��������

        else if(menu==7){
            selectMenu(p, count);
        }//�ֹ� �����ϱ�

        else if(menu==8){
        searchName(p,count);
        }//��ǰ�� �˻�

        else if(menu==9){
            
        }//�������� �˻�

        else if(menu==10){
            
        }//�޴� ������ �˻�

        else {
            for(int i=0;i<count;i++){
                free(p[i]);
            }
            printf("=>����Ǿ����ϴ�.\n");
            break;
        }
    }
}
