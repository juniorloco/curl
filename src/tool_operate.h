#ifndef HEADER_CURL_TOOL_OPERATE_H
#define HEADER_CURL_TOOL_OPERATE_H
/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include "tool_setup.h"
#include "tool_cb_hdr.h"
#include "tool_cb_prg.h"

struct per_transfer {
  /* double linked */
  struct per_transfer *next;
  struct per_transfer *prev;
  CURL *curl;
  long retry_numretries;
  long retry_sleep_default;
  long retry_sleep;
  struct timeval retrystart;
  bool metalink; /* nonzero for metalink download. */
  bool metalink_next_res;
  metalinkfile *mlfile;
  metalink_resource *mlres;
  char *this_url;
  char *outfile;
  bool infdopen; /* TRUE if infd needs closing */
  int infd;
  struct ProgressData progressbar;
  struct OutStruct outs;
  struct OutStruct heads;
  struct InStruct input;
  struct HdrCbData hdrcbdata;
  char errorbuffer[CURL_ERROR_SIZE];

  /* NULL or malloced */
  char *separator_err;
  char *separator;
  char *uploadfile;
};

CURLcode operate(struct GlobalConfig *config, int argc, argv_item_t argv[]);

#endif /* HEADER_CURL_TOOL_OPERATE_H */
