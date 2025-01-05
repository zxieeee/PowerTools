// so this file will contain function to organise multi files

#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<filesystem>
#include"../header/core.h"

std::string getfile_ext(const std::string& filename)
{
  //here we use size_t insted of string as find_last_of function returns in size_t
  //using it will case this error ERROR: Cannot assign size_t to std::string
  //intrative approch is not correct here as there can be multiple dots or white spaces in filename
  size_t pos = filename.find_last_of('.');
  // adding approprate not found postion which is npos for the size_t var
  if(pos == std::string::npos)//checking for errors
  {
    return "";
  }
//   pos + 1 to exclude the '.' in file name
  return filename.substr(pos+1);
}


void save(const std::vector<std::string>& file)
{
    //for unpacking files in vectors
    for(const auto& name : file )
    {
        std::filesystem::path source(name); // Create `source` directly using `name`
        // passing the difrent files to the getfile_ext function
        std::string ext = getfile_ext(name);

        // defining the file name ie extention + file name
        std::filesystem::path folder(ext + "_folder");
        
        // now checking if the folder exist or not by using the exist fun in the stl of filesystem
        if(!std::filesystem::exists(folder))
        {
        //   using create dir fin to cxretate dir if not allredy exist
        std::filesystem::create_directory(folder);
        }

        //  saving the file to the folder name 
        //fs::path destination = folder / file.filename();
        // folder: A std::filesystem::path object representing the folder where the file should be moved.
        // file.filename(): A method that extracts the filename (including the extension) from the full file path.
        // folder / file.filename(): This uses the / operator, which is overloaded in std::filesystem::path to concatenate paths in a platform-independent way.
        // If folder is "png_folder" and file.filename() is "image1.png", the result is "png_folder/image1.png" (or "png_folder\\image1.png" on Windows).
        // The resulting path (destination) represents the target location where the file will be moved.
        std::filesystem::path destination = folder/source.filename();

        if (std::filesystem::exists(source))
        {
          try //error handleing
          {
          // fs::rename it Moves or renames a file from one location to another.
          // if the destination already exists, it replaces the existing file 
          // It is a filesystem operation that is more efficient than copying and
          //  deleting, as it typically just updates the file system metadata.
          // file: The current path of the source (source).
          // destination: The new path of the file (target).
          std::filesystem::rename(source , destination);
        
          // printing the path 
          std::cout << "Moved: " << source.string() << " -> " << destination.string() << std::endl;
          }
          catch (const std::exception& e) 
          {
          std::cerr << "Error moving file: " << source << " - " << e.what() << std::endl;
          }
        }
        else
        {
          std::cerr << "File not found: " << source.string() << std::endl;
        }
      
    }
}

