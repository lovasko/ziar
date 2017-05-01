#include <stdio.h>
#include <stdlib.h>

#include "cam/persp.h"
#include "geom/vector.h"
#include "geom/ray.h"
#include "geom/isect.h"
#include "obj/object.h"
#include "obj/plane.h"
#include "obj/sphere.h"
#include "proc/debug.h"
#include "scene/array.h"

/* Scene camera. */
static persp cam;

/* Scene objects. */
static object objs[2];
/* static sphere sp; */
static plane pl;

static void
clamp(unsigned int* x, unsigned int lo, unsigned int hi)
{
  if (*x > hi) *x = hi;
  if (*x < lo) *x = lo;
}

static unsigned int
scale(float x, unsigned int s)
{
  unsigned int y;

  y = (unsigned int)(x * (float)s);
  clamp(&y, 0, s);
  return y;
}

static void
init_camera(void)
{
  vector_init(&cam.ps_pos, 0.0f, 2.0f, -20.0f);
  vector_init(&cam.ps_up,  0.0f, 1.0f, 0.0f);
  vector_init(&cam.ps_for, 0.0f, 0.0f, 1.0f);
  cam.ps_fov = 20.0f;

  cam_persp_setup(&cam, 60.0f / 80.0f);
}

static void
init_scene(void)
{
  /* vector_init(&sp.sp_pos, 0.0f, 1.0f, 2.0f); */
  /* sp.sp_rad = 1.0f; */
  /* objs[0].ob_geo = &sp; */
  /* objs[0].ob_mat = NULL; */
  /* objs[0].ob_gt  = OBJ_SPHERE; */
  /* objs[0].ob_mt  = 0; */

  vector_init(&pl.pl_pos, 0.0f, 0.0f, 0.0f);
  vector_init(&pl.pl_nor, 0.0f, 1.0f, 0.0f);
  objs[0].ob_geo = &pl;
  objs[0].ob_mat = NULL;
  objs[0].ob_gt  = OBJ_PLANE;
  objs[0].ob_mt  = 0;
}

int
main(void)
{
  FILE* output;
  float x;
  float y;
  vector c;
  ray r;
  isect i;

  init_camera();
  init_scene();

  output = fopen("output.ppm", "w");
  if (output == NULL) {
    perror("fopen");
    exit(1);
  }

  /* file header */
  fprintf(output, "P3\n%d %d\n", 80, 60);

  for (x = 0.0f; x <= 60.0f; x += 1.0f) {
    for (y = 0.0f; y <= 80.0f; y += 1.0f) {
      cam_persp_primary(&cam, x, y, &r);
      scene_array_intersect(objs, 1, &r, &i);
      proc_debug_compute(&r, &i, &c);
      fprintf(output, "%u %u %u ",
             scale(c.vc_x, 255),
             scale(c.vc_y, 255),
             scale(c.vc_z, 255));
    }
    fprintf(output, "\n");
  }

  return EXIT_SUCCESS;
}