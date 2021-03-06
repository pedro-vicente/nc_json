#include <iostream>
#include <stdio.h>
#include "nc_json.hh"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//main
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "usage : ./read_ncjson <NCO-JSON file>" << std::endl;
    return 1;
  }

  cf_json parser;
  if (parser.convert(argv[1]) < 1)
  {
    return 1;
  }

  return 0;
}
