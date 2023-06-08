#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
//cc ShooterMap.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

#define screenWidth 1900
#define screenHeight 1000

#define NUM_SHOOTS 1000

#define FIESR_WAVE_ENEMIES 20
#define SECOND_WAVE_ENEMIES 50
#define THIRD_WAVE_ENEMIES 100
#define NUM_MAX_ENEMIES 100


typedef enum { FIRST = 0, SECOND, THIRD } EnemyWave;

//??
typedef struct ShootAir{
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
    float x, y;
    int speed_y;
    int H, W;
}Shoot;

typedef struct Player{
    Texture2D Airplain;
    Rectangle rec;
    Vector2 speed;
    Color color;
    int H, W;
} Player;

typedef struct Enemy{
    Texture2D meteor;
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Enemy;


static bool gameOver = false;
static bool pause =  false;
static int score = 0;
static bool victory = false;

static EnemyWave wave = { 0 };
static Player player = { 0 };
static Enemy enemy[NUM_MAX_ENEMIES] = { 0 };
static Shoot shoot[NUM_SHOOTS] = { 0 };

static int shootRate = 0;
static float alpha = 0.0f;

static int enemiesKill = 0;
static int activeEnemies = 0;
static bool smooth = false;

static void InitGame(void);
static void UpdateGame(void);      
static void DrawGame(void);        
static void UnloadGame(void);       
static void UpdateDrawFrame(void);

int main(){
	InitWindow(screenWidth, screenHeight, "Shoot'er map");
	
	Texture2D Background = LoadTexture("Background.png");
    
    InitGame();
    InitAudioDevice();
    Sound shootA = LoadSound("shootmus.mp3");
    Music music = LoadMusicStream("music.mp3");
    PlayMusicStream(music);
    SetMasterVolume(0.3f);
    float timePlayd = 0.0f;

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(120);
    //
    

	while(!WindowShouldClose()){
		UpdateMusicStream(music);
        timePlayd = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
        if(timePlayd > 1.0f){
            timePlayd = 1.0;
        }
        if (IsKeyPressed(KEY_ENTER)){
            StopMusicStream(music);
            PlayMusicStream(music);
        }
        if(IsKeyDown(KEY_SPACE)){
            PlaySound(shootA);
        }
		BeginDrawing();
        UpdateDrawFrame();
		ClearBackground(BLACK);
		
		DrawTexture(Background, 568, 0, WHITE);
        DrawRectangle(570, 0, 1, 1000, GOLD);
        DrawRectangle(1422, 0, 1, 1000, GOLD);
        DrawRectangle(570, 0, 852, 1, GOLD);
        DrawRectangle(570, 999, 852, 1, GOLD);
        UpdateDrawFrame();
			
		EndDrawing();
	}
    #endif         // Unload loaded data (textures, sounds, models...)

    CloseWindow(); 
	UnloadTexture(Background);
    UnloadMusicStream(music);   // Unload music stream buffers from RAM
    UnloadSound(shootA);
    CloseAudioDevice(); 

   CloseWindow();       
   return 0;
}

        



void InitGame(void)
{
    shootRate = 0;
    pause = false;
    gameOver = false;
    victory = false;
    smooth = 0;
    score = 0;
    enemiesKill = 0;
    wave = FIRST;
    activeEnemies = FIESR_WAVE_ENEMIES;
    alpha = 0;

    player.rec.x =  900;
    player.rec.y = 800;
    player.rec.width = 50;
    player.rec.height = 50;
    player.speed.x = 5;
    player.speed.y = 5;
    
     for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].rec.width = 15;
        enemy[i].rec.height = 15;
        enemy[i].rec.x = GetRandomValue(580, 1390);
        enemy[i].rec.y = GetRandomValue(-1500, -300);
        enemy[i].speed.x = 3;
        enemy[i].speed.y = 3;
        enemy[i].active = true;
        enemy[i].color = GOLD; 
    }

    
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        shoot[i].rec.x = player.rec.x;
        shoot[i].rec.y = player.rec.y + player.rec.height/2;
        shoot[i].rec.width = 5;
        shoot[i].rec.height = 12;
        shoot[i].speed.x = 0;
        shoot[i].speed.y = 6;
        shoot[i].active = false;
        shoot[i].color = MAROON;
    }
}

