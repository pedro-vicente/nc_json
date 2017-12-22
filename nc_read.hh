#ifndef NC_ITERATE_HH
#define NC_ITERATE_HH

#include <string>
#include <vector>
#include <netcdf.h>
#include "nc_data.hh"

class nc_read
{
public:
  nc_read()
  {
  }
  int read(const std::string& file_name);
  int iterate(const std::string& file_name, const int grp_id);
};


#endif

