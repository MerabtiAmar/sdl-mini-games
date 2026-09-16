#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>

#define HIEGHT 600
#define WIDTH 800


void get_center_of_object(SDL_Rect pos,int &x,int &y,int marge){
    x = pos.x + marge;
    y = pos.y + marge;
}








int main(int argc, char** argv)
{
    srand(time(NULL));

    bool done = false,wessen = false;
    int x,y,xSpeed,ySpeed,gx,gy;



            SDL_Init(SDL_INIT_VIDEO);
            SDL_Surface *ecran = NULL,*ball = NULL,*hole[6] = {NULL},*goal = NULL;
            SDL_Event event;
            SDL_Rect ballPos,holePos[6],goalPos;

                xSpeed = rand()%2;
                ySpeed = rand()%2;
                if(xSpeed == 0) xSpeed = -1;else if(xSpeed == 2) xSpeed = 1;
                if(ySpeed == 0) ySpeed = -1;else if(ySpeed == 2) ySpeed = 1;

    long tura = SDL_GetTicks();


    ecran = SDL_SetVideoMode(WIDTH,HIEGHT,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,218,252,162));

        ball = IMG_Load("ball.png");
        ballPos.x = (WIDTH-34)/2;
        ballPos.y = (HIEGHT-34)/2;

        for(int i = 0;i<6;i++){
        hole[i] = IMG_Load("hole.png");
        }
        holePos[0].y = 0;
        holePos[0].x = 0;

        holePos[1].y = 0;
        holePos[1].x = (WIDTH-96)/2;

        holePos[2].y = 0;
        holePos[2].x = WIDTH - 96;

        holePos[3].y = HIEGHT - 87;
        holePos[3].x = 0;

        holePos[4].y = HIEGHT - 87;
        holePos[4].x = (WIDTH-96)/2;

        holePos[5].y = HIEGHT - 87;
        holePos[5].x = WIDTH - 96;


        goal = IMG_Load("goal.png");

    while(!done){

        SDL_PollEvent(&event);

        if(tura%100 == 0){
                do{
                    xSpeed = rand()%10;
                    ySpeed = rand()%10;
                }while(xSpeed == 0 && ySpeed == 0);
            if(xSpeed%2 == 1) xSpeed = -1;else if(xSpeed%2 == 0) xSpeed = 1;
            if(ySpeed%2 == 1) ySpeed = -1;else if(ySpeed%2 == 0) ySpeed = 1;

        }
                ballPos.x += xSpeed*2;
                ballPos.y += ySpeed*2;

                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                done = true;
                                break;
                            default:
                                done = false;
                                break;
                        }

                        switch(event.type){
                            case SDL_QUIT:
                                done = true;
                                break;
                        }




                        SDL_BlitSurface(ball,NULL,ecran,&ballPos);

                SDL_Flip(ecran);


                        get_center_of_object(ballPos,x,y,17);
                        if(x + 17 > WIDTH -2 ||x - 17 < 2){xSpeed*=-1;}
                        if(y + 17 > HIEGHT -2 ||y - 17 < 2){ySpeed*=-1;}


                for(int i = 0;i<6;i++){
                    if(((ballPos.x > holePos[i].x)&&(ballPos.x < holePos[i].x + 96/2))&&
                       ((ballPos.y > holePos[i].y)&&(ballPos.y < holePos[i].y + 86/2))){
                        wessen = true;
                        get_center_of_object(holePos[i],gx,gy,(91-34)/2);
                        goalPos.x = gx;
                        goalPos.y = gy;
                        ballPos.x = (WIDTH-34)/2;
                        ballPos.y = (HIEGHT-34)/2;
                       }
                }


                        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,218,252,162));

                        for(int i = 0;i<6;i++){
                            SDL_BlitSurface(hole[i],NULL,ecran,&holePos[i]);
                        }
                        if(wessen){
                        SDL_BlitSurface(goal,NULL,ecran,&goalPos);
                        }

                        tura = SDL_GetTicks();
    }


    for(int i = 0;i<6;i++){
        SDL_FreeSurface(hole[i]);
    }
    SDL_FreeSurface(ball);
    SDL_FreeSurface(goal);
    SDL_Quit();
    return EXIT_SUCCESS;
}
