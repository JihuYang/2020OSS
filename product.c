#include "product.h"


void saveData(Snack *s, int count){         //파일에 제품을 저장하는 함수
    FILE *fp;

    fp = fopen("snack.txt", "wt");

    for(int i=0;i<count;i++){
        if(s[i].weight != -1)
            fprintf(fp, "%s %d %d %0.f %d\n", 
                        s[i].name, s[i].weight, s[i].price, s[i].perprice, s[i].star);
    }

    printf("입력하신 과자 정보가 저장되었습니다!!\n");
}
int loadData(Snack s[]){                    //파일에 저장된 제품을 불러오는 함수
    int count = 0;
   
    FILE *fp;
    fp = fopen("snack.txt", "rt");
    if(fp==NULL){
        printf("=> 파일이 없습니다.\n");
        return 0;
    }
    fscanf(fp, "%[^\n]s %d %d %f %d", s->name, &s->weight, 
                                    &s->price, &s->perprice, &s->star); 
    count++;
    
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return count;
}

int createSnack(Snack *s){                  //하나의 제품을 추가하는 함수
    getchar();   
    printf("과자 이름을 입력해주세요:  ");
    scanf("%[^\n]s", s->name);
    printf("과자 무게를 입력해주세요 :  ");
    scanf("%d", &s->weight);
    printf("과자 가격을 입력해주세요 :  ");
    scanf("%d", &s->price);
    printf("별점수를 입력해주세요 :  ");
    scanf("%d", &s->star);
    s->perprice = ((float)s->price/(float)s->weight)*10.0;
    printf("=> 입력하신 과자 정보가 추가되었습니다!!!\n");
    return 1;
}
void readSnack(Snack s){                    //하나의 제품을 출력하는 함수
     printf("%s\t%5d %5d %0.f %5d\n", s.name, s.weight, s.price, s.perprice, s.star);

}
void listSnack(Snack *s, int count){        //전체 제품을 출력하는 함수
    printf("\nNo Name Weight Price Perprice Star\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].weight == -1) continue;
        printf("%2d", i+1);
        readSnack(s[i]);
    }
    printf("\n");
}

int updateSnack(Snack *s){   
    getchar();               //하나의 제품을 수정하는 함수
    printf("과자 이름을 입력해주세요 : ");
    scanf("%[^\n]s", s->name);
    printf("과자 무게를 입력해주세요 : ");
    scanf("%d", &s->weight);
    printf("과자 가격을 입력해주세요 : ");
    scanf("%d", &s->price);
    printf("별점수를 입력해주세요 :  ");
    scanf("%d", &s->star);
    s->perprice = ((float)s->price/(float)s->weight)*10.0;
    printf("=> 과자 정보가 수정되었습니다!!\n");
    return 1;
}
int selectDataNo(Snack *s, int count){      //수정하거나 삭제할 제품의 번호를 입력받는 함>수
    int no;
    listSnack(s, count);
    printf("원하는 번호를 입력해주세요 (취소: 0) : ");
    scanf("%d", &no);
    return no;
}
int deleteSnack(Snack *s){                  //하나의 제품을 삭제하는 함수
    s->weight = -1;
    s->price = -1;
    s->perprice = -1;
    s->star = -1;
    return 1; 
}
void searchName(Snack *s, int count){       //이름을 검색해 등록된 제품을 찾는 함수
    int scount = 0;
    char search[20];

    printf("검색할 과자의 이름을 입력해주세요 :  ");
    scanf("%s", search);

    printf("\nNo Name Weight Price Perprice Star\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].weight != -1){
            if(strstr(s[i].name, search)){
                printf("%2d", i+1);
                readSnack(s[i]); 
                scount++;
            }
        }            
    }
    if(scount==0) printf("=> 검색된 데이터가 없습니다. \n");
}
void searchPrice(Snack *s, int count){      //가격을 검색해 등록된 제품을 찾는 함수
    int scount = 0;
    int search;

    printf("검색할 과자의 가격을 입력해주세요 : ");
    scanf("%d", &search);

    printf("\nNo Name Weight Price Perprice Star\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].weight != -1){
            if(s[i].price == search){
                printf("%2d", i+1);
                readSnack(s[i]); 
                scount++;
            }
        }            
    }
    if(scount==0) printf("=> 검색된 데이터가 없습니다. \n");
}

void searchStar(Snack *s, int count){       //별점수를 검색해 등록된 제품을 찾는 함수
    int scount = 0;
    int search;

    printf("검색할 별점수를 입력해주세요 : ");
    scanf("%d", &search);

    printf("\nNo Name Weight Price Perprice Star\n");
    printf("================================\n");
    for(int i=0;i<count;i++){
        if(s[i].weight != -1){
            if(s[i].star == search){
                printf("%2d", i+1);
                readSnack(s[i]); 
                scount++;
            }
        }            
    }
    if(scount==0) printf("=> 검색된 데이터가 없습니다. \n");
}
int selectMenu(){
    int menu;
    printf("\n***과자 관리기***\n");
    printf("1 .과자  조회\n");
    printf("2. 과자  추가\n");
    printf("3. 과자 정보 수정\n");
    printf("4. 과자 정보 삭제\n");
    printf("5. 파일에 저장\n");
    printf("6. 이름검색\n");
    printf("7. 가격검색\n");
    printf("8. 별점수검색\n");
    printf("0. 종료하기\n\n");
    printf("=> 원하는 메뉴의 번호를 입력하세요 :  ");
    scanf("%d", &menu);
    return menu;
}
