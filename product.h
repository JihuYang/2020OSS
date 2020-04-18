#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];  //제품명
    int weight;     //중량
    int price;      //숫자
    float perprice;   //표준가격
    int star;       //별점수
} Snack;

void saveData(Snack *s, int count);         //파일에 제품을 저장하는 함수

int loadData(Snack s[]);                    //파일에 저장된 제품을 불러오는 함수

int createSnack(Snack *s);                  //하나의 제품을 추가하는 함수

void readSnack(Snack s);                    //하나의 제품을 출력하는 함수

void listSnack(Snack *s, int count);        //전체 제품을 출력하는 함수

int updateSnack(Snack *s);                  //하나의 제품을 수정하는 함수

int selectDataNo(Snack *s, int count);      //수정하거나 삭제할 제품의 번호를 입력받는 함수

int deleteSnack(Snack *s);                  //하나의 제품을 삭제하는 함수

void searchName(Snack *s, int count);       //이름을 검색해 등록된 제품을 찾는 함수

void searchPrice(Snack *s, int count);      //가격을 검색해 등록된 제품을 찾는 함수

void searchStar(Snack *s, int count);       //별점수를 검색해 등록된 제품을 찾는 함수

int selectMenu();                           //제품 추가, 삭제 등 원하는 메뉴를 선택받는 함수

