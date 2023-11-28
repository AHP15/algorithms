#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>


auto print = [](auto const& map)
{
  for (const auto& pair : map)
    std::cout << '{' << pair.first << ": " << pair.second << '}';
  std::cout << "\n";
};

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Usage: <program name> <file path>\n";
    return -1;
  }

  std::string filepath{argv[1]};
   std::ifstream inf{filepath};

  if(!inf.is_open())
  {
    std::cout << "failed to open " << filepath << '\n';
    return -1;
  }

  char file_content{};
  int length{0};
  std::map<char, int> char_numbers{};
  while (inf)
  {
    inf >> file_content;
    if(auto search = char_numbers.find(file_content); search != char_numbers.end())
    {
      ++char_numbers[file_content];
    } else
    {
      char_numbers[file_content] = 1;
    }

    std::cout << file_content << '\n';
    ++length;
  }

  print(char_numbers);
  return 0;
}
