#include "dessert.h"
#include <stdio.h>
#include <string.h>

int main(void){
    Menu* p [50];
    int menu;
    int count =0;
    while(1){
        menu = selectOption();
        if(menu==1){//메뉴 조회

        }
        else if(menu==2){//메뉴 추가
            
        }
        else if(menu==3){//메뉴 수정
            
        }
        else if(menu==4){//메뉴 삭제
            int num, n4;
            printf("삭제할 제품 번호를 입력해주세요 >");
            scanf("%d",&num);
            if(num<=count){
                n4 = deleteMenu(p[num-1]);
            } else{
                printf("=>존재하지 않는 제품 번호입니다!!");
            }
            if(n4==0) printf("삭제되었습니다.\n");
        }
        else if(menu==5){//메뉴 저장
            
        }
        else if(menu==6){//파일 가져오기
            
        }
        else if(menu==7){//주문 선택하기
            selectMenu(p, count);
        }
        else if(menu==8){//제품명 검색
            
        }
        else if(menu==9){//가격으로 검색
            
        }
        else if(menu==10){//메뉴 종류로 검색
            
        }
        else {
            for(int i=0;i<count;i++){
                free(p[i]);
            }
            printf("=>종료되었습니다.\n");
            break;
        }
    }
}
