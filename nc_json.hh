#ifndef STAR_JSON_HH
#define STAR_JSON_HH

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Purpose: Parse a CF-JSON format file
// External dependencies: 
// netCDF library (including HDF5, Curl, zlib, szip)
// Included dependencies
// JSON gason library
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "gason.h"
#ifdef HAVE_NETCDF
#include <netcdf.h>
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////
//cf_json
/////////////////////////////////////////////////////////////////////////////////////////////////////

class cf_json
{
public:
  cf_json()
  {
  }
  int convert(const char* file_name);

private:
  void do_objects_group(JsonValue value, const char* grp_name, int grp_id, int indent = 0);
  int do_groups(JsonValue value, const char* grp_name, int grp_id, int indent = 0);
  int do_dimensions(JsonValue value, const char* grp_name, int grp_id, int indent = 0);
  int do_variables(JsonValue value, const char* grp_name, int grp_id, int indent = 0);
  int do_attributes(JsonValue value, const char* grp_name, int grp_id, int indent = 0);
  int get_variable_data(JsonValue value, const char* var_name, int grp_id, int indent = 0);
  int dump_value(JsonValue value, int indent = 0);
  void dump_string(const char *s);
  void object_separator(JsonNode *node, int indent);
};

#endif




