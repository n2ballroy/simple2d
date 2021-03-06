// testcard.c
#include <simple2d.h>

S2D_Window *window;
S2D_Image  *img_bmp;
S2D_Image  *img_jpg;
S2D_Image  *img_png;
S2D_Image  *img_clr_r;
S2D_Image  *img_clr_g;
S2D_Image  *img_clr_b;
S2D_Sprite *spr;
int sprite_step = 0;
S2D_Text   *key_down_text;
S2D_Text   *key_down_char;
S2D_Text   *key_text;
S2D_Text   *key_char;
S2D_Text   *txt_clr_r;
S2D_Text   *txt_clr_g;
S2D_Text   *txt_clr_b;
S2D_Text   *fps;
S2D_Text   *fps_val;

char fps_str[7];
const char *font = "media/bitstream_vera/vera.ttf";
int font_size = 20;

typedef struct {
  int x;
  int y;
} Point;

Point pointer;


void on_key(S2D_Event e, const char *key) {
  switch (e) {
    case S2D_KEYDOWN:
      printf("Key down: %s\n", key);
      if (strcmp(key, "Escape") == 0) S2D_Close(window);
      S2D_SetText(key_down_char, key);
      break;
    
    case S2D_KEY:
      printf("Key held: %s\n", key);
      S2D_SetText(key_char, key);
      break;
    
    case S2D_KEYUP:
      printf("Key up: %s\n", key);
      break;
  }
}


void on_mouse(int x, int y) {
  printf("Mouse down at: %i, %i\n", x, y);
  S2D_DrawQuad(pointer.x - 9, pointer.y - 11, 0, 1, 0, 1,
               pointer.x + 9, pointer.y - 11, 0, 1, 0, 1,
               pointer.x + 9, pointer.y + 8,  0, 1, 0, 1,
               pointer.x - 9, pointer.y + 8,  0, 1, 0, 1);
}


void on_controller(int which, bool is_axis, int axis, int val, bool is_btn, int btn, bool pressed) {
  puts("=== Controller Pressed ===");
  printf(
    "which: %i\nis_axis: %i\naxis: %i\nval: %i\nis_btn: %i\nbtn: %i\n",
    which, is_axis, axis, val, is_btn, btn
  );
}


void update() {
  pointer.x = window->mouse.x;
  pointer.y = window->mouse.y;
}


