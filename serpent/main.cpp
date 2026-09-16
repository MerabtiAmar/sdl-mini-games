#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>

int abs(int a)
{
    if(a>0){return a;}
    else{return -a;}
}


int main (int argc, char** argv)
{

 int continuer = 1,n,i;
     SDL_Surface *ecran = NULL,*point = NULL,*carre[100] = {NULL};
    SDL_Event event;
    SDL_Rect pos,suite[100];

    SDL_Init(SDL_INIT_VIDEO);


    SDL_ShowCursor(SDL_DISABLE);

    ecran = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE|SDL_FULLSCREEN|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("SERPENT", NULL);
    SDL_WM_SetIcon(IMG_Load("serpent.jpg"),NULL);


    srand(time(NULL));
    pos.x = rand()% 1320 + 1;
    pos.y = rand()% 720 + 1;

    point = IMG_Load("point.png");
    carre[0] = IMG_Load("carre.jpg");
        suite[0].x = ecran->w / 2 - carre[0]->w / 2;
        suite[0].y = ecran->h / 2 - carre[0]->h / 2;
        n = 1;

       SDL_EnableKeyRepeat(10,10);

   while(continuer)
    {



        SDL_PollEvent(&event);
        if((abs(suite[0].x - pos.x))<30 && (abs((suite[0].y-pos.y+10))<30))
          {
            pos.x = rand()% 1320 + 1;
            pos.y = rand()% 720 + 1;

                for(i = 1;i<n+1;i++)
                {
                    carre[i] = IMG_Load("carre.jpg");
                }
                n++;
            }


            switch(event.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                       break;
                case SDL_MOUSEMOTION :
                    pos.x = event.motion.x;
                    pos.y = event.motion.y;
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                suite[0].y = suite[0].y - 1;
                suite[1].y = suite[0].y + 20;
                suite[1].x = suite[0].x;
                for(i = 1;i<n;i++)
                {
                    suite[i].y = suite[i-1].y + 20;
                    suite[i].x = suite[i-1].x;
                }
                break;
            case SDLK_DOWN:
                suite[0].y = suite[0].y + 1;
               suite[1].y = suite[0].y - 20;
                suite[1].x = suite[0].x;
                for(i = 1;i<n;i++)
                {
                    suite[i].y = suite[i-1].y - 20;
                    suite[i].x = suite[i-1].x;
                }

                break;
            case SDLK_LEFT:
                suite[0].x = suite[0].x - 1;
                suite[1].x = suite[0].x + 21;
                suite[1].y = suite[0].y;
                for(i = 1;i<n;i++)
                {
                    suite[i].x = suite[i-1].x + 21;
                    suite[i].y = suite[i-1].y;
                }

                break;
            case SDLK_RIGHT:
                suite[0].x = suite[0].x + 1;
                suite[1].x = suite[0].x - 21;
                suite[1].y = suite[0].y;
                for(i = 1;i<n;i++)
                {
                    suite[i].x = suite[i-1].x - 21;
                    suite[i].y = suite[i-1].y;
                }

                break;
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            default:
                continuer = 1;
                break;
                    }
                    break;
            case SDL_KEYDOWN :

                switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                suite[0].y = suite[0].y - 1;
                suite[1].y = suite[0].y + 20;
                suite[1].x = suite[0].x;
                for(i = 1;i<n;i++)
                {
                    suite[i].y = suite[i-1].y + 20;
                    suite[i].x = suite[i-1].x;
                }

                break;
            case SDLK_DOWN:
                suite[0].y = suite[0].y + 1;
                 suite[1].y = suite[0].y - 20;
                suite[1].x = suite[0].x;
                for(i = 1;i<n;i++)
                {
                    suite[i].y = suite[i-1].y - 20;
                    suite[i].x = suite[i-1].x;
                }

                break;
            case SDLK_LEFT:
                suite[0].x = suite[0].x - 1;
                 suite[1].x = suite[0].x + 21;
                suite[1].y = suite[0].y;
                for(i = 1;i<n;i++)
                {
                    suite[i].x = suite[i-1].x + 21;
                    suite[i].y = suite[i-1].y;
                }

                break;
            case SDLK_RIGHT:
                suite[0].x = suite[0].x + 1;
                 suite[1].x = suite[0].x - 21;
                suite[1].y = suite[0].y;
                for(i = 1;i<n;i++)
                {
                    suite[i].x = suite[i-1].x - 21;
                    suite[i].y = suite[i-1].y;
                }
                break;
                case SDLK_ESCAPE:
                continuer = 0;
                break;
            default:
                continuer = 1;
                break;


                    }
            }
                if(suite[0].x < 2){suite[0].x = 1360;}if(suite[0].x > 1360){suite[0].x = 3;}

                if(suite[0].y < 2){suite[0].y = 764;}if(suite[0].y > 764){suite[0].y = 3;}

                      if(pos.x < 2){pos.x = 1360;}if(pos.x > 1360){ pos.x = 3;}

                      if(pos.y < 2){pos.y = 764;}if(pos.y > 764){pos.y = 3;}



    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(point,NULL,ecran,&pos);

SDL_BlitSurface(carre[0],NULL,ecran,&suite[0]);
    for(i = 1;i<n;i++)
    {
        SDL_BlitSurface(carre[i],NULL,ecran,&suite[i]);
    }
       SDL_Flip(ecran);


    }
    SDL_FreeSurface(point);
    SDL_FreeSurface(carre[0]);
    for(i = 1;i<n;i++)
    {
        SDL_FreeSurface(carre[i]);
    }
    SDL_Quit();

    return EXIT_SUCCESS;
}
