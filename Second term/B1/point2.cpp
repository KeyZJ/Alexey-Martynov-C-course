#include "point2.hpp"
#include "uttils.hpp"

#include <fstream>
#include <vector>
#include <cstddef>
#include <memory>

void readFile(int argc, char * argv[])
{
  const int arguments = 3;
  if (argc != arguments)
  {
    throw std::invalid_argument("Invalid arguments! You must enter: point_number filename!\n");
  }
  std::unique_ptr<FILE, decltype(&fclose)> file(fopen(argv[2], "r"), &fclose);

  if (!file.get())
  {
    throw std::runtime_error("Missing the file!\n");
  }

  const size_t size_block = 4096;

  std::unique_ptr<char[], decltype(&free)> arr_c(static_cast<char*>(malloc(size_block)), &free);
  size_t size = fread(&arr_c[0], sizeof(char), size_block, file.get());

  if (size != 0)
  {
    while (size % size_block == 0)
    {
      std::unique_ptr<char[], decltype(&free)> new_arr(static_cast<char*>(realloc(arr_c.get(), size + size_block)), &free);
      if (!new_arr)
      {
        throw std::bad_alloc();
      }
      arr_c.release();
      arr_c.swap(new_arr);
      size += fread(&arr_c[size], sizeof(char), size_block, file.get());
    }
  }

  std::vector<char> data(&arr_c[0], &arr_c[size]);
  uttills::printContainer(data,false);
}
