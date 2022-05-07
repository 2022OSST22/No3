#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[20];      //제품명
    int weight;         //중량
    int price;          //판매가격
    char kind [20];     //종류

} Menu;

int selectOption();// 사용 기능을 선택하는 함수
void loadMenu( Menu* p[], int count);//모든 제품을 출력하는 함수
void readMenu(Menu *p);//하나의 제품을 출력하는 함수
int getMenu( Menu *p);//제품을 추가하는 함수
void saveMenu( Menu *p[], int count); // 파일에 상품을 저장하는 함수
int deleteMenu( Menu *p);//주문하지 않을 제품을 삭제하는 기능 주문하지 않을 시 (return -1)
int changeMenu(Menu* p[], int count);// 메뉴를 변경하는 함수
void selectMenu(Menu *p[], int count); //주문할 메뉴를 선택하는 함수
int bringMenu( Menu* p[]);// 저장한 메뉴를 다시 가져오는 함수
void searchName( Menu*p[], int count);//제품명을 찾는 함수
void searchPrice( Menu* p[], int count);//가격을 통해 검색하는 함수
void searchKind( Menu* p[], int count);//메뉴의 종류을 통해 검색하는 함수
