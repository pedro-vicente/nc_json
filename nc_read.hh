#ifndef NC_ITERATE_HH
#define NC_ITERATE_HH

#include <string>
#include <vector>
#include <netcdf.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////
//ncdim_t
//a netCDF dimension has a name and a size
/////////////////////////////////////////////////////////////////////////////////////////////////////

class ncdim_t
{
public:
  ncdim_t(const char* name, size_t size) :
    m_name(name),
    m_size(size)
  {
  }
  std::string m_name;
  size_t m_size;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//ncvar_t
//a netCDF variable has a name, a netCDF type, data buffer, and an array of dimensions
//defined in iteration
//data buffer is stored on per load variable from tree using netCDF API from item input
/////////////////////////////////////////////////////////////////////////////////////////////////////

class ncvar_t
{
public:
  ncvar_t(const char* name, nc_type nc_typ, const std::vector<ncdim_t> &ncdim) :
    m_name(name),
    m_nc_type(nc_typ),
    m_ncdim(ncdim)
  {
    m_buf = NULL;
  }
  ~ncvar_t()
  {
    switch (m_nc_type)
    {
    case NC_STRING:
      if (m_buf)
      {
        char **buf_string = NULL;
        size_t idx_buf = 0;
        buf_string = static_cast<char**> (m_buf);
        if (m_ncdim.size())
        {
          for (size_t idx_dmn = 0; idx_dmn < m_ncdim.size(); idx_dmn++)
          {
            for (size_t idx_sz = 0; idx_sz < m_ncdim[idx_dmn].m_size; idx_sz++)
            {
              free(buf_string[idx_buf]);
              idx_buf++;
            }
          }
        }
        else
        {
          free(*buf_string);
        }
        free(static_cast<char**>(buf_string));
      }
      break;
    default:
      free(m_buf);
    }
  }
  void store(void *buf)
  {
    m_buf = buf;
  }
  std::string m_name;
  nc_type m_nc_type;
  void *m_buf;
  std::vector<ncdim_t> m_ncdim;
};

int read_nc(const std::string& file_name);
int iterate(const std::string& file_name, const int grp_id);

#endif

