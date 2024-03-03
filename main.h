#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vec.h"

#define hp uint32_t
#define time uint32_t


struct plant {
  enum plant_type {
    plant_sunflower,
    plant_peashoter,
    
    plant_end
  } type;
  hp health;
  time cooldown;
};

time plant_cooldown[plant::plant_type::plant_end] = { 100, 200 };


struct zombie {
  enum zombie_type {
    zombie_regular,
    zombie_coned,

    zombie_end
  } type;
  hp health;
  float position;
};
float zombie_speed[zombie::zombie_type::zombie_end] = { 0.10, 0.10 };

struct projectile {
  enum projectile_type {
    projectile_sun,
    projectile_pea,

    projectile_end
  } type;
  float position_x;
  float position_y;
  float velocity_x;
  float velocity_y;
};
hp projectile_damage[projectile::projectile_type::projectile_end] = { 0 , 100 };

struct tile {
  enum tile_type {
    tile_grass,

    tile_end
  } type;
  bool is_planted;
  struct plant plant;
};

#ifdef LINES_WOLRD

struct line {
  size_t width;
  struct tile *tiles;
  struct zombie vec zombies;
};

struct world {
  size_t height;
  struct line *line;
  struct projectile vec projectiles;
};

#else

struct world {
  size_t width;
  size_t height;
  struct tile **tiles; 
  struct zombie vec*zombies;
  struct projectile vec projectiles;
};

#endif

#endif
