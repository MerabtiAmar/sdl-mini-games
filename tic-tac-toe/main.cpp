#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


void Degrade(SDL_Surface ecran,int w,int h){

SDL_Surface *surface[w] = {NULL};
SDL_Rect pos;

for(int i = 0;i<w;i++){
                 pos.y = 0;
                 pos.x = i*1.3;
        surface[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,2,h,32,0,0,0,0);
        if(i<510){
        if(i<255){
        SDL_FillRect(surface[i],NULL,SDL_MapRGB(surface[i]->format,255-i,144,106));
        }else{SDL_FillRect(surface[i],NULL,SDL_MapRGB(surface[i]->format,i-255,144,106));}
        SDL_BlitSurface(surface[i],NULL,&ecran,&pos);
        SDL_Flip(&ecran);
        SDL_Flip(surface[i]);
        SDL_FreeSurface(surface[i]);
        }
        else{
        SDL_FillRect(surface[i],NULL,SDL_MapRGB(surface[i]->format,255,0,0));
        SDL_Flip(&ecran);
        SDL_Flip(surface[i]);
        SDL_FreeSurface(surface[i]);
        }
                }
}

int xround(SDL_Event event){
if(event.button.x > 0 && event.button.x < 213){return 57;}
else if(event.button.x > 214 && event.button.x < 426){return 270;}
else{return 483;}
}
int yround(SDL_Event event){
if(event.button.y > 0 && event.button.y < 160){return 24;}
else if(event.button.y > 161 && event.button.y < 320){return 184;}
else{return 344;}
}



int main ( int argc, char** argv )
{
    int h = 480, w = 640,grid[3][3] = {0},s[8] = {0};

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *ecran = NULL,*verGrid[2] = {NULL},*horGrid[2] = {NULL},*X[9] = {NULL},*O[9] = {NULL};
    SDL_Rect ver[2],hor[2],xpos[9],opos[9];
    SDL_Event event;
    bool done = false;

    SDL_WM_SetCaption("X O",NULL);

   for(int i;i<9;i++){
    X[i] = IMG_Load("X.png");
    O[i] = IMG_Load("O.png");
   }

    hor[0].y = 160;hor[0].x = 0;
    hor[1].y = 320;hor[1].x = 0;

    ver[0].x = 213;ver[0].y = 0;
    ver[1].x = 427;ver[1].y = 0;

    for(int i = 0;i<2;i++){
        verGrid[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,4,h,32,0,0,0,0);
        horGrid[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,w,4,32,0,0,0,0);
    }


    ecran = SDL_SetVideoMode(w,h,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));



    while(!done){
        SDL_WaitEvent(&event);

        switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
                done = true;
                break;
            case SDLK_r:
                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
                for(int i = 0;i <3 ;i++){
                    for(int j = 0;j < 3;j++){
                        grid[i][j] = 0;
                    }
                }
                break;
            case SDLK_SPACE:
                //for(int i = 0;i < 8;i++){
                  //  if(s[i] == 3 || s[i] == -3){
                        Degrade(*ecran,w,h);
                    //}
                //}
                break;
            default:
                done = false;
                break;
        }

        switch(event.type){
            case SDL_QUIT:
                done = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int t = 0;
                if(event.button.button == SDL_BUTTON_RIGHT){
                xpos[t].x = xround(event);xpos[t].y = yround(event);
                SDL_BlitSurface(X[t],NULL,ecran,&xpos[t]);
                if(opos[t].x == 57)
                {
                    switch(opos[t].y){
                        case 24:
                            grid[0][0] = -1;
                            break;
                        case 184:
                            grid[0][1] = -1;
                            break;
                        case 344:
                            grid[0][2] = -1;
                            break;
                    }
                }else if(opos[t].x == 270)
                {
                    switch(opos[t].y){
                        case 24:
                            grid[1][0] = -1;
                            break;
                        case 184:
                            grid[1][1] = -1;
                            break;
                        case 344:
                            grid[1][2] = -1;
                            break;
                    }
                }else
                {
                    switch(opos[t].y){
                        case 24:
                            grid[2][0] = -1;
                            break;
                        case 184:
                            grid[2][1] = -1;
                            break;
                        case 344:
                            grid[2][2] = -1;
                            break;
                    }
                }
                }
                else if(event.button.button == SDL_BUTTON_LEFT){
                opos[t].x = xround(event);opos[t].y = yround(event);
                SDL_BlitSurface(O[t],NULL,ecran,&opos[t]);
                if(xpos[t].x == 57)
                {
                    switch(xpos[t].y){
                        case 24:
                            grid[0][0] = 1;
                            break;
                        case 184:
                            grid[0][1] = 1;
                            break;
                        case 344:
                            grid[0][2] = 1;
                            break;
                    }
                }else if(xpos[t].x == 270)
                {
                    switch(xpos[t].y){
                        case 24:
                            grid[1][0] = 1;
                            break;
                        case 184:
                            grid[1][1] = 1;
                            break;
                        case 344:
                            grid[1][2] = 1;
                            break;
                    }
                }else
                {
                    switch(xpos[t].y){
                        case 24:
                            grid[2][0] = 1;
                            break;
                        case 184:
                            grid[2][1] = 1;
                            break;
                        case 344:
                            grid[2][2] = 1;
                            break;
                    }
                }
                }
                t++;
                break;
        }


        s[0] = grid[0][0] + grid[0][1] + grid[0][2];
        s[1] = grid[1][0] + grid[1][1] + grid[1][2];
        s[2] = grid[2][0] + grid[2][1] + grid[2][2];
        s[3] = grid[0][0] + grid[1][0] + grid[2][0];
        s[4] = grid[0][1] + grid[1][1] + grid[1][2];
        s[5] = grid[0][2] + grid[1][2] + grid[2][2];
        s[6] = grid[0][0] + grid[1][1] + grid[2][2];
        s[7] = grid[2][0] + grid[1][1] + grid[0][2];



        for(int i = 0;i<2;i++){
            SDL_BlitSurface(verGrid[i],NULL,ecran,&ver[i]);
            SDL_BlitSurface(horGrid[i],NULL,ecran,&hor[i]);
        }

        SDL_Flip(ecran);
    }


    for(int i = 0;i<2;i++){
        SDL_FreeSurface(verGrid[i]);
        SDL_FreeSurface(horGrid[i]);
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}