void render() {
  
  // Primary colors
  
  S2D_DrawQuad( 0,   0, 1, 0, 0, 1,
               50,   0, 1, 0, 0, 1,
               50, 100, 1, 0, 0, 1,
                0, 100, 1, 0, 0, 1);
  
  S2D_DrawQuad( 50,   0, 0, 1, 0, 1,
               100,   0, 0, 1, 0, 1,
               100, 100, 0, 1, 0, 1,
                50, 100, 0, 1, 0, 1);
  
  S2D_DrawQuad(100,   0, 0, 0, 1, 1,
               150,   0, 0, 0, 1, 1,
               150, 100, 0, 0, 1, 1,
               100, 100, 0, 0, 1, 1);
  
  // Color combinations
  
  S2D_DrawQuad(150,  0, 0, 1, 1, 1,
               200,  0, 0, 1, 1, 1,
               200, 50, 0, 1, 1, 1,
               150, 50, 0, 1, 1, 1);
  
  S2D_DrawQuad(200,  0, 1, 0, 1, 1,
               250,  0, 1, 0, 1, 1,
               250, 50, 1, 0, 1, 1,
               200, 50, 1, 0, 1, 1);
  
  S2D_DrawQuad(250,  0, 1, 1, 0, 1,
               325,  0, 1, 1, 0, 1,
               325, 50, 1, 1, 0, 1,
               250, 50, 1, 1, 0, 1);
  
  S2D_DrawQuad(150, 50,  1, .5, 0, 1,
               200, 50,  1, .5, 0, 1,
               200, 100, 1, .5, 0, 1,
               150, 100, 1, .5, 0, 1);
  
  S2D_DrawQuad(200,  50, .5, 1, 0, 1,
               250,  50, .5, 1, 0, 1,
               250, 100, .5, 1, 0, 1,
               200, 100, .5, 1, 0, 1);
  
  S2D_DrawQuad(250,  50, 1, 0, .5, 1,
               325,  50, 1, 0, .5, 1,
               325, 100, 1, 0, .5, 1,
               250, 100, 1, 0, .5, 1);
  
  // White to black gradient
  
  S2D_DrawQuad(  0, 100, 1, 1, 1, 1,
               600, 100, 0, 0, 0, 1,
               600, 125, 0, 0, 0, 1,
                 0, 125, 1, 1, 1, 1);
  
  // Color gradient
  
  S2D_DrawQuad(  0, 125, 1, 0, 0, 1,
               600, 125, 0, 1, 0, 1,
               600, 175, 0, 0, 1, 1,
                 0, 175, 1, 1, 0, 1);
  
  // Transparancy
  
  S2D_DrawQuad(  0, 165, 1, 1, 1, 0,
               600, 165, 1, 1, 1, 1,
               600, 200, 1, 1, 1, 1,
                 0, 200, 1, 1, 1, 0);
  
  // Triangles
  
  S2D_DrawTriangle(25, 200, 1, 0, 0, 1,
                   50, 250, 1, 0, 0, 1,
                    0, 250, 1, 0, 0, 1);
  
  S2D_DrawTriangle( 75, 200, 0, 1, 0, 1,
                   100, 250, 0, 1, 0, 1,
                    50, 250, 0, 1, 0, 1);
  
  S2D_DrawTriangle(125, 200, 0, 0, 1, 1,
                   150, 250, 0, 0, 1, 1,
                   100, 250, 0, 0, 1, 1);
  
  S2D_DrawTriangle(175, 200, 1, 0, 0, 1,
                   200, 250, 0, 1, 0, 1,
                   150, 250, 0, 0, 1, 1);
  
  S2D_DrawTriangle(175, 200, 1, 0, 0, 1,
                   200, 250, 0, 1, 0, 1,
                   150, 250, 0, 0, 1, 1);
  
  S2D_DrawQuad(200, 200, 1, 1, 1, .5,
               250, 200, 1, 1, 1, .5,
               250, 250, 1, 1, 1, .5,
               200, 250, 1, 1, 1, .5);
  
  S2D_DrawTriangle(225, 200, 1, 1, 1, 1,
                   250, 250, 0, 0, 0, 1,
                   200, 250, 1, 1, 1, 0);
  
  // Quadrilaterals
  
  S2D_DrawQuad(300, 200, 1, 0, 0, 1,
               350, 200, 0, 1, 0, 1,
               300, 250, 0, 0, 1, 1,
               250, 250, 1, 1, 0, 1);
  
  S2D_DrawQuad(250, 200, 1, 1, 1, 0,
               300, 200, 1, 1, 1, 0,
               350, 250, 1, 1, 1, 1,
               300, 250, 1, 1, 1, 0);
  
  // Images
  
  S2D_DrawImage(img_png);
  S2D_DrawImage(img_jpg);
  S2D_DrawImage(img_bmp);
  S2D_DrawImage(img_clr_r);
  S2D_DrawImage(img_clr_g);
  S2D_DrawImage(img_clr_b);
  
  // Sprites
  
  if (window->frames % 50 == 0) {
    if (sprite_step == 0) {
      S2D_ClipSprite(spr, 0, 0, 50, 50);
      sprite_step++;
    } else if (sprite_step == 1) {
      S2D_ClipSprite(spr, 50, 0, 50, 50);
      sprite_step++;
    } else if (sprite_step == 2) {
      S2D_ClipSprite(spr, 100, 0, 50, 50);
      sprite_step++;
    } else if (sprite_step == 3) {
      S2D_ClipSprite(spr, 150, 0, 50, 50);
      sprite_step = 0;
    }
  }
  
  S2D_DrawSprite(spr);
  
  // Text
  
  S2D_DrawText(key_down_text);
  S2D_DrawText(key_down_char);
  S2D_DrawText(key_text);
  S2D_DrawText(key_char);
  S2D_DrawText(txt_clr_r);
  S2D_DrawText(txt_clr_g);
  S2D_DrawText(txt_clr_b);
  
  // Window stats
  
  S2D_DrawText(fps);
  snprintf(fps_str, 7, "%f", window->fps);
  if (window->frames % 20 == 0) S2D_SetText(fps_val, fps_str);
  S2D_DrawText(fps_val);
  
  // Mouse positions
  
  S2D_DrawQuad(pointer.x - 5, pointer.y - 7,  1, 1, 1, 1,
               pointer.x + 5, pointer.y - 7,  1, 1, 1, 1,
               pointer.x + 5, pointer.y + 4,  1, 1, 1, 1,
               pointer.x - 5, pointer.y + 4,  1, 1, 1, 1);
}


