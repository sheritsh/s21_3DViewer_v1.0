#ifndef C8_3DVIEWER_V1_0_1_MODEL_LOADING_H
#define C8_3DVIEWER_V1_0_1_MODEL_LOADING_H

#include "s21_3dviewer.h"

int parse_obj_file(char *filename, obj_data *data);
int memory_allocation(obj_data *data);
void count_vertices_and_indices(FILE *file, obj_data *data);
void data_destructor(obj_data *data);
int parse_vertices_and_indices(FILE *file, obj_data *data);
void print_data(obj_data *data);

#endif  // C8_3DVIEWER_V1_0_1_MODEL_LOADING_H
