#include <iostream>

#include <boost/lexical_cast.hpp>
#include <boost/process.hpp>
#include <boost/tokenizer.hpp>

#include <AverageUsage.hpp>
#include <PerformanceHelper.hpp>

using namespace boost::process;
using namespace systemkultur;

AverageUsage::AverageUsage
(
  const float cpu,
  const float memory
)
: _cpu(cpu)
, _memory(memory)
{}

float AverageUsage::cpu() const
{
  return _cpu;
}

float AverageUsage::memory() const
{
  return _memory;
}

void print (const std::string in)
{
  std::cout << "|" << in << "|" << std::endl;
}

AverageUsage from_string(const std::string& in)
{
  boost::tokenizer<> t(in);
  std::vector<std::string> v(t.begin(), t.end());
  return AverageUsage
          (
            boost::lexical_cast<float>(v.at(0)),
            boost::lexical_cast<float>(v.at(1))
          );
}
const AverageUsage AverageUsage::create_from_proc()
{
  const std::string cmd = std::string("/bin/ps -p ")
                        + std::to_string(PerformanceHelper::pid())
                        + std::string(" -o %cpu,%mem");
  /* result is something like
  %CPU %MEM
   0.0  0.0
  */

  ipstream pipe_stream;
  child c(cmd, std_out > pipe_stream);

  std::vector<std::string> results;
  std::string line;
  while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
    results.push_back(line);
  c.wait();

  return (results.size() > 1)
        ? from_string(results[1])
        : AverageUsage(0,0);
}

std::ostream& operator<<( std::ostream& stream, const AverageUsage& config)
{
    return stream   << "cpu="   << config.cpu()
                    << ",memory="<< config.memory();
}
