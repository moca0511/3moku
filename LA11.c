#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    
    int i,yokosum,tatesum,naname1,naname2,player,gameflag,gamecount,itiin,incount,tate,yoko;
    char end;
    gamecount=1;
    do{
        incount=0;
        system("CLS");
        printf("           ���R�ڕ��ׁ�\n");
        for(i=1;i<=9;i++){
            if(i==1||i==4||i==7){
                printf("\n             ");
            }
            printf("%2d",i);
        }
        printf("\n\n�����̋��u�������ꏊ�ɑΉ������P�`�X�̐��������݂ɓ���\n");
        printf("�c���΂߂����ꂩ1�񂪑����Ώ����ł��B\n\n");
        printf("enter�ŊJ�n");
        getchar();
        if(gamecount>1){
            getchar();
        }
        system("CLS");
        int board[3][3]={
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        player=-1;
        gameflag=0;
        do{
            player=player*-1;

            for(tate=0;tate<3;tate++){
                printf("\n             ");    
                for(yoko=0;yoko<3;yoko++){
                    printf("%2d",board[tate][yoko]);
                }
            }
            printf("\n");
            printf("\n�v���C���['%d'�̔Ԃł�\n",player);

            do{
                do{
                    printf("�ʒu����");
                    scanf("%d",&itiin);
                    if(itiin<0||itiin>9){
                        printf("1~9����͂��Ă��������B\n");
                    }
                }while(itiin<1||itiin>9);
                switch(itiin){
                    case 1:
                        tate=0;
                        yoko=0;
                        break;
                    case 2:
                        tate=0;
                        yoko=1;
                        break;
                    case 3:
                        tate=0;
                        yoko=2;
                        break;
                    case 4:
                        tate=1;
                        yoko=0;
                        break;
                    case 5:
                        tate=1;
                        yoko=1;
                        break;
                    case 6:
                        tate=1;
                        yoko=2;
                        break;
                    case 7:
                        tate=2;
                        yoko=0;
                        break;
                    case 8:
                        tate=2;
                        yoko=1;
                        break;
                    case 9:
                        tate=2;
                      yoko=2;
                }
                if(board[tate][yoko]==1||board[tate][yoko]==-1){
                    printf("�����ɂ͓��͂ł��܂���B\n");
                }
            }while(board[tate][yoko]==1||board[tate][yoko]==-1);
            board[tate][yoko]=player;
            for(tate=0;tate<3;tate++){
                yokosum=0;
                for(yoko=0;yoko<3;yoko++){
                    yokosum=board[tate][yoko]+yokosum;
                }
                if(yokosum==3||yokosum==-3){
                    gameflag=1;
                } 
            }
            for(yoko=0;yoko<3;yoko++){
                tatesum=0;
                for(tate=0;tate<3;tate++){
                    tatesum=board[tate][yoko]+tatesum;
                }
                if(tatesum==3||tatesum==-3){
                    gameflag=1;
                } 
            }
            naname1=0;
            for(i=0;i<3;i++){
                naname1=naname1+board[i][i];
            }
            if(naname1==3||naname1==-3){
                gameflag=1;
            }
            naname2=0;
            yoko=0;
            for(tate=2;tate>=0;tate--){
                naname2=board[tate][yoko]+naname2;
                yoko++;
            }
            if(naname2==3||naname2==-3){
                gameflag=1;
            }
            system("CLS");
            incount++;
            if(gameflag==1)break;
        }while(incount<9);
        for(tate=0;tate<3;tate++){
            printf("\n             ");    
            for(yoko=0;yoko<3;yoko++){
                printf("%2d",board[tate][yoko]);
            }
        }
        printf("\n\n");
        if(gameflag==1){
            printf("�v���C���['%d'�̏���\n\n",player);
        }else{
            printf("���������ł�\n\n");
        }
        printf("�����ėV�т܂����H(y/n):");
        scanf("%*c%c",&end);
        gamecount++;
    }while(end!='n');
    return 0;
}


