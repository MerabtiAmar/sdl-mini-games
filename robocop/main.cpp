#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUTNI 30
#define WPAD 94
#define HPAD 30
#define PAD 148
#define PARTITION 6
#define SHIFT 10
#define LIM 550

bool yekchem_degs(SDL_Rect netta_pos,SDL_Rect tawdect_pos)
{
    if((tawdect_pos.x > netta_pos.x) && (tawdect_pos.x < netta_pos.x + 32)
       && ((tawdect_pos.y > netta_pos.y) && (tawdect_pos.y < netta_pos.y + 25))){
        return true;
       }else
       {
           return false;
       }
}


int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *home = NULL,*ecran = NULL;
    SDL_Rect hpos;
    SDL_Event event;

    ecran = SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    home = IMG_Load("images/home.jpg");

    hpos.x = (ecran->w - home->w)/2;
    hpos.y = (ecran->h - home->h)/2;

    SDL_WM_SetCaption("ROBOCOP",NULL);
    //SDL_WM_SetIcon(IMG_Load("images/nekk.png"),NULL);
    bool done = false;
    bool mazal = true;
    while(mazal){
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            mazal = false;
            done = true;
            break;
        case SDL_KEYDOWN:
            mazal = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mazal = false;
            break;
                }
                SDL_BlitSurface(home,NULL,ecran,&hpos);
                SDL_Flip(ecran);
    }


    AHA:

    SDL_Surface *nekk = NULL,*netta[NUTNI] = {NULL},
                *tawdect = NULL,*limit = NULL,*win = NULL,*game_over = NULL,
                *easy = NULL,*lite_easy = NULL,*hard = NULL,*lite_hard = NULL,
                *medium = NULL,*lite_medium = NULL,*impossible = NULL,*lite_impossible = NULL,
                *level = NULL,*e = NULL,*m = NULL,*h = NULL,*im = NULL,
                *yes = NULL,*lite_yes = NULL,*y = NULL,*no = NULL,*lite_no = NULL,*n = NULL,
                *new_game = NULL,*ruh = NULL,*lite_ruh = NULL,*r = NULL,*tarsast = NULL;

    SDL_Rect pos,ppos[NUTNI],tpos,lpos,wpos,opos,
             epos,mpos,hardpos,ipos,levpos,
             ypos,nopos,newpos,rpos,tarpos;

    tawdect = SDL_CreateRGBSurface(SDL_HWSURFACE,3,5,32,0,0,0,0);
    limit = SDL_CreateRGBSurface(SDL_HWSURFACE,WIDTH,3,32,0,0,0,0);
    tarsast = SDL_CreateRGBSurface(SDL_HWSURFACE,3,5,32,0,0,0,0);

    nekk = IMG_Load("images/nekk.png");
    win = IMG_Load("images/WIN.jpg");
    game_over = IMG_Load("images/game over.png");
    easy = IMG_Load("images/easy.png");lite_easy = IMG_Load("images/lite_easy.png");e = easy;
    medium = IMG_Load("images/medium.png");lite_medium = IMG_Load("images/lite_medium.png");m = medium;
    hard = IMG_Load("images/hard.png");lite_hard = IMG_Load("images/lite_hard.png");h = hard;
    impossible = IMG_Load("images/impossible.png");lite_impossible = IMG_Load("images/lite_impossible.png");
    im = impossible;
    level = IMG_Load("images/level.png");
    yes = IMG_Load("images/yes.png");y = yes;lite_yes = IMG_Load("images/lite_yes.png");
    no = IMG_Load("images/no.png");n = no;lite_no = IMG_Load("images/lite_no.png");
    new_game = IMG_Load("images/new_game.png");
    ruh = IMG_Load("images/ruh.png");lite_ruh = IMG_Load("images/lite_ruh.png");r = ruh;

    int lxetyar;

    for(int i = 0;i<NUTNI;i++){
        netta[i] = IMG_Load("images/netta.png");
    }
    int xcont = 0,ycont = PAD;
    for(int i = 0;i<NUTNI;i++){
        ppos[i].x = PAD + xcont;
        ppos[i].y = ycont;
        xcont+=WPAD;
        if(i != 0 && i%PARTITION == 0){
        ycont+=HPAD;
        xcont = 0;
        }
    }
    srand(time(NULL));
    lxetyar = rand()%30;

    tarpos.x = ppos[lxetyar].x + netta[lxetyar]->w/2;
    tarpos.y = ppos[lxetyar].x + netta[lxetyar]->h/2;

    rpos.x = (ecran->w - ruh->w)/2;
    rpos.y = (ecran->h - ruh->h)/2+250;

    newpos.x = (ecran->w - new_game->w)/2;
    newpos.y = (ecran->h - new_game->h)/2-50;

    ypos.x = (ecran->w - yes->w)/2-50;
    ypos.y = (ecran->h - yes->h)/2+50;

    nopos.x = (ecran->w - no->w)/2+50;
    nopos.y = (ecran->h - no->h)/2+50;

    epos.x = (ecran->w - easy->w)/2;
    epos.y = (ecran->h - easy->h)/2-100;

    mpos.x = (ecran->w - medium->w)/2;
    mpos.y = (ecran->h - medium->h)/2;

    hardpos.x = (ecran->w - hard->w)/2;
    hardpos.y = (ecran->h - hard->h)/2+100;

    ipos.x = (ecran->w - impossible->w)/2;
    ipos.y = (ecran->h - impossible->h)/2+200;

    levpos.x = (ecran->w - level->w)/2;
    levpos.y = (ecran->h - level->h)/2-200;

    wpos.x = (ecran->w - win->w)/2;
    wpos.y = (ecran->h - win->h)/2;

    opos.x = (ecran->w - game_over->w)/2;
    opos.y = (ecran->h - game_over->h)/2;

    ppos[6].x = ppos[29].x + WPAD;
    ppos[6].y = ppos[23].y + HPAD;

    pos.x = (ecran->w - nekk->w)/2;
    pos.y = (ecran->h - nekk->h)/2+275;

    tpos.x = pos.x + (tawdect->w + nekk->w)/2-2;
    tpos.y = pos.y - (tawdect->h);

    lpos.x = 0;
    lpos.y = LIM;

    SDL_FillRect(tawdect,NULL,SDL_MapRGB(tawdect->format,255,255,255));
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_FillRect(limit,NULL,SDL_MapRGB(limit->format,106,106,106));


    SDL_EnableKeyRepeat(10,10);

    bool ewet = false;
    bool dayen[NUTNI];
    bool over = false;
    bool yekfa = false;

    double d,f,delay = 0.5;
    int bedel = 1,seknu = 0;
    int lahsab = 0;
    int aniwa = 0;

    for(int i = 0;i<NUTNI;i++){
        dayen[i] = true;
    }
    mazal = true;
    while(mazal){
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            mazal = false;
            done = true;
            break;
        case SDL_MOUSEMOTION:
            if(((event.motion.x > epos.x) && (event.motion.x < (easy->w+epos.x)))&&
               ((event.motion.y > epos.y) && (event.motion.y < (easy->h+epos.y)))){
                    e = lite_easy;
                        delay = 0.70;

               }else
               {
                    e = easy;
               }

               if(((event.motion.x > mpos.x) && (event.motion.x < (medium->w+mpos.x)))&&
                        ((event.motion.y > mpos.y) && (event.motion.y < (medium->h+mpos.y)))){
                    m = lite_medium;
                        delay = 0.5;

               }else
               {
                    m = medium;
               }

               if(((event.motion.x > hardpos.x) && (event.motion.x < (hard->w+hardpos.x)))&&
                        ((event.motion.y > hardpos.y) && (event.motion.y < (hard->h+hardpos.y)))){
                    h = lite_hard;
                        delay = 0.2;


               }else
               {
                    h = hard;
               }

               if(((event.motion.x > ipos.x) && (event.motion.x < (impossible->w+ipos.x)))&&
                        ((event.motion.y > ipos.y) && (event.motion.y < (impossible->h+ipos.y)))){
                    im = lite_impossible;
                        delay = 0.1;

               }else
               {
                    im = impossible;
               }
               break;
        case SDL_MOUSEBUTTONDOWN:
            goto BODY;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    mazal = false;
                    done = true;
                    break;
                default:
                    break;
            }
        }
                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                SDL_BlitSurface(level,NULL,ecran,&levpos);
                SDL_BlitSurface(e,NULL,ecran,&epos);
                SDL_BlitSurface(m,NULL,ecran,&mpos);
                SDL_BlitSurface(h,NULL,ecran,&hardpos);
                SDL_BlitSurface(im,NULL,ecran,&ipos);
                SDL_Flip(ecran);
    }

    BODY:
    d = clock();
    while(!done){
        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            done = true;
            break;
        case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = true;
                    break;
                case SDLK_LEFT:
                    pos.x--;
                    break;
                case SDLK_RIGHT:
                    pos.x++;
                    break;
                case SDLK_SPACE:
                    ewet = true;
                    break;
                default:
                    done = false;
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                if(((event.motion.x > rpos.x) && (event.motion.x < (ruh->w+rpos.x)))&&
                   ((event.motion.y > rpos.y) && (event.motion.y < (ruh->h+rpos.y)))){
                        r = lite_ruh;
                        yekfa = true;
                    }else
                    {
                        r = ruh;
                    }
                    break;
            case SDL_MOUSEBUTTONDOWN:
                if(yekfa){
                    goto NEW_GAME;
                }
                break;
        }

        lxetyar = rand()%30;

    tarpos.x = ppos[lxetyar].x + netta[lxetyar]->w/2;
    tarpos.y = ppos[lxetyar].x + netta[lxetyar]->h/2;



        if(ppos[5].x > 700 && bedel == 1){
            bedel*=-1;
        }else if(ppos[0].x < 100 && bedel == -1){
            bedel*=-1;
        }

        if(ppos[5].x > 700 || ppos[0].x < 100){
            seknu = 30;
        }else
        {
            seknu = 0;
        }


        f = clock();

        if((f-d)/1000 > delay){
            for(int i = 0;i<NUTNI;i++){
                ppos[i].x+=SHIFT*bedel;
                ppos[i].y+=seknu;
            }
            d = f;
        }


        if(ewet && tpos.y > PAD/3){
            tpos.y-=1;
        }else
        {
            ewet = false;
            tpos.x = pos.x + (tawdect->w + nekk->w)/2-2;
            tpos.y = pos.y - (tawdect->h);
        }

        if(tpos.y < ppos[6].y + 25){
            for(int i = 0;i<NUTNI;i++){
                if(yekchem_degs(ppos[i],tpos) && dayen[i]){
                    SDL_FreeSurface(netta[i]);
                    dayen[i] = false;
                    lahsab++;
                    ewet = false;
                    tpos.x = pos.x + (tawdect->w + nekk->w)/2-2;
                    tpos.y = pos.y - (tawdect->h);
                }else if(tpos.y < ppos[0].y){
                    ewet = false;
                    tpos.x = pos.x + (tawdect->w + nekk->w)/2-2;
                    tpos.y = pos.y - (tawdect->h);
                }
            }
        }

        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

        if(over){
            SDL_BlitSurface(game_over,NULL,ecran,&opos);
            SDL_BlitSurface(r,NULL,ecran,&rpos);
        }else if(lahsab == 30 && !over){
            SDL_BlitSurface(win,NULL,ecran,&wpos);
            SDL_BlitSurface(r,NULL,ecran,&rpos);
        }else{
            SDL_BlitSurface(tarsast,NULL,ecran,&tarpos);
        for(int i = 0;i<NUTNI;i++){
                if(dayen[i])
            SDL_BlitSurface(netta[i],NULL,ecran,&ppos[i]);
        }
            SDL_BlitSurface(nekk,NULL,ecran,&pos);
            SDL_BlitSurface(tawdect,NULL,ecran,&tpos);
            SDL_BlitSurface(limit,NULL,ecran,&lpos);
        }
        for(int i = 0;i<NUTNI && !over;i++){
            if(ppos[i].y >= 520 && dayen[i]){
                over = true;
            }
        }

        SDL_Flip(ecran);

    }

    NEW_GAME:
    mazal = true;
    while(mazal){
        SDL_WaitEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            mazal = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_ESCAPE:
                    mazal = false;
                    break;
                default:
                    break;
            }
            break;
        case SDL_MOUSEMOTION:
            if(((event.motion.x > ypos.x) && (event.motion.x < (yes->w+ypos.x)))&&
               ((event.motion.y > ypos.y) && (event.motion.y < (yes->h+ypos.y)))){
                    y = lite_yes;
                    aniwa = 1;

               }else
               {
                    y = yes;
               }

               if(((event.motion.x > nopos.x) && (event.motion.x < (no->w+nopos.x)))&&
                  ((event.motion.y > nopos.y) && (event.motion.y < (no->h+nopos.y)))){
                    n = lite_no;
                        aniwa = 2;
               }else
               {
                    n = no;
               }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(aniwa == 1){
                lahsab = 0;
                over = false;
                mazal = true;
                bedel = 1;seknu = 0;
                ewet = false;
                aniwa = 0;
                done = false;
                xcont = 0;ycont = PAD;
                for(int i = 0;i<NUTNI;i++){
                    dayen[i] = true;
                }
                for(int i = 0;i<NUTNI;i++){
                    ppos[i].x = PAD + xcont;
                    ppos[i].y = ycont;
                    xcont+=WPAD;
                    if(i != 0 && i%PARTITION == 0){
                    ycont+=HPAD;
                    xcont = 0;
                    }
                }
                ppos[6].x = ppos[29].x + WPAD;
                ppos[6].y = ppos[23].y + HPAD;



                goto AHA;
            }
            if(aniwa == 2){
                mazal = false;
            }
            break;
                }
                SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
                SDL_BlitSurface(new_game,NULL,ecran,&newpos);
                SDL_BlitSurface(y,NULL,ecran,&ypos);
                SDL_BlitSurface(n,NULL,ecran,&nopos);
                SDL_Flip(ecran);
    }

    for(int i = 0;i<NUTNI;i++){
            SDL_FreeSurface(netta[i]);
        }
        SDL_FreeSurface(nekk);
        SDL_FreeSurface(limit);
        SDL_Quit();

    return 0;
}
