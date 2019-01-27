#include <AverageUsage.hpp>

using namespace systemkultur;

int main()
{

  const auto usage = AverageUsage::create_from_proc();
  std::cout <<  usage << std::endl;
  return EXIT_SUCCESS;
}
