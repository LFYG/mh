/**
 * src/app/app.h -- header file for mh_cli app
 *
 * @author sskaje
 * @license MIT
 * ------------------------------------------------------------------------
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 - , sskaje (https://sskaje.me/)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * ------------------------------------------------------------------------
 */

#ifndef MH_APP_H
#define MH_APP_H

#define MH_APP_VERSION "0.2.0"

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>

#include <linenoise.h>

#include <mh/mh.h>


char ** args_parse(const char* cmd, int* argc);


typedef struct
{
    pid_t              process_id;
    MHProcess          process;
    MHDyldInfo         dyld;
    struct result_head results;
    size_t             result_count;
    size_t             query_size;
    struct result_entry *result_ptr;

} MHContext;

static MHContext *mh_global_context = NULL;

MHContext *MH_new();

int MH_free(MHContext *context);

int MHSaveGlobalContext(MHContext *context);

MHContext *MHGetGlobalContext();


#include "commands/commands.h"

#include "misc.h"


#endif //MH_APP_H

// EOF