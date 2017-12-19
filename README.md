# nc_json

JSON parser for netCDF, netCDF to JSON generator
-------

NCO-JSON/CF-JSON is a JSON format primarily intended for encoding climate and weather data. NCO-JSON is based on the NetCDF CF metadata conventions.
<br/> 
nc_json reads and validates a NCO-JSON file and optionally generates the corresponding netCDF file.
<br/> 
http://cf-json.org


Dependencies
------------
[CMake](https://cmake.org)
CMake build system

Optional
<br/> 
[netCDF](http://www.unidata.ucar.edu/software/netcdf)
netCDF is a set of software libraries and self-describing, 
machine-independent data formats that support the creation, 
access, and sharing of array-oriented scientific data.
<br /> 

JSON parsing
------------
https://github.com/vivkin/gason
A C++ JSON parser (included).
<br /> 

Building from source
------------

Install dependency packages: Debian-based systems (like Ubuntu)
<pre>
sudo apt-get install cmake
sudo apt-get install libnetcdf-dev netcdf-bin netcdf-doc
</pre>

Install dependency packages: For RPM-based systems (like Fedora and CentOS)
<pre>
sudo yum install netcdf netcdf-devel
sudo yum install cmake
</pre>

Get source:
<pre>
git clone https://github.com/pedro-vicente/nc_json.git
</pre>

Building with CMake in Unix
------------
On most Unix systems, the Jansson, netCDF libraries and dependencies are found on the default location with
<pre>
cd build
cmake ..
</pre>

CMake build options
------------
If the netCDF libraries and dependencies (HDF5, curl, zlib, szip) are not found on the default location, they can be set. 
<pre>
cmake .. \
-DNETCDF_INCLUDE:PATH=/your/netcdf/include/path \
-DNETCDF_LIBRARY=/your/netcdf/library/file/name \
-DCURL_LIBRARY=/your/curl/library/file/name \
-DHDF5_LIBRARY=/your/hdf5/library/file/name \
-DHDF5_HL_LIBRARY=/your/hdf5 high level/library/file/name \
-DZLIB_LIBRARY=/your/zlib/library/file/name \
-DSZIP_LIBRARY=/your/zlib/library/file/name
</pre>



Examples
------------

<pre>
{
  "dimensions":{
    "lat":2,
    "lon":3
  },
  "variables":{
    "var_1":{
      "shape":["lat","lon"],
      "type":"float",
      "data":[[1,2,3],[4,5,6]],
      "attributes": {
        "char_att": "foo",
        "int_att": 37,
        "float_att": 73.0,
        "arr_int_att": [0, 1, 2],
        "arr_char_att": ["foo","bar"]
      }
    }
  },
  "attributes": {
    "char_att": "foo",
    "int_att": 37,
    "float_att": 73.0,
    "arr_int_att": [0, 1, 2],
    "arr_char_att": ["foo","bar"]
  },
  "groups":{
    "g1":{
      "groups":{
        "g11":{
        }
      }
    },
    "g2":{
      "dimensions":{
        "lat":2,
        "lon":3
      },
      "variables":{
        "var_1":{
          "shape":["lat","lon"],
          "type":"float",
          "data":[[1,null,3],[null,null,6]]
        }
        "var_2":{
          "shape":["lat"],
          "type":"float",
          "data":[1,2,3]
        }
      }
    }
  }
}
</pre>


Documentation
--------------
http://cf-json.org/specification


