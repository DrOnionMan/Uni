#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAT_WIDTH 12



typedef enum Bearing {
  NODIR = 0, NORTH, EAST, SOUTH, WEST
} Bearing_t;


typedef struct Matrix {
  uint32_t rows;
  uint32_t cols;
  char** mat;
} Matrix_t;

typedef struct Vec2 {
  uint32_t x;
  uint32_t y;
  enum Bearing dir;
} Pos_t, Vec2_t;

// MISC FUNCTIONS
static inline void init_Vec2_t(struct Vec2* const restrict v);
static size_t read_entire_file(const char* fname, char* buffer);
static void create_maze_matrix(struct Matrix* const restrict mat, const char* const restrict maze, const size_t len);
#if defined(__DEBUG__)
static void print_matrix(const struct Matrix* const restrict mat);
#else
  #define print_matrix(...) ;
#endif
// A* & RELATED FUNCTIONS

// FUNCS FOR THE COURSEWORK ALGORITHM


int main(int argc, char** argv) {
  (void) argc;
#if defined(__DEBUG__)
  const char* fname = argv[1];
  char* fcontents = NULL;
  size_t alloc_len = read_entire_file(fname, fcontents);
  if (0 == alloc_len) {
    return -1;
  }
  printf("%s", fcontents);
  Matrix_t mat;
  create_maze_matrix(&mat, fcontents, alloc_len);
  print_matrix(&mat);
#else 
  printf("coolio");
#endif
  return 0;
}


























static inline void init_Vec2_t(struct Vec2* const restrict v) {
  v->x = 0; v->y = 0; v->dir = NODIR;
}


static inline bool is_valid_maze_char(const char c) {
  switch(c) {
    case 'W':
    case 'M':
    case 'P':
    case 'T': return true;
    default: return false;
  }
  return false;
}


#if defined( __DEBUG__)
static void print_matrix(const struct Matrix* const restrict mat) {
  for (uint32_t i = 0; i < mat->rows; i++) {
    printf("\n");
    for (uint32_t j = 0; j < mat->cols; j++) {
      printf("%c", mat->mat[i][j]);
    }
  }
}
#endif

static void create_maze_matrix(struct Matrix* const restrict mat, const char* const restrict maze, const size_t len) {
  mat->rows = MAT_WIDTH;
  mat->cols = MAT_WIDTH;
  // allocate rows
  mat->mat = (char**) malloc(sizeof(char*) * MAT_WIDTH);
  for (size_t i = 0; i < MAT_WIDTH; i++) mat->mat[i] = (char*) malloc(sizeof(char) * MAT_WIDTH);
  size_t mat_row = 0;
  size_t mat_col = 0;
  for (size_t i = 0; i < len; i++) {
    if ('\n' == maze[i]) {
      mat_row++;
      mat_col = 0;
      continue;
    }
    if(is_valid_maze_char(maze[i])) {
      mat->mat[mat_row][mat_col] = maze[i];
      mat_col++;
    }
  }
  return;
}

static size_t read_entire_file(const char* fname, char* buffer) {
  FILE* pfile = NULL;
  pfile = fopen(fname, "rb");
  if(!pfile) {
    printf("whvbbbwcce");
    goto Failure;
  }
  const size_t flen = fseek(pfile, 0L, SEEK_END);
  rewind(pfile);
  buffer = (char*) malloc( sizeof(char) * flen);
  if (!buffer) {
    goto Failure;
  }
  const size_t bytes_read = fread(buffer, sizeof(char), flen, pfile);
  if (bytes_read != flen) {
    goto Failure;
  }
  buffer[bytes_read] = '\0';
  fclose(pfile);
  return bytes_read;
Failure:
  printf("Error!");
  return 0;
}
