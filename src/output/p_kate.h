/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   $Id$

   class definition for the Kate packetizer

   Written by ogg.k.ogg.k <ogg.k.ogg.k@googlemail.com>.
   Adapted from code by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __P_KATE_H
#define __P_KATE_H

#include "os.h"

#include "common.h"
#include "pr_generic.h"
#include "smart_pointers.h"
#include "kate_common.h"

class kate_packetizer_c: public generic_packetizer_c {
private:
  vector<memory_cptr> headers;
  memory_cptr global_data;

  kate_identification_header_t kate_id;

  int64_t last_timecode;

public:
  kate_packetizer_c(generic_reader_c *_reader, const void *_global_data, int _global_size, track_info_c &_ti) throw (error_c);
  virtual ~kate_packetizer_c();

  virtual int process(packet_cptr packet);
  virtual void set_headers();

  virtual const char *get_format_name() {
    return "Kate";
  }
  virtual connection_result_e can_connect_to(generic_packetizer_c *src, string &error_message);
};


#endif  // __P_KATE_H
