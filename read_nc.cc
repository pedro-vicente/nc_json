#include <iostream>
#include <stdio.h>
#include "nc_json.hh"
#include "nc_read.hh"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//main
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "usage : ./read_nc <netcdf file>" << std::endl;
    return 1;
  }

  nc_read read_nc;
  if (read_nc.read(argv[1]) < 0)
  {
    return 1;
  }

  return 0;
}