int main() {
  
  S2D_Diagnostics(true);
  
  window = S2D_CreateWindow("Simple 2D – Test Card", 600, 500, update, render, S2D_RESIZABLE);
  
  window->on_key        = on_key;
  window->on_mouse      = on_mouse;
  window->on_controller = on_controller;
  
  img_png = S2D_CreateImage("media/image.png");
  img_png->x = 300;
  img_png->y = 0;
  
  img_jpg = S2D_CreateImage("media/image.jpg");
  img_jpg->x = 400;
  img_jpg->y = 0;
  
  img_bmp = S2D_CreateImage("media/image.bmp");
  img_bmp->x = 500;
  img_bmp->y = 0;
  
  img_clr_r = S2D_CreateImage("media/colors.png");
  img_clr_r->x = 350;
  img_clr_r->y = 200;
  img_clr_r->width  = 50;
  img_clr_r->height = 50;
  img_clr_r->color.r = 1.0;
  img_clr_r->color.g = 0.3;
  img_clr_r->color.b = 0.3;
  img_clr_r->color.a = 1.0;
  
  img_clr_g = S2D_CreateImage("media/colors.png");
  img_clr_g->x = 400;
  img_clr_g->y = 200;
  img_clr_g->width  = 50;
  img_clr_g->height = 50;
  img_clr_g->color.r = 0.3;
  img_clr_g->color.g = 1.0;
  img_clr_g->color.b = 0.3;
  img_clr_g->color.a = 1.0;
  
  img_clr_b = S2D_CreateImage("media/colors.png");
  img_clr_b->x = 450;
  img_clr_b->y = 200;
  img_clr_b->width  = 50;
  img_clr_b->height = 50;
  img_clr_b->color.r = 0.3;
  img_clr_b->color.g = 0.3;
  img_clr_b->color.b = 1.0;
  img_clr_b->color.a = 1.0;
  
  spr = S2D_CreateSprite("media/sprite_sheet.png");
  spr->x = 500;
  spr->y = 200;
  // Change color of sprite image:
  //   spr->img->color.r = 1.0;
  //   spr->img->color.g = 1.0;
  //   spr->img->color.b = 1.0;
  //   spr->img->color.a = 1.0;
  
  key_down_text = S2D_CreateText(font, "On Key Down:", font_size);
  key_down_text->x = 5;
  key_down_text->y = 300;
  key_down_char = S2D_CreateText(font, "", font_size);
  key_down_char->x = 154;
  key_down_char->y = 300;
  
  key_text = S2D_CreateText(font, "On Key:", font_size);
  key_text->x = 5;
  key_text->y = 270;
  key_char = S2D_CreateText(font, "", font_size);
  key_char->x = 90;
  key_char->y = 270;
  
  txt_clr_r = S2D_CreateText(font, "R", font_size);
  txt_clr_r->x = 44;
  txt_clr_r->y = 202;
  txt_clr_r->color.r = 1.0;
  txt_clr_r->color.g = 0.0;
  txt_clr_r->color.b = 0.0;
  txt_clr_r->color.a = 1.0;
  
  txt_clr_g = S2D_CreateText(font, "G", font_size);
  txt_clr_g->x = 92;
  txt_clr_g->y = 202;
  txt_clr_g->color.r = 0.0;
  txt_clr_g->color.g = 1.0;
  txt_clr_g->color.b = 0.0;
  txt_clr_g->color.a = 1.0;
  
  txt_clr_b = S2D_CreateText(font, "B", font_size);
  txt_clr_b->x = 144;
  txt_clr_b->y = 202;
  txt_clr_b->color.r = 0.0;
  txt_clr_b->color.g = 0.0;
  txt_clr_b->color.b = 1.0;
  txt_clr_b->color.a = 1.0;
  
  fps = S2D_CreateText(font, "FPS:", font_size);
  fps->x = 460;
  fps->y = 470;
  
  fps_val = S2D_CreateText(font, "", font_size);
  fps_val->x = 515;
  fps_val->y = 470;
  
  S2D_Show(window);
  
  S2D_FreeWindow(window);
  
  return 0;
}
