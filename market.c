#include "product.h"

int main(void){
#define DEGUG

    Snack slist[100];
    int curcount = 0;

    Snack s;
    int count = 0, menu;
    count = loadData(slist);
    curcount = count;

    while (1){
#ifdef DEBUG
        printf("debug[market.c] : call selectMenu()\n");
#endif
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
#ifdef DEBUG
        printf("debug[market.c] : call listSnack()\n");
#endif
            if(count > 0) listSnack(slist, curcount);
            else printf("데이터가 없습니다.\n");
        }
        else if (menu == 2){
#ifdef DEBUG
        printf("debug[market.c] : call selectMenu()\n");
#endif
            count += createSnack(&slist[curcount++]);
        }
        else if (menu == 3){
#ifdef DEBUG
        printf("debug[market.c] : call selectDataNo()\n");
#endif
            int no;
            no = selectDataNo(slist, curcount);
            if(no == 0){
                printf("=> 취소되었습니다!!\n");
                continue;
            }
#ifdef DEBUG
        printf("debug[market.c] : call updateSnack()\n");
#endif
            updateSnack(&slist[no-1]);
        }
        else if (menu == 4){
#ifdef DEBUG
        printf("debug[market.c] : call selectDataNo()\n");
#endif
            int no;
            no = selectDataNo(slist, curcount);
            if(no == 0){
                printf("=> 취소되었습니다!!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
#ifdef DEBUG
        printf("debug[market.c] : call deleteSnack()\n");
#endif
                if(deleteSnack(&slist[no-1])) count--;
            }
            deleteSnack(&s);
            if(deleteSnack(&s) == 1) printf("=> 삭제되었습니다!!\n");
        }
        else if (menu == 5){
            if(count == 0)
                printf("데이타가 없습니다!\n");
            else
#ifdef DEBUG
        printf("debug[market.c] : call savedata()\n");
#endif
                saveData(slist, curcount);
        } 
        else if (menu == 6){
            if(count == 0)
                printf("데이타가 없습니다!\n");
            else
#ifdef DEBUG
        printf("debug[market.c] : call searchName()\n");
#endif
                searchName(slist, curcount);
        }
        else if (menu == 7){
            if(count == 0)
                printf("데이타가 없습니다!\n");
            else
#ifdef DEBUG
        printf("debug[market.c] : call searchPrice()\n");
#endif
                searchPrice(slist, curcount);
        }   
        else if (menu == 8){
            if(count == 0)
                printf("데이타가 없습니다!\n");
            else
#ifdef DEBUG
        printf("debug[market.c] : call searchStar()\n");
#endif
                searchStar(slist, curcount);
        }          
    }
    printf("\n\n종료되었습니다. 감사합니다. \n");
    return 0;
}

