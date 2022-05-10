#include "dessert.h"

int selectOption(){
    int menu;
    printf("\n=== 디저트 주문 자판기 ===\n");
    printf("1. 메뉴 조회\t6. 파일 가져오기\n");
    printf("2. 메뉴 추가\t7. 주문 선택하기\n");
    printf("3. 메뉴 수정\t8. 제품명 검색\n");
    printf("4. 메뉴 삭제\t9. 가격으로 검색\n");
    printf("5. 메뉴 저장\t10. 메뉴종류로 검색\n");
    printf("0. 종료\n\n");
    printf("> 원하는 옵션을 선택해주세요. ");
    scanf("%d", &menu);
    return menu;
}

void readMenu(Menu* p){
  if(p->price!=-1)
    printf("%s %dg %d원 %s\n",p->name,p->weight,p->price,p->kind);

}//하나의 제품을 출력하는 함수

void loadMenu( Menu* p[], int count){
    printf("\n제품명  중량    가격    종류\n-----------------------\n");
    for(int i=0; i<count; i++){
        if(p[i]->price!=-1)printf("[%d]",i+1);
        readMenu(p[i]);
    }
}//모든 제품을 출력하는 함수

int getMenu( Menu *p){
    
    printf("이름은?");
    scanf("%s",p->name);
    printf("중량은?");
    scanf("%d",&p->weight);
    printf("가격은?");
    scanf("%d",&p->price);
    printf("종류는?");
    scanf("%s",p->kind);
    return 1;
}//제품을 추가하는 함수


int changeMenu(Menu* p[], int count){
    int updatenum;
    printf("수정하고싶은 제품의 번호를 입력해주세요: ");
    scanf("%d",&updatenum);
    if(updatenum< count) return 0;

    printf("이름은?");
    scanf("%s",p[updatenum-1]->name);
    printf("중량은?");
    scanf("%d",&p[updatenum-1]->weight);
    printf("가격은?");
    scanf("%d",&p[updatenum-1]->price);
    printf("종류는?");
    scanf("%s",p[updatenum-1]->kind);
    printf("수정되었습니다\n");
    return 1;
}// 메뉴를 변경하는 함수

int deleteMenu( Menu *p){
    int n;
    printf("정말 삭제하시겠습니까?(확인:0/아니오:1) ");
    scanf("%d",&n);
    if(n==0){
        p->price = -1;
        return 0;
    }
    return -1;
}//주문하지 않을 제품을 삭제하는 기능 주문하지 않을 시 (return -1)

void selectMenu(Menu *p[], int count){
    int num,a,b;
    FILE* fp;
    fp = fopen("order.txt","wt");
    while(1){
        loadMenu(p,count);
        printf("선택할 메뉴의 번호를 입력 하세요: ");
        scanf("%d",&num);
        printf("수량을 입력하세요: ");
        scanf("%d",&a);
        if(p[num-1]->price != -1 && num <count) {
            fprintf(fp, "%s %dg %d %s %d개\n",p[num-1]->name, p[num-1]->weight, p[num-1]->price, p[num-1]->kind, a);
        }
        printf(" 더 주문하시겠습니까? (네:0/아니오:1) ");
        scanf("%d",&b);
        if(b==1) break;
    }
    fclose(fp);
    printf("=>주문이 접수되었습니다.\n\n");
} //주문할 메뉴를 선택하는 함수

void searchName( Menu *p[], int count){
    char search[20];
    printf("검색할 제품의 이름을 입력하세요: ");
    scanf("%s",search);
    for(int i=0;i<count;i++){
        if(strstr(p[i]->name,search)){
            readMenu(p[i]);
        }
    }
}//제품명을 통해 검색하는 함수

void searchPrice( Menu* p[], int count){
    int search;
    printf("검색할 제품의 가격을 입력하세요: ");
    scanf("%d",&search);
    for(int i=0;i<count;i++){
        if(p[i]->price=search){
            readMenu(p[i]);
        }
    }
}//가격을 통해 검색하는 함수

void searchKind( Menu* p[], int count);//메뉴의 종류을 통해 검색하는 함수