void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause)
        {
            switch (wave)
            {
                case FIRST:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f) smooth = true;
                    }

                    if (smooth) alpha -= 0.02f;

                    if (enemiesKill == activeEnemies)
                    {
                        enemiesKill = 0;

                        for (int i = 0; i < activeEnemies; i++)
                        {
                            if (!enemy[i].active){ enemy[i].active = true;}
                        }

                        activeEnemies = SECOND_WAVE_ENEMIES;
                        wave = SECOND;
                        smooth = false;
                        alpha = 0.0f;
                    }
                } break;
                case SECOND:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f) smooth = true;
                    }

                    if (smooth) alpha -= 0.02f;

                    if (enemiesKill == activeEnemies)
                    {
                        enemiesKill = 0;

                        for (int i = 0; i < activeEnemies; i++)
                        {
                            if (!enemy[i].active) enemy[i].active = true;
                        }

                        activeEnemies = THIRD_WAVE_ENEMIES;
                        wave = THIRD;
                        smooth = false;
                        alpha = 0.0f;
                    }
                } break;
                case THIRD:
                {
                    if (!smooth)
                    {
                        alpha += 0.02f;

                        if (alpha >= 1.0f) smooth = true;
                    }

                    if (smooth) alpha -= 0.02f;

                    if (enemiesKill == activeEnemies) victory = true;

                } break;
                default: break;
            }

            // Player movement
            if (IsKeyDown(KEY_D)) player.rec.x += player.speed.x;
            if (IsKeyDown(KEY_A)) player.rec.x -= player.speed.x;
            if (IsKeyDown(KEY_W)) player.rec.y -= player.speed.y;
            if (IsKeyDown(KEY_S)) player.rec.y += player.speed.y;

            // Player collision with enemy
            for (int i = 0; i < activeEnemies; i++)
            {
                if (CheckCollisionRecs(player.rec, enemy[i].rec)) gameOver = true;
            }
            if(player.rec.x > 1365){
                player.rec.x = 550;
            }
            if(player.rec.x < 550){
                player.rec.x = 1365;
            }
            if(player.rec.y >923){
                player.rec.y = 923;
            }
            if(player.rec.y < -48.0f){
                player.rec.y = -48.0f;
            }

             // Enemy behaviour
            for (int i = 0; i < activeEnemies; i++)
            {
                if (enemy[i].active)
                {
                    enemy[i].rec.y += enemy[i].speed.y;

                    if (enemy[i].rec.y > 1000)
                    {
                        enemy[i].rec.x = GetRandomValue(580, 1355);
                        enemy[i].rec.y = GetRandomValue(-800, -300);
                    }
                }
            }

            // Shoot initialization
            if (IsKeyDown(KEY_SPACE))
            {
                shootRate += 5;

                for (int i = 0; i < NUM_SHOOTS; i++)
                {
                    if (!shoot[i].active && shootRate%50 == 0)
                    {
                        shoot[i].rec.x = player.rec.x+37;
                        shoot[i].rec.y = player.rec.y + player.rec.height-30;
                        shoot[i].active = true;
                        break;
                    }
                }
            }

            // Shoot logic
            for (int i = 0; i < NUM_SHOOTS; i++)
            {
                if (shoot[i].active)
                {
                    // Movement
                    shoot[i].rec.y -= shoot[i].speed.y;

                    // Collision with enemy
                    for (int j = 0; j < activeEnemies; j++)
                    {
                        if (enemy[j].active)
                        {
                            if (CheckCollisionRecs(shoot[i].rec, enemy[j].rec))
                            {
                                shoot[i].active = false;
                                enemy[j].rec.x = GetRandomValue(580, 1390);
                                enemy[j].rec.y = GetRandomValue(-1500, -500);
                                shootRate = 0;
                                enemiesKill++;
                                score += 100;
                            }

                            if (shoot[i].rec.y + shoot[i].rec.height >= screenWidth)
                            {
                                shoot[i].active = false;
                                shootRate = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

void DrawGame(void){
    player.Airplain = LoadTexture("AIRPLAIN.png");
    BeginDrawing();
    if(!gameOver){
        DrawTexture(player.Airplain, player.rec.x-10, player.rec.y-10, WHITE);
        if (wave == FIRST) DrawText("FIRST WAVE", screenWidth/2 + 40 - MeasureText("FIRST WAVE", 40)/2, screenHeight/5 - 40, 40, Fade(GOLD, alpha));
        else if (wave == SECOND) DrawText("SECOND WAVE", screenWidth/2 + 40 - MeasureText("SECOND WAVE", 40)/2, screenHeight/5 - 40, 40, Fade(GOLD, alpha));
        else if (wave == THIRD) DrawText("THIRD WAVE", screenWidth/2 + 40 - MeasureText("THIRD WAVE", 40)/2, screenHeight/5 - 40, 40, Fade(GOLD, alpha));

        for (int i = 0; i < activeEnemies; i++)
        {
            if (enemy[i].active) DrawRectangleRec(enemy[i].rec, enemy[i].color);
        }

        for (int i = 0; i < NUM_SHOOTS; i++){
            if (shoot[i].active) DrawRectangleRec(shoot[i].rec, shoot[i].color);
        }

        DrawText(TextFormat("%06i", score), 20, 20, 40, GOLD);

        if (victory) DrawText("YOU WIN", screenWidth/2+ 40 - MeasureText("YOU WIN", 40)/2, screenHeight/5 - 40, 40, GOLD);

        if (pause) DrawText("GAME PAUSED", screenWidth/2+40 - MeasureText("GAME PAUSED", 40)/2, screenHeight/5 - 40, 40, GOLD);
    }
    else{
        DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2+40 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GOLD);
    }
    
    EndDrawing();
}

void UnloadGame(void)
{
    CloseAudioDevice(); 
}

void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}