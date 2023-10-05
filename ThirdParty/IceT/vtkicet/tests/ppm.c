/* -*- c -*- *******************************************************/
/*
 * Copyright (C) 2003 Sandia Corporation
 * Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
 * the U.S. Government retains certain rights in this software.
 *
 * This source code is released under the New BSD License.
 */

#include "test_util.h"

#include <stdlib.h>
#include <stdio.h>

#include <IceT.h>

void write_ppm(const char *filename,
               const IceTUByte *image,
               int width, int height)
{
    FILE *fd;
    int x, y;
    const unsigned char *color;

#ifndef WIN32
    fd = fopen(filename, "wb");
#else /*WIN32*/
    fopen_s(&fd, filename, "wb");
#endif /*WIN32*/

    fprintf(fd, "P6\n");
    fprintf(fd, "# %s generated by IceT test suite.\n", filename);
    fprintf(fd, "%d %d\n", width, height);
    fprintf(fd, "255\n");

    for (y = height-1; y >= 0; y--) {
        color = image + y*width*4;
        for (x = 0; x < width; x++) {
            fwrite(color, 1, 3, fd);
            color += 4;
        }
    }

    fclose(fd);
}
