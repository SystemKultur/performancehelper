#include <Poco/Process.h>
#include <PerformanceHelper.hpp>


using namespace systemkultur;

std::uint32_t PerformanceHelper::pid()
{
  return Poco::Process::id();
}
