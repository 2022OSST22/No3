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
int deleteMenu( Menu *p){
    int n;
    printf("정말 삭제하시겠습니까?(확인:0/아니오:1)\n");
    scanf("%d",&n);
    if(n==0){
        p->price = -1;
        return 0;
    }
    return -1;
}//주문하지 않을 제품을 삭제하는 기능 주문하지 않을 시 (return -1)
void selectMenu(Menu *p[]){
    int num;
    printf("선택할 메뉴의 번호를 입력 하세요");
    scanf("%d",&num);
    FILE* fp;

    fp = fopen("order.txt","a");
    if(p[num]->price != -1) {
        fprintf(fp, "%s %s %dg %d %s\n",p[num]->name, p[num]->explain, p[num]->weight, p[num]->price, p[num]->kind);
    }
    fclose(fp);
} //주문할 메뉴를 선택하는 함수
