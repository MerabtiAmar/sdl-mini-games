#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

int main ( int argc, char** argv )
{

        SDL_Init(SDL_INIT_VIDEO);

        bool dayen = false;int y = 1,x = 2,ia[200],i;

        for(i = 0;i<200;i++){ia[i] = 250+i;}

        SDL_Surface *ecran = NULL,*lblok = NULL,*rblok = NULL,*point = NULL;
        SDL_Event event;
        SDL_Rect lpos,rpos,ppos;
        srand(time(NULL));
        ppos.x = rand()%1346 + 1;ppos.y = rand()% 748 + 1;

        ecran = SDL_SetVideoMode(1366,768,32,
                                 SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

            point = IMG_Load("point.png");

        lblok = SDL_CreateRGBSurface(SDL_HWSURFACE,20,150,32,0,0,0,0);
        rblok = SDL_CreateRGBSurface(SDL_HWSURFACE,20,150,32,0,0,0,0);

        lpos.x = 0;lpos.y = 306;
        rpos.x = 1346;rpos.y = 309;

        SDL_FillRect(lblok,NULL,SDL_MapRGB(lblok->format,255,255,255));
        SDL_FillRect(rblok,NULL,SDL_MapRGB(rblok->format,255,255,255));

        SDL_ShowCursor(SDL_DISABLE);

        SDL_EnableKeyRepeat(10,10);

        while(!dayen)
        {
        ppos.x = ppos.x + x;ppos.y = ppos.y + y;
        if(ppos.y<1 || ppos.y>750)
            {
            y = - y;
            }
            if((ppos.x+30>1346) && (ppos.y > rpos.y -10 && ppos.y < rpos.y +150))
            {
                x = -x;
            }else if((ppos.x-10>1346) && (ppos.y-10 < rpos.y || ppos.y > rpos.y +150))
            {ppos.x = 683;ppos.y = 384;}

            if((ppos.x<20) && (lpos.y < ppos.y - 10  && lpos.y +150 > ppos.y))
            {
                x = -x;
            }else if((ppos.x<20) && (ppos.y-10 < rpos.y || ppos.y > rpos.y +150))
            {ppos.x = 683;ppos.y = 384;}

            srand(time(NULL));

            i = rand()%199+1;

            if(x<0 && ppos.x < ia[i]){
            if(lpos.y+75>ppos.y)
            {
                lpos.y-=1;
            }else{lpos.y+=1;}}

            SDL_PollEvent(&event);
            switch(event.type)
            {
            case SDL_QUIT:
                dayen = true;
                break;
            case SDL_MOUSEMOTION:
               rpos.y = event.motion.y;
                break;
            default:
                dayen = false;
                break;
            }

            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                dayen = true;
                break;
            default:
                dayen = false;
                break;

            }


            SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,90,185,254));
            SDL_BlitSurface(point,NULL,ecran,&ppos);
            SDL_BlitSurface(lblok,NULL,ecran,&lpos);
            SDL_BlitSurface(rblok,NULL,ecran,&rpos);
            SDL_Flip(ecran);
        }



        SDL_FreeSurface(lblok);SDL_FreeSurface(rblok);SDL_FreeSurface(point);

        SDL_Quit();

    return EXIT_SUCCESS;
}
