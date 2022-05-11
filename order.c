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
        }//메뉴 조회

        else if(menu==2){
            p[index] = (Menu*) malloc(sizeof(Menu));
            count=count+getMenu(p[index++]);

        }//메뉴 추가

        else if(menu==3){
            int n3 = changeMenu(p,index);
            if(n3 !=1) printf("=>잘못된 번호입니다.\n");
        }//메뉴 수정

        else if(menu==4){
            int num, n4;
            printf("삭제할 제품 번호를 입력해주세요 >");
            scanf("%d",&num);
            if(num<=count){
                n4 = deleteMenu(p[num-1]);
            } else{
                printf("=>존재하지 않는 제품 번호입니다!!");
            }
            if(n4==0) printf("삭제되었습니다.\n");
        }//메뉴 삭제

        else if(menu==5){
            saveMenu(p,count);
        }//메뉴 저장

        else if(menu==6){
            int count = bringMenu(p);
            for(int i=0;i<count;i++){
                p[i] = (Menu*) malloc(sizeof(Menu));
            }
            int n6 = bringMenu(p);
            if(n6>0) printf("=>로딩 성공!\n");
            else printf("=>자료 없음\n");
        }//파일 가져오기

        else if(menu==7){
            selectMenu(p, count);
        }//주문 선택하기

        else if(menu==8){
            searchName(p,count);
        }//제품명 검색

        else if(menu==9){
            searchPrice(p,count);
        }//가격으로 검색

        else if(menu==10){
            
        }//메뉴 종류로 검색

        else {
            for(int i=0;i<count;i++){
                free(p[i]);
            }
            printf("=>종료되었습니다.\n");
            break;
        }
    }
}
