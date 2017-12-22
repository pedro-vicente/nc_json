#include "nc_read.hh"
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////////////////
//nc_read::read
/////////////////////////////////////////////////////////////////////////////////////////////////////

int nc_read::read(const std::string& file_name)
{
  int nc_id;

  if (nc_open(file_name.c_str(), NC_NOWRITE, &nc_id) != NC_NOERR)
  {
    return -1;
  }

  if (iterate(file_name, nc_id) != NC_NOERR)
  {

  }

  if (nc_close(nc_id) != NC_NOERR)
  {

  }

  return NC_NOERR;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//nc_read::iterate
/////////////////////////////////////////////////////////////////////////////////////////////////////

int nc_read::iterate(const std::string& file_name, const int grp_id)
{
  char grp_nm[NC_MAX_NAME + 1]; // group name 
  char var_nm[NC_MAX_NAME + 1]; // variable name 
  char *grp_nm_fll = NULL; // group full name 
  int nbr_att; // number of attributes 
  int nbr_dmn_grp; // number of dimensions for group 
  int nbr_var; // number of variables 
  int nbr_grp; // number of sub-groups in this group 
  int nbr_dmn_var; // number of dimensions for variable 
  nc_type var_typ; // netCDF type 
  int *grp_ids; // sub-group IDs array
  size_t grp_nm_lng; //lenght of full group name
  int var_dimid[NC_MAX_VAR_DIMS]; // dimensions for variable
  size_t dmn_sz[NC_MAX_VAR_DIMS]; // dimensions for variable sizes
  char dmn_nm_var[NC_MAX_NAME + 1]; //dimension name

  // get full name of (parent) group
  if (nc_inq_grpname_full(grp_id, &grp_nm_lng, NULL) != NC_NOERR)
  {

  }

  grp_nm_fll = new char[grp_nm_lng + 1];

  if (nc_inq_grpname_full(grp_id, &grp_nm_lng, grp_nm_fll) != NC_NOERR)
  {

  }

  std::cout << grp_nm_fll << '\n';

  if (nc_inq(grp_id, &nbr_dmn_grp, &nbr_var, &nbr_att, (int *)NULL) != NC_NOERR)
  {

  }

  for (int idx_var = 0; idx_var < nbr_var; idx_var++)
  {
    std::vector<ncdim_t> ncdim; //dimensions for each variable 

    if (nc_inq_var(grp_id, idx_var, var_nm, &var_typ, &nbr_dmn_var, var_dimid, &nbr_att) != NC_NOERR)
    {

    }

    std::string path(grp_nm_fll);
    if (path.compare("/") != 0)
    {
      path += "/";
    }
    path += var_nm;
    std::cout << path << '\n';

    //get dimensions
    for (int idx_dmn = 0; idx_dmn < nbr_dmn_var; idx_dmn++)
    {
      //dimensions belong to groups
      if (nc_inq_dim(grp_id, var_dimid[idx_dmn], dmn_nm_var, &dmn_sz[idx_dmn]) != NC_NOERR)
      {

      }
    }//dimensions
  }//variables 

  if (nc_inq_grps(grp_id, &nbr_grp, (int *)NULL) != NC_NOERR)
  {

  }

  grp_ids = new int[nbr_grp];

  if (nc_inq_grps(grp_id, &nbr_grp, grp_ids) != NC_NOERR)
  {

  }

  for (int idx_grp = 0; idx_grp < nbr_grp; idx_grp++)
  {
    if (nc_inq_grpname(grp_ids[idx_grp], grp_nm) != NC_NOERR)
    {

    }

    if (iterate(file_name, grp_ids[idx_grp]) != NC_NOERR)
    {

    }
  }

  delete[] grp_ids;
  delete[] grp_nm_fll;

  return NC_NOERR;
}

